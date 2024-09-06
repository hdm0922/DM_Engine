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

	template <typename U>
	Vector2(Vector2<U> v) : Vector2(static_cast<T>(v.x), static_cast<T>(v.y)) {}

	static Vector2<T> absoluteValue(Vector2<T> vector);
	
	Vector2<T> operator+(const Vector2<T>& other)	const { return { this->x + other.x, this->y + other.y }; }
	Vector2<T> operator-(const Vector2<T>& other)	const { return { this->x - other.x, this->y - other.y }; }
	Vector2<T> operator-()							const { return { -this->x, -this->y }; }
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

	static BOOL Point_Box2D(Vector2<FLOAT> point, Vector2<FLOAT> boxTopLeft, Vector2<FLOAT> boxBottomRight);
	static BOOL Box2D_Box2D(
		Vector2<FLOAT> box1_TopLeft, Vector2<FLOAT> box1_BottomRight,
		Vector2<FLOAT> box2_TopLeft, Vector2<FLOAT> box2_BottomRight);
};





template<typename T>
inline DM::Math::Vector2<T> DM::Math::Vector2<T>::absoluteValue(Vector2<T> vector)
{
	return Vector2<T>(
		(vector.x > 0.0f) ? vector.x : -vector.x,
		(vector.y > 0.0f) ? vector.y : -vector.y
	);
}
