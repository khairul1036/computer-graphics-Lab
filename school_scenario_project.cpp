#include <windows.h>
#include <GL/glut.h>
#include <cmath>
#include <ctime>

void drawCircle(float cx, float cy, float radius, float r, float g, float b) {
    glColor3f(r, g, b); // Set circle color

    int x = 0;
    int y = radius;
    int d = 1 - radius;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx, cy); // Center of the circle

    while (x <= y) {
        // Draw the 8 symmetric points of the circle
        glVertex2f(cx + x, cy + y); // Point 1
        glVertex2f(cx - x, cy + y); // Point 2
        glVertex2f(cx + x, cy - y); // Point 3
        glVertex2f(cx - x, cy - y); // Point 4
        glVertex2f(cx + y, cy + x); // Point 5
        glVertex2f(cx - y, cy + x); // Point 6
        glVertex2f(cx + y, cy - x); // Point 7
        glVertex2f(cx - y, cy - x); // Point 8

        // Update decision parameter and coordinates
        if (d < 0) {
            x++;
            d += 2 * x + 1;
        }
        else {
            x++;
            y--;
            d += 2 * x - 2 * y + 1;
        }
    }
    glEnd();
}

void drawSun(float cx, float cy, int radius) {
    // Sun body
    drawCircle(cx, cy, radius, 1.0f, 1.0f, 0.0f);  // Draw the sun using the circle function

    // Sun rays
    glColor3f(1.0f, 1.0f, 0.0f); // Same yellow for the rays
    glBegin(GL_LINES);
    glVertex2f(cx + radius + 10, cy);
    glVertex2f(cx + radius + 30, cy);

    glVertex2f(cx - radius - 10, cy);
    glVertex2f(cx - radius - 30, cy);

    glVertex2f(cx, cy + radius + 10);
    glVertex2f(cx, cy + radius + 30);

    glVertex2f(cx, cy - radius - 10);
    glVertex2f(cx, cy - radius - 30);

    glVertex2f(cx + 0.707 * (radius + 10), cy + 0.707 * (radius + 10));
    glVertex2f(cx + 0.707 * (radius + 30), cy + 0.707 * (radius + 30));

    glVertex2f(cx - 0.707 * (radius + 10), cy + 0.707 * (radius + 10));
    glVertex2f(cx - 0.707 * (radius + 30), cy + 0.707 * (radius + 30));

    glVertex2f(cx + 0.707 * (radius + 10), cy - 0.707 * (radius + 10));
    glVertex2f(cx + 0.707 * (radius + 30), cy - 0.707 * (radius + 30));

    glVertex2f(cx - 0.707 * (radius + 10), cy - 0.707 * (radius + 10));
    glVertex2f(cx - 0.707 * (radius + 30), cy - 0.707 * (radius + 30));

    glEnd();
}

void drawCloud(float cx, float cy, float size) {
    drawCircle(cx, cy, size, 1.0f, 1.0f, 1.0f); // Center
    drawCircle(cx - size / 2, cy, size / 1.2, 1.0f, 1.0f, 1.0f); // Left
    drawCircle(cx + size / 2, cy, size / 1.2, 1.0f, 1.0f, 1.0f); // Right
    drawCircle(cx - size / 3, cy - size / 3, size / 1.5, 1.0f, 1.0f, 1.0f); // Bottom-left
    drawCircle(cx + size / 3, cy - size / 3, size / 1.5, 1.0f, 1.0f, 1.0f); // Bottom-right
}

void drawClouds() {
    drawCloud(100, 1000, 70);  // Cloud 1
    drawCloud(600, 950, 100); // Cloud 2
    drawCloud(1000, 850, 90); // Cloud 3
    drawCloud(1400, 900, 120); // Cloud 4
    drawCloud(1700, 950, 80); // Cloud 5
}

