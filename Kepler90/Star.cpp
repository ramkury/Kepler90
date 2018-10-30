#include "Star.h"
#include "Planet.h"

Star::Star(double radius) : 
	star_radius(Planet::RADIUS_SCALE * radius),
	rotation_speed(10)
{
	// 1 Earth's equatorial radius = 4.26354E-5 AU, UA
	// 1 AU, UA = 23454.706481336 Earth's equatorial radius
	Planet::RADIUS_OFFSET = star_radius * (Planet::ORBITAL_RADIUS_SCALE, Planet::RADIUS_SCALE);
}

void Star::Tick(double time)
{
	rotation += rotation_speed * time;
}

void Star::Draw()
{
	glPushMatrix();
	glRotated(rotation, 0, 1, 0);
	glutWireSphere(star_radius, 20, 20);
	glPopMatrix();
}
