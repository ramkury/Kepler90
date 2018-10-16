#include "Camera.h"

GLfloat Camera::fAspect;

void Camera::OnWindowSizeChanged(GLsizei width, GLsizei height)
{
	if (height == 0) return;

	glViewport(0, 0, width, height);
	fAspect = width / (float)height;

	this->UpdateViewParameters();
}

void Camera::OnMouseClick(int button, int state, int x, int y)
{
}

void Camera::KeyboardSpecial(int key, int x, int y)
{
}

PerspectiveCamera::PerspectiveCamera()
{
	pos.x = 0;
	pos.y = 80;
	pos.z = 200;

	up.x = 0;
	up.y = 1;
	up.z = 0;

	direction.x = 0;
	direction.y = 0;
	direction.z = 0;

	angle = 45;
}

void PerspectiveCamera::Tick()
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(pos.x, pos.y, pos.z, direction.x, direction.y, direction.z, up.x, up.y, up.z);
}

void PerspectiveCamera::UpdateViewParameters()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(angle, fAspect, 0.5, 500);
}

void PerspectiveCamera::OnMouseClick(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON)
		if (state == GLUT_DOWN) {  // Zoom-in
			if (angle >= 10) angle -= 5;
		}
	if (button == GLUT_RIGHT_BUTTON)
		if (state == GLUT_DOWN) {  // Zoom-out
			if (angle <= 130) angle += 5;
		}
	UpdateViewParameters();
}

void PerspectiveCamera::KeyboardSpecial(int key, int x, int y)
{
	switch (key) {
	case GLUT_KEY_LEFT:
		pos.x -= 10;
		break;
	case GLUT_KEY_RIGHT:
		pos.x += 10;
		break;
	case GLUT_KEY_UP:
		pos.y += 10;
		break;
	case GLUT_KEY_DOWN:
		pos.y -= 10;
		break;
	case GLUT_KEY_HOME:
		pos.z += 10;
		break;
	case GLUT_KEY_END:
		pos.z -= 10;
		break;
	}
	Tick();
}

Camera * Camera::operator=(Camera * cam)
{
	cam->UpdateViewParameters();
	return cam;
}