void drawSchool() {

    //school-  ground
    glBegin(GL_POLYGON);
    glColor3f(0.2f, 0.2f, 0.0f);
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

    //school- full base body
    glBegin(GL_POLYGON);
    glColor3f(0.918f, 0.0f, 0.004f);
    glVertex2d(200, 850);
    glVertex2d(1700, 850);
    glVertex2d(1700, 950);
    glVertex2d(200, 950);
    glEnd();
    //school- full base body border
    glLineWidth(2.0f); // Set the line thickness
    glBegin(GL_LINE_LOOP);
    glColor3f(0.604f, 0.0f, 0.004f);
    glVertex2d(200, 850);
    glVertex2d(1700, 850);
    glVertex2d(1700, 950);
    glVertex2d(200, 950);
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

    // school- main upper full
    glBegin(GL_POLYGON);
    glColor3f(0.918f, 0.0f, 0.004f);
    glVertex2d(695, 850);
    glVertex2d(1205, 850);
    glVertex2d(1100, 1000);
    glVertex2d(800, 1000);
    glEnd();
    // school- main upper full border
    glLineWidth(5.0f); // Set line thickness
    glColor3f(0.604f, 0.0f, 0.004f);
    glBegin(GL_LINE_LOOP);
    glVertex2d(695, 850);
    glVertex2d(1205, 850);
    glVertex2d(1100, 1000);
    glVertex2d(800, 1000);
    glEnd();

    //school- main building upper
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.647f, 0.29f);
    glVertex2d(800, 850);
    glVertex2d(1100, 850);
    glVertex2d(950, 1070);
    glEnd();
    //school- main building upper border-1
    glLineWidth(8.0f); // Set the line thickness
    glBegin(GL_LINE_LOOP);
    glColor3f(0.604f, 0.0f, 0.004f);
    glVertex2d(800, 850);
    glVertex2d(950, 1070);
    glEnd();
    //school- main building upper border-2
    glLineWidth(8.0f); // Set the line thickness
    glBegin(GL_LINE_LOOP);
    glColor3f(0.604f, 0.0f, 0.004f);
    glVertex2d(1100, 850);
    glVertex2d(950, 1070);
    glEnd();


    // Main Building Door rectangle
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.647f, 0.91f); // Brown color for the door
    glVertex2d(900, 500);
    glVertex2d(1000, 500);
    glVertex2d(1000, 650);
    glVertex2d(900, 650);
    glEnd();
    // Main Building Door border
    glLineWidth(5.0f); // Set line thickness
    glColor3f(0.4f, 0.2f, 0.0f);
    glBegin(GL_LINE_LOOP);
    glVertex2d(900, 500);
    glVertex2d(1000, 500);
    glVertex2d(1000, 650);
    glVertex2d(900, 650);
    glEnd();

    // Stairs - Step 1
    glBegin(GL_POLYGON);
    glColor3f(0.6f, 0.6f, 0.6f);
    glVertex2d(830, 520);
    glVertex2d(1080, 520);
    glVertex2d(1080, 550);
    glVertex2d(830, 550);
    glEnd();
    // Stairs - Step 1 border
    glLineWidth(1.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINE_LOOP);
    glVertex2d(830, 520);
    glVertex2d(1080, 520);
    glVertex2d(1080, 550);
    glVertex2d(830, 550);
    glEnd();

    // Stairs - Step 2
    glBegin(GL_POLYGON);
    glColor3f(0.7f, 0.7f, 0.7f);
    glVertex2d(820, 490);
    glVertex2d(1090, 490);
    glVertex2d(1090, 520);
    glVertex2d(820, 520);
    glEnd();
    // Stairs - Step 2 border
    glLineWidth(1.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINE_LOOP);
    glVertex2d(820, 490);
    glVertex2d(1090, 490);
    glVertex2d(1090, 520);
    glVertex2d(820, 520);
    glEnd();

    // Stairs - Step 3
    glBegin(GL_POLYGON);
    glColor3f(0.7f, 0.7f, 0.7f);
    glVertex2d(810, 460);
    glVertex2d(1100, 460);
    glVertex2d(1100, 490);
    glVertex2d(810, 490);
    glEnd();
    // Stairs - Step 3 border
    glLineWidth(1.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINE_LOOP);
    glVertex2d(810, 460);
    glVertex2d(1100, 460);
    glVertex2d(1100, 490);
    glVertex2d(810, 490);
    glEnd();

    // Stairs - road 
    glBegin(GL_POLYGON);
    glColor3f(0.4f, 0.4f, 0.4f);
    glVertex2d(750, 199);
    glVertex2d(1190, 199);
    glVertex2d(1100, 460);
    glVertex2d(810, 460);
    glEnd();
    // Stairs - road border
    glLineWidth(1.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINE_LOOP);
    glVertex2d(750, 199);
    glVertex2d(1190, 199);
    glVertex2d(1100, 460);
    glVertex2d(810, 460);
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
    //school- left side building upper border-1
    glLineWidth(8.0f); // Set the line thickness
    glBegin(GL_LINE_LOOP);
    glColor3f(0.604f, 0.0f, 0.004f);
    glVertex2d(100, 840);
    glVertex2d(250, 1050);
    glEnd();
    //school- left side building upper border-2
    glLineWidth(8.0f); // Set the line thickness
    glBegin(GL_LINE_LOOP);
    glColor3f(0.604f, 0.0f, 0.004f);
    glVertex2d(400, 840);
    glVertex2d(250, 1050);
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
    //school- right side building upper border-1
    glLineWidth(8.0f); // Set the line thickness
    glBegin(GL_LINE_LOOP);
    glColor3f(0.604f, 0.0f, 0.004f);
    glVertex2d(1500, 840);
    glVertex2d(1650, 1050);
    glEnd();
    //school- right side building upper border-2
    glLineWidth(8.0f); // Set the line thickness
    glBegin(GL_LINE_LOOP);
    glColor3f(0.604f, 0.0f, 0.004f);
    glVertex2d(1800, 840);
    glVertex2d(1650, 1050);
    glEnd();

    // main building divided line
    glLineWidth(5.0f);
    glColor3f(0.604f, 0.0f, 0.004f);
    glBegin(GL_POLYGON);
    glVertex2d(700, 680);
    glVertex2d(1200, 680);
    glVertex2d(1200, 690);
    glVertex2d(700, 690);
    glEnd();
    // main building divided line border
    glLineWidth(1.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINE_LOOP);
    glVertex2d(700, 680);
    glVertex2d(1200, 680);
    glVertex2d(1200, 690);
    glVertex2d(700, 690);
    glEnd();

    // left building divided line
    glLineWidth(5.0f);
    glColor3f(0.604f, 0.0f, 0.004f);
    glBegin(GL_POLYGON);
    glVertex2d(100, 680);
    glVertex2d(400, 680);
    glVertex2d(400, 690);
    glVertex2d(100, 690);
    glEnd();
    // left building divided line border
    glLineWidth(1.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINE_LOOP);
    glVertex2d(100, 680);
    glVertex2d(400, 680);
    glVertex2d(400, 690);
    glVertex2d(100, 690);
    glEnd();

    // right building divided line
    glLineWidth(5.0f);
    glColor3f(0.604f, 0.0f, 0.004f);
    glBegin(GL_POLYGON);
    glVertex2d(1500, 680);
    glVertex2d(1800, 680);
    glVertex2d(1800, 690);
    glVertex2d(1500, 690);
    glEnd();
    // right building divided line border
    glLineWidth(1.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINE_LOOP);
    glVertex2d(1500, 680);
    glVertex2d(1800, 680);
    glVertex2d(1800, 690);
    glVertex2d(1500, 690);
    glEnd();

    // main to right building divided line
    glLineWidth(5.0f);
    glColor3f(0.604f, 0.0f, 0.004f);
    glBegin(GL_POLYGON);
    glVertex2d(1200, 670);
    glVertex2d(1500, 670);
    glVertex2d(1500, 680);
    glVertex2d(1200, 680);
    glEnd();
    // main to right building divided line border
    glLineWidth(1.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINE_LOOP);
    glVertex2d(1200, 670);
    glVertex2d(1500, 670);
    glVertex2d(1500, 680);
    glVertex2d(1200, 680);
    glEnd();

    // left to main building divided line
    glLineWidth(5.0f);
    glColor3f(0.604f, 0.0f, 0.004f);
    glBegin(GL_POLYGON);
    glVertex2d(400, 670);
    glVertex2d(700, 670);
    glVertex2d(700, 680);
    glVertex2d(400, 680);
    glEnd();
    // left to main building divided line border
    glLineWidth(1.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINE_LOOP);
    glVertex2d(400, 670);
    glVertex2d(700, 670);
    glVertex2d(700, 680);
    glVertex2d(400, 680);
    glEnd();


    // start left building windows
    // bottom side
    // First window
    glBegin(GL_POLYGON);
    glColor3f(0.7f, 0.9f, 1.0f);
    glVertex2d(150, 550);
    glVertex2d(200, 550);
    glVertex2d(200, 630);
    glVertex2d(150, 630);
    glEnd();

    glLineWidth(2.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINE_LOOP);
    glVertex2d(150, 550);
    glVertex2d(200, 550);
    glVertex2d(200, 630);
    glVertex2d(150, 630);
    glEnd();

    glLineWidth(1.5f);
    glBegin(GL_LINES);
    glVertex2d(175, 550);
    glVertex2d(175, 630);
    glEnd();

    glBegin(GL_LINES);
    glVertex2d(150, 590);
    glVertex2d(200, 590);
    glEnd();

    // Second window
    glBegin(GL_POLYGON);
    glColor3f(0.7f, 0.9f, 1.0f);
    glVertex2d(280, 550);
    glVertex2d(330, 550);
    glVertex2d(330, 630);
    glVertex2d(280, 630);
    glEnd();

    glLineWidth(2.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINE_LOOP);
    glVertex2d(280, 550);
    glVertex2d(330, 550);
    glVertex2d(330, 630);
    glVertex2d(280, 630);
    glEnd();

    glLineWidth(1.5f);
    glBegin(GL_LINES);
    glVertex2d(305, 550);
    glVertex2d(305, 630);
    glEnd();

    glBegin(GL_LINES);
    glVertex2d(280, 590);
    glVertex2d(330, 590);
    glEnd();

    // top side
    // First window
    glBegin(GL_POLYGON);
    glColor3f(0.7f, 0.9f, 1.0f);
    glVertex2d(150, 720);
    glVertex2d(200, 720);
    glVertex2d(200, 800);
    glVertex2d(150, 800);
    glEnd();

    glLineWidth(2.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINE_LOOP);
    glVertex2d(150, 720);
    glVertex2d(200, 720);
    glVertex2d(200, 800);
    glVertex2d(150, 800);
    glEnd();

    glLineWidth(1.5f);
    glBegin(GL_LINES);
    glVertex2d(175, 720);
    glVertex2d(175, 800);
    glEnd();

    glBegin(GL_LINES);
    glVertex2d(150, 760);
    glVertex2d(200, 760);
    glEnd();

    // Second window
    glBegin(GL_POLYGON);
    glColor3f(0.7f, 0.9f, 1.0f);
    glVertex2d(280, 720);
    glVertex2d(330, 720);
    glVertex2d(330, 800);
    glVertex2d(280, 800);
    glEnd();

    glLineWidth(2.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINE_LOOP);
    glVertex2d(280, 720);
    glVertex2d(330, 720);
    glVertex2d(330, 800);
    glVertex2d(280, 800);
    glEnd();

    glLineWidth(1.5f);
    glBegin(GL_LINES);
    glVertex2d(305, 720);
    glVertex2d(305, 800);
    glEnd();

    glBegin(GL_LINES);
    glVertex2d(280, 760);
    glVertex2d(330, 760);
    glEnd();
    // end left building windows

    // start right building windows
    // Bottom side
    // First window
    glBegin(GL_POLYGON);
    glColor3f(0.7f, 0.9f, 1.0f);
    glVertex2d(1550, 550);
    glVertex2d(1600, 550);
    glVertex2d(1600, 630);
    glVertex2d(1550, 630);
    glEnd();

    glLineWidth(2.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINE_LOOP);
    glVertex2d(1550, 550);
    glVertex2d(1600, 550);
    glVertex2d(1600, 630);
    glVertex2d(1550, 630);
    glEnd();

    glLineWidth(1.5f);
    glBegin(GL_LINES);
    glVertex2d(1575, 550);
    glVertex2d(1575, 630);
    glEnd();

    glBegin(GL_LINES);
    glVertex2d(1550, 590);
    glVertex2d(1600, 590);
    glEnd();

    // Second window
    glBegin(GL_POLYGON);
    glColor3f(0.7f, 0.9f, 1.0f);
    glVertex2d(1680, 550);
    glVertex2d(1730, 550);
    glVertex2d(1730, 630);
    glVertex2d(1680, 630);
    glEnd();

    glLineWidth(2.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINE_LOOP);
    glVertex2d(1680, 550);
    glVertex2d(1730, 550);
    glVertex2d(1730, 630);
    glVertex2d(1680, 630);
    glEnd();

    glLineWidth(1.5f);
    glBegin(GL_LINES);
    glVertex2d(1705, 550);
    glVertex2d(1705, 630);
    glEnd();

    glBegin(GL_LINES);
    glVertex2d(1680, 590);
    glVertex2d(1730, 590);
    glEnd();

    // Top side
    // First window
    glBegin(GL_POLYGON);
    glColor3f(0.7f, 0.9f, 1.0f);
    glVertex2d(1550, 720);
    glVertex2d(1600, 720);
    glVertex2d(1600, 800);
    glVertex2d(1550, 800);
    glEnd();

    glLineWidth(2.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINE_LOOP);
    glVertex2d(1550, 720);
    glVertex2d(1600, 720);
    glVertex2d(1600, 800);
    glVertex2d(1550, 800);
    glEnd();

    glLineWidth(1.5f);
    glBegin(GL_LINES);
    glVertex2d(1575, 720);
    glVertex2d(1575, 800);
    glEnd();

    glBegin(GL_LINES);
    glVertex2d(1550, 760);
    glVertex2d(1600, 760);
    glEnd();

    // Second window
    glBegin(GL_POLYGON);
    glColor3f(0.7f, 0.9f, 1.0f);
    glVertex2d(1680, 720);
    glVertex2d(1730, 720);
    glVertex2d(1730, 800);
    glVertex2d(1680, 800);
    glEnd();

    glLineWidth(2.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINE_LOOP);
    glVertex2d(1680, 720);
    glVertex2d(1730, 720);
    glVertex2d(1730, 800);
    glVertex2d(1680, 800);
    glEnd();

    glLineWidth(1.5f);
    glBegin(GL_LINES);
    glVertex2d(1705, 720);
    glVertex2d(1705, 800);
    glEnd();

    glBegin(GL_LINES);
    glVertex2d(1680, 760);
    glVertex2d(1730, 760);
    glEnd();
    // end right building windows

    // start left to main building windows
    // Bottom side
    // First window (450 to 500)
    glBegin(GL_POLYGON);
    glColor3f(0.7f, 0.9f, 1.0f);
    glVertex2d(450, 560);
    glVertex2d(500, 560);
    glVertex2d(500, 640);
    glVertex2d(450, 640);
    glEnd();

    glLineWidth(2.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINE_LOOP);
    glVertex2d(450, 560);
    glVertex2d(500, 560);
    glVertex2d(500, 640);
    glVertex2d(450, 640);
    glEnd();

    glLineWidth(1.5f);
    glBegin(GL_LINES);
    glVertex2d(475, 560);
    glVertex2d(475, 640);
    glEnd();

    glBegin(GL_LINES);
    glVertex2d(450, 600);
    glVertex2d(500, 600);
    glEnd();

    // Second window (580 to 630)
    glBegin(GL_POLYGON);
    glColor3f(0.7f, 0.9f, 1.0f);
    glVertex2d(580, 560);
    glVertex2d(630, 560);
    glVertex2d(630, 640);
    glVertex2d(580, 640);
    glEnd();

    glLineWidth(2.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINE_LOOP);
    glVertex2d(580, 560);
    glVertex2d(630, 560);
    glVertex2d(630, 640);
    glVertex2d(580, 640);
    glEnd();

    glLineWidth(1.5f);
    glBegin(GL_LINES);
    glVertex2d(605, 560);
    glVertex2d(605, 640);
    glEnd();

    glBegin(GL_LINES);
    glVertex2d(580, 600);
    glVertex2d(630, 600);
    glEnd();

    // Top side
    // First window (450 to 500)
    glBegin(GL_POLYGON);
    glColor3f(0.7f, 0.9f, 1.0f);
    glVertex2d(450, 720);
    glVertex2d(500, 720);
    glVertex2d(500, 800);
    glVertex2d(450, 800);
    glEnd();

    glLineWidth(2.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINE_LOOP);
    glVertex2d(450, 720);
    glVertex2d(500, 720);
    glVertex2d(500, 800);
    glVertex2d(450, 800);
    glEnd();

    glLineWidth(1.5f);
    glBegin(GL_LINES);
    glVertex2d(475, 720);
    glVertex2d(475, 800);
    glEnd();

    glBegin(GL_LINES);
    glVertex2d(450, 760);
    glVertex2d(500, 760);
    glEnd();

    // Second window (580 to 630)
    glBegin(GL_POLYGON);
    glColor3f(0.7f, 0.9f, 1.0f);
    glVertex2d(580, 720);
    glVertex2d(630, 720);
    glVertex2d(630, 800);
    glVertex2d(580, 800);
    glEnd();

    glLineWidth(2.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINE_LOOP);
    glVertex2d(580, 720);
    glVertex2d(630, 720);
    glVertex2d(630, 800);
    glVertex2d(580, 800);
    glEnd();

    glLineWidth(1.5f);
    glBegin(GL_LINES);
    glVertex2d(605, 720);
    glVertex2d(605, 800);
    glEnd();

    glBegin(GL_LINES);
    glVertex2d(580, 760);
    glVertex2d(630, 760);
    glEnd();
    // end left to main building windows

    // start main to right building windows
