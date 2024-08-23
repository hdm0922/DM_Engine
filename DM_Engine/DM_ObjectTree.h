#pragma once
#include "framework.h"





namespace DM
{
	template <typename T>
	class ObjectTree;
}




template <typename T>
class DM::ObjectTree
{

public:

	ObjectTree();
	virtual ~ObjectTree();

	virtual void Initialize();
	virtual void Update();
	virtual void Render(HDC hdc) const;
	virtual void Destroy();

	template <typename T2>
	void Create();


public:

	void SetParent(T* node) { this->parentNode = node; }

	T* GetParent() const { return this->parentNode; }


private:

	T* parentNode;
	std::vector<T*> subNodes;


};





template<typename T>
inline DM::ObjectTree<T>::ObjectTree()
	: parentNode(nullptr)
	, subNodes({})
{
}





template<typename T>
inline DM::ObjectTree<T>::~ObjectTree()
{
	for (T* subNode : this->subNodes)
	{
		delete subNode;
		subNode = nullptr;
	}
}





template<typename T>
inline void DM::ObjectTree<T>::Initialize()
{
	for (T* subNode : this->subNodes)
	{
		subNode->Initialize();
	}
}





template<typename T>
inline void DM::ObjectTree<T>::Update()
{
	for (T* subNode : this->subNodes)
	{
		subNode->Update();
	}
}





template<typename T>
inline void DM::ObjectTree<T>::Render(HDC hdc) const
{
	for (T* subNode : this->subNodes)
	{
		subNode->Render(hdc);
	}
}





template<typename T>
inline void DM::ObjectTree<T>::Destroy()
{
	for (T* subNode : this->subNodes)
	{
		subNode->Destroy();
	}
}





template<typename T> template <typename T2>
inline void DM::ObjectTree<T>::Create()
{
	T* subNode = dynamic_cast<T>(new T2());
	assert(subNode); // DEBUG

	subNode->SetParent(this);
	this->subNodes.push_back(subNode);

	return;
}