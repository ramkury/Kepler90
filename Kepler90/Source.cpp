#define DOUBLE_BUFFERED

#include <GL/glut.h>
#include <vector>
#include <array>
#include "Planet.h"
#include "Star.h"
#include "Camera.h"
#include "Timer.h"

GLfloat angle, fAspect;
GLdouble obsX=0, obsY=0, obsZ=200;

std::array<Camera*, 2> cameras;
Camera* activeCamera;
Timer timer(1);

Star star(30);
std::vector<Planet> Planets;

void fillPlanets()
{	
	Planets.reserve(8); // 8 planets
	Planets.emplace_back(0.074,   7.0,  1.31, star.radius, RGBColor(255, 255, 255));	// Kepler 90b
	Planets.emplace_back(0.089,   8.7,  1.19, star.radius, RGBColor(255, 255, 255));	// Kepler 90c
	Planets.emplace_back(0.150,  14.4,  1.32, star.radius, RGBColor(255, 255, 255));	// Kepler 90i (RADIUS UNDEFINED!!!!)
	Planets.emplace_back(0.320,  59.7,  2.81, star.radius, RGBColor(255, 255, 255));	// Kepler 90d
	Planets.emplace_back(0.420,  91.9,  2.60, star.radius, RGBColor(255, 255, 255));	// Kepler 90e
	Planets.emplace_back(0.480, 124.9,  2.82, star.radius, RGBColor(255, 255, 255));	// Kepler 90f
	Planets.emplace_back(0.710, 210.6,  7.93, star.radius, RGBColor(255, 255, 255));	// Kepler 90g
	Planets.emplace_back(1.010, 331.6, 11.06, star.radius, RGBColor(255, 255, 255));	// Kepler 90h
}

void draw(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	activeCamera->UpdateViewParameters();
	star.Draw();
	for (auto& planet : Planets)
	{
		planet.Draw();
	}

#ifdef DOUBLE_BUFFERED
	glutSwapBuffers();
#else
	glFlush();
#endif // DOUBLE_BUFFERED

}

// Initialize rendering parameters
void setup(void)
{
	glEnable(GL_DEPTH_TEST);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	fillPlanets();
	//activeCamera = new PerspectiveCamera();
	cameras[0] = new PerspectiveCamera();
	cameras[1] = new PlanetCamera(Planets.at(7));
	activeCamera = cameras[0];
	activeCamera->Enable();
}

// Função callback chamada quando o tamanho da janela é alterado 
void OnWindowSizeChanged(GLsizei w, GLsizei h)
{
	activeCamera->OnWindowSizeChanged(w, h);
}

// Função callback chamada para gerenciar eventos do mouse
void MouseEvent(int button, int state, int x, int y)
{
	activeCamera->OnMouseEvent(button, state, x, y);
}

// Callback para gerenciar eventos do teclado para teclas especiais (F1, PgDn, entre outras)
void SpecialKeys(int key, int x, int y)
{
	activeCamera->KeyboardSpecial(key, x, y);
}

void KeyboardFunc(unsigned char key, int x, int y)
{
	if (key == '1')
	{
		activeCamera = cameras[0];
	}
	else if (key == '2')
	{
		activeCamera = cameras[1];
	}
	else
	{
		return;
	}
	activeCamera->Enable();
}

void idle()
{
	double time = timer.Tick();
	if (time > 0)
	{
		star.Tick(time);
		for (auto& planet : Planets)
		{
			planet.Tick(time);
		}
		glutPostRedisplay();
	}
}

// Programa Principal
int main(int argc, char** argv)
{
	glutInit(&argc, argv);

#ifdef DOUBLE_BUFFERED
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
#else
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
#endif // DOUBLE_BUFFERED

	glutInitWindowSize(900, 600);
	glutCreateWindow("Kepler 90");
	
	glutDisplayFunc(draw);
	glutReshapeFunc(OnWindowSizeChanged);
	glutMouseFunc(MouseEvent);
	glutSpecialFunc(SpecialKeys);
	glutKeyboardFunc(KeyboardFunc);
	glutIdleFunc(idle);
	setup();
	glutMainLoop();
}