// Bottom side
// First window (1250 to 1300)
    glBegin(GL_POLYGON);
    glColor3f(0.7f, 0.9f, 1.0f);
    glVertex2d(1250, 560);
    glVertex2d(1300, 560);
    glVertex2d(1300, 640);
    glVertex2d(1250, 640);
    glEnd();

    glLineWidth(2.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINE_LOOP);
    glVertex2d(1250, 560);
    glVertex2d(1300, 560);
    glVertex2d(1300, 640);
    glVertex2d(1250, 640);
    glEnd();

    glLineWidth(1.5f);
    glBegin(GL_LINES);
    glVertex2d(1275, 560);
    glVertex2d(1275, 640);
    glEnd();

    glBegin(GL_LINES);
    glVertex2d(1250, 600);
    glVertex2d(1300, 600);
    glEnd();

    // Second window (1380 to 1430)
    glBegin(GL_POLYGON);
    glColor3f(0.7f, 0.9f, 1.0f);
    glVertex2d(1380, 560);
    glVertex2d(1430, 560);
    glVertex2d(1430, 640);
    glVertex2d(1380, 640);
    glEnd();

    glLineWidth(2.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINE_LOOP);
    glVertex2d(1380, 560);
    glVertex2d(1430, 560);
    glVertex2d(1430, 640);
    glVertex2d(1380, 640);
    glEnd();

    glLineWidth(1.5f);
    glBegin(GL_LINES);
    glVertex2d(1405, 560);
    glVertex2d(1405, 640);
    glEnd();

    glBegin(GL_LINES);
    glVertex2d(1380, 600);
    glVertex2d(1430, 600);
    glEnd();

    // Top side
    // First window (1350 to 1100)
    glBegin(GL_POLYGON);
    glColor3f(0.7f, 0.9f, 1.0f);
    glVertex2d(1250, 720);
    glVertex2d(1300, 720);
    glVertex2d(1300, 800);
    glVertex2d(1250, 800);
    glEnd();

    glLineWidth(2.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINE_LOOP);
    glVertex2d(1250, 720);
    glVertex2d(1300, 720);
    glVertex2d(1300, 800);
    glVertex2d(1250, 800);
    glEnd();

    glLineWidth(1.5f);
    glBegin(GL_LINES);
    glVertex2d(1275, 720);
    glVertex2d(1275, 800);
    glEnd();

    glBegin(GL_LINES);
    glVertex2d(1250, 760);
    glVertex2d(1300, 760);
    glEnd();

    // Second window (1180 to 1230)
    glBegin(GL_POLYGON);
    glColor3f(0.7f, 0.9f, 1.0f);
    glVertex2d(1380, 720);
    glVertex2d(1430, 720);
    glVertex2d(1430, 800);
    glVertex2d(1380, 800);
    glEnd();

    glLineWidth(2.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINE_LOOP);
    glVertex2d(1380, 720);
    glVertex2d(1430, 720);
    glVertex2d(1430, 800);
    glVertex2d(1380, 800);
    glEnd();

    glLineWidth(1.5f);
    glBegin(GL_LINES);
    glVertex2d(1405, 720);
    glVertex2d(1405, 800);
    glEnd();

    glBegin(GL_LINES);
    glVertex2d(1380, 760);
    glVertex2d(1430, 760);
    glEnd();
    // end main to right building windows

    // pilar of main buiding 
    // main building divided line
    glLineWidth(5.0f);
    glColor3f(0.604f, 0.0f, 0.004f);
    glBegin(GL_POLYGON);
    glVertex2d(800, 680);
    glVertex2d(810, 680);
    glVertex2d(810, 850);
    glVertex2d(800, 850);
    glEnd();
    // main building divided line border
    glLineWidth(1.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINE_LOOP);
    glVertex2d(800, 680);
    glVertex2d(810, 680);
    glVertex2d(810, 850);
    glVertex2d(800, 850);
    glEnd();

    // main building divided line
    glLineWidth(5.0f);
    glColor3f(0.604f, 0.0f, 0.004f);
    glBegin(GL_POLYGON);
    glVertex2d(1100, 680);
    glVertex2d(1110, 680);
    glVertex2d(1110, 850);
    glVertex2d(1100, 850);
    glEnd();
    // main building divided line border
    glLineWidth(1.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINE_LOOP);
    glVertex2d(1100, 680);
    glVertex2d(1110, 680);
    glVertex2d(1110, 850);
    glVertex2d(1100, 850);
    glEnd();

    // main building divided line
    glLineWidth(5.0f);
    glColor3f(0.604f, 0.0f, 0.004f);
    glBegin(GL_POLYGON);
    glVertex2d(850, 680);
    glVertex2d(860, 680);
    glVertex2d(860, 550);
    glVertex2d(850, 550);
    glEnd();
    // main building divided line border
    glLineWidth(1.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINE_LOOP);
    glVertex2d(850, 680);
    glVertex2d(860, 680);
    glVertex2d(860, 550);
    glVertex2d(850, 550);
    glEnd();

    // main building divided line
    glLineWidth(5.0f);
    glColor3f(0.604f, 0.0f, 0.004f);
    glBegin(GL_POLYGON);
    glVertex2d(1050, 680);
    glVertex2d(1060, 680);
    glVertex2d(1060, 550);
    glVertex2d(1050, 550);
    glEnd();
    // main building divided line border
    glLineWidth(1.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINE_LOOP);
    glVertex2d(1050, 680);
    glVertex2d(1060, 680);
    glVertex2d(1060, 550);
    glVertex2d(1050, 550);
    glEnd();

    // First window
    glBegin(GL_POLYGON);
    glColor3f(0.7f, 0.9f, 1.0f); // Light blue color
    glVertex2d(860, 700);  // Bottom-left corner
    glVertex2d(920, 700);  // Bottom-right corner
    glVertex2d(920, 800);  // Top-right corner
    glVertex2d(860, 800);  // Top-left corner
    glEnd();

    glLineWidth(2.0f);
    glColor3f(0.0f, 0.0f, 0.0f); // Black color
    glBegin(GL_LINE_LOOP);
    glVertex2d(860, 700);
    glVertex2d(920, 700);
    glVertex2d(920, 800);
    glVertex2d(860, 800);
    glEnd();

    glLineWidth(1.5f);
    glBegin(GL_LINES);
    glVertex2d(890, 700); // Vertical division line
    glVertex2d(890, 800);
    glEnd();

    glBegin(GL_LINES);
    glVertex2d(860, 750); // Horizontal division line
    glVertex2d(920, 750);
    glEnd();

    // Second window
    glBegin(GL_POLYGON);
    glColor3f(0.7f, 0.9f, 1.0f); // Light blue color
    glVertex2d(980, 700);  // Bottom-left corner
    glVertex2d(1040, 700); // Bottom-right corner
    glVertex2d(1040, 800); // Top-right corner
    glVertex2d(980, 800);  // Top-left corner
    glEnd();

    glLineWidth(2.0f);
    glColor3f(0.0f, 0.0f, 0.0f); // Black color
    glBegin(GL_LINE_LOOP);
    glVertex2d(980, 700);
    glVertex2d(1040, 700);
    glVertex2d(1040, 800);
    glVertex2d(980, 800);
    glEnd();

    glLineWidth(1.5f);
    glBegin(GL_LINES);
    glVertex2d(1010, 700); // Vertical division line
    glVertex2d(1010, 800);
    glEnd();

    glBegin(GL_LINES);
    glVertex2d(980, 750); // Horizontal division line
    glVertex2d(1040, 750);
    glEnd();

}

