#include <D:/SkullBreaker/Skull Breaker/Controles.h>
#include <iostream>

bool Acciones::mododibujo = false;

void Acciones::manejarbotones(unsigned char tecla, int x, int y)
{
	int modificadores = glutGetModifiers();
	switch (tecla)
	{
		case 'd':
		case 'D':
			if (modificadores & GLUT_ACTIVE_CTRL)
			{
				mododibujo = !mododibujo;
				if (mododibujo)
				{
					std::cout << "Modo de Dibujo ON" << std::endl;
				}
				else
				{
					std::cout << "Modo de Dibujo OFF" << std::endl;
				}
			}
			break;
	}
}