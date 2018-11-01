#pragma once

#include <GL/glut.h>

struct Point3f
{
	GLfloat x, y, z;
	Point3f() = default;
	Point3f(GLfloat x, GLfloat y, GLfloat z) : x(x), y(y), z(z) {}
};

struct RGBColor
{
	GLubyte r, g, b;
	RGBColor() = default;
	RGBColor(GLubyte r, GLubyte g, GLubyte b) : r(r), g(g), b(b) {}
	void set() const {
		glColor3ub(r, g, b);
	}
};
