#include <windows.h>
#include <GL/glut.h>
#include <cmath>
#include <time.h>
#include <sstream>


int circleQ = 200;
int direction = 1;
int speed = 3;
float timeOffset = 0.0f; // Time offset for animation
//tithy
void renderBitmapString(float x, float y, void* font, const char* string) {

    glRasterPos2f(x, y); // Set the position for the text

    while (*string) {
        glutBitmapCharacter(font, *string); // Draw each character
        string++;
    }

}

void drawRectangle(float x, float y, float width, float height, float angle) {
    glPushMatrix();  //Saves the current transformation state
    glTranslatef(x, y, 0.0f);   // Move to rectangle position
    glRotatef(angle, 0.0f, 0.0f, 1.0f); // Rotate around the center
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f); // Rectangle color
    glVertex2f(-width, -height); // Bottom-left corner
    glVertex2f(width, -height);  // Bottom-right corner
    glVertex2f(width, height);   // Top-right corner
    glVertex2f(-width, height);  // Top-left corner
    glEnd();
    glPopMatrix(); //Restores the saved transformation state
}
void circuler_path() {
    float x = 19.2;
    float y = 13.5;
    const float PI = 3.14159265359f;
    float centerX = x * 27.0f;  // X-coordinate of the circle center
    float centerY = y * 43.0f;  // Y-coordinate of the circle center
    float radius = 18.0f;  // Radius of the circle
    int numRectangles = 6; // Number of rectangles on the circle

    float rectangleWidth = 2.5f;  // Width of each rectangle
    float rectangleHeight = 6.0f; // Height of each rectangle

    for (int i = 0; i < numRectangles; ++i) {
        float angle = 2.0f * PI * i / numRectangles + timeOffset; // Dynamic angle with time offset
        float w = centerX + radius * cos(angle);    // X position on the circle
        float z = centerY + radius * sin(angle);    // Y position on the circle
        float rotationAngle = angle * 180.0f / PI;  // Convert radians to degrees

        drawRectangle(w, z, rectangleWidth, rectangleHeight, rotationAngle);
    }

    glColor3f(1.0, 0.0, 0.0); // Red color
    renderBitmapString(x * 25.6f, y * 42.5f, GLUT_BITMAP_HELVETICA_12, "Lodding");
}


void plotCirclePoints(int centerP, int centerQ, int x, int y, float r, float g, float b) {
    glColor3f(r, g, b);
    glBegin(GL_POLYGON);
    glVertex2i(centerP + x, centerQ + y);
    glVertex2i(centerP - x, centerQ + y);
    glVertex2i(centerP + x, centerQ - y);
    glVertex2i(centerP - x, centerQ - y);
    glVertex2i(centerP + y, centerQ + x);
    glVertex2i(centerP - y, centerQ + x);
    glVertex2i(centerP + y, centerQ - x);
    glVertex2i(centerP - y, centerQ - x);
    glEnd();
}

void bresenhamCircle(int centerP, int centerQ, int r, float colorX, float colorY, float colorZ) {
    int x = 0;
    int y = r;
    int p = 3 - 2 * r;

    plotCirclePoints(centerP, centerQ, x, y, colorX, colorY, colorZ);

    while (y >= x) {
        x++;
        if (p > 0) {
            y--;
            p = p + 4 * (x - y) + 10;
        }
        else {
            p = p + 4 * x + 6;
        }
        plotCirclePoints(centerP, centerQ, x, y, colorX, colorY, colorZ);
    }
}

