#pragma once

#include <vector>

#include "../AgiEncryption.h"
#include "../AgiStringHelper.h"
#include "Resource.h"

namespace sage
{
	namespace agi
	{
		class AgiLogic :
			public Resource
		{
		private:
			std::vector<uint8_t> logicData;
			std::vector<std::string> messages;

			void ExtractLogicCode();
			void LoadMessages();
		public:
			AgiLogic(AgiFile file, uint8_t resourceID);
			~AgiLogic();

			std::string GetMessage(int messageIndex);
			std::vector<uint8_t> GetLogicData();
		};

	}
}