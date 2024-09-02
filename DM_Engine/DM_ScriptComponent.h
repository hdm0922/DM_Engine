#pragma once
#include "DM_Component.h"





namespace DM
{
    class ScriptComponent;
}





class DM::ScriptComponent:
    public Component
{

public:

    ScriptComponent(const GameObject* owner, const std::wstring& name = L"", const UINT STATE_SIZE = 0);
    virtual ~ScriptComponent() override;

    virtual void Initialize() override;
    virtual void Update() override;

    virtual void CollisionEvent_Enter(const GameObject* other) {};
    virtual void CollisionEvent_Collide(const GameObject* other) {};
    virtual void CollisionEvent_Exit(const GameObject* other) {};

public:

    void SetCurrentState(UINT stateIdx) { this->currentStateIdx = stateIdx; }

    UINT GetCurrentState() const { return this->currentStateIdx; }


private:

    void checkStateChangeConditions();


protected:

    std::function<BOOL()>** stateChangeConditionMatrix;
    std::function<void()>* stateEnterEvent;


private:

    UINT currentStateIdx;
    UINT stateSize;

};

