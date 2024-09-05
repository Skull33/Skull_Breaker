#include <GL/glut.h>
#include <iostream>
#include <D:/Skull_Breaker/Skull Breaker/Grilla.h>
#include <D:/Skull_Breaker/Skull Breaker/Zoom.h>
#include <D:/Skull_Breaker/Skull Breaker/Controles.h>
#include <D:/Skull_Breaker/Skull Breaker/Consola.h>

//llamamos a la clase Grilla
Grilla grilla(20.0f);
Zoom zoom;
Controles controles(&zoom);
Consola consola(10);

//todo esto es lo que se mostrara en ventana
void Display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	int w = glutGet(GLUT_WINDOW_WIDTH);
	int h = glutGet(GLUT_WINDOW_HEIGHT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	float nivelzoom = zoom.GetZoomLevel();
	gluOrtho2D(-w/2.0*nivelzoom, w/2.0*nivelzoom, -h/2.0*nivelzoom, h/2.0*nivelzoom);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	grilla.Dibujar(w,h,nivelzoom);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,w,0,h);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	consola.actualizarMTG(w,h,nivelzoom);
	consola.dibujar(10,10,w-20,200);
	glutSwapBuffers();
}

void redimesionar(int w, int h)
{
	//evitamos la division entre 0
	if (h == 0)
	{
		h = 1;
	}
	glViewport(0,0,w,h);
}

void teclado(unsigned char teclas, int x, int y)
{
	controles.tecladoI(teclas,x,y);
}

void mouse(int boton, int stado, int x, int y)
{
	controles.mouseI(boton, stado, x, y);
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
	glutCreateWindow("Skull Breaker");
	glutDisplayFunc(Display);
	glutReshapeFunc(redimesionar);
	glutKeyboardFunc(teclado);
	glutMouseFunc(mouse);
	//mansajes de la consola
	logenConsola("Bienvenido a Skull Breaker");
	glutMainLoop();

	return 0;
}