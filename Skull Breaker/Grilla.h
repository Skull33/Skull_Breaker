#pragma once
#ifndef GRILLA_H
#define GRILLA_H

class Grilla
{
	public:
		Grilla(float tamaņoGrilla, int espacioGrilla);
		void Dibujar() const;
		float GettamaņoGrilla() const;
		int GetespacioGrilla() const;
	private:
		float tamaņoGrilla;
		int espacioGrilla;
};
#endif // !GRILLA_H
