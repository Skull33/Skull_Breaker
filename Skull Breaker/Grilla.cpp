#include <GL/glut.h>
#include <D:/SkullBreaker/Skull Breaker/Grilla.h>
#include <cmath>

Grilla::Grilla(int tama�o, float espacio) :
	tama�oGrilla(tama�o), espacioGrilla(espacio){}

void Grilla::dibujar() const
{
    glColor3f(1.0f, 1.0f, 1.0f);

    // Empieza a dibujar l�neas
    glBegin(GL_LINES);

    // L�neas verticales
    for (int i = -tama�oGrilla; i <= tama�oGrilla; ++i) {
        glVertex2f(i * espacioGrilla, -tama�oGrilla * espacioGrilla);
        glVertex2f(i * espacioGrilla, tama�oGrilla * espacioGrilla);
    }

    // L�neas horizontales
    for (int i = -tama�oGrilla; i <= tama�oGrilla; ++i) {
        glVertex2f(-tama�oGrilla * espacioGrilla, i * espacioGrilla);
        glVertex2f(tama�oGrilla * espacioGrilla, i * espacioGrilla);
    }

    glEnd();

    //dibujamos los vertices
    for (const auto& vertice : vertices)
    {
        vertice.dibujar();
    }
}

void Grilla::a�adirvertice(float x, float y)
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

        a�adirvertice(verticeX, verticeY);
        glutPostRedisplay(); //redibuja la ventana
    }
}

float Grilla::PantallauniversalX(int x) const
{
    int viewport[4];
    glGetIntegerv(GL_VIEWPORT, viewport);
    return (2.0f * x/viewport[2]) - 1.0f;
}

float Grilla::PantallauniversalY(int y) const
{
    int viewport[4];
    glGetIntegerv(GL_VIEWPORT, viewport);
    return 1.0f - (2.0f * y / viewport[3]);
}
