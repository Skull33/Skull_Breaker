#pragma once
#ifndef GRILLA_H
#define GRILLA_H

class Grilla
{
	public:
		Grilla(float tamañoGrilla);
		void Dibujar(int w, int h, float nivelZoom) const;
	private:
		float tamañoGrilla;
};
#endif // !GRILLA_H
