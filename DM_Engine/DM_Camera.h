#pragma once
#include "DM_GameObject.h"





namespace DM
{
    class Camera;
}





class DM::Camera :
    public GameObject
{

public:

    Camera(const std::wstring& name = L"");
    virtual ~Camera();

    virtual void Initialize();
    virtual void Update();

    Math::Vector2<FLOAT> GetPosition_Relative(Math::Vector2<FLOAT> position) { return position - this->GetTopLeft(); }


public:

    void SetRenderTarget(GameObject* target) { this->renderTarget = target; }


private:

    GameObject* renderTarget;


};

