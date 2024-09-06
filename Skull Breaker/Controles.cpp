#include <D:/Skull_Breaker/Skull Breaker/Controles.h>
#include <GL/glut.h>

Controles::Controles(Zoom* zoom) : zoom(zoom)
{}

void Controles::setconsola(Consola* consola)
{
	this->consola = consola;
}

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
		else if (boton == GLUT_LEFT_BUTTON)
		{
			int vemtamaAltura = glutGet(GLUT_WINDOW_HEIGHT);
			int consolaY = 10;
			int consolaAlto = 200;

			if (y >(vemtamaAltura - consolaY - consolaAlto) && y < (vemtamaAltura - consolaY)
				&& x > (glutGet(GLUT_WINDOW_WIDTH) - 30) && x < (glutGet(GLUT_WINDOW_HEIGHT) -10))
			{
				consola->cerrar();
			}
		}
	}
	glutPostRedisplay();
}