void adnan() {

    float x = 19.2;
    float y = 13.5;

    //deal1
    glBegin(GL_POLYGON);
    glColor3f(0.945f, 0.6f, 0.451f);
    glVertex2d(0, 1013);
    glVertex2d(1248, 878);
    glVertex2d(1248, 490);
    glVertex2d(0, 320);
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


    // Draw the circle at its current Y position
    if (direction == 1) { // Moving up
        bresenhamCircle(1474, circleQ, 20, 1.0f, 0.8f, 0.0f); // Orange
    }
    else { // Moving down
        bresenhamCircle(1474, circleQ, 20, 1.0f, 1.0f, 1.0f); // White
    }

    //deal 2 sun cover
    glBegin(GL_POLYGON);
    glColor3f(0.945f, 0.82f, 0.478f);
    glVertex2d(1363, 726);
    glVertex2d(1550, 742);
    glVertex2d(1550, 1240);
    glVertex2d(1363, 1260);
    glEnd();

    //deal 2 sun cover
    glBegin(GL_POLYGON);
    glColor3f(0.945f, 0.82f, 0.478f);
    glVertex2d(1363, 540);
    glVertex2d(1550, 560);
    glVertex2d(1550, 100);
    glVertex2d(1363, 100);
    glEnd();

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
    glVertex2d(0, 300);
    glEnd();

    //floor mat
    glBegin(GL_POLYGON);
    glColor3f(0.718f, 0.796f, 0.569f);
    glVertex2d(x * 56, y * 26);
    glVertex2d(x * 0, y * 5);
    glVertex2d(x * 0, y * 0);
    glVertex2d(x * 1920, y * -600);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2d(1920, 364);
    glVertex2d(1248, 472);
    glVertex2d(1248, 452);
    glVertex2d(1920, 344);
    glEnd();

    //door
    glBegin(GL_POLYGON);
    glColor3f(0.4039f, 0.2471f, 0.1765f);
    glVertex2d(x * 0, y * 22.3);
    glVertex2d(x * 13, y * 24.8);
    glVertex2d(x * 13, y * 61.5);
    glVertex2d(x * 0, y * 63);
    glEnd();

    //canvas image
    glBegin(GL_POLYGON);
    glColor3f(0.4118f, 0.1804f, 0.0667f);
    glVertex2d(x * 50.2, y * 50.9);
    glVertex2d(x * 59.8, y * 50.3);
    glVertex2d(x * 59.8, y * 62);
    glVertex2d(x * 50.2, y * 63);
    glEnd();
    //canvas image
    glBegin(GL_POLYGON);
    glColor3f(0.6196f, 0.8627f, 0.9608f);
    glVertex2d(x * 51, y * 52);
    glVertex2d(x * 59, y * 51.5);
    glVertex2d(x * 59, y * 61);
    glVertex2d(x * 51, y * 61.7);
    glEnd();
    //canvas image
    glBegin(GL_POLYGON);
    glColor3f(0.0118f, 0.5725f, 0.2549f);
    glVertex2d(x * 53, y * 51.9);
    glVertex2d(x * 57, y * 57);
    glVertex2d(x * 59, y * 54);
    glVertex2d(x * 59, y * 51.5);
    glEnd();
    //canvas image
    glBegin(GL_POLYGON);
    glColor3f(0.2275f, 0.7098f, 0.2902f);
    glVertex2d(x * 51, y * 55);
    glVertex2d(x * 54, y * 58);
    glVertex2d(x * 56, y * 51.6);
    glVertex2d(x * 51, y * 52);
    glEnd();

    //ac
    glBegin(GL_POLYGON);
    glColor3f(0.8275f, 0.8275f, 0.8275f);
    glVertex2d(x * 70, y * 61);
    glVertex2d(x * 72, y * 60);
    glVertex2d(x * 82, y * 62);
    glVertex2d(x * 79, y * 63);
    glEnd();
    //ac
    glBegin(GL_POLYGON);
    glColor3f(0.7529f, 0.7529f, 0.7529f);
    glVertex2d(x * 82, y * 62);
    glVertex2d(x * 79, y * 63);
    glVertex2d(x * 79, y * 67);
    glVertex2d(x * 82, y * 66);
    glEnd();
    //ac
    glBegin(GL_POLYGON);
    glColor3f(0.8627f, 0.8627f, 0.8627f);
    glVertex2d(x * 79, y * 65);
    glVertex2d(x * 79, y * 67);
    glVertex2d(x * 71, y * 65);
    glVertex2d(x * 70.5, y * 63);
    glEnd();
    //ac
    glBegin(GL_POLYGON);
    glColor3f(0.4667f, 0.5333f, 0.6000f);
    glVertex2d(x * 79, y * 63);
    glVertex2d(x * 79, y * 65);
    glVertex2d(x * 70.5, y * 63);
    glVertex2d(x * 70, y * 61);
    glEnd();

    //window bar
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.5490f, 0.0f);
    glVertex2d(x * 70, y * 55);
    glVertex2d(x * 82, y * 56.7);
    glVertex2d(x * 82, y * 57.7);
    glVertex2d(x * 70, y * 56);
    glEnd();

    //sun
    bresenhamCircle(x * 10, y * 40, 15, 0.7529f, 0.7529f, 0.7529f);

    //windo mounten big
    glBegin(GL_POLYGON);
    glColor3f(0.0118f, 0.5765f, 0.2500f);
    glVertex2d(x * 75, y * 40.8);
    glVertex2d(x * 80.8, y * 40);
    glVertex2d(x * 80.8, y * 44);
    glVertex2d(x * 79, y * 46);
    glEnd();

    //windo mounten small
    glBegin(GL_POLYGON);
    glColor3f(0.2275f, 0.7098f, 0.2902f);
    glVertex2d(x * 73, y * 41.1);
    glVertex2d(x * 78, y * 40.4);
    glVertex2d(x * 76, y * 44);
    glEnd();

    //windo border
    glBegin(GL_POLYGON);
    glColor3f(0.4039f, 0.2471f, 0.1765f);
    glVertex2d(x * 71, y * 41.5);
    glVertex2d(x * 71, y * 53.8);
    glVertex2d(x * 72, y * 53.9);
    glVertex2d(x * 72, y * 41.3);
    glEnd();

    //windo border
    glBegin(GL_POLYGON);
    glColor3f(0.4039f, 0.2471f, 0.1765f);
    glVertex2d(x * 71, y * 41.5);
    glVertex2d(x * 72, y * 42.2);
    glVertex2d(x * 80.75, y * 40.5);
    glVertex2d(x * 80.75, y * 39.5);
    glEnd();
}

void drawCircle(float x, float y, float radius, float red, float green, float blue) {
    int segments = 100; // Higher value for a smoother circle
    float angle;
    x *= 19.2;
    y *= 13.5;
    glBegin(GL_POLYGON); // Keeps it as a line-based circle
    glColor3f(red, green, blue); // Set the color dynamically
    for (int i = 0; i < segments; i++) {
        angle = 2.0f * M_PI * i / segments; // Calculate the angle
        glVertex2f(x + cos(angle) * radius, y + sin(angle) * radius);
    }
    glEnd();
}

