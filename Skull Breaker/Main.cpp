#include <GL/glut.h>
#include <D:/SkullBreaker/Skull Breaker/Grilla.h>
#include <D:/SkullBreaker/Skull Breaker/Zoom.h>
#include <D:/SkullBreaker/Skull Breaker/Consola.h>

//llamamos a la clase Grilla
Grilla grilla(20);
Zoom zoom;
Consola consola(10);

//todo esto es lo que se mostrara en ventana
void Display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	int w = glutGet(GLUT_WINDOW_WIDTH);
	int h = glutGet(GLUT_WINDOW_HEIGHT);

	grilla.Dibujar(w,h, zoom.GetZoomLevel());
	consola.dibujar(w,h);
	glutSwapBuffers();
}

void redimesionar(int w, int h)
{
	//evitamos la divisionentre 0
	if (h == 0)
	{
		h = 1;
	}
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	float nivelZoom = zoom.GetZoomLevel();
	gluOrtho2D(-w / 2.0 * nivelZoom, w / 2.0 * nivelZoom, -h / 2.0 * nivelZoom, h / 2.0 * nivelZoom);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void Controles(unsigned char teclas, int x, int y)
{
	switch (teclas)
	{
	case '+':
		zoom.acercarZoom();
		redimesionar(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
		glutPostRedisplay();
		break;
	case '-':
		zoom.alejarZoom();
		redimesionar(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
		glutPostRedisplay();
		break;
	}
}

void logenConsola(const std::string& mensaje)
{
	consola.log(mensaje);
	glutPostRedisplay();
}

//Funcion principal
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(1080, 720);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Skull Breaker");

	//mansajes de la consola
	logenConsola("Inciando SkullBreaker...");
	logenConsola("Creando la cuadricula con tamano de celda 20");

	glutDisplayFunc(Display);
	glutReshapeFunc(redimesionar);
	glutKeyboardFunc(Controles);
	glutMainLoop();

	return 0;
}