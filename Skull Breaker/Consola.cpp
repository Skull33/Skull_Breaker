#include <D:/SkullBreaker/Skull Breaker/Consola.h>
#include <GL/glut.h>
#include <iostream>
#include <cctype>

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

void Consola::actualizarMTG(int w, int h, float nivelzoom)
{
	mensajeTamaņoGrilla = "tamano de la grilla: " + std::to_string(w / nivelzoom) + " ancho, por " + std::to_string(h / nivelzoom) + " alto";
}

void Consola::dibujar(int x, int y, int winw, int winh) const 
{
	//espacio donde estara la consola
	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_QUADS);
	glVertex2f(x,y);
	glVertex2f(x + winw,y);
	glVertex2f(x + winw, y + winh);
	glVertex2f(x, y + winh);
	glEnd();
	
	int alturalineas = 20;
	int textoY = y + winh - alturalineas;
	glColor3f(1.0f, 1.0f, 1.0f);
	//mensajes
	for (const std::string& msg : mensajes)
	{
		glRasterPos2i(x + 5, textoY);
		for (char c : msg)
		{
			glutBitmapCharacter(GLUT_BITMAP_9_BY_15, c);
		}
		textoY -= alturalineas;
		glRasterPos2i(x + 5, textoY);
		for (char c : mensajeTamaņoGrilla)
		{
			glutBitmapCharacter(GLUT_BITMAP_9_BY_15, c);
		}
		textoY -= alturalineas;
		if (textoY < y)
		{
			break;
		}
	}
	
}