void drawTree(float x, float y, float trunkWidth, float trunkHeight, float foliageRadius) {
    // Draw tree trunk
    glColor3f(0.4f, 0.2f, 0.0f); // Brown color for the trunk
    glBegin(GL_POLYGON);
    glVertex2f(x - trunkWidth / 2, y);                  // Bottom left
    glVertex2f(x + trunkWidth / 2, y);                  // Bottom right
    glVertex2f(x + trunkWidth / 2, y + trunkHeight);    // Top right
    glVertex2f(x - trunkWidth / 2, y + trunkHeight);    // Top left
    glEnd();

    // Draw foliage (leaves) using multiple overlapping circles
    glColor3f(0.0f, 0.6f, 0.0f);
    drawCircle(x, y + trunkHeight + foliageRadius, foliageRadius, 0.0f, 0.6f, 0.0f);            // Center
    drawCircle(x - foliageRadius / 2, y + trunkHeight + foliageRadius / 1.5, foliageRadius / 1.2, 0.0f, 0.6f, 0.0f); // Left
    drawCircle(x + foliageRadius / 2, y + trunkHeight + foliageRadius / 1.5, foliageRadius / 1.2, 0.0f, 0.6f, 0.0f); // Right
    drawCircle(x, y + trunkHeight + foliageRadius / 2, foliageRadius / 1.5, 0.0f, 0.6f, 0.0f);  // Bottom center
}

