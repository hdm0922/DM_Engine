#pragma once





namespace DM
{
	namespace Utility
	{
		template <typename src, typename dest>
		dest ForcedBitConversion(src source) { return *(dest*)(&source); }

	}
}