void drawNumber(float x, float y, int number) {
    // Set text color to black
    glColor3f(0.0f, 0.0f, 0.0f); // Black
    x *= 19.2;
    y *= 13.5;

    std::stringstream ss;
    ss << number;
    std::string text = ss.str();

    glRasterPos2f(x, y);        // Set position for the text

    for (char c : text) {       // Render each character
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
    }
}

void drawClock(float x, float y, float radius) {
    x *= 19.2;
    y *= 13.5;
    // Get the current time
    time_t t;
    struct tm* localTime;
    time(&t);
    localTime = localtime(&t);

    // Calculate the angles for hour, minute, and second hands
    // Calculate the angle for the second hand (clockwise)
    float secondAngle = localTime->tm_sec * 6.0f; // Keep it positive for clockwise rotation
    float minuteAngle = localTime->tm_min * 6.0f + (localTime->tm_sec * 0.1f); // Minute hand with second hand adjustment
    float hourAngle = (localTime->tm_hour % 12) * 30.0f + (localTime->tm_min * 0.5f); // Hour hand with minute hand adjustment

    // Draw the clock hands at the specified position and radius
    glColor3f(0.0f, 0.0f, 0.0f); // Black for the hands

    // Hour hand
    glPushMatrix();
    glTranslatef(x, y, 0.0f); // Translate to clock center
    glRotatef(hourAngle, 0.0f, 0.0f, 1.0f); // Rotate hour hand
    glBegin(GL_LINES);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.0f, radius * 0.5f); // Hour hand length
    glEnd();
    glPopMatrix();

    // Minute hand
    glPushMatrix();
    glTranslatef(x, y, 0.0f); // Translate to clock center
    glRotatef(minuteAngle, 0.0f, 0.0f, 1.0f); // Rotate minute hand
    glBegin(GL_LINES);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.0f, radius * 0.75f); // Minute hand length
    glEnd();
    glPopMatrix();

    // Draw the second hand
    glPushMatrix();
    glTranslatef(x, y, 0.0f);
    glRotatef(360.0f - secondAngle, 0.0f, 0.0f, 1.0f); // Subtract secondAngle from 360 to make it clockwise
    glBegin(GL_LINES);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.0f, radius); // Length of the second hand
    glEnd();
    glPopMatrix();
}


/// tithy

void cpu() {
    float x = 19.2;
    float y = 13.5;

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2d(x * 17, y * 25);
    glVertex2d(x * 17, y * 30);
    glVertex2d(x * 21, y * 28);
    glVertex2d(x * 21, y * 22);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2d(x * 17, y * 30);
    glVertex2d(x * 19, y * 31);
    glVertex2d(x * 23, y * 29);
    glVertex2d(x * 21, y * 28);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex2d(x * 21, y * 28);
    glVertex2d(x * 21, y * 22);
    glVertex2d(x * 23, y * 23);
    glVertex2d(x * 23, y * 29);
    glEnd();

    // Draw  translucent gray 
    glBegin(GL_POLYGON);
    glColor4f(0.502f, 0.502f, 0.502f, 0.5f);
    glVertex2d(x * 21, y * 28);
    glVertex2d(x * 21, y * 22);
    glVertex2d(x * 23, y * 23);
    glVertex2d(x * 23, y * 29);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2d(x * 21.3, y * 27.8);
    glVertex2d(x * 21.3, y * 22.7);
    glVertex2d(x * 22.6, y * 23.3);
    glVertex2d(x * 22.6, y * 28.4);
    glEnd();

    glBegin(GL_POLYGON);
    glColor4f(0.502f, 0.502f, 0.502f, 0.5f);
    glVertex2d(x * 21.5, y * 27.6);
    glVertex2d(x * 21.5, y * 23.2);
    glVertex2d(x * 22.4, y * 23.6);
    glVertex2d(x * 22.4, y * 28);
    glEnd();

    drawCircle(21.92f, 26.5f, 5.0f, 0.560784f, 0.560784f, 0.737255f);
    drawCircle(21.935f, 24.5f, 5.0f, 0.560784f, 0.560784f, 0.737255f);

    glBegin(GL_LINES);
    glColor3f(0.502f, 0.502f, 0.502f);
    glVertex2d(x * 17.3, y * 30.2);
    glVertex2d(x * 21, y * 28);
    glEnd();

}

