#pragma once

#include<GL/glut.h>

class Planet
{
public:
	Planet();
	~Planet();

	void tick();
	void draw();

//private:
#pragma region Properties
	double rotation_speed;
	double translation_speed;
	double planet_radius;
	double orbit_radius;
#pragma endregion

#pragma region State
	double posX;
	double posY;
	double rotation;
#pragma endregion

};

