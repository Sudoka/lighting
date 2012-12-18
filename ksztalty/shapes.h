#ifndef SHAPES_H
#define SHAPES_H

#include <QtOpenGL>

class Shapes : public QGLWidget
{
    Q_OBJECT
    
public:
    explicit Shapes(QWidget *parent = 0);
    ~Shapes();

protected:
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();
    
};

#endif // SHAPES_H
