#pragma once

namespace sage
{
	namespace agi
	{
		enum class ViewMotion
		{
			/// <summary>
			/// Normal motion.
			/// </summary>
			Normal = 0,
			/// <summary>
			/// View wanders around on screen.
			/// </summary>
			Wander = 1,
			/// <summary>
			/// View will follow the ego.
			/// </summary>
			FollowEgo = 2,
			/// <summary>
			/// Not sure what this does yet.
			/// </summary>
			MoveObject = 3
		};
	}
}
