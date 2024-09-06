#pragma once
#ifndef CONSOLA_H
#define CONSOLA_H

#include <string>
#include <vector>

class Consola
{
	public:
		Consola(int maximodeLineas = 10);
		void log(const std::string& mensaje);
		void dibujar(int x, int y, int winw, int winh) const;
		void actualizarMTG(int w, int h, float nivelzoom);
		void cerrar();
	private:
		int maximodeLineas;
		std::vector<std::string> mensajes;
		std::string mensajeTamañoGrilla;
		bool visible;
};
#endif // !CONSOLA_H
