#include "shapes.h"
#include "ui_shapes.h"

#include <GL/glu.h>

Shapes::Shapes(QWidget *parent) :
    QGLWidget(parent),
    _angle(10.0f),
    _camera_angle(5.0f)
{
    connect(&_rotate_timer, SIGNAL(timeout()), this, SLOT(rotate()));
    _rotate_timer.start(25);
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
    glRotatef(-_camera_angle, 0.0f, 0.0f, 1.0f);
    glTranslatef(0.0f, 0.0f, -5.0f);

    glPushMatrix();
    glTranslatef(0.0f, -1.0f, 0.0f);
    glRotatef(_angle * 2.0, 0.0f, 0.0f, 1.0f);

    glBegin(GL_QUADS);
    glVertex3f(-0.2f, -0.5f, 0.0f);
    glVertex3f(0.2f, -0.5f, 0.0f);
    glVertex3f(0.2f, 0.5f, 0.0f);
    glVertex3f(-0.2f, 0.5f, 0.0f);
    glEnd();

    glPopMatrix();
    glPushMatrix();
    glTranslatef(1.0f, 1.0f, 0.0f);
    glRotatef(_angle, 0.0f, 1.0f, 0.0f);
    glScalef(0.9f, 0.9f, 0.9f);

    glBegin(GL_TRIANGLES);
    glVertex3f(-0.5f, -0.5f, 0.0f);
    glVertex3f(0.5f, -0.5f, 0.0f);
    glVertex3f(-0.5f, 0.0f, 0.0f);

    glVertex3f(-0.5f, 0.0f, 0.0f);
    glVertex3f(0.5f, 0.0f, 0.0f);
    glVertex3f(0.0f, 0.5f, 0.0f);
    glEnd();

    glPopMatrix();
    glPushMatrix();
    glTranslatef(1.0f, -1.0f, 0.0f);
    glRotatef(_angle * 0.5, 0.0f, 1.0f, 0.0f);

    glBegin(GL_TRIANGLES);
    glVertex3f(0.5f, 0.5f, 0.0f);
    glVertex3f(0.0f, -0.5f, 0.0f);
    glVertex3f(-0.5f, 0.5f, 0.0f);
    glEnd();

    glPopMatrix();

    glBegin(GL_LINES);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(2.0f, 0.0f, 0.0f);

    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 2.0f, 0.0f);

    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(-2.0f, 0.0f, 0.0f);

    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, -2.0f, 0.0f);
    glEnd();

    swapBuffers();
}



void Shapes::rotate()
{
    _angle += 2.0f;
    if (_angle > 360) {
        _angle -= 360;
    }

    _camera_angle += 1.0f;
    if (_camera_angle > 360) {
        _camera_angle -= 360;
    }

    updateGL();
}
