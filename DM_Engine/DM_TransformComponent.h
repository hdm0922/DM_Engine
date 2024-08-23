#pragma once
#include "DM_Component.h"





namespace DM
{
    class TransformComponent;
    class GameObject;
}





class DM::TransformComponent :
    public Component
{

public:

    TransformComponent(const GameObject* owner, const std::wstring& name = L"");
    virtual ~TransformComponent() override;

    virtual void Initialize() override;
    virtual void Update() override;


public:

    void SetPosition(const Math::Vector2<FLOAT>& position) { this->position = position; }
    void SetScale(const Math::Vector2<FLOAT>& scale) { this->scale = scale; }
    void SetRotation(FLOAT rotation) { this->rotation = rotation; }

    Math::Vector2<FLOAT> GetPosition() const { return this->position; }
    Math::Vector2<FLOAT> GetScale() const { return this->scale; }
    FLOAT GetRotation() const { return this->rotation; }


private:

    Math::Vector2<FLOAT> position;
    Math::Vector2<FLOAT> scale;

    FLOAT rotation;


};