#pragma once

#include <GL/glut.h>

struct Point3f{
	GLfloat x, y, z;
	Point3f() = default;
	Point3f(GLfloat x, GLfloat y, GLfloat z) : x(x), y(y), z(z) {}
};