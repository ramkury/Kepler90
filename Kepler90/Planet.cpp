#include "Planet.h"
#include "Structs.h"

const double Planet::RADIUS_SCALE = 1.5;
const double Planet::ORBITAL_RADIUS_SCALE = 300.0;
const double Planet::ORBITAL_SPEED_SCALE = 1100.0;


Planet::Planet(double orbital_radius, double orbital_period, double planet_radius, double star_radius, RGBColor color) :
	rotation_speed(10),
	orbital_speed(ORBITAL_SPEED_SCALE / orbital_period),
	planet_radius(RADIUS_SCALE * planet_radius),
	orbital_radius((ORBITAL_RADIUS_SCALE * orbital_radius) + (RADIUS_SCALE * star_radius)),
	color(color),
	orbit_position(0),
	rotation(0)
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
	color.set();
	glPushMatrix();
	glRotated(-orbit_position, 0, 1, 0);
	glTranslated(orbital_radius, 0, 0);
	glRotated(rotation, 0, 1, 0);
	glutWireSphere(planet_radius, 20, 20);
	glPopMatrix();
}