void tithy() {
    float x = 19.2;
    float y = 13.5;

    //windo border
    glBegin(GL_POLYGON);
    glColor3f(0.3f, 0.2f, 0.1f);
    glVertex2d(x * 71, y * 47);
    glVertex2d(x * 71, y * 48);
    glVertex2d(x * 80.75, y * 48);
    glVertex2d(x * 80.75, y * 47);
    glEnd();

    //window Glass
    glBegin(GL_POLYGON);
    glColor4f(0.502f, 0.502f, 0.502f, 0.5f);
    glVertex2d(x * 71, y * 48);
    glVertex2d(x * 71, y * 53.9);
    glVertex2d(x * 80.75, y * 54.9);
    glVertex2d(x * 80.75, y * 48);
    glEnd();

    //desktop Table
    glBegin(GL_POLYGON);
    glColor3f(0.9216f, 0.8902f, 0.3412f);

    glVertex2d(x * 15, y * 36.3);
    glVertex2d(x * 36, y * 39.5);
    glVertex2d(x * 45, y * 35.3);
    glVertex2d(x * 25, y * 31.5);
    glEnd();


    //Cpu
    cpu();

    //table side 
    glBegin(GL_POLYGON);
    glColor3f(0.824f, 0.565f, 0.251f);
    glVertex2d(x * 15, y * 36.3);
    glVertex2d(x * 25, y * 31.5);
    glVertex2d(x * 25, y * 30.4);
    glVertex2d(x * 15, y * 35.2);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.824f, 0.565f, 0.251f);
    glVertex2d(x * 25, y * 31.5);
    glVertex2d(x * 45, y * 35.3);
    glVertex2d(x * 45, y * 34.3);
    glVertex2d(x * 25, y * 30.4);
    glEnd();

    // table leg left
    glBegin(GL_POLYGON);
    glColor3f(0.9216f, 0.8902f, 0.3412f);
    glVertex2d(x * 15.3, y * 35.1);
    glVertex2d(x * 15.3, y * 24);
    glVertex2d(x * 16, y * 24);
    glVertex2d(x * 16, y * 34.7);
    glEnd();

    //table leg middle
    glBegin(GL_POLYGON);
    glColor3f(0.9216f, 0.8902f, 0.3412f);
    glVertex2d(x * 25, y * 30.4);
    glVertex2d(x * 25, y * 20);
    glVertex2d(x * 24.3, y * 20);
    glVertex2d(x * 24.3, y * 30.7);
    glEnd();

    //table leg Right
    glBegin(GL_POLYGON);
    glColor3f(0.9216f, 0.8902f, 0.3412f);
    glVertex2d(x * 44.7, y * 34.3);
    glVertex2d(x * 44.7, y * 25);
    glVertex2d(x * 44, y * 25);
    glVertex2d(x * 44, y * 34.1);
    glEnd();
    //table leg vitore
    glBegin(GL_POLYGON);
    glColor3f(0.9216f, 0.8902f, 0.3412f);
    glVertex2d(x * 36, y * 32.5);
    glVertex2d(x * 36, y * 28);
    glVertex2d(x * 35.3, y * 28);
    glVertex2d(x * 35.3, y * 32.4);
    glEnd();

    //shelf
    glBegin(GL_POLYGON);
    glColor3f(0.9216f, 0.8902f, 0.3412f);
    glVertex2d(x * 17, y * 60);
    glVertex2d(x * 35, y * 60);
    glVertex2d(x * 40, y * 57.8);
    glVertex2d(x * 22, y * 57.8);
    glEnd();


    //self side
    glBegin(GL_POLYGON);
    glColor3f(0.834f, 0.575f, 0.261f);
    glVertex2d(x * 17, y * 60);
    glVertex2d(x * 22, y * 57.8);
    glVertex2d(x * 22, y * 57);
    glVertex2d(x * 17, y * 59.2);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.834f, 0.575f, 0.261f);
    glVertex2d(x * 22, y * 57.8);
    glVertex2d(x * 40, y * 57.8);
    glVertex2d(x * 40, y * 57);
    glVertex2d(x * 22, y * 57);
    glEnd();

    /* glBegin(GL_LINES);
     glColor3f(0.0f, 0.0f, 0.0f);
     glVertex2d(x * 35, y * 60);
     glVertex2d(x * 40, y * 57.8);
     glEnd();

     glBegin(GL_LINES);
     glColor3f(0.0f, 0.0f, 0.0f);
     glVertex2d(x * 40, y * 57.8);
     glVertex2d(x * 22, y * 57.8);
     glEnd();

     glBegin(GL_LINES);
     glColor3f(0.0f, 0.0f, 0.0f);
     glVertex2d(x * 22, y * 57.8);
     glVertex2d(x * 17, y * 60);
     glEnd();*/


     // 1st books
    glBegin(GL_POLYGON);
    glColor3f(0.620f, 0.867f, 0.957f);
    glVertex2d(x * 22, y * 62);
    glVertex2d(x * 24.8, y * 63);
    glVertex2d(x * 27.5, y * 61.7);
    glVertex2d(x * 24.8, y * 61);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.620f, 0.867f, 0.957f);
    glVertex2d(x * 22, y * 62);
    glVertex2d(x * 24.8, y * 61);
    glVertex2d(x * 24.8, y * 60);
    glVertex2d(x * 22, y * 61);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2d(x * 24.8, y * 61);
    glVertex2d(x * 27.5, y * 61.7);
    glVertex2d(x * 27.2, y * 60.7);
    glVertex2d(x * 24.8, y * 60);
    glEnd();

    // 2nd book
    glBegin(GL_POLYGON);
    glColor3f(0.580f, 0.667f, 0.784f);
    glVertex2d(x * 22, y * 61);
    glVertex2d(x * 24.8, y * 60);
    glVertex2d(x * 24.8, y * 59);
    glVertex2d(x * 22, y * 60);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2d(x * 24.8, y * 60);
    glVertex2d(x * 27.2, y * 60.7);
    glVertex2d(x * 27.1, y * 59.6);
    glVertex2d(x * 24.8, y * 59);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.620f, 0.867f, 0.957f);
    glVertex2d(x * 24.8, y * 60);
    glVertex2d(x * 27.2, y * 60.7);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.580f, 0.667f, 0.784f);
    glVertex2d(x * 27.1, y * 59.6);
    glVertex2d(x * 24.8, y * 59);
    glEnd();

    //book 3
    glBegin(GL_POLYGON);
    glColor3f(0.1412f, 0.5412f, 0.2392f);
    glVertex2d(x * 22, y * 60);
    glVertex2d(x * 24.8, y * 59);
    glVertex2d(x * 24.8, y * 58.2);
    glVertex2d(x * 22, y * 59);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2d(x * 24.8, y * 59);
    glVertex2d(x * 27.1, y * 59.6);
    glVertex2d(x * 27.1, y * 59);
    glVertex2d(x * 24.8, y * 58.2);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.1412f, 0.5412f, 0.2392f);
    glVertex2d(x * 27.1, y * 59);
    glVertex2d(x * 24.8, y * 58.2);
    glEnd();

    // book part 2
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2d(x * 28, y * 63);
    glVertex2d(x * 32, y * 63);
    glVertex2d(x * 35, y * 62);
    glVertex2d(x * 31, y * 62);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.580f, 0.667f, 0.784f);
    glVertex2d(x * 28, y * 63);
    glVertex2d(x * 31, y * 62);
    glVertex2d(x * 31, y * 58);
    glVertex2d(x * 28, y * 59);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.580f, 0.667f, 0.784f);
    glVertex2d(x * 31, y * 62);
    glVertex2d(x * 32, y * 62.2);
    glVertex2d(x * 32, y * 58);
    glVertex2d(x * 31, y * 58);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.580f, 0.667f, 0.784f);
    glVertex2d(x * 32, y * 62.2);
    glVertex2d(x * 29, y * 63);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.533f, 0.071f, 0.176f);
    glVertex2d(x * 32, y * 62);
    glVertex2d(x * 33, y * 62);
    glVertex2d(x * 33, y * 58);
    glVertex2d(x * 32, y * 58);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.533f, 0.071f, 0.176f);
    glVertex2d(x * 33, y * 62);
    glVertex2d(x * 30, y * 62.8);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.620f, 0.867f, 0.957f);
    glVertex2d(x * 33, y * 62.2);
    glVertex2d(x * 34, y * 62.2);
    glVertex2d(x * 34, y * 58);
    glVertex2d(x * 33, y * 58);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.620f, 0.867f, 0.957f);
    glVertex2d(x * 34, y * 62.2);
    glVertex2d(x * 31, y * 63);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.6941f, 0.3216f, 0.8706f);
    glVertex2d(x * 34, y * 62);
    glVertex2d(x * 35, y * 62);
    glVertex2d(x * 35, y * 58);
    glVertex2d(x * 34, y * 58);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.6941f, 0.3216f, 0.8706f);
    glVertex2d(x * 35, y * 62);
    glVertex2d(x * 32, y * 63);
    glEnd();

    //Monitor
    //glEnable(GL_BLEND);
    //glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2d(x * 22, y * 39);
    glVertex2d(x * 22, y * 47);
    glVertex2d(x * 32, y * 46.6);
    glVertex2d(x * 32, y * 40.3);
    glEnd();

    glBegin(GL_POLYGON);
    glColor4f(0.502f, 0.502f, 0.502f, 0.5f);
    glVertex2d(x * 22.7, y * 40);
    glVertex2d(x * 22.7, y * 46);
    glVertex2d(x * 31.5, y * 45.8);
    glVertex2d(x * 31.5, y * 41);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2d(x * 26.8, y * 40.3);
    glVertex2d(x * 28, y * 40.3);
    glVertex2d(x * 28, y * 38);
    glVertex2d(x * 26.8, y * 38);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2d(x * 25, y * 38);
    glVertex2d(x * 29, y * 38.7);
    glVertex2d(x * 31, y * 36.88);
    glVertex2d(x * 26.8, y * 36);
    glEnd();

    circuler_path();

    /* glBegin(GL_POLYGON);
      glColor4f(0.502f, 0.502f, 0.502f, 0.5f);
      glVertex2d(x * 22.7, y * 40);
      glVertex2d(x * 22.7, y * 46);
      glVertex2d(x * 31.5, y * 45.8);
      glVertex2d(x * 31.5, y * 41);
      glEnd();*/

      //keyboard
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2d(x * 27.5, y * 33);
    glVertex2d(x * 33.7, y * 34.5);
    glVertex2d(x * 32, y * 36.5);
    glVertex2d(x * 25.7, y * 35);
    glEnd();

    glBegin(GL_POLYGON);
    glColor4f(0.502f, 0.502f, 0.502f, 0.5f);
    glVertex2d(x * 27.8, y * 33.6);
    glVertex2d(x * 32.8, y * 34.8);
    glVertex2d(x * 31.7, y * 36);
    glVertex2d(x * 26.7, y * 34.8);
    glEnd();

    //tab
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2d(x * 33, y * 36.7);
    glVertex2d(x * 34.5, y * 37);
    glVertex2d(x * 36, y * 35.5);
    glVertex2d(x * 34.5, y * 35.2);
    glEnd();

    glBegin(GL_POLYGON);
    glColor4f(0.502f, 0.502f, 0.502f, 0.5f);
    glVertex2d(x * 33.4, y * 36.6);
    glVertex2d(x * 34.4, y * 36.9);
    glVertex2d(x * 35.7, y * 35.6);
    glVertex2d(x * 34.6, y * 35.4);
    glEnd();

    // speaker
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2d(x * 33, y * 42);
    glVertex2d(x * 35, y * 42);
    glVertex2d(x * 35, y * 38.5);
    glVertex2d(x * 33, y * 38.5);
    glEnd();

    //speaker round
    drawCircle(34.0f, 40.2f, 16.0f, 0.502f, 0.502f, 0.502f);
    drawCircle(34.0f, 40.2f, 11.0f, 0.0f, 0.0f, 0.0f);
    //drawCircle(34.0f, 40.2f, 6.0f, 0.502f, 0.502f, 0.502f);

    // Note
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2d(x * 18, y * 37.2);
    glVertex2d(x * 18, y * 40.5);
    glVertex2d(x * 19.7, y * 40.5);
    glVertex2d(x * 19.7, y * 37.5);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2d(x * 18, y * 37.8);
    glVertex2d(x * 19.7, y * 38);
    glVertex2d(x * 18, y * 38.4);
    glVertex2d(x * 19.7, y * 38.6);
    glVertex2d(x * 18, y * 39);
    glVertex2d(x * 19.7, y * 39.2);
    glEnd();

    drawCircle(18.9f, 40.0f, 3.5f, 1.0f, 0.0f, 0.0f);

    //Chair 
    glBegin(GL_POLYGON);
    glColor3f(0.620f, 0.867f, 0.957f);
    glVertex2d(x * 30, y * 29.8);
    glVertex2d(x * 37, y * 31);
    glVertex2d(x * 39, y * 29.2);
    glVertex2d(x * 35, y * 28);
    glEnd();

    //seat
    glBegin(GL_POLYGON);
    glColor3f(0.580f, 0.667f, 0.784f);
    glVertex2d(x * 30, y * 29.8);
    glVertex2d(x * 35, y * 28);
    glVertex2d(x * 35, y * 27.3);
    glVertex2d(x * 30, y * 29.3);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.580f, 0.667f, 0.784f);
    glVertex2d(x * 35, y * 28);
    glVertex2d(x * 39, y * 29.2);
    glVertex2d(x * 39, y * 28.5);
    glVertex2d(x * 35, y * 27.3);
    glEnd();

    //chair structure
    glBegin(GL_POLYGON);
    glColor3f(0.2431f, 0.7059f, 0.5373f);
    glVertex2d(x * 30, y * 29.3);
    glVertex2d(x * 35, y * 27.3);
    glVertex2d(x * 35, y * 26.8);
    glVertex2d(x * 30, y * 28.8);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.2431f, 0.7059f, 0.5373f);
    glVertex2d(x * 39, y * 28.5);
    glVertex2d(x * 35, y * 27.3);
    glVertex2d(x * 35, y * 26.8);
    glVertex2d(x * 39, y * 28);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.2431f, 0.7059f, 0.5373f);
    glVertex2d(x * 35, y * 26.8);
    glVertex2d(x * 34.3, y * 38);
    glVertex2d(x * 35, y * 38);
    glVertex2d(x * 35.5, y * 27);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.2431f, 0.7059f, 0.5373f);
    glVertex2d(x * 39, y * 28);
    glVertex2d(x * 40, y * 38);
    glVertex2d(x * 39.3, y * 38);
    glVertex2d(x * 38.5, y * 28);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.2431f, 0.7059f, 0.5373f);
    glVertex2d(x * 36.7, y * 27.5);
    glVertex2d(x * 37, y * 38);
    glVertex2d(x * 37.5, y * 38);
    glVertex2d(x * 37.2, y * 27.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.2431f, 0.7059f, 0.5373f);
    glVertex2d(x * 34.3, y * 37.8);
    glVertex2d(x * 40, y * 38);
    glVertex2d(x * 40, y * 38.8);
    glVertex2d(x * 34.3, y * 38.8);
    glEnd();

    //chair leg
    glBegin(GL_POLYGON);
    glColor3f(0.2431f, 0.7059f, 0.5373f);
    glVertex2d(x * 35, y * 27.3);
    glVertex2d(x * 35, y * 20);
    glVertex2d(x * 34.5, y * 20);
    glVertex2d(x * 34.5, y * 27.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.2431f, 0.7059f, 0.5373f);
    glVertex2d(x * 39, y * 28.3);
    glVertex2d(x * 39, y * 22);
    glVertex2d(x * 38.5, y * 22);
    glVertex2d(x * 38.5, y * 28);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.2431f, 0.7059f, 0.5373f);
    glVertex2d(x * 30.2, y * 28.8);
    glVertex2d(x * 30.2, y * 22);
    glVertex2d(x * 30.7, y * 22);
    glVertex2d(x * 30.7, y * 28.9);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.2431f, 0.7059f, 0.5373f);
    glVertex2d(x * 37, y * 28);
    glVertex2d(x * 37, y * 24);
    glVertex2d(x * 36.5, y * 24);
    glVertex2d(x * 36.5, y * 27.8);
    glEnd();

    glBegin(GL_POLYGON);
    glColor4f(0.9f, 0.9f, 0.9f, 0.5f);
    glVertex2d(x * 76.2, y * 48);
    glVertex2d(x * 71, y * 52);
    glVertex2d(x * 71, y * 53.9);
    glVertex2d(x * 72.75, y * 54.1);
    glVertex2d(x * 77.5, y * 48);
    glEnd();

    glBegin(GL_POLYGON);
    glColor4f(0.9f, 0.9f, 0.9f, 0.5f);
    glVertex2d(x * 79, y * 48);
    glVertex2d(x * 75.25, y * 54.3);
    glVertex2d(x * 76.75, y * 54.6);
    glVertex2d(x * 79.75, y * 48);
    glEnd();

}

