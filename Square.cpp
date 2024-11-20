#include <windows.h>
#include <GL/glut.h>

void display() {
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // RGB background color
  //glOrtho(-4, 4, -4, 4, -4, 4); // first two value x,y,z
  gluOrtho2D(0, 400, 0, 400);
  glClear(GL_COLOR_BUFFER_BIT); // clear screen

  // glBegin(GL_QUADS);
  // glColor3f(1.0f, 0.0f, 0.0f); // polygon color ---- rang: 3f(0-1); 3ub(0-255)
  // glVertex2f(-2.0f, -2.0f);
  // glVertex2f(2.0f, -2.0f);
  // glVertex2f(2.0f, 2.0f);
  //glVertex2f(-2.0f, 2.0f);  
  glBegin(GL_QUADS);
  glColor3f(1.0f, 1.0f, 1.0f);
  glVertex2d(100, 100);
  glVertex2d(300, 100);
  glVertex2d(300, 300);
  glVertex2d(100, 300);
  glEnd();

  glBegin(GL_QUADS);
  glColor3f(0.0f, 0.0f, 0.1f);
  glVertex2d(175, 100);
  glVertex2d(225, 100);
  glVertex2d(225, 250);
  glVertex2d(175, 250);
  glEnd();

  glBegin(GL_QUADS);
  glColor3f(0.2f, 0.0f, 0.1f);
  glVertex2d(120, 180);
  glVertex2d(155, 180);
  glVertex2d(155, 230);
  glVertex2d(120, 230);
  glEnd();

  glBegin(GL_QUADS);
  glColor3f(0.2f, 0.0f, 0.1f);
  glVertex2d(245, 180);
  glVertex2d(280, 180);
  glVertex2d(280, 230);
  glVertex2d(245, 230);
  glEnd();

  glBegin(GL_TRIANGLES);
  glColor3f(0.7f, 0.5f, 0.8f);
  glVertex2d(100, 300);
  glVertex2d(300, 300);
  glVertex2d(200, 400);

  glEnd();

  glFlush();
}

int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutCreateWindow("Simple Square");
  glutInitWindowSize(320, 320);
  glutInitWindowPosition(50, 50);
  glutDisplayFunc(display);
  glutMainLoop();

  return 0;
}