#pragma once
#ifndef GRILLA_H
#define GRILLA_H
#include <vector>
#include <D:/SkullBreaker/Skull Breaker/vertice.h>

class Grilla {
	public:
		Grilla(int tamaño, float espacio);
		void dibujar() const;
		void añadirvertice(float x, float y);
		void clickdelmouse(int button, int stado, int x, int y);
		int gettamañoGrilla() const;
		float getespacioGrilla() const;
	private:
		int tamañoGrilla;
		float espacioGrilla;
		std::vector<Vertice> vertices;
		float PantallauniversalX(int x) const;
		float PantallauniversalY(int y) const;
};
#endif // !GRILLA_H

