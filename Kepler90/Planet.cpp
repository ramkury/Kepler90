#include "Planet.h"
#include "Structs.h"
#include <cmath>

#define DEG2RAD(deg) ((deg) * 0.01745)

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
	glRotated(orbit_position, 0, 1, 0);
	glTranslated(orbital_radius, 0, 0);
	glRotated(rotation, 0, 1, 0);
	glutSolidSphere(planet_radius, 50, 50);
	glPopMatrix();
}

Point3f Planet::GetPosition() const
{
	Point3f position;
	double angle_rads = DEG2RAD(orbit_position);
	position.x = (GLfloat) (cos(angle_rads) * orbital_radius);
	position.y = 0;
	position.z = (GLfloat) (sin(angle_rads) * -orbital_radius);
	return position;
}
