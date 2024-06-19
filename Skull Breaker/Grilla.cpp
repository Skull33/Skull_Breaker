#include <GL/glut.h>
#include <D:/SkullBreaker/Skull Breaker/Grilla.h>
#include <cmath>

Grilla::Grilla(float espacio):
	espacioGrilla(espacio), anchoGrilla(2.0f), altoGrilla(2.0f){}

void Grilla::dibujar() const
{
    glColor3f(1.0f, 1.0f, 1.0f);

    // Empieza a dibujar líneas
    glBegin(GL_LINES);

    // Líneas verticales
    for (int i = -anchoGrilla; i <= anchoGrilla; i += espacioGrilla) {
        glVertex2f(i,-altoGrilla);
        glVertex2f(i, altoGrilla);
    }

    // Líneas horizontales
    for (int i = -altoGrilla; i <= altoGrilla; i += altoGrilla)
    {
        glVertex2f(-anchoGrilla, i);
        glVertex2f(anchoGrilla, i);
    }

    glEnd();

    //dibujamos los vertices
    for (const auto& vertice : vertices)
    {
        vertice.dibujar();
    }
}

void Grilla::añadirvertice(float x, float y)
{
    vertices.emplace_back(x,y);
}

void Grilla::clickdelmouse(int button, int stado, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && stado == GLUT_DOWN)
    {
        float universalX = PantallauniversalX(x);
        float universalY = PantallauniversalY(y);
        //buscamos la esquina mas cercana de los cuadrados

        int grillaX = round(universalX / espacioGrilla);
        int grillaY = round(universalY / espacioGrilla);
        float verticeX = grillaX * espacioGrilla;
        float verticeY = grillaY * espacioGrilla;

        añadirvertice(verticeX, verticeY);
        glutPostRedisplay(); //redibuja la ventana
    }
}

float Grilla::PantallauniversalX(int x) const
{
    int viewport[4];
    glGetIntegerv(GL_VIEWPORT, viewport);
    float principal_x = ((float)x / (float)viewport[2]) * 2.0 - 1.0;
    return principal_x * (viewport[2] / (float)viewport[3]);
}

float Grilla::PantallauniversalY(int y) const
{
    int viewport[4];
    glGetIntegerv(GL_VIEWPORT, viewport);
    return 1.0f - ((float)y / (float)viewport[3]) *2.0;
}
