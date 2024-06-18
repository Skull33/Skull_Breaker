#pragma once
#ifndef CONTROLES_H
#define CONTROLES_H
#include <GL/glut.h>

class Acciones 
{
	public:
		static bool mododibujo;

		static void manejarbotones(unsigned char tecla, int x, int y);
};
#endif // !CONTROLES_H
