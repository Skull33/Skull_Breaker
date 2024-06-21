#include <D:/SkullBreaker/Skull Breaker/Grilla.h>
#include <GL/glut.h>
#include <cstdio>

Grilla::Grilla(float tama�o, int espacio) :
	tama�oGrilla(tama�o), espacioGrilla(espacio)
{
	printf("Creando cuadridula con tama�o: \n %2f y munero de lineas %d\n", tama�oGrilla, espacioGrilla);
	fflush(stdout);
}

void Grilla::Dibujar() const
{
	glColor3f(0.5f, 0.5f, 0.5f);

	glBegin(GL_LINES);
	for (int i = -espacioGrilla; i <= espacioGrilla; ++i)
	{
		glVertex2f(i*tama�oGrilla, -espacioGrilla * tama�oGrilla);
		glVertex2f(i*tama�oGrilla, espacioGrilla * tama�oGrilla);

		glVertex2f(-espacioGrilla * tama�oGrilla, i * tama�oGrilla);
		glVertex2f(espacioGrilla * tama�oGrilla, i * tama�oGrilla);
	}
	glEnd();
}

float Grilla::Gettama�oGrilla()const
{
	return tama�oGrilla;
}

int Grilla::GetespacioGrilla() const
{
	return espacioGrilla;
}