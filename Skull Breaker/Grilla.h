#pragma once
#ifndef GRILLA_H
#define GRILLA_H

class Grilla
{
	public:
		Grilla(float tama�oGrilla);
		void Dibujar(int w, int h, float nivelZoom) const;
	private:
		float tama�oGrilla;
};
#endif // !GRILLA_H
