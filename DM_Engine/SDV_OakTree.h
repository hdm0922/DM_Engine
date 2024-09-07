#pragma once
#include "SDV_Tree.h"





namespace SDV
{
    class OakTree;
}





class SDV::OakTree :
    public Tree
{

public:

    OakTree(const std::wstring& name = L"");
    virtual ~OakTree() override;


};