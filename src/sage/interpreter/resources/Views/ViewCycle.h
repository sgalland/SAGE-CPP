#pragma once

namespace sage
{
	namespace agi
	{
		enum ViewCycle
		{
			/// <summary>
			/// Normal indicates that the animation is progressing normally, calling the next cel from beginning to end.
			/// </summary>
			Normal = 0,
			/// <summary>
			/// Indicates that the end of the animation loop has been reached.
			/// </summary>
			EndOfLoop = 1,
			/// <summary>
			/// Indicates that the animation loop will play backwards.
			/// </summary>
			ReverseLoop = 2,
			/// <summary>
			/// Indicates the loop is cycling backwards. NOTE: NOT REALLY SURE
			/// </summary>
			ReverseCycle = 3
		};
	}
}