void drawTrees() {
    drawTree(200, 205, 30, 100, 50);   // Tree 1
    drawTree(500, 210, 35, 120, 60);   // Tree 2
    drawTree(750, 200, 40, 110, 70);   // Tree 3
    drawTree(1200, 200, 30, 100, 50);  // Tree 4
    drawTree(1600, 215, 35, 115, 55);  // Tree 5
    drawTree(1900, 200, 40, 125, 60);  // Tree 6
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
    glBegin(GL_POLYGON);
    glColor3f(0.6f, 0.6f, 0.6f);
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

void drawLeftRoadBoundary() {
    glLineWidth(3.0f);

    // Outer boundary lines
    glColor3f(0.7f, 0.7f, 0.7f);
    glBegin(GL_LINE_LOOP);
    glVertex2d(0, 200);
    glVertex2d(770, 200);
    glVertex2d(770, 300);
    glVertex2d(0, 300);
    glEnd();

    // Filled middle lines
    glColor3f(0.7f, 0.7f, 0.7f);
    glBegin(GL_QUADS);

    // Fill  the boundary
    for (int x = 0; x < 770; x += 50) {
        glVertex2d(x, 200);
        glVertex2d(x + 20, 200);
        glVertex2d(x + 20, 300);
        glVertex2d(x, 300);
    }

    glEnd();
}

void drawRightRoadBoundary() {
    glLineWidth(3.0f);

    // Outer boundary lines
    glColor3f(0.7f, 0.7f, 0.7f);
    glBegin(GL_LINE_LOOP);
    glVertex2d(1200, 200);
    glVertex2d(1920, 200);
    glVertex2d(1920, 300);
    glVertex2d(1200, 300);
    glEnd();

    // Filled middle lines
    glColor3f(0.7f, 0.7f, 0.7f);
    glBegin(GL_QUADS);

    // Fill  the boundary
    for (int x = 1200; x < 1920; x += 50) {
        glVertex2d(x, 200);
        glVertex2d(x + 20, 200);
        glVertex2d(x + 20, 300);
        glVertex2d(x, 300);
    }

    glEnd();
}

void drawClock(float x, float y, float radius) {
    // Get the current time
    time_t t;
    struct tm* localTime;
    time(&t);
    localTime = localtime(&t);

    // Calculate the angles for the hands
    float secondAngle = localTime->tm_sec * 6.0f;
    float minuteAngle = localTime->tm_min * 6.0f + (localTime->tm_sec * 0.1f);
    float hourAngle = (localTime->tm_hour % 12) * 30.0f + (localTime->tm_min * 0.5f);

    // Draw the clock face (circle)
    glColor3f(1.0f, 1.0f, 1.0f); // White
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < 360; i++) {
        float angle = (float)i * 3.14159f / 180.0f;
        glVertex2f(x + cos(angle) * radius, y + sin(angle) * radius);
    }
    glEnd();

    // Draw the numbers (12, 3, 6, 9)
    glColor3f(0.0f, 0.0f, 0.0f); // Black
    glRasterPos2f(x - 5.0f, y - radius + 15.0f); glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '1'); glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '2');
    glRasterPos2f(x + radius - 10.0f, y - 5.0f); glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '3');
    glRasterPos2f(x - 10.0f, y + radius - 20.0f); glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '6');
    glRasterPos2f(x - radius + 5.0f, y - 5.0f); glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '9');

    // Draw the hands
    // Hour hand
    glPushMatrix();
    glTranslatef(x, y, 0.0f);
    glRotatef(hourAngle, 0.0f, 0.0f, 1.0f);
    glLineWidth(6.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.0f, radius * 0.5f);
    glEnd();
    glPopMatrix();

    // Minute hand
    glPushMatrix();
    glTranslatef(x, y, 0.0f);
    glRotatef(minuteAngle, 0.0f, 0.0f, 1.0f);
    glLineWidth(4.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.0f, radius * 0.75f);
    glEnd();
    glPopMatrix();

    // Second hand
    glPushMatrix();
    glTranslatef(x, y, 0.0f);
    glRotatef(360.0f - secondAngle, 0.0f, 0.0f, 1.0f);
    glLineWidth(2.0f);
    glColor3f(1.0f, 0.0f, 0.0f); // Red for second hand
    glBegin(GL_LINES);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.0f, radius);
    glEnd();
    glPopMatrix();
}

