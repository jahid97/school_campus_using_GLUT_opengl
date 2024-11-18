#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <math.h>
#include "cube.h"
#include "Elements.h"
#include "handleKeyboard.h"


GLfloat eyeX = 10;
GLfloat eyeY = 35;
GLfloat eyeZ = 120;

GLfloat lookX = 15.0;
GLfloat lookY = 12.0;
GLfloat lookZ = 0;


int width = 1500;
int height = 1000;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();

    glFrustum(-3.5, 3, -3, 3, 2.0, 800.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(eyeX, eyeY, eyeZ, lookX, lookY, lookZ, 0, 1, 0);
    glViewport(0, 0, width, height);

    createBaseField();

    schoolfild();
    SunAndCloud();
    initMovingThings();
    Mainbuilding();
    sidebuilding();
    batfild();
    wall();
    multiple_trees();
    school_footpath();
    divider();
    road();
    footpath();
    bus_stop();
    bus();
    drawWheels();
    background();



    glutSwapBuffers();
}
