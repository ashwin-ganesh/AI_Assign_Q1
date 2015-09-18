#include <iostream>
#include <stdio.h>
#include <vector>
#include <gl/glut.h>
#include <math.h>
using namespace std;

void myInit(void)
 {
    glClearColor(1.0,1.0,1.0,0.0);       // set white background color
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 416.0, 0.0, 416.0);
}

void DrawCircle(float cx, float cy, float r, int num_segments)
{
    glBegin(GL_LINE_LOOP);
    for(int ii = 0; ii < num_segments; ii++)
    {
        float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);//get the current angle

        float x = r * cosf(theta);//calculate the x component
        float y = r * sinf(theta);//calculate the y component

        glVertex2f(x + cx, y + cy);//output vertex

    }
    glEnd();
}

void drawChecker(int size)
{
    int i = 0;
    int j = 0;

    for (i = 0; i < 8 ; ++i) {
    for (j = 0; j < 8; ++j) {
        if((i + j)%2 == 0) // if i + j is even
            glColor3f( 0.4, 0.2, 0.6);
        else
            glColor3f( 0.2, 0.3, 0.4);
        glRecti(i*size, j*size, (i+1)*size, (j+1)*size);    // draw the rectangle
    }
    }
    glColor3f( 1, 1, 0);
    for(i=0;i<8;i++)
        DrawCircle(52*i + 26 ,26,14,30);

     glColor3f( 1, 0, 0);

    for(i=0;i<8;i++)
        DrawCircle(52*i + 26 ,52*7+26,14,30);


  glFlush();
}

void checkerboard(void) {
    glClear(GL_COLOR_BUFFER_BIT);     // clear the screen
    drawChecker(52);

}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);          // initialize the toolkit
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // set display mode
    glutInitWindowSize(640,480);     // set window size
    glutInitWindowPosition(100, 150); // set window position on screen
    glutCreateWindow("null"); // open the screen window
    glutDisplayFunc(checkerboard);     // register redraw function
    myInit();
    glutMainLoop();     // go into a perpetual loop

    return 0;
}





