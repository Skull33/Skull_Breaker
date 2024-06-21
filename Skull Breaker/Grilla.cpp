#include <D:/SkullBreaker/Skull Breaker/Grilla.h>
#include <GL/glut.h>
#include <cstdio>

Grilla::Grilla(float tamaņo):
	tamaņoGrilla(tamaņo)
{
	printf("Creando cuadridula con tamaņo: \n %2f y munero de lineas %d\n", tamaņoGrilla);
	fflush(stdout);
}

void Grilla::Dibujar(int w, int h) const
{
	glColor3f(0.5f, 0.5f, 0.5f);

	int espacioGrillaX = w / tamaņoGrilla /2;
	int espacioGrillaY = h / tamaņoGrilla / 2;

	glBegin(GL_LINES);
	for (int i = -espacioGrillaX; i <= espacioGrillaX; ++i)
	{
		glVertex2f(i * tamaņoGrilla, -h / 2.0);
		glVertex2f(i * tamaņoGrilla, h / 2.0);
	}
	for (int i = -espacioGrillaY; i <= espacioGrillaY; ++i)
	{
		glVertex2f(-w / 2.0, i* tamaņoGrilla);
		glVertex2f(w / 2.0, i * tamaņoGrilla);
	}
	glEnd();
}
