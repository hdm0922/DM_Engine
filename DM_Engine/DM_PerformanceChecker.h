#pragma once
#include "framework.h"
#include "DM_Entity.h"





namespace DM
{
	class PerformanceChecker;
}





class DM::PerformanceChecker
{

public:

	struct Function
	{

		Function(Entity* obj, void* address) : object(obj), memberFunctionAddress(address) {}

		BOOL operator<(const Function& other) const
		{
			return (this->object == other.object) ?
				((INT64)(this->memberFunctionAddress) < (INT64)(other.memberFunctionAddress)) :
				((INT64)(this->object) < (INT64)(other.object));
		}

		Entity* object;
		void* memberFunctionAddress;
	};


public:

	static void Start() { QueryPerformanceCounter(&PerformanceChecker::frequency_start); }
	static void End()	{ QueryPerformanceCounter(&PerformanceChecker::frequency_end); }

	static void Record(const Function& functionInfo);

	static const std::map<Function, FLOAT>& GetOccupancyRatio() { return PerformanceChecker::occupancyRatio; }
	static FLOAT GetTotalTimeRatio();

private:

	static LARGE_INTEGER frequency_start;
	static LARGE_INTEGER frequency_end;

	static std::map<Function, FLOAT> occupancyRatio;
};