#pragma once
#ifndef GRILLA_H
#define GRILLA_H

class Grilla
{
	public:
		Grilla(float tamañoGrilla, int espacioGrilla);
		void Dibujar() const;
		float GettamañoGrilla() const;
		int GetespacioGrilla() const;
	private:
		float tamañoGrilla;
		int espacioGrilla;
};
#endif // !GRILLA_H
