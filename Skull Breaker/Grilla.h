#pragma once
#ifndef GRILLA_H
#define GRILLA_H

class Grilla
{
	public:
		Grilla(float tama�oGrilla, int espacioGrilla);
		void Dibujar() const;
		float Gettama�oGrilla() const;
		int GetespacioGrilla() const;
	private:
		float tama�oGrilla;
		int espacioGrilla;
};
#endif // !GRILLA_H
