#pragma once

#include<GL/glut.h>

class Planet
{
public:
	Planet();
	~Planet();

	void Tick();
	void Draw();

//private:
#pragma region Properties
	float rotation_speed;
	float translation_speed;
	float planet_radius;
	float orbit_radius;
#pragma endregion

#pragma region State
	float posX;
	float posY;
	float rotation;
#pragma endregion

};

