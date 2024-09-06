#include <D:/Skull_Breaker/Skull Breaker/Consola.h>
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
	mensajeTamañoGrilla = "tamano de la grilla: " + std::to_string(w / nivelzoom) + " ancho, por " + std::to_string(h / nivelzoom) + " alto";
}

void Consola::dibujar(int x, int y, int winw, int winh) const 
{
	if (visible) return;
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
		for (char c : mensajeTamañoGrilla)
		{
			glutBitmapCharacter(GLUT_BITMAP_9_BY_15, c);
		}
		textoY -= alturalineas;
		if (textoY < y)
		{
			break;
		}
	}
	// Dibuja la "X" en la esquina superior derecha
	int xOffset = x + winw - 20;
	int yOffset = y + winh - 20;

	//verificar si el cursor esta en la X

	glBegin(GL_LINES);
	glVertex2f(xOffset, yOffset);
	glVertex2f(xOffset + 15, yOffset - 15);
	glVertex2f(xOffset + 15, yOffset);
	glVertex2f(xOffset, yOffset - 15);
	glEnd();
}

void Consola::cerrar()
{
	visible = false;
}