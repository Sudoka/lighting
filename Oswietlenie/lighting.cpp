#include "lighting.h"
#include <GL/glu.h>

Lighting::Lighting(QGLWidget *parent)
    : QGLWidget(parent),
    _camera_angle(0.0f)
{
    connect(&_rotate_timer, SIGNAL(timeout()), this, SLOT(rotate()));
    _rotate_timer.start(30);
}

Lighting::~Lighting()
{
    
}

void Lighting::initializeGL()
{
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
}

void Lighting::resizeGL(int w, int h)
{
    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();
    gluPerspective(45.0,
                   (double)w / (double)h,
                   1.0,
                   200.0);
}

void Lighting::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRotatef(-_camera_angle, 0.0f, 0.0f, 1.0f);

    swapBuffers();
}
