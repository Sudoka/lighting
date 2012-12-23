#ifndef LIGHTING_H
#define LIGHTING_H

#include <QGLWidget>

class Lighting : public QGLWidget
{
    Q_OBJECT
    
public:
    Lighting(QGLWidget *parent = 0);
    ~Lighting();

protected:
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();
};

#endif // LIGHTING_H
