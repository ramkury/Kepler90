#include "Planet.h"



Planet::Planet(float orbital_radius, float orbital_period, float planet_radius) :
	rotation_speed(10),
	orbital_speed(1 / orbital_period),
	planet_radius(planet_radius),
	orbital_radius(orbital_radius),
	orbit_position(0),
	rotation(0)
{

}


Planet::~Planet()
{
}

void Planet::Tick(double time)
{
	rotation += rotation_speed * time;
	if (rotation >= 360)
	{
		rotation -= 360;
	}

	orbit_position += orbital_speed * time;
	if (orbit_position >= 360)
	{
		orbit_position -= 360;
	}
}

void Planet::Draw()
{
	glPushMatrix();
	glRotatef(-orbit_position, 0, 1, 0);
	glTranslatef(orbital_radius, 0, 0);
	glRotatef(rotation, 0, 1, 0);
	glutWireSphere(planet_radius, 20, 20);
	glPopMatrix();
}
