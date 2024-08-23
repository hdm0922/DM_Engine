#include "DM_RandomGenerator.h"





namespace DM
{
	thread_local std::mt19937 RandomGenerator::engine = std::mt19937();
}





void DM::RandomGenerator::Initialize()
{
	RandomGenerator::engine = std::mt19937((UINT)time(NULL));


}