#include <GL/glut.h>
#include "Planet.h"
#include "Camera.h"

GLfloat angle, fAspect;
GLdouble obsX=0, obsY=0, obsZ=200;

Planet planet1;
Camera* activeCamera;

void draw(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(0.0f, 0.0f, 1.0f);

	planet1.Draw();

	glutSwapBuffers();
}

// Initialize rendering parameters
void setup(void)
{
	activeCamera = new PerspectiveCamera();
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	angle = 45;
	planet1.posX = planet1.posY = 0;
	planet1.planet_radius = 20;
	planet1.rotation = 0;
	planet1.rotation_speed = 0.01;
}

// Fun��o usada para especificar a posi��o do observador virtual
//void PosicionaObservador(void)
//{
//	// Especifica sistema de coordenadas do modelo
//	glMatrixMode(GL_MODELVIEW);
//	// Inicializa sistema de coordenadas do modelo
//	glLoadIdentity();
//	// Especifica posi��o do observador e do alvo
//	gluLookAt(0, 80, 200, 0, 0, 0, 0, 1, 0);
//}

// Fun��o usada para especificar o volume de visualiza��o
//void EspecificaParametrosVisualizacao(void)
//{
//	// Especifica sistema de coordenadas de proje��o
//	glMatrixMode(GL_PROJECTION);
//	// Inicializa sistema de coordenadas de proje��o
//	glLoadIdentity();
//
//	// Especifica a proje��o perspectiva(angulo,aspecto,zMin,zMax)
//	gluPerspective(angle, fAspect, 0.5, 500);
//
//	PosicionaObservador();
//}

// Fun��o callback chamada quando o tamanho da janela � alterado 
void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
	activeCamera->OnWindowSizeChanged(w, h);
}

// Fun��o callback chamada para gerenciar eventos do mouse
void GerenciaMouse(int button, int state, int x, int y)
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
	planet1.Tick();
	activeCamera->Tick();
	glutPostRedisplay();
}

// Programa Principal
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(900, 600);
	glutCreateWindow("Kepler 90");
	
	glutDisplayFunc(draw);
	glutReshapeFunc(AlteraTamanhoJanela);
	glutMouseFunc(GerenciaMouse);
	glutSpecialFunc(SpecialKeys);
	glutIdleFunc(idle);
	setup();
	glutMainLoop();
}
