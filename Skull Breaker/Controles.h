#pragma once
#ifndef CONTROLES_H
#define CONTROLES_H
#include <D:/Skull_Breaker/Skull Breaker/Zoom.h>
class Controles
{
	public:
		Controles(Zoom* zoom);
		void tecladoI(unsigned char tecla, int x, int y);
		void mouseI(int boton, int stdado, int x, int y);
	private:
		Zoom* zoom;
};

#endif // !CONTROLES_H
