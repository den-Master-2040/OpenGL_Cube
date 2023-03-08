#ifndef GLVIEW_H
#define GLVIEW_H

#include <QWidget>
#include <QtOpenGL>

QT_BEGIN_NAMESPACE
namespace Ui { class glView; }
QT_END_NAMESPACE

class glView : public QGLWidget
{
    Q_OBJECT

public:
    glView(QWidget *parent = nullptr);
    ~glView();
private:
    Ui::glView *ui;
    float xRot, yRot, zRot;
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;
    void mousePressEvent(QMouseEvent *event)override;
    void mouseMoveEvent(QMouseEvent *event)override;
    void drawCube(float a);
    QPoint mPos;
};
#endif // GLVIEW_H
