#include <GL/glut.h>
#include <D:/SkullBreaker/Skull Breaker/Grilla.h>

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

}
