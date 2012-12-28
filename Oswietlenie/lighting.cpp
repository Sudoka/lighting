#include "lighting.h"
#include <GL/glu.h>

Lighting::Lighting(QGLWidget *parent)
    : QGLWidget(parent),
    _camera_angle(0.0f),
    _angle(0.0f)
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

    GLfloat ambientColor[] = {0.4f, 0.2f, 0.4f, 1.0f};
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor);

    GLfloat lightColor0[] = {0.6f, 0.6f, 0.6f, 1.0f};
    GLfloat lightPosition0[] = {4.0f, 0.0f, 8.0f, 1.0f};
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor0);
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition0);

    GLfloat lightColor1[] = {0.5f, 0.2f, 0.2f, 1.0f};
    GLfloat lightPosition1[] = {-1.0f, 0.5f, 0.5f, 0.0f};
    glLightfv(GL_LIGHT1, GL_DIFFUSE, lightColor1);
    glLightfv(GL_LIGHT1, GL_POSITION, lightPosition1);

    glTranslatef(0.0f, 0.0f, -10.0f);
    glRotatef(_angle, 1.0f, 1.0f, 0.0f);
    glColor3f(1.0f, 1.0f, 0.0f);
    glBegin(GL_QUADS);

    glNormal3f(0.0f, 0.0f, 1.0f);
    glVertex3f(-1.5f, -1.0f, 1.5f);
    glVertex3f(1.5f, -1.0f, 1.5f);
    glVertex3f(1.5f, 1.0f, 1.5f);
    glVertex3f(-1.5f, 1.0f, 1.5f);

    glNormal3f(1.0f, 0.0f, 0.0f);
    glVertex3f(1.5f, -1.0f, -1.5f);
    glVertex3f(1.5f, 1.0f, -1.5f);
    glVertex3f(1.5f, 1.0f, 1.5f);
    glVertex3f(1.5f, -1.0f, 1.5f);

    glNormal3f(0.0f, 0.0f, -1.0f);
    glVertex3f(-1.5f, -1.0f, -1.5f);
    glVertex3f(-1.5f, 1.0f, -1.5f);
    glVertex3f(1.5f, 1.0f, -1.5f);
    glVertex3f(1.5f, -1.0f, -1.5f);

    glNormal3f(-1.0f, 0.0f, 0.0f);
    glVertex3f(-1.5f, -1.0f, -1.5f);
    glVertex3f(-1.5f, -1.0f, 1.5f);
    glVertex3f(-1.5f, 1.0f, 1.5f);
    glVertex3f(-1.5f, 1.0f, -1.5f);

    glEnd();

    swapBuffers();
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
    updateGL();
}
