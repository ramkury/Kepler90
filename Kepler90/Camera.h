#pragma once

#include <GL/glut.h>
#include "Structs.h"
#include "Planet.h"

class Camera
{
public:
	virtual void UpdateViewParameters() = 0;
	virtual void OnMouseEvent(int button, int state, int x, int y) = 0;
	virtual void KeyboardSpecial(int key, int x, int y) = 0;
	virtual void Enable() = 0;
	virtual void Keyboard(unsigned char key, int x, int y);
	virtual void OnWindowSizeChanged(GLsizei width, GLsizei height);
protected:
	static GLfloat fAspect;
};

class PerspectiveCamera : public Camera
{
public:
	PerspectiveCamera();
	void UpdateViewParameters() override;
	void OnMouseEvent(int button, int state, int x, int y) override;
	void KeyboardSpecial(int key, int x, int y) override;
	void Enable() override;
protected:
	Point3f pos;
};

class PlanetCamera : public Camera
{
public:
	PlanetCamera(const Planet& planet);
	void UpdateViewParameters() override;
	void OnMouseEvent(int button, int state, int x, int y) override;
	void KeyboardSpecial(int key, int x, int y) override;
	void Enable() override;
protected:
	const Planet& planet;
};
