#include <D:/SkullBreaker/Skull Breaker/Grilla.h>
#include <GL/glut.h>
#include <cstdio>

Grilla::Grilla(float tamaño):
	tamañoGrilla(tamaño)
{
	printf("Creando cuadridula con tamaño: \n %2f y munero de lineas %d\n", tamañoGrilla);
	fflush(stdout);
}

void Grilla::Dibujar(int w, int h) const
{
	glColor3f(0.5f, 0.5f, 0.5f);

	int espacioGrillaX = w / tamañoGrilla /2;
	int espacioGrillaY = h / tamañoGrilla / 2;

	glBegin(GL_LINES);
	for (int i = -espacioGrillaX; i <= espacioGrillaX; ++i)
	{
		glVertex2f(i * tamañoGrilla, -h / 2.0);
		glVertex2f(i * tamañoGrilla, h / 2.0);
	}
	for (int i = -espacioGrillaY; i <= espacioGrillaY; ++i)
	{
		glVertex2f(-w / 2.0, i* tamañoGrilla);
		glVertex2f(w / 2.0, i * tamañoGrilla);
	}
	glEnd();
}
