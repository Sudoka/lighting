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

private slots:
    void rotate();

private:
    QTimer _rotate_timer;
    float _angle;
    float _camera_angle;
    
};

#endif // SHAPES_H
