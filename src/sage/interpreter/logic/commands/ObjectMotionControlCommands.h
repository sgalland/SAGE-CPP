#pragma once

#include <cinttypes>

class ObjectMotionControlCommands
{
public:
	static void set_horizon(uint8_t horizon);
	static void ignore_horizon();
	static void observe_horizon();
	static void block();
	static void unblock();
	static void ignore_blocks();
	static void observe_blocks();
	static void ignore_objs();
	static void observe_objs();
	static void player_control();
	static void program_control();
	static void stop_motion();
	static void step_size();
	static void step_time();
	static void move_obj();
	static void move_obj_v();
	static void follow_ego();
	static void wander();
	static void normal_motion();
	static void set_dir();
	static void get_dir();
	static void object_on_water();
	static void object_on_land();
	static void object_on_anything();
	static void reposition();
	static void reposition_to();
	static void reposition_to_v();
	static void stop_update(uint8_t number);
	static void start_update();
	static void force_update();
	static void distance();
};
