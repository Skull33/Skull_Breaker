#include <GL/glut.h>
#include <D:\SkullBreaker\Skull Breaker\Grilla.h>
#include <D:/SkullBreaker/Skull Breaker/Controles.h>

extern Grilla grilla;

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

	float cudradosiguales = grilla.gettamañoGrilla() * grilla.getespacioGrilla();
	if (w <= h)
	{
		glOrtho(-cudradosiguales, cudradosiguales,
				-cudradosiguales * (GLfloat)h / (GLfloat)w,
				cudradosiguales * (GLfloat)h / (GLfloat)w, -1.0, 1.0);
	}
	else
	{
		glOrtho(-cudradosiguales * (GLfloat)w / (GLfloat)h,
				cudradosiguales * (GLfloat)w / (GLfloat)h,
				-cudradosiguales, cudradosiguales, - 1.0, 1.0);
	}

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void init()
{
	glClearColor(0.0, 0.0, 0.0 ,0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	float cudradosiguales = grilla.gettamañoGrilla() * grilla.getespacioGrilla();
	glOrtho(-cudradosiguales, cudradosiguales, -cudradosiguales, cudradosiguales, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void Mouse(int button, int stado, int x, int y)
{
	if (Acciones::mododibujo)
	{
		grilla.clickdelmouse(button, stado, x, y);
	}
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
	glutReshapeFunc(redimensionar);
	glutMouseFunc(Mouse);
	glutKeyboardFunc(Acciones::manejarbotones);
	glutKeyboardUpFunc(Acciones::NOmanejarbotones);
	glutMainLoop();

	return 0;
}

