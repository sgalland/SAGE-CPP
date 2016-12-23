#pragma once

namespace sage
{
	namespace agi
	{
		class ObjectControlCommands
		{
		public:
			static void animate_obj();
			static void unanimate_all();
			static void set_view();
			static void set_view_v();
			static void set_loop();
			static void set_loop_v();
			static void fix_loop();
			static void release_loop();
			static void set_cel();
			static void set_cel_v();
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