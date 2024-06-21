#include <D:/SkullBreaker/Skull Breaker/Grilla.h>
#include <GL/glut.h>
#include <cstdio>

Grilla::Grilla(float tamaño, int espacio) :
	tamañoGrilla(tamaño), espacioGrilla(espacio)
{
	printf("Creando cuadridula con tamaño: \n %2f y munero de lineas %d\n", tamañoGrilla, espacioGrilla);
	fflush(stdout);
}

void Grilla::Dibujar() const
{
	glColor3f(0.5f, 0.5f, 0.5f);

	glBegin(GL_LINES);
	for (int i = -espacioGrilla; i <= espacioGrilla; ++i)
	{
		glVertex2f(i*tamañoGrilla, -espacioGrilla * tamañoGrilla);
		glVertex2f(i*tamañoGrilla, espacioGrilla * tamañoGrilla);

		glVertex2f(-espacioGrilla * tamañoGrilla, i * tamañoGrilla);
		glVertex2f(espacioGrilla * tamañoGrilla, i * tamañoGrilla);
	}
	glEnd();
}

float Grilla::GettamañoGrilla()const
{
	return tamañoGrilla;
}

int Grilla::GetespacioGrilla() const
{
	return espacioGrilla;
}