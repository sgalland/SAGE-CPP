#pragma once

#include <string>

#include "LogicCallbacks.h"

using namespace sage::agi;

namespace sage
{
	namespace agi
	{
		class DispatcherContainer
		{
		private:
			int id;
			std::string functionName;
			int argCount;
			cb0_t callback0;
			cb1_t callback1;
			cb2_t callback2;
			cb3_t callback3;
			cb4_t callback4;
			cb5_t callback5;

			acb0_t acallback0;
			acb1_t acallback1;
			acb2_t acallback2;
			acb3_t acallback3;
			acb4_t acallback4;
			acb5_t acallback5;

			void Initialize(uint8_t id, std::string functionName, cb0_t callback0, cb1_t callback1, cb2_t callback2, cb3_t callback3, cb4_t callback4, cb5_t callback5, uint8_t argumentCount);
			void Initialize(uint8_t id, std::string functionName, acb0_t callback0, acb1_t callback1, acb2_t callback2, acb3_t callback3, acb4_t callback4, acb5_t callback5, uint8_t argumentCount);

		public:
			DispatcherContainer(uint8_t id, std::string functionName, cb0_t callback0);
			DispatcherContainer(uint8_t id, std::string functionName, cb1_t callback1);
			DispatcherContainer(uint8_t id, std::string functionName, cb2_t callback2);
			DispatcherContainer(uint8_t id, std::string functionName, cb3_t callback3);
			DispatcherContainer(uint8_t id, std::string functionName, cb4_t callback4);
			DispatcherContainer(uint8_t id, std::string functionName, cb5_t callback5);

			DispatcherContainer(uint8_t id, std::string functionName, acb0_t acallback0);
			DispatcherContainer(uint8_t id, std::string functionName, acb1_t acallback1);
			DispatcherContainer(uint8_t id, std::string functionName, acb2_t acallback2);
			DispatcherContainer(uint8_t id, std::string functionName, acb3_t acallback3);
			DispatcherContainer(uint8_t id, std::string functionName, acb4_t acallback4);
			DispatcherContainer(uint8_t id, std::string functionName, acb5_t acallback5);

			bool CallTest(uint8_t arg1, uint8_t arg2, uint8_t arg3, uint8_t arg4, uint8_t arg5);
			void CallAction(uint8_t arg1, uint8_t arg2, uint8_t arg3, uint8_t arg4, uint8_t arg5);			

			int getID();

			uint8_t getArgumentCount();
		};
	}
}