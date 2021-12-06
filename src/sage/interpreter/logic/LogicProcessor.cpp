#include "LogicProcessor.h"
#include "../resources/AgiLogic.h"
#include "../AgiInterpreter.h"

//AgiLogic * LogicProcessor::currentLogic;

sage::agi::LogicProcessor::LogicProcessor(AgiInterpreter* interpreter)
{
	this->interpreter = interpreter;
}

void LogicProcessor::Execute(uint8_t resourceID)
{
	this->currentLogic = this->interpreter->logics[resourceID];

	bool isRunning = true;
	logicIndex = -1;
	uint8_t currentByte = 0;

	do
	{
		currentByte = currentLogic->GetLogicData().at(++logicIndex);
		switch (currentByte)
		{
		case 0x00: isRunning = false; break;
		case 0xFF: ProcessIf(); break;
		case 0xFE: ProcessElse(); break;
		default: // All normal logic functions
			ProcessAction(currentByte);
			break;
		}
	} while (logicIndex < currentLogic->GetLogicData().size() && isRunning);
}

void LogicProcessor::ProcessIf()
{
	uint8_t currentByte = 0xFF;
	bool notCondition = false;
	bool orCondition = false;

	this->processActions = true;

	do
	{
		currentByte = currentLogic->GetLogicData().at(++logicIndex);

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

void LogicProcessor::ProcessElse()
{
	logicIndex++;
	int16_t functionSize = BitConverter::ToInt16(this->currentLogic->GetLogicData(), logicIndex);
	if (this->processActions)
		logicIndex += functionSize;
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
	return this->currentLogic->GetLogicData().at(++this->logicIndex) + (this->currentLogic->GetLogicData().at(++this->logicIndex) << 8);
}

std::vector<uint8_t> sage::agi::LogicProcessor::GetArguments(int argumentCount)
{
	std::vector<uint8_t> arguments;
	logicIndex++;

	for (int i = 0; i < argumentCount; i++)
	{
		arguments.push_back(this->currentLogic->GetLogicData().at(logicIndex + i));
	}

	logicIndex += argumentCount - 1;

	return arguments;
}





