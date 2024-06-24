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

void Consola::dibujar(int x, int y, int winw, int winh) const 
{
	//espacio donde estara la consola
	glColor3f(0.2f,0.2f,0.2f);
	glBegin(GL_QUADS);
	glVertex2f(x,y);
	glVertex2f(x + winw,y);
	glVertex2f(x + winw, y + winh);
	glVertex2f(x, y + winh);
	glEnd();

	glColor3f(1.0f,1.0f,1.0f);
	int alturalineas = 20;
	int textoY = y + winh - alturalineas;
	for (size_t i = 0; i<mensajes.size();++i)
	{
		glRasterPos2i(x + 5, textoY);
		const std::string& msg = mensajes[i];
		
		for (char c: msg)
		{
			glutBitmapCharacter(GLUT_BITMAP_9_BY_15,c);
		}
		textoY -= alturalineas;
		if (textoY < y)
		{
			break;
		}
	}
}