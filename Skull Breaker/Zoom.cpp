#include <D:/SkullBreaker/Skull Breaker/Zoom.h>

Zoom::Zoom() :
	nivelzoom(1.0f), incrementoZoom(0.1f), maximoincremento(0.5f), maximodecremento(20.0f)
{}

void Zoom::acercarZoom()
{
	if (nivelzoom - incrementoZoom >= maximoincremento)
	{
		nivelzoom -= incrementoZoom;
	}
}

void Zoom::alejarZoom()
{
	if (nivelzoom + incrementoZoom <= maximodecremento)
	{
		nivelzoom += incrementoZoom;
	}
}

float Zoom::GetZoomLevel() const
{
	return nivelzoom;
}