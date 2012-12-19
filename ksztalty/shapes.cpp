#include "shapes.h"
#include "ui_shapes.h"

#include <GL/glu.h>

Shapes::Shapes(QWidget *parent) :
    QGLWidget(parent)
{
}

Shapes::~Shapes()
{
}

void Shapes::initializeGL()
{
    glEnable(GL_DEPTH_TEST);
}

void Shapes::resizeGL(int w, int h)
{
    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();
    gluPerspective(45.0,
                   (double)w / (double)h,
                   1.0,
                   10.0);
}

void Shapes::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glBegin(GL_QUADS);
    glVertex3f(-0.2f, -1.5f, -5.0f);
    glVertex3f(0.2f, -1.5f, -5.0f);
    glVertex3f(0.2f, -0.5f, -5.0f);
    glVertex3f(-0.2f, -0.5f, -5.0f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex3f(0.5f, 0.5f, -5.0f);
    glVertex3f(1.5f, 0.5f, -5.0f);
    glVertex3f(0.5f, 1.0f, -5.0f);

    glVertex3f(0.5f, 1.0f, -5.0f);
    glVertex3f(1.5f, 1.0f, -5.0f);
    glVertex3f(1.0f, 1.5f, -5.0f);

    glVertex3f(0.5f, -0.5f, -5.0f);
    glVertex3f(1.0f, -1.5f, -5.0f);
    glVertex3f(1.5f, -0.5f, -5.0f);
    glEnd();

    swapBuffers();
}

