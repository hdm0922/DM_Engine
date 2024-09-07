#pragma once
#include <windows.h>
#include "DM_Enums.h"





namespace DM
{
	namespace Math
	{
		template <typename T>
		struct Vector2;

		class CollisionChecker;
		class PositionCalculator;
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





class DM::Math::PositionCalculator
{

public:

	// standard 직사각형과 target 직사각형이 특정 위치에서 겹치려 할 때의 targetPosition
	static Vector2<FLOAT> GetProperPosition(const Vector2<FLOAT>& position_standard, const Vector2<FLOAT>& size_standard, const Vector2<FLOAT>& size_target, Enums::FitMode fitMode);

	// size의 크기를 갖는 직사각형이 특정 위치에서 point와 겹치려 할 때의 targetPosition
	static Vector2<FLOAT> GetProperPosition(const Vector2<FLOAT>& point, const Vector2<FLOAT>& size, Enums::FitMode fitMode);

	// 직사각형에 대한 특정 점의 위치
	static Vector2<FLOAT> GetLocation(const Vector2<FLOAT>& position, const Vector2<FLOAT>& size, Enums::FitMode fitMode);


private:

	static Vector2<FLOAT> getProperPosition_TopLeft(const Vector2<FLOAT>& position_standard, const Vector2<FLOAT>& size_standard, const Vector2<FLOAT>& size_target);
	static Vector2<FLOAT> getProperPosition_BottomRight(const Vector2<FLOAT>& position_standard, const Vector2<FLOAT>& size_standard, const Vector2<FLOAT>& size_target);
	static Vector2<FLOAT> getProperPosition_BottomCenter(const Vector2<FLOAT>& position_standard, const Vector2<FLOAT>& size_standard, const Vector2<FLOAT>& size_target);

	static Vector2<FLOAT> getProperPosition_TopLeft(const Vector2<FLOAT>& point, const Vector2<FLOAT>& size);
	static Vector2<FLOAT> getProperPosition_BottomRight(const Vector2<FLOAT>& point, const Vector2<FLOAT>& size);
	static Vector2<FLOAT> getProperPosition_BottomCenter(const Vector2<FLOAT>& point, const Vector2<FLOAT>& size);

	static Vector2<FLOAT> getLocation_TopLeft(const Vector2<FLOAT>& position, const Vector2<FLOAT>& size);
	static Vector2<FLOAT> getLocation_BottomRight(const Vector2<FLOAT>& position, const Vector2<FLOAT>& size);
	static Vector2<FLOAT> getLocation_BottomCenter(const Vector2<FLOAT>& position, const Vector2<FLOAT>& size);

};





template<typename T>
inline DM::Math::Vector2<T> DM::Math::Vector2<T>::absoluteValue(Vector2<T> vector)
{
	return Vector2<T>(
		(vector.x > 0.0f) ? vector.x : -vector.x,
		(vector.y > 0.0f) ? vector.y : -vector.y
	);
}
