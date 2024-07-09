#include <D:/SkullBreaker/Skull Breaker/Controles.h>
#include <GL/glfw3.h>

Controles::Controles(Zoom* zoom) : zoom(zoom)
{}

void Controles::tecladoI(unsigned char tecla, int x, int y)
{
	switch (tecla)
	{
	case '+':
		zoom->acercarZoom();
		break;
	case '-':
		zoom->alejarZoom();
		break;
	}
}

void Controles::mouseI(double compensacionY)
{
	if (compensacionY > 0)
	{
		zoom->acercarZoom();
	}
	else if (compensacionY < 0)
	{
		zoom->alejarZoom();
	}
}