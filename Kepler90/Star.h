#pragma once
#include "Structs.h"

class Star
{
public:
	Star(
		double radius // in Earths
	);

	void Tick(double time);
	void Draw();

	const double rotation_speed;
	const double radius;
	static const RGBColor color;
private:
	double rotation;
};

