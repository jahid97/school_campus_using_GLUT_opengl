#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <math.h>
#include "handleKeyboard.h"


extern GLfloat eyeX;
extern GLfloat eyeY;
extern GLfloat eyeZ;
extern GLfloat lookX;
extern GLfloat lookY;
extern GLfloat lookZ;


 void key(unsigned char key, int x, int y)
{
    float switchSpeed = 1.0;
    switch (key)
    {
    case 'd':
        eyeX += switchSpeed;
        printf("eye x = %f \n", eyeX);
        break;
    case 'a':
        eyeX -= switchSpeed;
        printf("eye x = %f \n", eyeX);
        break;
    case 'w':
        eyeY += switchSpeed;
        printf("eye y = %f\n", eyeY);
        break;
    case 's':
        eyeY -= switchSpeed;
        printf("eye y = %f\n", eyeY);
        break;
    case '1':
        eyeZ += switchSpeed;
        printf("eye z = %f\n", eyeZ);
        break;
    case '2':
        eyeZ -= switchSpeed;
        printf("eye z = %f\n", eyeZ);
        break;
    case 'l':
        lookX += switchSpeed;
        printf("L X = %f\n", lookX);
        break;
    case 'j':
        lookX -= switchSpeed;
        printf("L X = %f\n", lookX);
        break;
    case 'o':
        lookY += switchSpeed;
        printf("L Y = %f\n", lookY);
        break;
    case 'k':
        lookY -= switchSpeed;
        printf("L Y = %f\n", lookY);
        break;
    case 'p':
        lookZ += switchSpeed;
        printf("L Z = %f\n", lookZ);
        break;
    case 'i':
        lookZ -= switchSpeed;
        printf("L Z = %f\n", lookZ);
        break;
    }

    glutPostRedisplay();
}
