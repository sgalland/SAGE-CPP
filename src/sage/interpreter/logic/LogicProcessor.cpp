#include "LogicProcessor.h"

sage::agi::LogicProcessor::LogicProcessor()
{
}

void LogicProcessor::Execute(uint8_t resourceID)
{
	AgiFileReader logicReader(AgiFileType::Logic);
	AgiLogic logic(logicReader.GetFile(resourceID), resourceID);
	AgiInterpreter::currentLogic = &logic;

	bool isRunning = true;
	logicIndex = -1;
	uint8_t currentByte = 0;

	do
	{
		currentByte = AgiInterpreter::currentLogic->GetLogicData().at(++logicIndex);
		switch (currentByte)
		{
		case 0x00: isRunning = false; break; // return statement
		case 0xFF: ProcessIf(); break; // if statement
		default:
			ProcessAction(currentByte);
			break;
		}
	} while (logicIndex < AgiInterpreter::currentLogic->GetLogicData().size() && isRunning);
}

void LogicProcessor::ProcessIf()
{
	uint8_t currentByte = 0xFF;
	bool notCondition = false;
	bool orCondition = false;

	this->processActions = true;

	do
	{
		currentByte = AgiInterpreter::currentLogic->GetLogicData().at(++logicIndex);

		switch (currentByte)
		{
		case 0xFD: notCondition = false; break; // Not
		case 0xFC: orCondition = true; break; // Or
		case 0xFF: break; // end of if statement
		default:
			DispatcherContainer* condition = this->testDispatcher[currentByte];
			if (condition != nullptr)
			{
				std::vector<uint8_t> args = GetArguments(condition->getArgumentCount());

				if (orCondition)
					processActions = processActions || testDispatcher.ExecuteTest(currentByte, args);
				else
					processActions = processActions && testDispatcher.ExecuteTest(currentByte, args);

				if (notCondition)
					processActions = !processActions;
			}
			break;
		}
	} while (currentByte != 0xFF);

	codeBlockSize = ReadCodeBlockSize();

	if (!processActions)
	{
		logicIndex += codeBlockSize;
	}
}

void LogicProcessor::ProcessAction(uint8_t currentByte)
{
	DispatcherContainer* action = this->actionDispatcher[currentByte];
	if (action != nullptr)
	{
		std::vector<uint8_t> args = GetArguments(action->getArgumentCount());
		actionDispatcher.ExecuteAction(currentByte, args);
	}	
}

int LogicProcessor::ReadCodeBlockSize()
{
	return AgiInterpreter::currentLogic->GetLogicData().at(++this->logicIndex) + (AgiInterpreter::currentLogic->GetLogicData().at(++this->logicIndex) << 8);
}

std::vector<uint8_t> sage::agi::LogicProcessor::GetArguments(int argumentCount)
{
	std::vector<uint8_t> arguments;
	logicIndex++;

	for (int i = 0; i < argumentCount; i++)
	{
		arguments.push_back(AgiInterpreter::currentLogic->GetLogicData().at(logicIndex + i));
	}

	logicIndex += argumentCount - 1;

	return arguments;
}





