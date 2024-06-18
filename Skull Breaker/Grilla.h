#pragma once
#ifndef GRILLA_H
#define GRILLA_H
#include <vector>
#include <D:/SkullBreaker/Skull Breaker/vertice.h>

class Grilla {
	public:
		Grilla(int tama�o, float espacio);
		void dibujar() const;
		void a�adirvertice(float x, float y);
		void clickdelmouse(int button, int stado, int x, int y);
		int gettama�oGrilla() const;
		float getespacioGrilla() const;
	private:
		int tama�oGrilla;
		float espacioGrilla;
		std::vector<Vertice> vertices;
		float PantallauniversalX(int x) const;
		float PantallauniversalY(int y) const;
};
#endif // !GRILLA_H

