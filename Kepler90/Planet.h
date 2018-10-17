#pragma once

#include<GL/glut.h>

class Planet
{
public:
	Planet(float orbital_radius, float orbital_period, float planet_radius);
	~Planet();

	void Tick(double time);
	void Draw();

//private:
#pragma region Properties
	const float rotation_speed;
	const float orbital_speed;
	const float planet_radius;
	const float orbital_radius;
#pragma endregion

#pragma region State
	float orbit_position;
	float rotation;
#pragma endregion

};

