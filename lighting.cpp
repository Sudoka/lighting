#include "lighting.h"
#include <GL/glu.h>
#include <QKeyEvent>

Lighting::Lighting(QGLWidget *parent)
    : QGLWidget(parent),
    _camera_angle(0.0f),
    _angle(0.0f),
    _light_position(0.0f),
    _light_inc(0.01f)
{
    connect(&_rotate_timer, SIGNAL(timeout()), this, SLOT(rotate()));
    _rotate_timer.start(30);
}

Lighting::~Lighting()
{
    
}

void Lighting::initializeGL()
{
    _ligting = true;
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
    glEnable(GL_LIGHT2);

    glShadeModel(GL_SMOOTH);
}

void Lighting::resizeGL(int w, int h)
{
    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();
    gluPerspective(45.0,
                   (double)w / (double)h,
                   0.5,
                   200.0);
}

void Lighting::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    //glRotatef(-_camera_angle, 0.0f, 0.0f, 1.0f);

    GLfloat ambientColor[] = {0.5f, 0.5f, 0.5f, 1.0f};
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor);

    GLfloat lightColor0[] = {1.0f, 0.0f, 0.0f, 1.0f};
    GLfloat lightPosition0[] = {4.0f, 0.0f, 8.0f, 1.0f};
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor0);
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition0);

    GLfloat lightColor1[] = {0.0f, 0.0f, 1.0f, 1.0f};
    GLfloat lightPosition1[] = {-1.0f, 0.5f, 0.5f, 0.0f};
    glLightfv(GL_LIGHT1, GL_DIFFUSE, lightColor1);
    glLightfv(GL_LIGHT1, GL_POSITION, lightPosition1);

    GLfloat lightColor2[] = {0.0f, 1.0f, 0.0f, 1.0f};
    GLfloat lightPosition2[] = {_light_position, 0.5f, 0.5f, 0.0f};
    glLightfv(GL_LIGHT2, GL_DIFFUSE, lightColor2);
    glLightfv(GL_LIGHT2, GL_POSITION, lightPosition2);

    glTranslatef(0.0f, 0.0f, -8.0f);
    glRotatef(_angle, 1.0f, 1.0f, 0.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);

    glNormal3f(-1.0f, 0.0f, 1.0f);
    glVertex3f(-1.5f, -1.0f, 1.5f);
    glNormal3f(1.0f, 0.0f, 1.0f);
    glVertex3f(1.5f, -1.0f, 1.5f);
    glNormal3f(1.0f, 0.0f, 1.0f);
    glVertex3f(1.5f, 1.0f, 1.5f);
    glNormal3f(-1.0f, 0.0f, 1.0f);
    glVertex3f(-1.5f, 1.0f, 1.5f);

    glNormal3f(1.0f, 0.0f, -1.0f);
    glVertex3f(1.5f, -1.0f, -1.5f);
    glNormal3f(1.0f, 0.0f, -1.0f);
    glVertex3f(1.5f, 1.0f, -1.5f);
    glNormal3f(1.0f, 0.0f, 1.0f);
    glVertex3f(1.5f, 1.0f, 1.5f);
    glNormal3f(1.0f, 0.0f, 1.0f);
    glVertex3f(1.5f, -1.0f, 1.5f);

    glNormal3f(-1.0f, 0.0f, -1.0f);
    glVertex3f(-1.5f, -1.0f, -1.5f);
    glNormal3f(-1.0f, 0.0f, -1.0f);
    glVertex3f(-1.5f, 1.0f, -1.5f);
    glNormal3f(1.0f, 0.0f, -1.0f);
    glVertex3f(1.5f, 1.0f, -1.5f);
    glNormal3f(1.0f, 0.0f, -1.0f);
    glVertex3f(1.5f, -1.0f, -1.5f);

    glNormal3f(-1.0f, 0.0f, -1.0f);
    glVertex3f(-1.5f, -1.0f, -1.5f);
    glNormal3f(-1.0f, 0.0f, 1.0f);
    glVertex3f(-1.5f, -1.0f, 1.5f);
    glNormal3f(-1.0f, 0.0f, 1.0f);
    glVertex3f(-1.5f, 1.0f, 1.5f);
    glNormal3f(-1.0f, 0.0f, -1.0f);
    glVertex3f(-1.5f, 1.0f, -1.5f);

    glEnd();

    swapBuffers();
}

void Lighting::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_L:
        if (_ligting) {
            glDisable(GL_LIGHT0);
            glDisable(GL_LIGHT1);
            _ligting = false;
        } else {
            glEnable(GL_LIGHT0);
            glEnable(GL_LIGHT1);
            _ligting = true;
        }
        break;
    }
}

void Lighting::rotate()
{
    _camera_angle += 1.0f;
    if (_camera_angle > 360) {
        _camera_angle -= 360;
    }
    _angle += 1.0f;
    if (_angle > 360) {
        _angle -= 360;
    }

    _light_position += _light_inc;
    if (_light_position > 6 || _light_position < -6) {
        _light_inc = -_light_inc;
    }
    updateGL();
}
