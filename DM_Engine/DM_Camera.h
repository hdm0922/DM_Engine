#pragma once
#include "DM_GameObject.h"

#include "DM_Application.h"
#include "DM_Window.h"





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
    //Math::Vector2<FLOAT> GetPosition_Relative(Math::Vector2<FLOAT> position) { return position; }


public:

    void SetRenderTarget(GameObject* target) { this->renderTarget = target; }

    virtual Math::Vector2<FLOAT> GetSize() const override;


private:

    GameObject* renderTarget;


};

