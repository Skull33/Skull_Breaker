#include <GL/glut.h>
#include <D:/SkullBreaker/Skull Breaker/Grilla.h>

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

}