void drawRectangle() {
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.5f, 0.0f);
    glVertex2d(450, 800);
    glVertex2d(450, 700);
    glVertex2d(650, 700);
    glVertex2d(650, 800);
    glEnd();
}

void drawStand() {
    glBegin(GL_QUADS);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex2d(440, 500);
    glVertex2d(440, 820);
    glVertex2d(450, 820);
    glVertex2d(450, 500);
    glEnd();
}

void drawGND() {
    glBegin(GL_QUADS);
    glColor3f(0.5f, 0.3f, 0.3f);
    glVertex2d(430, 500);
    glVertex2d(460, 500);
    glVertex2d(460, 480);
    glVertex2d(430, 480);
    glEnd();
}

void drawFlag() {
    drawRectangle();
    drawCircle(550, 750, 35, 1.0f, 0.0f, 0.0f);
    drawGND();
    drawStand();
}

void drawPillargnd() {
    glBegin(GL_POLYGON);
    glColor3f(0.4f, 0.4f, 0.4f);
    glVertex2d(500, 410);
    glVertex2d(50, 410);
    glVertex2d(100, 480);
    glVertex2d(350, 480);
    glEnd();
}

void drawPillar(int x1, int y1, int x2, int y2) {
    glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(6.0f);
    glBegin(GL_LINES);
    glVertex2d(x1, y1);
    glVertex2d(x2, y2);
    glEnd();
}

