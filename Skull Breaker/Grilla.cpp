#include <D:/SkullBreaker/Skull Breaker/Grilla.h>
#include <GL/glut.h>
#include <cstdio>

Grilla::Grilla(float tamaņo, int espacio) :
	tamaņoGrilla(tamaņo), espacioGrilla(espacio)
{
	printf("Creando cuadridula con tamaņo: \n %2f y munero de lineas %d\n", tamaņoGrilla, espacioGrilla);
	fflush(stdout);
}

void Grilla::Dibujar() const
{
	glColor3f(0.5f, 0.5f, 0.5f);

	glBegin(GL_LINES);
	for (int i = -espacioGrilla; i <= espacioGrilla; ++i)
	{
		glVertex2f(i*tamaņoGrilla, -espacioGrilla * tamaņoGrilla);
		glVertex2f(i*tamaņoGrilla, espacioGrilla * tamaņoGrilla);

		glVertex2f(-espacioGrilla * tamaņoGrilla, i * tamaņoGrilla);
		glVertex2f(espacioGrilla * tamaņoGrilla, i * tamaņoGrilla);
	}
	glEnd();
}

float Grilla::GettamaņoGrilla()const
{
	return tamaņoGrilla;
}

int Grilla::GetespacioGrilla() const
{
	return espacioGrilla;
}