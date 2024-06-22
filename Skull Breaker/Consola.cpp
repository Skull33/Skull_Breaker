#include <D:/SkullBreaker/Skull Breaker/Consola.h>
#include <GL/glut.h>
#include <iostream>

Consola::Consola(int maximodeLineas):
	maximodeLineas(maximodeLineas){}

void Consola::log(const std::string& mensaje)
{
	mensajes.push_back(mensaje);
	if (mensajes.size() > maximodeLineas)
	{
		mensajes.erase(mensajes.begin());
	}
}

void Consola::dibujar(int winw, int winh) const 
{
	int alturaConsola = winh / 4;
	//espacio donde estara la consola
	glColor3f(0.0f,0.0f,0.0f);
	glBegin(GL_QUADS);
	glVertex2f(-winw / 2.0f, -winh /2.0f);
	glVertex2f(winw / 2.0f, -winh / 2.0f);
	glVertex2f(winw / 2.0f, -winh /2.0f + alturaConsola);
	glVertex2f(-winw / 2.0f, -winh /2.0f + alturaConsola);
	glEnd();

	//texto que botara la consola
	glColor3f(1.0f,1.0f,1.0f);
	int alturadeLinea = 20;
	int inicioX = -winw / 2 + 10;
	int inicioY = -winh / 2 + 10;
	
	for (size_t i = 0; i < mensajes.size(); ++i)
	{
		glRasterPos2f(inicioX, inicioY + i * alturadeLinea);
		const std::string& msg = mensajes[i];
		for (char c : msg)
		{
			glutBitmapCharacter(GLUT_BITMAP_9_BY_15, c);
		}
	}
}