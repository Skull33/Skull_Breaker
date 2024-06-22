#pragma once
#ifndef ZOOM_H
#define ZOOM_H
class Zoom
{
	public:
		Zoom();
		void acercarZoom();
		void alejarZoom();
		float GetZoomLevel() const;
	private:
		float nivelzoom;
		const float incrementoZoom;
		const float maximoincremento;
		const float maximodecremento;
};
#endif // !ZOOM_H
