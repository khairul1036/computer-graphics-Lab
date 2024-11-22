#include <windows.h>
#include <GL/glut.h>
#include <cmath>

void drawCircle(float cx, float cy, float radius, float r, float g, float b) {
    glColor3f(r, g, b); // Set circle color
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx, cy); // Center of the circle
    for (int i = 0; i <= 100; ++i) {
        float angle = i * 2.0f * M_PI / 100; // Divide circle into 100 segments
        float x = cx + cos(angle) * radius;
        float y = cy + sin(angle) * radius;
        glVertex2f(x, y);
    }
    glEnd();
}

// void drawCircle(float cx, float cy, float radius, float r, float g, float b) {
//     glColor3f(r, g, b); // Set circle color

//     int x = 0;
//     int y = radius;
//     int d = 1 - radius;

//     glBegin(GL_TRIANGLE_FAN);
//     glVertex2f(cx, cy); // Center of the circle

//     while (x <= y) {
//         // Draw the 8 symmetric points of the circle
//         glVertex2f(cx + x, cy + y); // Point 1
//         glVertex2f(cx - x, cy + y); // Point 2
//         glVertex2f(cx + x, cy - y); // Point 3
//         glVertex2f(cx - x, cy - y); // Point 4
//         glVertex2f(cx + y, cy + x); // Point 5
//         glVertex2f(cx - y, cy + x); // Point 6
//         glVertex2f(cx + y, cy - x); // Point 7
//         glVertex2f(cx - y, cy - x); // Point 8

//         // Update decision parameter and coordinates
//         if (d < 0) {
//             x++;
//             d += 2 * x + 1;
//         }
//         else {
//             x++;
//             y--;
//             d += 2 * x - 2 * y + 1;
//         }
//     }
//     glEnd();
// }


void drawSchool() {

    //school- green ground
    glBegin(GL_POLYGON);
    glColor3f(0.004f, 0.502f, 0.004f);
    glVertex2d(0, 0);
    glVertex2d(1920, 0);
    glVertex2d(1920, 600);
    glVertex2d(0, 600);
    glEnd();

    //school- full base body
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.647f, 0.29f);
    glVertex2d(200, 550);
    glVertex2d(1700, 550);
    glVertex2d(1700, 850);
    glVertex2d(200, 850);
    glEnd();
    //school- full base body border
    glLineWidth(1.0f); // Set the line thickness
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2d(200, 550);
    glVertex2d(1700, 550);
    glVertex2d(1700, 850);
    glVertex2d(200, 850);
    glEnd();

    //school- main building
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.647f, 0.29f);
    glVertex2d(700, 500);
    glVertex2d(1200, 500);
    glVertex2d(1200, 860);
    glVertex2d(700, 860);
    glEnd();
    //school- main building border
    glLineWidth(1.0f); // Set the line thickness
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2d(700, 500);
    glVertex2d(1200, 500);
    glVertex2d(1200, 860);
    glVertex2d(700, 860);
    glEnd();

    //school- left side building
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.647f, 0.29f);
    glVertex2d(100, 500);
    glVertex2d(400, 500);
    glVertex2d(400, 840);
    glVertex2d(250, 1050);
    glVertex2d(100, 840);
    glEnd();
    //school- left side building border
    glLineWidth(1.0f); // Set the line thickness
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2d(100, 500);
    glVertex2d(400, 500);
    glVertex2d(400, 840);
    glVertex2d(250, 1050);
    glVertex2d(100, 840);
    glEnd();

    //school- right side building
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.647f, 0.29f);
    glVertex2d(1500, 500);
    glVertex2d(1800, 500);
    glVertex2d(1800, 840);
    glVertex2d(1650, 1050);
    glVertex2d(1500, 840);
    glEnd();
    //school- right side building border
    glLineWidth(1.0f); // Set the line thickness
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2d(1500, 500);
    glVertex2d(1800, 500);
    glVertex2d(1800, 840);
    glVertex2d(1650, 1050);
    glVertex2d(1500, 840);
    glEnd();

    // //road background
    // glBegin(GL_POLYGON);
    // glColor3f(0.3f, 0.3f, 0.3f);
    // glVertex2d(0, 0);
    // glVertex2d(1920, 0);
    // glVertex2d(1920, 150);
    // glVertex2d(0, 150);
    // glEnd();
    // //road lane divider lines
    // glLineWidth(5.0f);
    // glColor3f(1.0f, 1.0f, 1.0f);
    // glBegin(GL_LINES);
    // for (int x = 50; x < 1920; x += 100) {
    //     glVertex2d(x, 75);
    //     glVertex2d(x + 50, 75);
    // }
    // glEnd();

    // // Walk road on the right side
    // glBegin(GL_POLYGON);
    // glColor3f(0.6f, 0.6f, 0.6f); // Light gray for the walk road
    // glVertex2d(0, 150);
    // glVertex2d(1920, 150);
    // glVertex2d(1920, 200);
    // glVertex2d(0, 200);
    // glEnd();

}

