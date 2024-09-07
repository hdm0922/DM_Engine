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





DM::Math::Vector2<FLOAT> DM::Math::PositionCalculator::GetProperPosition(
	const Vector2<FLOAT>& position_standard,
	const Vector2<FLOAT>& size_standard,
	const Vector2<FLOAT>& size_target,
	Enums::FitMode fitMode)
{

	switch (fitMode)
	{
	case Enums::FitMode::Center:		return position_standard;
	case Enums::FitMode::TopLeft:		return PositionCalculator::getProperPosition_TopLeft(position_standard, size_standard, size_target);
	case Enums::FitMode::BottomRight:	return PositionCalculator::getProperPosition_BottomRight(position_standard, size_standard, size_target);
	case Enums::FitMode::BottomCenter:	return PositionCalculator::getProperPosition_BottomCenter(position_standard, size_standard, size_target);
	}

	return Vector2<FLOAT>();
}





DM::Math::Vector2<FLOAT> DM::Math::PositionCalculator::GetProperPosition(const Vector2<FLOAT>& point, const Vector2<FLOAT>& size, Enums::FitMode fitMode)
{
	switch (fitMode)
	{
	case Enums::FitMode::Center:		return point;
	case Enums::FitMode::TopLeft:		return PositionCalculator::getProperPosition_TopLeft(point, size);
	case Enums::FitMode::BottomRight:	return PositionCalculator::getProperPosition_BottomRight(point, size);
	case Enums::FitMode::BottomCenter:	return PositionCalculator::getProperPosition_BottomCenter(point, size);
	}

	return Vector2<FLOAT>();
}





DM::Math::Vector2<FLOAT> DM::Math::PositionCalculator::GetLocation(const Vector2<FLOAT>& position, const Vector2<FLOAT>& size, Enums::FitMode fitMode)
{

	switch (fitMode)
	{
	case Enums::FitMode::Center:		return position;
	case Enums::FitMode::TopLeft:		return PositionCalculator::getLocation_TopLeft(position, size);
	case Enums::FitMode::BottomRight:	return PositionCalculator::getLocation_BottomRight(position, size);
	case Enums::FitMode::BottomCenter:	return PositionCalculator::getLocation_BottomCenter(position, size);
	}

	return Vector2<FLOAT>();
}





DM::Math::Vector2<FLOAT> DM::Math::PositionCalculator::getProperPosition_TopLeft(const Vector2<FLOAT>& position_standard, const Vector2<FLOAT>& size_standard, const Vector2<FLOAT>& size_target)
{
	return position_standard - (size_standard / 2.0f) + (size_target / 2.0f);
}





DM::Math::Vector2<FLOAT> DM::Math::PositionCalculator::getProperPosition_BottomRight(const Vector2<FLOAT>& position_standard, const Vector2<FLOAT>& size_standard, const Vector2<FLOAT>& size_target)
{
	return position_standard + (size_standard / 2.0f) - (size_target / 2.0f);
}





DM::Math::Vector2<FLOAT> DM::Math::PositionCalculator::getProperPosition_BottomCenter(const Vector2<FLOAT>& position_standard, const Vector2<FLOAT>& size_standard, const Vector2<FLOAT>& size_target)
{
	return position_standard + Vector2<FLOAT>(0, 0.5f * size_standard.y) - Vector2<FLOAT>(0, 0.5f * size_target.y);
}





DM::Math::Vector2<FLOAT> DM::Math::PositionCalculator::getProperPosition_TopLeft(const Vector2<FLOAT>& point, const Vector2<FLOAT>& size)
{
	return point + (size / 2.0f);
}





DM::Math::Vector2<FLOAT> DM::Math::PositionCalculator::getProperPosition_BottomRight(const Vector2<FLOAT>& point, const Vector2<FLOAT>& size)
{
	return point + size;
}





DM::Math::Vector2<FLOAT> DM::Math::PositionCalculator::getProperPosition_BottomCenter(const Vector2<FLOAT>& point, const Vector2<FLOAT>& size)
{
	return point + DM::Math::Vector2<FLOAT>(0, 0.5f * size.y);
}





DM::Math::Vector2<FLOAT> DM::Math::PositionCalculator::getLocation_TopLeft(const Vector2<FLOAT>& position, const Vector2<FLOAT>& size)
{
	return position - (size / 2.0f);
}





DM::Math::Vector2<FLOAT> DM::Math::PositionCalculator::getLocation_BottomRight(const Vector2<FLOAT>& position, const Vector2<FLOAT>& size)
{
	return position + (size / 2.0f);
}





DM::Math::Vector2<FLOAT> DM::Math::PositionCalculator::getLocation_BottomCenter(const Vector2<FLOAT>& position, const Vector2<FLOAT>& size)
{
	return position + Vector2<FLOAT>(0, 0.5f * size.y);
}