void sohidMinar() {

    drawPillargnd();
    drawCircle(235, 520, 55, 1.0f, 0.0f, 0.0f);
    //Left side
    drawPillar(105, 550, 105, 450);
    drawPillar(125, 550, 125, 450);
    drawPillar(140, 550, 140, 450);
    drawPillar(105, 550, 140, 550);
    //Right side
    drawPillar(305, 550, 305, 450);
    drawPillar(325, 550, 325, 450);
    drawPillar(340, 550, 340, 450);
    drawPillar(305, 550, 340, 550);
    //Middle
    drawPillar(190, 580, 190, 450);
    drawPillar(230, 580, 230, 450);
    drawPillar(270, 580, 270, 450);
    drawPillar(190, 580, 270, 580);

    //side
    drawPillar(230, 580, 280, 650);
    drawPillar(190, 580, 240, 650);
    drawPillar(270, 580, 320, 650);
    drawPillar(234, 650, 323, 650);
}

void Drawfootball() {
    // Draw the field rectangle
    glBegin(GL_POLYGON);
    glColor3f(0.1f, 0.7f, 0.1f);  // Green color for the field
    glVertex2d(1200, 480);  // Top-left corner
    glVertex2d(1700, 480);  // Top-right corner
    glVertex2d(1800, 300);  // Bottom-right corner
    glVertex2d(1160, 300);  // Bottom-left corner
    glEnd();

    // Draw the field boundary lines (White color)
    glLineWidth(3.0f);
    glColor3f(1.0f, 1.0f, 1.0f);  // White color for the boundary
    glBegin(GL_LINE_LOOP);
    glVertex2d(1200, 480);  // Top-left corner
    glVertex2d(1700, 480);  // Top-right corner
    glVertex2d(1800, 300);  // Bottom-right corner
    glVertex2d(1160, 300);  // Bottom-left corner
    glEnd();

    // Draw the center line (White)
    glBegin(GL_LINES);
    glVertex2d(1450, 480);  // Start of the center line
    glVertex2d(1450, 300);  // End of the center line (adjusted y-position)
    glEnd();

    // Draw the center circle (White)
    float radius = 50.0f;
    glColor3f(1.0f, 1.0f, 1.0f);  // White color for the center circle
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < 360; i++) {
        float angle = i * 3.14159f / 180.0f;
        glVertex2d(1450 + cos(angle) * radius, 390 + sin(angle) * radius);  // Center circle at (1450, 390)
    }
    glEnd();

    // Draw the center spot (small circle, White)
    glBegin(GL_POLYGON);
    glVertex2d(1450 - 5, 390 - 5);  // Center spot at (1450, 390)
    glVertex2d(1450 + 5, 390 - 5);
    glVertex2d(1450 + 5, 390 + 5);
    glVertex2d(1450 - 5, 390 + 5);
    glEnd();

    // Draw the penalty areas (White lines)
    glBegin(GL_LINE_LOOP);
    glVertex2d(1195, 450);  // Left penalty area top-left
    glVertex2d(1270, 450);  // Left penalty area top-right
    glVertex2d(1280, 360);  // Left penalty area bottom-right
    glVertex2d(1170, 360);  // Left penalty area bottom-left
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex2d(1715, 450);  // Right penalty area top-left
    glVertex2d(1640, 450);  // Right penalty area top-right
    glVertex2d(1660, 360);  // Right penalty area bottom-right
    glVertex2d(1765, 360);  // Right penalty area bottom-left
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    drawSun(1800, 1000, 50);
    drawClouds();
    drawSchool();
    sohidMinar();
    Drawfootball();
    drawTrees();
    drawLeftRoadBoundary();
    drawRightRoadBoundary();
    drawRoad();
    drawWalkRoad();
    drawZebraCrossing();
    drawTrafficLight();
    drawBus(x);
    drawFlag();
    drawClock(950.0f, 950.0f, 45.0f);

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);

    glutInitWindowSize(1920, 1080);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("School Scenario");
    glClearColor(0.7f, 0.9f, 1.0f, 1.0f);
    gluOrtho2D(0, 1920, 0, 1080);
    glutDisplayFunc(display);
    glutIdleFunc(moveableBus);
    glutMainLoop();
    return 0;
}
