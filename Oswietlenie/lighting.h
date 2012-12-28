#ifndef LIGHTING_H
#define LIGHTING_H

#include <QGLWidget>
#include <QTimer>

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

private slots:
    void rotate();

private:
    QTimer _rotate_timer;
    float _camera_angle;
    float _angle;
};

#endif // LIGHTING_H
