#pragma once
#include "framework.h"





namespace DM
{
	template <typename T>
	class Container2D;
}





template <typename T>
class DM::Container2D
{

public:

	Container2D(const Math::Vector2<UINT>& size);
	~Container2D();

	void SetItem(const Math::Vector2<UINT>& index, T* item) { this->items[index.y][index.x] = item; }

	T* GetItem(UINT x, UINT y) const { return this->items[y][x]; }
	const Math::Vector2<UINT>& GetContainerSize() const { return this->size; }


private:

	T*** items;
	const Math::Vector2<UINT> size;


};





template<typename T>
inline DM::Container2D<T>::Container2D(const Math::Vector2<UINT>& size)
	: size(size)
{

	this->items = new T * *[size.y];

	for (UINT y = 0; y < size.y; y++)
	{
		this->items[y] = new T * [size.x];

		for (UINT x = 0; x < size.x; x++)
			this->items[y][x] = nullptr;
	}
}





template<typename T>
inline DM::Container2D<T>::~Container2D()
{

	for (UINT y = 0; y < this->size.y; y++)
	{
		delete[] this->items[y];
		this->items[y] = nullptr;
	}
		
	delete[] this->items;
	this->items = nullptr;
}
