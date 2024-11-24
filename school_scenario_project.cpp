#include <windows.h>
#include <GL/glut.h>
#include <cmath>

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





void khairul() {
    drawSun(1800, 1000, 50);
    drawClouds();
    drawSchool();
    drawTrees();
    drawLeftRoadBoundary();
    drawRightRoadBoundary();
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
    glutCreateWindow("School Scenario");
    glClearColor(0.7f, 0.9f, 1.0f, 1.0f);
    gluOrtho2D(0, 1920, 0, 1080);
    glutDisplayFunc(display);
    glutIdleFunc(moveableBus);
    glutMainLoop();
    return 0;
}
