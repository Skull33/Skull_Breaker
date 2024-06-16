#include <GL/glut.h>
#include <D:\SkullBreaker\Skull Breaker\Grilla.h>
#include <d:/SkullBreaker/Skull Breaker/vertice.h>

Grilla grilla(10, 0.1f);

void Display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	grilla.dibujar();
	glFlush();
}

void redimensionar(int w, int h)
{
	glViewport(0,0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (w <= h)
	{
		gluOrtho2D(-1.0, 1.0, -1.0*(GLfloat)h / (GLfloat)w, 1.0 * (GLfloat)h / (GLfloat)w);
	}
	else
	{
		gluOrtho2D(-1.0 * (GLfloat)h / (GLfloat)w, 1.0 * (GLfloat)h / (GLfloat)w, -1.0, 1.0);
	}
}

void init()
{
	glClearColor(0.0, 0.0, 0.0 ,0.0);
}

void Mouse(int button, int stado, int x, int y)
{
	grilla.clickdelmouse(button, stado, x, y);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1080, 720);
	glutInitWindowPosition(100,100);
	glutCreateWindow("SkullBreaker");

	init();

	glutDisplayFunc(Display);

	glutMouseFunc(Mouse);

	glutMainLoop();

	return 0;
}

