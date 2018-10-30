#define DOUBLE_BUFFERED

#include <GL/glut.h>
#include <vector>
#include "Planet.h"
#include "Star.h"
#include "Camera.h"
#include "Timer.h"

GLfloat angle, fAspect;
GLdouble obsX=0, obsY=0, obsZ=200;

Camera* activeCamera;
Timer timer(1);

Star star(20);
std::vector<Planet> Planets;

void draw(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(0.0f, 0.0f, 1.0f);

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

void fillPlanets()
{	
	Planets.reserve(8); // 8 planets
	Planets.emplace_back(0.074/* + orbit_offset */,   7.0,  1.31);	// Kepler 90b
	Planets.emplace_back(0.089/* + orbit_offset */,   8.7,  1.19);	// Kepler 90c
	Planets.emplace_back(0.150/* + orbit_offset */,  14.4,  1.32);	// Kepler 90i (RADIUS UNDEFINED!!!!)
	Planets.emplace_back(0.320/* + orbit_offset */,  59.7,  2.81);	// Kepler 90d
	Planets.emplace_back(0.420/* + orbit_offset */,  91.9,  2.60);	// Kepler 90e
	Planets.emplace_back(0.480/* + orbit_offset */, 124.9,  2.82);	// Kepler 90f
	Planets.emplace_back(0.710/* + orbit_offset */, 210.6,  7.93);	// Kepler 90g
	Planets.emplace_back(1.010/* + orbit_offset */, 331.6, 11.06);	// Kepler 90h

}

// Initialize rendering parameters
void setup(void)
{
	activeCamera = new PerspectiveCamera();
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	fillPlanets();
}

// Função callback chamada quando o tamanho da janela é alterado 
void OnWindowSizeChanged(GLsizei w, GLsizei h)
{
	activeCamera->OnWindowSizeChanged(w, h);
}

// Função callback chamada para gerenciar eventos do mouse
void MouseEvent(int button, int state, int x, int y)
{
	activeCamera->OnMouseClick(button, state, x, y);
	glutPostRedisplay();
}

// Callback para gerenciar eventos do teclado para teclas especiais (F1, PgDn, entre outras)
void SpecialKeys(int key, int x, int y)
{
	activeCamera->KeyboardSpecial(key, x, y);
	glutPostRedisplay();
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
		activeCamera->Tick();
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
	glutIdleFunc(idle);
	setup();
	glutMainLoop();
}
