#pragma once

#include <boost/type_traits.hpp>
#include <cinttypes>
#include "../../resources/AgiFileReader.h"

namespace sage
{
	namespace agi
	{
		class ResourceCommands
		{
		private:
			static AgiFile& load_resource(uint8_t resourceID, AgiFileType fileType);
		public:
			static void load_logic(uint8_t resourceID);
			static void load_logic_v(uint8_t variableID);
			static void load_pic(uint8_t variableID);
			static void load_view(uint8_t resourceID);
			static void load_view_v(uint8_t variableID);
			static void load_sound(uint8_t resourceID);
			static void discard_pic(uint8_t variableID);
			static void discard_view(uint8_t resourceID);
			static void discard_view_v(uint8_t variableID);
		};
	}
}