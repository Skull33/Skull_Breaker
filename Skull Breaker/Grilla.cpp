#include <GL/glut.h>
#include <D:/SkullBreaker/Skull Breaker/Grilla.h>
#include <cmath>

Grilla::Grilla(int tamaño, float espacio) :
	tamañoGrilla(tamaño), espacioGrilla(espacio){}

void Grilla::dibujar() const
{
    glColor3f(1.0f, 1.0f, 1.0f);

    // Empieza a dibujar líneas
    glBegin(GL_LINES);

    // Líneas verticales
    for (int i = -tamañoGrilla; i <= tamañoGrilla; ++i) {
        glVertex2f(i * espacioGrilla, -tamañoGrilla * espacioGrilla);
        glVertex2f(i * espacioGrilla, tamañoGrilla * espacioGrilla);
    }

    // Líneas horizontales
    for (int i = -tamañoGrilla; i <= tamañoGrilla; ++i) {
        glVertex2f(-tamañoGrilla * espacioGrilla, i * espacioGrilla);
        glVertex2f(tamañoGrilla * espacioGrilla, i * espacioGrilla);
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
    return (2.0f * x/viewport[2]) - 1.0f;
}

float Grilla::PantallauniversalY(int y) const
{
    int viewport[4];
    glGetIntegerv(GL_VIEWPORT, viewport);
    return 1.0f - (2.0f * y / viewport[3]);
}
