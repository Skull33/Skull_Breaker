#include <D:/Skull_Breaker/Skull Breaker/Controles.h>
#include <GL/glut.h>

Controles::Controles(Zoom* zoom) : zoom(zoom)
{}

void Controles::tecladoI(unsigned char tecla, int x, int y)
{
	switch (tecla)
	{
	case '+':
		zoom->acercarZoom();
		break;
	case '-':
		zoom->alejarZoom();
		break;
	}
	glutPostRedisplay();
}

void Controles::mouseI(int boton, int stado, int x, int y)
{
	if (stado == GLUT_DOWN)
	{
		if (boton == 3) 
		{
			zoom->acercarZoom();
		}
		else if (boton == 4)
		{
			zoom->alejarZoom();
		}
	}
	glutPostRedisplay();
}