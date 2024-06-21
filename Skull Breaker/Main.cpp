#include <GL/glut.h>
#include <D:/SkullBreaker/Skull Breaker/Grilla.h>

//llamamos a la clase Grilla
Grilla grilla(20);

//todo esto es lo que se mostrara en ventana
void Display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	int w = glutGet(GLUT_WINDOW_WIDTH);
	int h = glutGet(GLUT_WINDOW_HEIGHT);

	grilla.Dibujar(w,h);
	glutSwapBuffers();
}

void redimesionar(int w, int h)
{
	//evitamos la divisionentre 0
	if (h == 0)
	{
		h = 1;
	}
	float radiodeaspecto = (float)w / (float)h;
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	if (radiodeaspecto >= 1.0)
	{
		gluOrtho2D(-w/2.0, w/2.0, -h/2.0, h/2.0);
	}
	else
	{
		gluOrtho2D(-w / 2.0, w / 2.0, -h / 2.0, h / 2.0);
	}

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
//Funcion principal
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(1080, 720);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Skull Breaker");
	glutDisplayFunc(Display);
	glutReshapeFunc(redimesionar);
	glutMainLoop();

	return 0;
}