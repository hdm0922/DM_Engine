#pragma once
#include <windows.h>





namespace DM
{
	namespace Math
	{
		template <typename T>
		struct Vector2;

		class CollisionChecker;
	}
}





template <typename T>
struct DM::Math::Vector2
{

	Vector2() : x(T()), y(T()) {}
	Vector2(T _x) : Vector2(_x, _x) {}
	Vector2(T _x, T _y) : x(_x), y(_y) {}

	Vector2<T> operator+(const Vector2<T>& other)	const { return { this->x + other.x, this->y + other.y }; }
	Vector2<T> operator-(const Vector2<T>& other)	const { return { this->x - other.x, this->y - other.y }; }
	T operator*(const Vector2<T>& other)			const { return (this->x * other.x) + (this->y * other.y); }
	Vector2<T> operator*(const T& scalar)			const { return { this->x * scalar, this->y * scalar }; }
	Vector2<T> operator/(const T& scalar)			const { return { this->x / scalar, this->y / scalar }; }

	Vector2<T>& operator+=(const Vector2<T>& other)	{ this->x += other.x; this->y += other.y; return *this; }
	Vector2<T>& operator-=(const Vector2<T>& other)	{ this->x -= other.x; this->y -= other.y; return *this; }
	Vector2<T>& operator*=(const T& scalar)			{ this->x *= scalar; this->y *= scalar; return *this; }
	Vector2<T>& operator/=(const T& scalar)			{ this->x /= scalar; this->y /= scalar; return *this; }

	Vector2<T>& operator=(const Vector2<T>& other)	{ this->x = other.x; this->y = other.y; return *this; }
	BOOL operator==(const Vector2<T>& other)		{ return (this->x == other.x) && (this->y == other.y); }

	T x;
	T y;

};





class DM::Math::CollisionChecker
{

public:

	static BOOL Point_Box_2D(Vector2<FLOAT> point, Vector2<FLOAT> boxTopLeft, Vector2<FLOAT> boxBottomRight);
};