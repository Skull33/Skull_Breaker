#pragma once
#ifndef VERTICE_H
#define VERTICE_H
class Vertice
{
public:
	Vertice(float x, float y):
		x(x), y(y){}
	void dibujar() const;

private:
	float x, y;
};
#endif // !VERTICE_H
