#include "Planet.h"



Planet::Planet()
{
}


Planet::~Planet()
{
}

void Planet::tick()
{
	rotation += rotation_speed;
	if (rotation >= 360)
	{
		rotation -= 360;
	}
}

void Planet::draw()
{
	glPushMatrix();
	glRotated(rotation, 0, 1, 0);
	glutWireSphere(planet_radius, 20, 20);
	glPopMatrix();
}