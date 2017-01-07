#pragma once

#include <cinttypes>

namespace sage
{
	namespace agi
	{
		class ObjectControlCommands
		{
		public:
			static void animate_obj(uint8_t objectID);
			static void unanimate_all();
			static void set_view(uint8_t objectID, uint8_t resourceID);
			static void set_view_v(uint8_t objectID, uint8_t variableID);
			static void set_loop(uint8_t objectID, uint8_t loopID);
			static void set_loop_v(uint8_t objectID, uint8_t variableID);
			static void fix_loop(uint8_t objectID);
			static void release_loop(uint8_t objectID);
			static void set_cel(uint8_t objectID, uint8_t celID);
			static void set_cel_v(uint8_t objectID, uint8_t variableID);
			static void last_cel(uint8_t objectID, uint8_t variableID);
			static void current_cel(uint8_t objectID, uint8_t variableID);
			static void current_loop();
			static void current_view();
			static void set_priority();
			static void set_priority_v();
			static void release_priority();
			static void get_priority();
			static void position();
			static void position_n();
			static void draw();
			static void erase();
			static void get_posn();
			static void start_cycling();
			static void stop_cycling();
			static void normal_cycling();
			static void reverse_cycle();
			static void end_of_loop();
			static void reverse_loop();
			static void cycle_time();

		};
	}
}