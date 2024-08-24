#include "DM_Resource.h"





DM::Resource::Resource(const std::wstring& path, const std::wstring& name)
	: Entity(name)
	, path(path)
{
}





DM::Resource::~Resource()
{
}
