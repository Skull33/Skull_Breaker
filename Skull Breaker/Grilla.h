#pragma once
#ifndef GRILLA_H
#define GRILLA_H

class Grilla
{
	public:
		Grilla(float tamaņoGrilla);
		void Dibujar(int w, int h) const;
	private:
		float tamaņoGrilla;
};
#endif // !GRILLA_H
