#pragma once

#include<GL/glut.h>
#include "Structs.h"

class Planet
{
public:
	Planet(
		double orbital_radius,	// in Astronomical Units (AU)
		double orbital_period,	// in days
		double planet_radius,	// in Earths
		double star_radius,		// in Earths
		RGBColor color
	);

	void Tick(double time);
	void Draw() const;
	Point3f GetPosition() const;

	const RGBColor color;
	static const double RADIUS_SCALE;
	static const double ORBITAL_RADIUS_SCALE;
	static const double ORBITAL_SPEED_SCALE;

#pragma region Properties
	const double rotation_speed;
	const double orbital_speed;
	const double planet_radius;
	const double orbital_radius;
#pragma endregion

private:

#pragma region State
	double orbit_position;
	double rotation;
#pragma endregion
};

