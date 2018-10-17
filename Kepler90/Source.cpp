#define DOUBLE_BUFFERED

#include <GL/glut.h>
#include "Planet.h"
#include "Camera.h"
#include "Timer.h"

GLfloat angle, fAspect;
GLdouble obsX=0, obsY=0, obsZ=200;

Planet planet1(40, 0.01, 20);
Planet planet2(40, 0.01, 20);
Camera* activeCamera;
Timer timer(1);

void draw(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(0.0f, 0.0f, 1.0f);

	planet1.Draw();

#ifdef DOUBLE_BUFFERED
	glutSwapBuffers();
#else
	glFlush();
#endif // DOUBLE_BUFFERED

}

// Initialize rendering parameters
void setup(void)
{
	activeCamera = new PerspectiveCamera();
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
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
		planet1.Tick(time);
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
