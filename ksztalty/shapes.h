#ifndef SHAPES_H
#define SHAPES_H

#include <QtOpenGL>

class Shapes : public QGLWidget
{
    Q_OBJECT
    QTimer _rotate_timer;
    float _angle;
    float _camera_angle;
    
private slots:
    void rotate();

public:
    explicit Shapes(QWidget *parent = 0);
    ~Shapes();

protected:
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();
    
};

#endif // SHAPES_H
