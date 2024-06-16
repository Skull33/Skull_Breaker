#include <GL/glut.h>
#include <D:/SkullBreaker/Skull Breaker/vertice.h>

void Vertice::dibujar() const
{
	glColor3f(1.0, 0.0, 0.0f);
	glPointSize(5.0f);
	glBegin(GL_POINTS);
	glVertex2f(x, y);
	glEnd();
}