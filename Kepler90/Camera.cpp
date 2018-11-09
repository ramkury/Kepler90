#include "Camera.h"
#include <cstdio>
#include <cctype>

GLfloat Camera::fAspect;

void Camera::Keyboard(unsigned char key, int x, int y)
{
}

void Camera::OnWindowSizeChanged(GLsizei width, GLsizei height)
{
	if (height == 0) return;

	glViewport(0, 0, width, height);
	fAspect = width / (float)height;
}

PerspectiveCamera::PerspectiveCamera()
{
	pos.x = 0;
	pos.y = 300;
	pos.z = 500;
}

void PerspectiveCamera::UpdateViewParameters()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(55, fAspect, 100, 1300);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(pos.x, pos.y, pos.z, 0, 0, 0, 0, 1, 0);
}

void PerspectiveCamera::OnMouseEvent(int button, int state, int x, int y)
{
}

void PerspectiveCamera::KeyboardSpecial(int key, int x, int y)
{
	float step = 10;
	switch (key)
	{
	case GLUT_KEY_UP: // Moves closer to the sun on Z axis
		STEP_DOWN(pos.z, step, step);
		break;
	case GLUT_KEY_DOWN: // Moves away from the sun on Z axis
		STEP_UP(pos.z, step, 750);
		break;
	case GLUT_KEY_RIGHT: // Moves up on Y axis
		STEP_UP(pos.y, step, 500);
		break;
	case GLUT_KEY_LEFT: // Moves down on Y axis
		STEP_DOWN(pos.y, step, 0);
		break;
	default:
		break;
	}

	printf("Camera position: x = %.2f, y = %.2f, z = %.2f\n", pos.x, pos.y, pos.z);
}

void PerspectiveCamera::Enable()
{
	printf("Perspective camera enabled!\n");
}

PlanetCamera::PlanetCamera(const Planet & planet) : planet(planet)
{
}

void PlanetCamera::UpdateViewParameters()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(55, fAspect, 0.1, 1300);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	Point3f pos = planet.GetPosition();
	gluLookAt(pos.x, pos.y + planet.planet_radius + 1, pos.z, 0, 0, 0, 0, 1, 0);
}

void PlanetCamera::OnMouseEvent(int button, int state, int x, int y)
{
}

void PlanetCamera::KeyboardSpecial(int key, int x, int y)
{
}

void PlanetCamera::Enable()
{
	printf("Planet camera enabled!\n");
}

FreeCamera::FreeCamera(Point3f starting_position, Point3f starting_direction) :
	starting_position(starting_position), starting_direction(starting_direction),
	position(starting_position), direction(starting_direction)
{
	
}

void FreeCamera::UpdateViewParameters()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(55, fAspect, 100, 1300);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(position.x, position.y, position.z, direction.x, direction.y, direction.z, 0, 1, 0);
}

void FreeCamera::OnMouseEvent(int button, int state, int x, int y)
{
}

void FreeCamera::KeyboardSpecial(int key, int x, int y)
{
	const float horizontal_step = 5;
	const float vertical_step = 5;
	switch (key)
	{
	case GLUT_KEY_UP:
		STEP_UP(direction.z, vertical_step, 20);
		break;
	case GLUT_KEY_DOWN:
		STEP_DOWN(direction.z, vertical_step, -20);
		break;
	case GLUT_KEY_LEFT:
		STEP_DOWN(direction.x, horizontal_step, -1000);
		break;
	case GLUT_KEY_RIGHT:
		STEP_UP(direction.x, horizontal_step, 1000);
		break;
	default:
		break;
	}
}

void FreeCamera::Keyboard(unsigned char key, int x, int y)
{
	const float step = 5;
	switch (toupper(key))
	{
	case 'W':
		STEP_DOWN(position.y, step, 50);
		break;
	case 'S':
		STEP_UP(position.y, step, 1000);
		break;
	case 'A':
		STEP_DOWN(position.x, step, -1000);
		break;
	case 'D':
		STEP_UP(position.x, step, 1000);
		break;
	case 'E':
		STEP_UP(position.z, step, 300);
		break;
	case 'Q':
		STEP_DOWN(position.z, step, -300);
		break;
	default:
		break;
	}
}

void FreeCamera::Enable()
{
	printf("Free camera enabled!\n");
}
