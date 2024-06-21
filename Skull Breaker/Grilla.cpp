#include <D:/SkullBreaker/Skull Breaker/Grilla.h>
#include <GL/glut.h>
#include <cstdio>

Grilla::Grilla(float tama�o):
	tama�oGrilla(tama�o)
{
	printf("Creando cuadridula con tama�o: \n %2f y munero de lineas %d\n", tama�oGrilla);
	fflush(stdout);
}

void Grilla::Dibujar(int w, int h) const
{
	glColor3f(0.5f, 0.5f, 0.5f);

	int espacioGrillaX = w / tama�oGrilla /2;
	int espacioGrillaY = h / tama�oGrilla / 2;

	glBegin(GL_LINES);
	for (int i = -espacioGrillaX; i <= espacioGrillaX; ++i)
	{
		glVertex2f(i * tama�oGrilla, -h / 2.0);
		glVertex2f(i * tama�oGrilla, h / 2.0);
	}
	for (int i = -espacioGrillaY; i <= espacioGrillaY; ++i)
	{
		glVertex2f(-w / 2.0, i* tama�oGrilla);
		glVertex2f(w / 2.0, i * tama�oGrilla);
	}
	glEnd();
}
