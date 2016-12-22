#pragma once

namespace sage
{
	namespace agi
	{
		enum class ViewDirection
		{
			/// <summary>
			/// View is stationary, in other words not moving.
			/// </summary>
			Stationary = 0,
			/// <summary>
			/// The view is moving towards the North (the top of the screen).
			/// </summary>
			North = 1,
			/// <summary>
			/// The view is moving towards the North East (the top-right of the screen).
			/// </summary>
			NorthEast = 2,
			/// <summary>
			/// The view is moving towards the East (the right side of the screen).
			/// </summary>
			East = 3,
			/// <summary>
			/// The view is moving towards the South East (the bottom-right side of the screen).
			/// </summary>
			SouthEast = 4,
			/// <summary>
			/// The view is moving towards the South (the bottom side of the screen).
			/// </summary>
			South = 5,
			/// <summary>
			/// The view is moving towards the South West (the bottom-left side of the screen).
			/// </summary>
			SouthWest = 6,
			/// <summary>
			/// The view is moving towards the West (the left side of the screen).
			/// </summary>
			West = 7,
			/// <summary>
			/// The view is moving towards the North West (the top-left side of the screen).
			/// </summary>
			NorthWest = 8
		};
	}
}