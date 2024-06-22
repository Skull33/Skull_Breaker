#include <D:/SkullBreaker/Skull Breaker/Grilla.h>
#include <GL/glut.h>
#include <cstdio>

Grilla::Grilla(float tamaño):
	tamañoGrilla(tamaño)
{
	printf("Creando cuadridula con tamaño: \n %2f y munero de lineas %d\n", tamañoGrilla);
	fflush(stdout);
}

void Grilla::Dibujar(int w, int h, float nivelZoom) const
{
	glColor3f(0.5f, 0.5f, 0.5f);

	float ajustartamañoGrilla = tamañoGrilla / nivelZoom;
	float mitadancho = (w / 2.0f) * nivelZoom;
	float mitadalto = (h / 2.0f) * nivelZoom;

	int espacioGrillaX = (w / ajustartamañoGrilla) /2 +1;
	int espacioGrillaY = (h / ajustartamañoGrilla) /2 +1;

	glBegin(GL_LINES);
	for (float x = -mitadancho; x <= mitadancho; x += ajustartamañoGrilla)
	{
		glVertex2f(x, -mitadalto);
		glVertex2f(x, mitadalto);
	}
	for (float y = -mitadalto; y <= mitadalto; y += ajustartamañoGrilla)
	{
		glVertex2f(-mitadancho, y);
		glVertex2f(mitadancho, y);
	}
	glEnd();
}
