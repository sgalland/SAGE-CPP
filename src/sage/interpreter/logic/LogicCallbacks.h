#pragma once

#include <functional>

namespace sage
{
	namespace agi
	{
		using cb0_t = std::function<bool()>;
		using cb1_t = std::function<bool(uint8_t)>;
		using cb2_t = std::function<bool(uint8_t, uint8_t)>;
		using cb3_t = std::function<bool(uint8_t, uint8_t, uint8_t)>;
		using cb4_t = std::function<bool(uint8_t, uint8_t, uint8_t, uint8_t)>;
		using cb5_t = std::function<bool(uint8_t, uint8_t, uint8_t, uint8_t, uint8_t)>;

		using acb0_t = std::function<void()>;
		using acb1_t = std::function<void(uint8_t)>;
		using acb2_t = std::function<void(uint8_t, uint8_t)>;
		using acb3_t = std::function<void(uint8_t, uint8_t, uint8_t)>;
		using acb4_t = std::function<void(uint8_t, uint8_t, uint8_t, uint8_t)>;
		using acb5_t = std::function<void(uint8_t, uint8_t, uint8_t, uint8_t, uint8_t)>;
	}
}