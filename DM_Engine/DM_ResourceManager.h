#pragma once
#include "framework.h"

#include "DM_Resource.h"





namespace DM
{
	class ResourceManager;
}





class DM::ResourceManager
{

public:

	template <typename T>
	static T* GetResource(const std::wstring& name);

	template <typename T>
	static void LoadResource(const std::wstring& name, const std::wstring& path);


private:

	static std::map<const std::wstring&, Resource*> resources;


};





template<typename T>
inline T* DM::ResourceManager::GetResource(const std::wstring& name)
{

	auto iter = ResourceManager::resources.find(name);

	return (iter == ResourceManager::resources.end()) ? nullptr : iter->second;
}





template<typename T>
inline void DM::ResourceManager::LoadResource(const std::wstring& name, const std::wstring& path)
{

	Resource* resource = ResourceManager::GetResource<T>(name);
	if (resource) return;

	resource = new T(path, name);
	resource->Load();

	ResourceManager::resources.insert({ name, resource });

	return;
}
