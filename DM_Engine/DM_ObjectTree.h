//#pragma once
//#include "framework.h"
//
//
//
//
//
//namespace DM
//{
//	template <typename T>
//	class ObjectTree;
//}
//
//
//
//
//template <typename T>
//class DM::ObjectTree
//{
//
//public:
//
//	ObjectTree();
//	virtual ~ObjectTree();
//
//	void Hide();
//	void Show();
//
//	template <typename T2>
//	T2* Create();
//
//
//public:
//
//	virtual void SetParent(T* node) { this->parentNode = node; }
//	void SetHidden(BOOL hidden) { this->hidden = true; }
//
//	T* GetParent() const { return this->parentNode; }
//	BOOL GetHidden() const { return this->hidden; }
//
//private:
//
//	T* parentNode;
//	std::vector<T*> subNodes;
//	BOOL hidden;
//
//};
//
//
//
//
//
//template<typename T>
//inline DM::ObjectTree<T>::ObjectTree()
//	: parentNode(nullptr)
//	, subNodes({})
//	, hidden(false)
//{
//}
//
//
//
//
//
//template<typename T>
//inline DM::ObjectTree<T>::~ObjectTree()
//{
//	for (T* subNode : this->subNodes)
//	{
//		delete subNode;
//		subNode = nullptr;
//	}
//}
//
//
//
//
//
//template<typename T>
//inline void DM::ObjectTree<T>::Initialize()
//{
//	for (T* subNode : this->subNodes)
//	{
//		subNode->Initialize();
//	}
//}
//
//
//
//
//
//template<typename T>
//inline void DM::ObjectTree<T>::Update()
//{
//	for (T* subNode : this->subNodes)
//	{
//		subNode->Update();
//	}
//}
//
//
//
//
//
//template<typename T>
//inline void DM::ObjectTree<T>::Render(HDC hdc) const
//{
//	for (T* subNode : this->subNodes)
//	{
//		subNode->Render(hdc);
//	}
//}
//
//
//
//
//
//template<typename T>
//inline void DM::ObjectTree<T>::Destroy()
//{
//	for (T* subNode : this->subNodes)
//	{
//		subNode->Destroy();
//	}
//}
//
//
//
//
//
//template<typename T>
//inline void DM::ObjectTree<T>::Hide()
//{
//		
//	for (T* subNode : this->subNodes)
//	{
//		subNode->ObjectTree<T>::SetHidden(true);
//	}
//
//	this->SetHidden(true);
//}
//
//
//
//
//
//template<typename T>
//inline void DM::ObjectTree<T>::Show()
//{
//	this->SetHidden(false);
//}
//
//
//
//
//
//template<typename T> template <typename T2>
//inline T2* DM::ObjectTree<T>::Create()
//{
//	T2* subNode = new T2();
//	assert(static_cast<T*>(subNode)); // DEBUG
//
//	this->subNodes.push_back(static_cast<T*>(subNode));
//
//	return subNode;
//}