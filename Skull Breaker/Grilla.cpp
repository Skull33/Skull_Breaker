#include <D:/SkullBreaker/Skull Breaker/Grilla.h>
#include <GL/glut.h>
#include <cstdio>

Grilla::Grilla(float tamaņo):
	tamaņoGrilla(tamaņo)
{
	printf("Creando cuadridula con tamaņo: \n %2f y munero de lineas %d\n", tamaņoGrilla);
	fflush(stdout);
}

void Grilla::Dibujar(int w, int h, float nivelZoom) const
{
	glColor3f(0.5f, 0.5f, 0.5f);

	float ajustartamaņoGrilla = tamaņoGrilla / nivelZoom;
	float mitadancho = (w / 2.0f) * nivelZoom;
	float mitadalto = (h / 2.0f) * nivelZoom;

	int espacioGrillaX = (w / ajustartamaņoGrilla) /2 +1;
	int espacioGrillaY = (h / ajustartamaņoGrilla) /2 +1;

	glBegin(GL_LINES);
	for (float x = -mitadancho; x <= mitadancho; x += ajustartamaņoGrilla)
	{
		glVertex2f(x, -mitadalto);
		glVertex2f(x, mitadalto);
	}
	for (float y = -mitadalto; y <= mitadalto; y += ajustartamaņoGrilla)
	{
		glVertex2f(-mitadancho, y);
		glVertex2f(mitadancho, y);
	}
	glEnd();
}
