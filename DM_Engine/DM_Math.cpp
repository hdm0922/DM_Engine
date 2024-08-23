#include "DM_Math.h"





BOOL DM::Math::CollisionChecker::Point_Box_2D(
	Vector2<FLOAT> point,
	Vector2<FLOAT> boxTopLeft,
	Vector2<FLOAT> boxSize)
{
	Vector2<FLOAT> boxBottomRight = boxTopLeft + boxSize;

	return (
		(boxTopLeft.x <= point.x) && (point.x <= boxBottomRight.x) &&
		(boxTopLeft.y <= point.y) && (point.y <= boxBottomRight.y)
	);
}
