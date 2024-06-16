#include <GL/glut.h>
#include <D:\SkullBreaker\Skull Breaker\Grilla.h>

Grilla grilla(10, 0.1f);

void Display()
{
	glClear(GL_COLOR_BUFFER_BIT);

	grilla.dibujar();

	glFlush();
}

void init()
{
	glClearColor(0.0, 0.0, 0.0 ,0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
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

	glutMainLoop();

	return 0;
}

