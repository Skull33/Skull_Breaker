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

	int alturalineas = 20;
	int textoY = y + winh - alturalineas;
	for (size_t i = 0; i < mensajes.size(); ++i)
	{
		glRasterPos2i(x + 5, textoY);
		const std::string& msg = mensajes[i];
		size_t pos = msg.find("Skull Breaker");
		if (pos != std::string::npos)
		{
			//el texto antes de skullbreaker
			glColor3f(1.0f,1.0f,1.0f);
			for (size_t j = 0; j < pos; ++j)
			{
				glutBitmapCharacter(GLUT_BITMAP_9_BY_15, msg[j]);
			}
			//convertir SkullBreaker en rojo
			glColor3f(1.0f,0.0f,0.0f);
			for (size_t j = pos; j < pos + 13; ++j)
			{
				glutBitmapCharacter(GLUT_BITMAP_9_BY_15, msg[j]);
			}
			//el texto despues de SkullBreaker
			glColor3f(1.0f,1.0f,1.0f);
			for (size_t j = pos +13; j< msg.size(); ++j)
			{
				glutBitmapCharacter(GLUT_BITMAP_9_BY_15, msg[j]);
			}
		}
		else
		{
			//todo el texto que no contenga la palabra SkullBreaker
			glColor3f(1.0f, 1.0f, 1.0f);
			for (char c: msg)
			{
				glutBitmapCharacter(GLUT_BITMAP_9_BY_15,c);
			}
		}
		textoY -= alturalineas;
		if (textoY < y)
		{
			break;
		}
	}
}