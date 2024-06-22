#include <D:/SkullBreaker/Skull Breaker/Grilla.h>
#include <GL/glut.h>
#include <cstdio>

Grilla::Grilla(float tama�o):
	tama�oGrilla(tama�o)
{
	printf("Creando cuadridula con tama�o: \n %2f y munero de lineas %d\n", tama�oGrilla);
	fflush(stdout);
}

void Grilla::Dibujar(int w, int h, float nivelZoom) const
{
	glColor3f(0.5f, 0.5f, 0.5f);

	float ajustartama�oGrilla = tama�oGrilla / nivelZoom;
	float mitadancho = (w / 2.0f) * nivelZoom;
	float mitadalto = (h / 2.0f) * nivelZoom;

	int espacioGrillaX = (w / ajustartama�oGrilla) /2 +1;
	int espacioGrillaY = (h / ajustartama�oGrilla) /2 +1;

	glBegin(GL_LINES);
	for (float x = -mitadancho; x <= mitadancho; x += ajustartama�oGrilla)
	{
		glVertex2f(x, -mitadalto);
		glVertex2f(x, mitadalto);
	}
	for (float y = -mitadalto; y <= mitadalto; y += ajustartama�oGrilla)
	{
		glVertex2f(-mitadancho, y);
		glVertex2f(mitadancho, y);
	}
	glEnd();
}
