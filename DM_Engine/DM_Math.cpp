#include "DM_Math.h"





BOOL DM::Math::CollisionChecker::Point_Box2D(
	Vector2<FLOAT> point,
	Vector2<FLOAT> boxTopLeft,
	Vector2<FLOAT> boxBottomRight)
{
	return (
		(boxTopLeft.x <= point.x) && (point.x <= boxBottomRight.x)
	&&	(boxTopLeft.y <= point.y) && (point.y <= boxBottomRight.y)
	);
}





BOOL DM::Math::CollisionChecker::Box2D_Box2D(
	Vector2<FLOAT> box1_TopLeft, 
	Vector2<FLOAT> box1_BottomRight, 
	Vector2<FLOAT> box2_TopLeft, 
	Vector2<FLOAT> box2_BottomRight)
{

	Vector2<FLOAT> center1 = (box1_TopLeft + box1_BottomRight) / 2.0f;
	Vector2<FLOAT> center2 = (box2_TopLeft + box2_BottomRight) / 2.0f;

	Vector2<FLOAT> size1 = box1_BottomRight - box1_TopLeft;
	Vector2<FLOAT> size2 = box2_BottomRight - box2_TopLeft;

	const Math::Vector2<FLOAT> CENTER_DIFF = Vector2<FLOAT>::absoluteValue(center1 - center2);

	bool collision_x = CENTER_DIFF.x < ((size1.x + size2.x) / 2.0f);
	bool collision_y = CENTER_DIFF.y < ((size1.y + size2.y) / 2.0f);

	return collision_x && collision_y;

}