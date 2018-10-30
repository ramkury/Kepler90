#pragma once

#include<GL/glut.h>

class Planet
{
public:
	Planet(
		double orbital_radius,	// in Astronomical Units (AU)
		double orbital_period,	// in days
		double planet_radius	// in Earths
	);

	void Tick(double time);
	void Draw();

private:
#pragma region Properties
	const double rotation_speed;
	const double orbital_speed;
	const double planet_radius;
	const double orbital_radius;
#pragma endregion

#pragma region State
	double orbit_position;
	double rotation;
#pragma endregion

	static double RADIUS_OFFSET; // This must not be const because it is modified by friend class Star
	static const double RADIUS_SCALE;
	static const double ORBITAL_RADIUS_SCALE;
	static const double ORBITAL_SPEED_SCALE;

	friend class Star;
};