void drawRoad() {
    // Road background
    glBegin(GL_POLYGON);
    glColor3f(0.3f, 0.3f, 0.3f); // Dark gray for the road
    glVertex2d(0, 0);
    glVertex2d(1920, 0);
    glVertex2d(1920, 150);
    glVertex2d(0, 150);
    glEnd();

    // Road lane divider lines
    glLineWidth(5.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_LINES);
    for (int x = 50; x < 1920; x += 100) {
        glVertex2d(x, 75);
        glVertex2d(x + 50, 75);
    }
    glEnd();
}

void drawWalkRoad() {
    // Walk road on the right side
    glBegin(GL_POLYGON);
    glColor3f(0.6f, 0.6f, 0.6f); // Light gray for the walk road
    glVertex2d(0, 150);
    glVertex2d(1920, 150);
    glVertex2d(1920, 200);
    glVertex2d(0, 200);
    glEnd();
}

void drawZebraCrossing() {
    glColor3f(1.0f, 1.0f, 1.0f); // White stripes
    for (int x = 600; x <= 800; x += 20) { // Stripes in the center
        glBegin(GL_POLYGON);
        glVertex2d(x, 0);
        glVertex2d(x + 10, 0);
        glVertex2d(x + 10, 150);
        glVertex2d(x, 150);
        glEnd();
    }
}

void drawTrafficLight() {
    // Traffic light pole
    glBegin(GL_POLYGON);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2d(850, 150);
    glVertex2d(860, 150);
    glVertex2d(860, 280);
    glVertex2d(850, 280);
    glEnd();

    // Traffic light box
    glBegin(GL_POLYGON);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2d(840, 280);
    glVertex2d(870, 280);
    glVertex2d(870, 350);
    glVertex2d(840, 350);
    glEnd();

    // Red light
    drawCircle(855, 340, 10, 1.0f, 0.0f, 0.0f); // Red circle (center at x=855, y=340, radius=10)

    // Yellow light
    drawCircle(855, 315, 10, 1.0f, 1.0f, 0.0f); // Yellow circle (center at x=855, y=315, radius=10)

    // Green light
    drawCircle(855, 290, 10, 0.0f, 1.0f, 0.0f); // Green circle (center at x=855, y=290, radius=10)
}

void drawBus(float x) {
    float y = 50;
    // Bus body
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex2f(x, y);
    glVertex2f(x + 300, y);
    glVertex2f(x + 300, y + 120);
    glVertex2f(x, y + 120);
    glEnd();

    // Bus roof
    glBegin(GL_POLYGON);
    glColor3f(0.8f, 0.2f, 0.2f);
    glVertex2f(x, y + 120);
    glVertex2f(x + 300, y + 120);
    glVertex2f(x + 280, y + 140);
    glVertex2f(x + 20, y + 140);
    glEnd();

    // Windows
    glColor3f(0.8f, 0.9f, 1.0f);
    for (int i = 0; i < 3; i++) {
        glBegin(GL_POLYGON);
        glVertex2f(x + 20 + i * 70, y + 60);
        glVertex2f(x + 60 + i * 70, y + 60);
        glVertex2f(x + 60 + i * 70, y + 110);
        glVertex2f(x + 20 + i * 70, y + 110);
        glEnd();
    }

    // Bus door frame
    glBegin(GL_POLYGON);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex2f(x + 240, y);
    glVertex2f(x + 290, y);
    glVertex2f(x + 290, y + 100);
    glVertex2f(x + 240, y + 100);
    glEnd();

    // Bus door glass
    glBegin(GL_POLYGON);
    glColor3f(0.6f, 0.8f, 1.0f);
    glVertex2f(x + 245, y + 5);
    glVertex2f(x + 285, y + 5);
    glVertex2f(x + 285, y + 95);
    glVertex2f(x + 245, y + 95);
    glEnd();

    // Door handle
    glLineWidth(2.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glVertex2f(x + 275, y + 50);
    glVertex2f(x + 280, y + 50);
    glEnd();

    // Wheels
    drawCircle(x + 60, y - 20, 25, 0.0f, 0.0f, 0.0f);   // Front wheel (black)
    drawCircle(x + 240, y - 20, 25, 0.0f, 0.0f, 0.0f);  // Rear wheel (black)

    // Wheel rims
    drawCircle(x + 60, y - 20, 10, 0.6f, 0.6f, 0.6f);   // Front wheel rim (gray)
    drawCircle(x + 240, y - 20, 10, 0.6f, 0.6f, 0.6f);  // Rear wheel rim (gray)
}

float x = 0;
void moveableBus() {
    x += 0.1;
    if (x > 1920) {
        x = -300;
    }
    glutPostRedisplay(); // redraw or repeat
}

void khairul() {
    drawSchool();
    drawRoad();
    drawWalkRoad();
    drawZebraCrossing();
    drawTrafficLight();
    drawBus(x);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    khairul();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);

    glutInitWindowSize(1920, 1080);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("School Scenario v1");
    glClearColor(0.7f, 0.9f, 1.0f, 1.0f);
    gluOrtho2D(0, 1920, 0, 1080);
    glutDisplayFunc(display);
    glutIdleFunc(moveableBus);
    glutMainLoop();
    return 0;
}
