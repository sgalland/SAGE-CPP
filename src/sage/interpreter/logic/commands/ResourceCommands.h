#pragma once

#include <boost/type_traits.hpp>
#include <cinttypes>

#include "../../AgiInterpreter.h"

using namespace sage::agi;

namespace sage
{
	namespace agi
	{
		class ResourceCommands
		{
		private:
			static void load_resource(uint8_t resourceID);
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