#pragma once
#include "framework.h"



namespace DM
{
	class Entity;
}



class DM::Entity
{

public:

	Entity(const std::wstring& name = L"") : name(name) {};
	virtual ~Entity() {};

public:

		const std::wstring& GetName() const { return this->name; }


private:

	const std::wstring name;

};