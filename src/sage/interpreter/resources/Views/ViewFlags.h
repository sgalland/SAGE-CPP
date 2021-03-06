#pragma once

namespace sage
{
	namespace agi
	{
		enum class ViewFlags : int
		{
			// 0  ??
			// 1  0 = observe blocks, 1 = ignore blocks
			IgnoreBlocks = 0x1,
			// 2  0 = priority released, 1 = fixed priority
			FixedPriority = 0x2,
			// 3  0 = observe horizon, 1 = ignore horizon
			IgnoreHorizon = 0x4,
			// 4  ??
			// 5  0 = stop cycling, 1 = cycling.
			Cycling = 0x20,
			// 6  ??
			// 7  ??
			// 8  1 = view on water
			OnWater = 0x100,
			// 9  0 = observe objects, 1 = ignore objects
			IgnoreObjects = 9,
			//10  ??
			Update = 0x10,
			//11  1 = view on land
			OnLand = 64,
			//12  ??
			//13  0 = loop released, 1 = loop fixed
			LoopFixed = 128,
			Animated = 256,
			Updating = 512,
			//14  ??
			//15  ??
			//27  ?? (storage for some view related command parameters)
			//28  ?? (storage for some view related command parameters)
			//29  ?? (storage for some view related command parameters)
			//2A  ?? (storage for some view related command parameters)

			ReverseCycling = 1024,
		};

		inline ViewFlags operator |(ViewFlags l, ViewFlags r)
		{
			return static_cast<ViewFlags>(static_cast<int>(l) | static_cast<int>(r));
		}

		inline ViewFlags operator &(ViewFlags l, ViewFlags r)
		{
			return static_cast<ViewFlags>(static_cast<int>(l) & static_cast<int>(r));
		}

		inline ViewFlags operator ~(ViewFlags l)
		{
			return static_cast<ViewFlags>(~l);
		}

		inline ViewFlags operator ^(ViewFlags l, ViewFlags r)
		{
			return static_cast<ViewFlags>(static_cast<int>(l) ^ static_cast<int>(r));
		}

		inline ViewFlags& operator |=(ViewFlags& l, ViewFlags r)
		{
			return l = static_cast<ViewFlags>(static_cast<int>(l) | static_cast<int>(r));
		}

		inline ViewFlags& operator &=(ViewFlags& l, ViewFlags r)
		{
			return l = static_cast<ViewFlags>(static_cast<int>(l) & static_cast<int>(r));
		}

		inline ViewFlags& operator ^=(ViewFlags& l, ViewFlags r)
		{
			return l = static_cast<ViewFlags>(static_cast<int>(l) ^ static_cast<int>(r));
		}
	}
}