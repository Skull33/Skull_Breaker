#include <GL/glut.h>
#include <D:/SkullBreaker/Skull Breaker/Controles.h>
#include <cstdio>

bool Acciones::mododibujo = false;
bool Acciones::apretarcontrol = false;

void Acciones::manejarbotones(unsigned char tecla, int x, int y)
{
	if (tecla == 'd')
	{
		mododibujo = !mododibujo;
		if (mododibujo)
		{
			printf("Modo de Dibujo ON \n");
			fflush(stdout);
		}
		else
		{
			printf("Modo de Dibujo OFF \n");
			fflush(stdout);
		}
	}
}

void Acciones::NOmanejarbotones(unsigned char tecla, int x, int y)
{
	printf("Tecla liberada: %c (Código ASCII: %d)\n", tecla, tecla);
	fflush(stdout);
}