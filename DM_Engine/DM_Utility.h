#pragma once
#include <vector>
#include <string>





namespace DM
{
	namespace Utility
	{
		template <typename src, typename dest>
		dest ForcedBitConversion(src source) { return *(dest*)(&source); }

		std::vector<std::string> Split_String_With_WhiteSpace(const std::string& source);
	}
}