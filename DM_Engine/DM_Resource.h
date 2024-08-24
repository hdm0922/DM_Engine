#pragma once
#include "DM_Entity.h"





namespace DM
{
    class Resource;
}





class DM::Resource abstract :
    public Entity
{

public:

    Resource(const std::wstring& path, const std::wstring& name = L"");
    virtual ~Resource();

    virtual void Load() = 0;


public:

    const std::wstring& GetPath() const { return this->path; }


private:

    const std::wstring& path;
};

