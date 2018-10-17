#pragma once

#include<GL/glut.h>

class Planet
{
public:
	Planet(double orbital_radius, double orbital_period, double planet_radius);

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

	static const double RADIUS_SCALE;
	static const double ORBITAL_RADIUS_SCALE;
	static const double ORBITAL_SPEED_SCALE;
};

