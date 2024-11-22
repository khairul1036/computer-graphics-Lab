#include <windows.h>
#include <GL/glut.h>

void adnan() {
    //ceiling
    glBegin(GL_POLYGON);
    glColor3f(0.925f, 0.937f, 0.62f);
    glVertex2d(0, 1013);
    glVertex2d(1248, 878);
    glVertex2d(1920, 986);
    glVertex2d(1920, 1080);
    glVertex2d(0, 1080);
    glEnd();
    //floor
    glBegin(GL_POLYGON);
    glColor3f(0.839f, 0.337f, 0.333f);
    glVertex2d(0, 0);
    glVertex2d(1920, 0);
    glVertex2d(1920, 364);
    glVertex2d(1248, 472);
    glVertex2d(0, 270);
    glEnd();
    //deal1
    glBegin(GL_POLYGON);
    glColor3f(0.945f, 0.6f, 0.451f);
    glVertex2d(0, 1013);
    glVertex2d(1248, 878);
    glVertex2d(1248, 472);
    glVertex2d(0, 270);
    glEnd();
    //deal2
    glBegin(GL_POLYGON);
    glColor3f(0.945f, 0.82f, 0.478f);
    glVertex2d(1920, 364);
    glVertex2d(1248, 472);
    glVertex2d(1248, 878);
    glVertex2d(1920, 986);
    glEnd();

    //windo-sky
    glBegin(GL_POLYGON);
    glColor3f(0.62f, 0.863f, 0.961f);
    glVertex2d(1363, 726);
    glVertex2d(1550, 742);
    glVertex2d(1550, 540);
    glVertex2d(1363, 560);
    glEnd();

}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    adnan();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);

    glutInitWindowSize(1920, 1080);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("212-15-4155");
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    gluOrtho2D(0, 1920, 0, 1080);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
