#include <GL/glut.h>
#include <D:/SkullBreaker/Skull Breaker/Grilla.h>

//llamamos a la clase Grilla
Grilla grilla(20.0f, 10);

//todo esto es lo que se mostrara en ventana
void Display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	grilla.Dibujar();
	glutSwapBuffers();
}

void redimesionar(int w, int h)
{
	//evitamos la divisionentre 0
	if (h == 0)
	{
		h = 1;
	}
	float radiodeaspecto = (float)w / (float)h;
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	float tamañoGrilla = grilla.GettamañoGrilla();
	int espacioGrilla = grilla.GetespacioGrilla();
	if (radiodeaspecto >= 1.0)
	{
		gluOrtho2D(-espacioGrilla * tamañoGrilla * radiodeaspecto, espacioGrilla * tamañoGrilla * radiodeaspecto, -espacioGrilla * tamañoGrilla, espacioGrilla * tamañoGrilla);
	}
	else
	{
		gluOrtho2D(-espacioGrilla * tamañoGrilla, espacioGrilla * tamañoGrilla, -espacioGrilla * tamañoGrilla * radiodeaspecto, espacioGrilla * tamañoGrilla * radiodeaspecto);
	}

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

//lo que se vera al iniciar el programa
void inicializar()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
}

//Funcion principal
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(1080, 720);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Skull Breaker");
	glutDisplayFunc(Display);
	glutReshapeFunc(redimesionar);
	glutMainLoop();

	return 0;
}