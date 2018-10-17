#pragma once

#include <GL/glut.h>
#include "Structs.h"

class Camera
{
public:
	virtual void Tick() = 0;
	virtual void UpdateViewParameters() = 0;
	virtual void OnWindowSizeChanged(GLsizei width, GLsizei height);
	virtual void OnMouseClick(int button, int state, int x, int y);
	virtual void KeyboardSpecial(int key, int x, int y);
	Camera* operator=(Camera* cam);
protected:
	Point3f pos;
	Point3f up;
	Point3f direction;
	static GLfloat fAspect;
};

class PerspectiveCamera : public Camera
{
public:
	PerspectiveCamera();
	void Tick();
	void UpdateViewParameters();
	void OnMouseClick(int button, int state, int x, int y);
	void KeyboardSpecial(int key, int x, int y);
protected:
	float angle;
};