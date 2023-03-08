#include "glview.h"
#include "ui_glview.h"
#include <algorithm>
glView::glView(QWidget *parent)
    : QGLWidget(parent)
{
    setWindowTitle("My Firts OpenGL window!");
    setGeometry(400,200, 800, 600);
}

void glView::initializeGL()
{
    glEnable(GL_DEPTH_TEST);
}

void glView::resizeGL(int w, int h)
{
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-1,1,-1,1,1,20);
}

void glView::paintGL()
{
    glClearColor(0,0,0,1);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glTranslatef(0,0,-3);
    glRotatef(xRot,1,0,0);
    glRotatef(yRot,0,1,0);

    drawCube(0.6);
}

void glView::drawCube(float a)
{
    float ver_cub[] =
    {
        -a,-a, a,      a,-a, a,    a, a, a,     -a, a, a,
         a,-a,-a,     -a,-a,-a,   -a, a,-a,      a, a,-a,
        -a,-a,-a,     -a,-a, a,   -a, a, a,     -a, a,-a,
         a,-a, a,      a,-a,-a,    a, a,-a,      a, a, a,
        -a,-a, a,      a,-a, a,    a,-a,-a,     -a,-a,-a,
        -a, a, a,      a, a, a,    a, a,-a,     -a, a,-a
    };

    float color_arr[] =
    {
        1,0,0,   1,0,0,   1,0,0,   1,0,0,
        0,0,1,   0,0,1,   0,0,1,   0,0,1,
        1,1,0,   1,1,0,   1,1,0,   1,1,0,
        0,1,1,   0,1,1,   0,1,1,   0,1,1,
        1,0,1,   1,0,1,   1,0,1,   1,0,1,
        1, 0.5,0.5,   1, 0.5,0.5,    1, 0.5,0.5,    1, 0.5,0.5
    };

    glVertexPointer(3,GL_FLOAT, 0,&ver_cub);
    glEnableClientState(GL_VERTEX_ARRAY);

    glColorPointer(3,GL_FLOAT, 0,&color_arr);
    glEnableClientState(GL_COLOR_ARRAY);

        glDrawArrays(GL_QUADS, 0, 24);

    glDisableClientState(GL_COLOR_ARRAY);
    glDisableClientState(GL_VERTEX_ARRAY);
}

void glView::mousePressEvent(QMouseEvent *mo)
{
    mPos = mo->pos();
}

void glView::mouseMoveEvent(QMouseEvent *mo)
{
    xRot += 1 / M_PI * std::abs(mo->pos().y() - mPos.y());
    yRot += 1 / M_PI * (mo->pos().x() - mPos.x());

    mPos = mo->pos();

    updateGL();
}

glView::~glView()
{

}