void update(int value) {
    // Update the circle's Y position
    circleQ += direction * speed;

    // Reverse direction if it reaches the boundary
    if (circleQ >= 1000 || circleQ <= 200) { // Adjust boundaries as needed
        direction = -direction;
    }

    // Redraw the scene
    glutPostRedisplay();

    // Call update again after 16 milliseconds (for smoother animation)
    glutTimerFunc(16, update, 0);
}
void timer(int) {
    timeOffset += 0.1f; //smooth and gradual animation
    if (timeOffset > 2 * 3.14159f) {
        timeOffset -= 2 * 3.14159f;
    }

    glutPostRedisplay();// Redraw the scene
    glutTimerFunc(16, timer, 0);
}

void sadid() {
    float x = 19.2;
    float y = 13.5;
    //glColor3f(1.0f, 1.0f, 1.0f);

    //BED Top
    glBegin(GL_POLYGON);
    glColor3f(0.945f, 0.969f, 0.957f);
    glVertex2d(x * 47, y * 30);
    glVertex2d(x * 65, y * 31);
    glVertex2d(x * 65, y * 45);
    glVertex2d(x * 47, y * 44);
    glEnd();

    //BED Top Left
    glBegin(GL_POLYGON);
    glColor3f(0.216f, 0.251f, 0.224f);
    glVertex2d(x * 46, y * 31);
    glVertex2d(x * 47, y * 30);
    glVertex2d(x * 47, y * 44);
    glVertex2d(x * 46, y * 45);
    glEnd();

    //BED Top Top
    glBegin(GL_POLYGON);
    glColor3f(0.216f, 0.251f, 0.224f);
    glVertex2d(x * 47, y * 44);
    glVertex2d(x * 65, y * 45);
    glVertex2d(x * 64, y * 46);
    glVertex2d(x * 46, y * 45);
    glEnd();

    //BED left TOP
    glBegin(GL_POLYGON);
    glColor3f(0.580f, 0.667f, 0.784f);
    glVertex2d(x * 65, y * 28);
    glVertex2d(x * 65, y * 30);
    glVertex2d(x * 47, y * 35);
    glVertex2d(x * 47, y * 33);
    glEnd();

    //BED left Buttom
    glBegin(GL_POLYGON);
    glColor3f(0.784f, 0.784f, 0.784f);
    glVertex2d(x * 65, y * 24);
    glVertex2d(x * 65, y * 28);
    glVertex2d(x * 47, y * 33);
    glVertex2d(x * 47, y * 30);
    glEnd();

    //BED sheet left
    glBegin(GL_POLYGON);
    glColor3f(0.718f, 0.796f, 0.569f);
    glVertex2d(x * 64, y * 27);
    glVertex2d(x * 65, y * 30);
    glVertex2d(x * 55, y * 32.8);
    glVertex2d(x * 54, y * 30);
    glEnd();

    //BED sheet left
    glBegin(GL_LINES);
    glColor3f(0.649f, 0.720f, 0.514f);
    glVertex2d(x * 65, y * 30);
    glVertex2d(x * 55, y * 32.8);
    glEnd();

    //BED sheet top
    glBegin(GL_POLYGON);
    glColor3f(0.718f, 0.796f, 0.569f);
    glVertex2d(x * 65, y * 30);
    glVertex2d(x * 79, y * 35);
    glVertex2d(x * 73, y * 36);
    glVertex2d(x * 55, y * 32.8);
    glEnd();

    //BED sheed top
    glBegin(GL_POLYGON);
    glColor3f(0.620f, 0.867f, 0.957f);
    glVertex2d(x * 55, y * 32.8);
    glVertex2d(x * 73, y * 36);
    glVertex2d(x * 65, y * 37);
    glVertex2d(x * 47, y * 35);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.824f, 0.827f, 0.824f);
    glVertex2d(x * 66, y * 24.01);
    glVertex2d(x * 85, y * 29);
    glVertex2d(x * 85, y * 35);
    glVertex2d(x * 66, y * 31);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.828f, 0.825f, 0.825f);
    glVertex2d(x * 65, y * 24.01);
    glVertex2d(x * 66, y * 24.01);
    glVertex2d(x * 66, y * 31);
    glVertex2d(x * 65, y * 32);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.933f, 0.961f, 0.953f);
    glVertex2d(x * 66, y * 31);
    glVertex2d(x * 85, y * 35);
    glVertex2d(x * 84, y * 36);
    glVertex2d(x * 65, y * 32);
    glEnd();

    //pellow
    glBegin(GL_POLYGON);
    glColor3f(0.718f, 0.796f, 0.569f);
    glVertex2d(x * 57, y * 34);
    glVertex2d(x * 61, y * 35);
    glVertex2d(x * 60, y * 36);
    glVertex2d(x * 55, y * 35);
    glEnd();

    //Almery
    glBegin(GL_POLYGON);
    glColor3f(0.412f, 0.181f, 0.067f);
    glVertex2d(x * 86, y * 24);
    glVertex2d(x * 91, y * 23);
    glVertex2d(x * 91, y * 48.5);
    glVertex2d(x * 86, y * 49);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3f(0.412f, 0.181f, 0.067f);
    glVertex2d(x * 91, y * 23);
    glVertex2d(x * 96, y * 22);
    glVertex2d(x * 96, y * 48);
    glVertex2d(x * 91, y * 48.5);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2d(x * 91, y * 23);
    glVertex2d(x * 91, y * 48.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.408f, 0.212f, 0.137f);
    glVertex2d(x * 96, y * 22);
    glVertex2d(x * 99, y * 23);
    glVertex2d(x * 99, y * 50);
    glVertex2d(x * 96, y * 48);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2d(x * 96, y * 22);
    glVertex2d(x * 96, y * 48);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.408f, 0.212f, 0.137f);
    glVertex2d(x * 86, y * 49);
    glVertex2d(x * 96, y * 48);
    glVertex2d(x * 99, y * 50);
    glVertex2d(x * 88, y * 51);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2d(x * 96, y * 48);
    glVertex2d(x * 99, y * 50);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2d(x * 96, y * 48);
    glVertex2d(x * 86, y * 49);
    glEnd();
    //Almery

    //Table
    glBegin(GL_POLYGON);
    glColor3f(0.404f, 0.247f, 0.176f);
    glVertex2d(x * 65, y * 6);
    glVertex2d(x * 84, y * 15);
    glVertex2d(x * 65, y * 21);
    glVertex2d(x * 47, y * 14);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.980f, 0.753f, 0.431f);
    glVertex2d(x * 47, y * 13);
    glVertex2d(x * 65, y * 5);
    glVertex2d(x * 65, y * 6);
    glVertex2d(x * 47, y * 14);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.980f, 0.753f, 0.431f);
    glVertex2d(x * 65, y * 5);
    glVertex2d(x * 84, y * 14);
    glVertex2d(x * 84, y * 15);
    glVertex2d(x * 65, y * 6);
    glEnd();

    //Table leg
    glBegin(GL_POLYGON);
    glColor3f(0.404f, 0.247f, 0.176f);
    glVertex2d(x * 47, y * 10);
    glVertex2d(x * 48, y * 10);
    glVertex2d(x * 48, y * 12.5);
    glVertex2d(x * 47, y * 13);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.404f, 0.247f, 0.176f);
    glVertex2d(x * 64, y * 2);
    glVertex2d(x * 65, y * 1);
    glVertex2d(x * 65, y * 5);
    glVertex2d(x * 64, y * 5.4);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.980f, 0.753f, 0.431f);
    glVertex2d(x * 65, y * 1);
    glVertex2d(x * 66, y * 2);
    glVertex2d(x * 66, y * 5.5);
    glVertex2d(x * 65, y * 5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.404f, 0.247f, 0.176f);
    glVertex2d(x * 83, y * 11);
    glVertex2d(x * 84, y * 11);
    glVertex2d(x * 84, y * 14);
    glVertex2d(x * 83, y * 13.5);
    glEnd();


    //Flower vase
    glBegin(GL_POLYGON);
    glColor3f(0.824f, 0.565f, 0.251f);
    glVertex2d(x * 64, y * 13);
    glVertex2d(x * 66, y * 13);
    glVertex2d(x * 67, y * 16);
    glVertex2d(x * 63, y * 16);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2d(x * 65, y * 16);
    glVertex2d(x * 65, y * 19);
    glEnd();

    //flower
    glBegin(GL_POLYGON);
    glColor3f(0.533f, 0.071f, 0.176f);
    glVertex2d(x * 64, y * 17);
    glVertex2d(x * 65, y * 17);
    glVertex2d(x * 65, y * 18);
    glVertex2d(x * 64, y * 18);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.898f, 0.737f, 0.518f);
    glVertex2d(x * 65, y * 17);
    glVertex2d(x * 66, y * 17);
    glVertex2d(x * 66, y * 18);
    glVertex2d(x * 65, y * 18);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.898f, 0.737f, 0.518f);
    glVertex2d(x * 64, y * 18);
    glVertex2d(x * 65, y * 18);
    glVertex2d(x * 65, y * 19);
    glVertex2d(x * 64, y * 19);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.533f, 0.071f, 0.176f);
    glVertex2d(x * 65, y * 18);
    glVertex2d(x * 66, y * 18);
    glVertex2d(x * 66, y * 19);
    glVertex2d(x * 65, y * 19);
    glEnd();

    /*glBegin(GL_POLYGON);
   glColor3f(1.0f, 0.0f, 0.0f);
   glVertex2d(x*, y*);
   glVertex2d(x*, y*);
   glVertex2d(x*, y*);
   glVertex2d(x*,y*);
   glEnd();*/

   //X, y , redious, color
    drawCircle(93.0f, 60.0f, 65.0f, 0.733f, 0.510f, 0.224f);
    drawCircle(93.0f, 60.0f, 50.0f, 1.0f, 1.0f, 1.0f);
    drawNumber(90.6f, 59.5f, 9);
    drawNumber(95.0f, 59.5f, 3);
    drawNumber(92.7f, 56.5f, 6);
    drawNumber(92.4f, 62.5f, 12);
    drawClock(93.0f, 60.0f, 45.0f);
    //Handel
    drawCircle(90.0f, 36.0f, 10.0f, 0.733f, 0.510f, 0.224f);
    drawCircle(92.0f, 35.8f, 10.0f, 0.733f, 0.510f, 0.224f);


}


void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    adnan();
    sadid();
    tithy();

    glFlush();
}


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(1920, 1080);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Home interior Design");
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    gluOrtho2D(0, 1920, 0, 1080);
    glutDisplayFunc(display);
    glutTimerFunc(1, update, 0);
    glutTimerFunc(0, timer, 0); // Start timer for animation
    glutMainLoop();
    return 0;
}
