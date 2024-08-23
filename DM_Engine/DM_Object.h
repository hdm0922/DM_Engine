#pragma once
#include "framework.h"





namespace DM
{
	class Object;
}





class DM::Object abstract
{

public:

	Object() {};
	virtual ~Object() = 0;

	virtual void Initialize() = 0;
	virtual void Update() = 0;
	virtual void Render(HDC hdc) const = 0;
	virtual void Destroy() = 0;


protected:

	Object* owner;

};

