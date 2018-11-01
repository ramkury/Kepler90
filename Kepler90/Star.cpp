#include "Star.h"
#include "Planet.h"

const RGBColor Star::color(255, 169, 64);

Star::Star(double radius) : 
	radius(Planet::RADIUS_SCALE * radius),
	rotation_speed(10)
{
}

void Star::Tick(double time)
{
	rotation += rotation_speed * time;
}

void Star::Draw()
{
	glPushMatrix();
	color.set();
	glRotated(rotation, 0, 1, 0);
	glutWireSphere(radius, 20, 20);
	glPopMatrix();
}
