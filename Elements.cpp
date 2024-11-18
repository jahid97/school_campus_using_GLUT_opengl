
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <math.h>
#include "cube.h"

// Function to create the base field, unchanged from your original code
void createBaseField()
{
    // FIELD
    glPushMatrix();
    glTranslated(-232, 0 - 12, -200);
    glScaled(580, 1, 380);
    cube(0.4, 0.8, 0.5); // Same as your cube function call
    glPopMatrix();

    // Sky
    glPushMatrix();
    glTranslated(-1532, -220, -200);
    glScaled(2700, 1000, 1);
    cube(100 / 255.0, 255 / 255.0, 255 / 255.0); // Same cube function call
    glPopMatrix();
}


void circle(GLfloat xAxis, GLfloat yAxis, GLfloat zAxis, GLfloat radius, GLfloat rColor, GLfloat gColor, GLfloat bColor)
{
    glPushMatrix(); // Push the current matrix onto the stack
    glTranslatef(xAxis, yAxis, zAxis);

    glColor3f(rColor/255.0, gColor/255.0, bColor/255.0); // Red color used to draw.
    glutSolidSphere(radius, 20, 20);

    glPopMatrix(); // Pop the matrix from the stack to revert to the previous state
}


    float sunXPosition = -183;
    float sunYPosition = 150;
    float sunZPosition = -90;


    float cloud1XPosition = -190;
    float cloud1YPosition = 102;
    float cloud1ZPosition = -57;

    float cloud2XPosition = -253;
    float cloud2YPosition = 45;
    float cloud2ZPosition = -90;


    float cloud3XPosition = -100;
    float cloud4XPosition = 60;
    float cloud5XPosition = 80;
    float cloud5YPosition = 150;

void SunAndCloud() {
    // sun
    circle(sunXPosition, sunYPosition, sunZPosition, 6, 255, 255, 0);

    // cloud 1
    circle(cloud1XPosition+14, cloud1YPosition, cloud1ZPosition, 5, 245, 255, 255);
    circle(cloud1XPosition+23, cloud1YPosition, cloud1ZPosition, 8, 255, 245, 235);
    circle(cloud1XPosition+32, cloud1YPosition, cloud1ZPosition, 5, 245, 255, 255);
    // cloud 2
    circle(cloud2XPosition+13, cloud2YPosition+13, cloud2ZPosition, 5, 245, 255, 255);
    circle(cloud2XPosition+22, cloud2YPosition+13.5, cloud2ZPosition, 8, 255, 245, 245);
    circle(cloud2XPosition+33, cloud2YPosition+13, cloud2ZPosition, 5, 245, 255, 255);


    // cloud 3
    circle(cloud3XPosition+14, cloud1YPosition-1.2, cloud1ZPosition, 5, 245, 255, 255);
    circle(cloud3XPosition+23, cloud1YPosition-1.2, cloud1ZPosition, 8, 255, 245, 235);
    circle(cloud3XPosition+32, cloud1YPosition-1.2, cloud1ZPosition, 5, 245, 255, 255);
    // cloud 4
    circle(cloud4XPosition+13, cloud2YPosition+30+3.5, cloud2ZPosition, 5, 245, 255, 255);
    circle(cloud4XPosition+22, cloud2YPosition+30.5+3.5, cloud2ZPosition, 8, 255, 245, 245);
    circle(cloud4XPosition+33, cloud2YPosition+30+3.5, cloud2ZPosition, 5, 245, 255, 255);

    //clude5

    circle(cloud5XPosition+15, cloud5YPosition-5, cloud2ZPosition, 5, 245, 255, 255); // Small circle
    circle(cloud5XPosition+24, cloud5YPosition-5.5, cloud2ZPosition, 8, 255, 245, 245); // Big circle
    circle(cloud5XPosition+33, cloud5YPosition-5, cloud2ZPosition, 5, 245, 255, 255); // Small circle

}

void Sun() {
    // sun
    sunYPosition += 0.001;
}

void Clouds() {
    // cloud 1
    cloud1XPosition += 0.0125;


    // cloud 2
    cloud2XPosition += 0.02;

        // cloud 3
    cloud3XPosition += 0.0155;

    cloud4XPosition += 0.018;

    cloud5XPosition += 0.018;
}

void initMovingThings() {
    Sun();
    Clouds();
}

void window()
{
    glPushMatrix();
    glScaled(5, 6 , 1);
    cube(0.1,0.9,0.9);
    glPopMatrix();
}

void windows(){
    // total glass
    float xBasePosition =-0.6;
    float yBasePosition = 0;
    float zBasePosition = 0.9;
    float rotateDegree=0;
    float rX=0;
    float rY=0;
    float rZ=0;

    glPushMatrix();
    glTranslated(xBasePosition,yBasePosition,zBasePosition);
    glRotated(rotateDegree, rX, rY, rZ);
    glScaled(7,5,0.01);
    cube(0.68f, 0.85f, 0.90f);
    glPopMatrix();

    // out line
    glPushMatrix();
    glTranslated(xBasePosition-0.5,yBasePosition-0.5,zBasePosition-0.2);
    glRotated(rotateDegree, rX, rY, rZ);
    glScaled(7.7,5.65,0.01);
    cube(0.9,0.9,0.9);
    glPopMatrix();

    float xPlus = 0.12;
    float zPlus = -3;

    if(rotateDegree == 0) {
        xPlus = 3.2;
        zPlus = 0.2;
    }
    // middle line
    glPushMatrix();
    glTranslated(xBasePosition+xPlus,yBasePosition+0.06,zBasePosition+zPlus);
    glRotated(rotateDegree, rX, rY, rZ);
    glScaled(0.7, 5.35,0.01);
    cube(0.9,0.9,0.9);
    glPopMatrix();
}


void door()
{
    glPushMatrix();
    glScaled(16,9,0.5);
    cube(0.7, 0.8, 0.7);
    glPopMatrix();
}


void floor_of_building()
{

    glPushMatrix();
    glTranslated(-9, -11 , 0);
    glScaled(13,14,18);
    for (int i = 0; i < 5; i++)
    {
        glPushMatrix();
        glTranslatef(i, 0, 0); // Translate along X-axis
        cube(0.69f, 0.63f, 0.58f);
        glPopMatrix();
    }

    glPopMatrix();

//line
    glPushMatrix();
    glTranslated(-9, 3 , 0);
    glScaled(83,1.5,18);
    cube(0, 0 , 0);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-16, -11 , 0);
    glScaled(18,14,13);
    for (int i = 0; i < 3; i++)
    {
        glPushMatrix();
        glTranslatef(4, 0, i); // Translate along X and Z axes (flipped side)
        cube(0.69f, 0.63f, 0.58f);
        glPopMatrix();
    }
    glPopMatrix();
    //line
    glPushMatrix();
    glTranslated(56, 3 , 18.5);
    glScaled(18,1.5,20.5);
    cube(0, 0 , 0);
    glPopMatrix();


    glPushMatrix();
    glTranslated(-3, -7 ,19);
    windows();
    glPopMatrix();

    glPushMatrix();
    glTranslated(7,-7,19);
    windows();
    glPopMatrix();

    glPushMatrix();
    glTranslated(17,-7,19);
    windows();
    glPopMatrix();

    glPushMatrix();
    glTranslated(27,-7,19);
    windows();
    glPopMatrix();

    glPushMatrix();
    glTranslated(57,-7,38.5);
    windows();
    glPopMatrix();

    glPushMatrix();
    glTranslated(67,-7,38.5);
    windows();
    glPopMatrix();


}


void Mainbuilding()
{
    //1st floor
    glPushMatrix();
    floor_of_building();

    //door
    glTranslated(37,-9,19);
    glScaled(15,10,0.5);
    cube(0.6, 0.4, 0.2);
    glPopMatrix();

    //2st floor
    glPushMatrix();
    glTranslated(0, 15.5 ,0);
    floor_of_building();

    glPushMatrix();
    glTranslated(37,-7,20);
    windows();
    glPopMatrix();

    glPushMatrix();
    glTranslated(46,-7,20);
    windows();
    glPopMatrix();

    glPopMatrix();

    //3rd floor

    glPushMatrix();
    glTranslated(0, 31 ,0);
    floor_of_building();

    glPushMatrix();
    glTranslated(37,-7,20);
    windows();
    glPopMatrix();

    glPushMatrix();
    glTranslated(46,-7,20);
    windows();
    glPopMatrix();

    glPopMatrix();
//4th


    glPushMatrix();
    glTranslated(0, 46.5 ,0);
    floor_of_building();

    glPushMatrix();
    glTranslated(37,-7,20);
    windows();
    glPopMatrix();

    glPushMatrix();
    glTranslated(46,-7,20);
    windows();
    glPopMatrix();

    glPopMatrix();


}

void extra_sidebuilding()
{

//roof
    glPushMatrix();
    glTranslatef(-48, -3, 45);
    glScaled(5, 1, 7);
    cube(1, 0 ,0);
    glPopMatrix();
//piler
    glPushMatrix();
    glTranslatef(-45, -11, 45);
    glScaled(0.5, 8, 0.5);
    cube(0, 0 ,0.5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-45, -11, 50);
    glScaled(0.5, 8, 0.5);
    cube(0, 0 ,0.5);
    glPopMatrix();


}
void Sidebuilding_first_floor()
{

    glPushMatrix();
    glTranslatef(-60, -11, 40);
    glScaled(12, 9, 15);
    cube(0.76f, 0.67f, 0.57f);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-60, -2, 40);
    glScaled(12, 1, 15);
    cube(0, 0 ,0);
    glPopMatrix();
//window

    glPushMatrix();
    glTranslatef(-58, -8, 54.1);
    glScaled(3, 4 , 1);
    cube(0.7, 0.8, 0.7);
    glPopMatrix();
    //window
    glPushMatrix();
    glTranslatef(-53, -8, 54.1);
    glScaled(3, 4 , 1);
    cube(0.7, 0.8, 0.7);
    glPopMatrix();




}

void sidebuilding()
{
    glPushMatrix();
    Sidebuilding_first_floor();
    extra_sidebuilding();
    glTranslatef(-48, -9.5, 45);
    glScaled(0.5, 7, 5);
    cube(0.7, 0.8, 0.7);
    glPopMatrix();
    //2nd floor

    glPushMatrix();
    glTranslated(0, 10 ,0);
    Sidebuilding_first_floor();

    glPushMatrix();
    glTranslatef(-48, -7, 50);
    glScaled(0.5, 4, 3);
    cube(0.7, 0.8, 0.7);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(-48, -7, 43);
    glScaled(0.5, 4, 3);
    cube(0.7, 0.8, 0.7);
    glPopMatrix();

    glPopMatrix();
    //3rd

    glPushMatrix();
    glTranslated(0, 20 ,0);
    Sidebuilding_first_floor();

    glPushMatrix();
    glTranslatef(-48, -7, 50);
    glScaled(0.5, 4, 3);
    cube(0.7, 0.8, 0.7);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(-48, -7, 43);
    glScaled(0.5, 4, 3);
    cube(0.7, 0.8, 0.7);
    glPopMatrix();

    glPopMatrix();
}

void schoolfild()
{

    glPushMatrix();
    glTranslated(-80,-11,-30);
    glScaled(210,1,100);
    cube(0.13f, 0.53f, 0.13f);
    glPopMatrix();

}

void letter()
{

    // First vertical bar of "M"
    glPushMatrix();
    glTranslatef(18, 2, 69.6);
    glTranslatef(23.8, 0.5, 0.1);
    glScaled(.6, 3.5, 1);
    cube(0.0, 0.0, 0.0);
    glPopMatrix();

    // Second vertical bar of "M"
    glPushMatrix();
    glTranslatef(18, 2, 69.6);
    glTranslatef(26, 0.5, 0.1);
    glScaled(.6, 3.5, 1);
    cube(0, 0.0, 0);
    glPopMatrix();

    // Top part of "M"
    glPushMatrix();
    glTranslatef(18, 2, 70);
    glTranslatef(25, 1.9, 0.1);
    glRotated(30, 0, 0, 1);
    glScaled(0.5, 2, 0.5);
    cube(0, 0.0, 0.0);
    glPopMatrix();

    // Bottom part of "M"
    glPushMatrix();
    glTranslatef(18, 2, 70);
    glTranslatef(25, 1.9, 0.1);
    glRotated(-30, 0, 0, 1);
        glScaled(0.5, 2, 0.5);
    cube(0.0, 0.0, 0.0);
    glPopMatrix();



    //      A

    glPushMatrix();
    glTranslatef(37.3,2.8,70.2);
    glRotated(-25,0,0,1);
    glScaled(.6,4,0.5);
    cube(0.0,0.0,0.0); //bend straight line
    glPopMatrix();


    glPushMatrix();
    glTranslated(40.5,2.5,70.1);
    glRotated(25,0,0,1);
    glScaled(.6,4,0.5);
    cube(0.0,0.0,0.0); //bend straight line
    glPopMatrix();

    glPushMatrix();
    glTranslated(38.3,3.7,69.7); // middle line
    glScaled(2,.6,1);
    cube(0.0,0.0,0.0);
    glPopMatrix();


    //C

    // Left
    glPushMatrix();
    glTranslatef(20, 2, 69.6);
    glTranslatef(26.1, 0.6, 0.1);
    glScaled(.6, 3.2, 1);
    cube(0, 0.0, 0);
    glPopMatrix();

    // bottom
    glPushMatrix();
    glTranslatef(20, 2, 69.6);
    glTranslatef(26.1, 0.6, 0.1);
    glScaled(2, .6, 1);
    cube(0, 0.0, 0);
    glPopMatrix();

    // top
    glPushMatrix();
    glTranslatef(20, 5, 69.6);
    glTranslatef(26.1, 0.6, 0.1);
    glScaled(2, .6, 1);
    cube(0, 0.0, 0);
    glPopMatrix();

    // round of C
    glPushMatrix();
    glTranslatef(21.4, 4.5, 69.6);
    glTranslatef(26.1, 0.6, 0.1);
    glScaled(.6 ,.6, 1);
    cube(0, 0.0, 0);
    glPopMatrix();
}


void wall()
{
//backwall
    glPushMatrix();
    glTranslated(-80,-10,-30);
    glScaled(210,7,1);
    cube(0.6,0.0,0.3);
    glPopMatrix();
//leftwall


    glPushMatrix();
    glTranslated(-80,-10,-30);
    glScaled(1,7,100);
    cube(0.6,0.0,0.3);
    glPopMatrix();
   //rightwall
    glPushMatrix();
    glTranslated(130,-10,-30);
    glScaled(1,7,100);
    cube(0.6,0.0,0.3);
    glPopMatrix();

    //forward
     glPushMatrix();
    glTranslated(-80,-10,69);
    glScaled(110,7,1);
    cube(0.6,0.0,0.3);
    glPopMatrix();

    //piller
    glPushMatrix();
    glTranslated(30,-10,69);
    glScaled(2,12,2);
    cube(1,0.0,0);
    glPopMatrix();


    glPushMatrix();
    glTranslated(55,-10,69);
    glScaled(77,7,1);
    cube(0.6,0.0,0.3);
    glPopMatrix();

    //piller
    glPushMatrix();
    glTranslated(53,-10,69);
    glScaled(2,12,1);
    cube(1,0.0,0);
    glPopMatrix();


//signboard
    glPushMatrix();
    glTranslated(29.5,2,70);
    glScaled(25,5,0.5);
    cube(1,1.0,1);
    glPopMatrix();


    letter();


    //gate
    glPushMatrix();
    glTranslated(32,-9,70);
    glRotated(20,0, 1, 0);
    glScaled(9,7,0.5);
    cube(0.7, 0.8, 0.7);
    glPopMatrix();

    glPushMatrix();
    glTranslated(45,-9.5,66);
    glRotated(-20,0, 1, 0);
    glScaled(9,7,0.5);
    cube(0.7, 0.8, 0.7);
    glPopMatrix();


}

void batfild()
{
    glPushMatrix();
    glTranslated(-45,-20,-75);
    //Main field
    glPushMatrix();
    glTranslated(-20,10,50);
    glScaled(25,1,40);
    cube(0.9,0.5,0.1);
    glPopMatrix();

    //Back Line
    glPushMatrix();
    glTranslated(-20,11.1,50);
    glScaled(25,0,1);
    cube(1.0,1.0,1.0);
    glPopMatrix();

    //Left Line
    glPushMatrix();
    glTranslated(-20,11.1,50);
    glScaled(1,0,40);
    cube(1.0,1.0,1.0);
    glPopMatrix();

    //Front line
    glPushMatrix();
    glTranslated(-20,11.1,89);
    glScaled(25,0,1);
    cube(1.0,1.0,1.0);
    glPopMatrix();

    //Right line
    glPushMatrix();
    glTranslated(4,11.1,50);
    glScaled(1,0,40);
    cube(1.0,1.0,1.0);
    glPopMatrix();

    //Middle Back line
    glPushMatrix();
    glTranslated(-20,11.1,67.5);
    glScaled(25,0,1);
    cube(1.0,1.0,1.0);
    glPopMatrix();

    //Middle line
    glPushMatrix();
    glTranslated(-20,11.1,71.5);
    glScaled(25,0,1);
    cube(1.0,1.0,1.0);
    glPopMatrix();

    //Middle Front line
    glPushMatrix();
    glTranslated(-20,11.1,75.5);
    glScaled(25,0,1);
    cube(1.0,1.0,1.0);
    glPopMatrix();

    //Middle Horizontal line
    glPushMatrix();
    glTranslated(-8,11.1,50);
    glScaled(1,0,17.5);
    cube(1.0,1.0,1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-8,11.1,75.5);
    glScaled(1,0,14.5);
    cube(1.0,1.0,1.0);
    glPopMatrix();

    glPopMatrix();


}


void Tree(float xBasePosition, float yBasePosition, float zBasePosition) {
// pillar
glPushMatrix();
glTranslated(xBasePosition, yBasePosition, zBasePosition);
glScaled(1.5, 15, 1.5);
cube(166/255.0, 137/255.0, 101/255.0);
glPopMatrix();

// center circle
circle(xBasePosition+1, yBasePosition+12, zBasePosition+1.4, 2.35, 11, 103, 35);

circle(xBasePosition+3, yBasePosition+12, zBasePosition+1.4, 2.35, 11, 103, 35);

circle(xBasePosition+6, yBasePosition+12, zBasePosition+1.4, 2.35, 11, 103, 35);

circle(xBasePosition-2, yBasePosition+12, zBasePosition+1.4, 2.35, 11, 103, 35);

circle(xBasePosition-5, yBasePosition+12, zBasePosition+1.4, 2.35, 11, 103, 35);



circle(xBasePosition+1, yBasePosition+16, zBasePosition+1.4, 2.35, 11, 103, 35);

circle(xBasePosition+3.5, yBasePosition+15, zBasePosition+1.4, 2.35, 11, 103, 35);

circle(xBasePosition-2.5, yBasePosition+15, zBasePosition+1.4, 2.35, 11, 103, 35);


circle(xBasePosition+2, yBasePosition+18, zBasePosition+1.4, 2.35, 11, 103, 35);

circle(xBasePosition-1, yBasePosition+18, zBasePosition+1.4, 2.35, 11, 103, 35);


circle(xBasePosition+1, yBasePosition+20, zBasePosition+1.4, 2.35, 11, 103, 35);


}

void multiple_trees() {

float xBasePosition = 50;
float yBasePosition = -10;
float zBasePosition = 110;

// between windmill and hills
// tree x
    Tree(xBasePosition+10, yBasePosition, zBasePosition-45);

    Tree(xBasePosition+30, yBasePosition, zBasePosition-45);

    Tree(xBasePosition+50, yBasePosition, zBasePosition-45);

    Tree(xBasePosition+70, yBasePosition, zBasePosition-45);



    Tree(xBasePosition+78, yBasePosition, zBasePosition-60);

    Tree(xBasePosition+78, yBasePosition, zBasePosition-75);

    Tree(xBasePosition+78, yBasePosition, zBasePosition-90);

    Tree(xBasePosition+78, yBasePosition, zBasePosition-105);

    Tree(xBasePosition+78, yBasePosition, zBasePosition-120);

    Tree(xBasePosition+78, yBasePosition, zBasePosition-135);



    Tree(xBasePosition+50, yBasePosition, zBasePosition-135);

    Tree(xBasePosition+70, yBasePosition, zBasePosition-135);

    Tree(xBasePosition+30, yBasePosition, zBasePosition-135);

    Tree(xBasePosition+10, yBasePosition, zBasePosition-135);


    //other side

    Tree(xBasePosition-30, yBasePosition, zBasePosition-45);

    Tree(xBasePosition-50, yBasePosition, zBasePosition-45);

    Tree(xBasePosition-70, yBasePosition, zBasePosition-45);

    Tree(xBasePosition-120, yBasePosition, zBasePosition-45);




    Tree(xBasePosition-125, yBasePosition, zBasePosition-60);

    Tree(xBasePosition-125, yBasePosition, zBasePosition-75);

    Tree(xBasePosition-125, yBasePosition, zBasePosition-90);

    Tree(xBasePosition-125, yBasePosition, zBasePosition-105);

    Tree(xBasePosition-125, yBasePosition, zBasePosition-120);

    Tree(xBasePosition-125, yBasePosition, zBasePosition-135);

}



void footpath()
{
    glPushMatrix();
    glTranslated(-95,-10,70.5);
    glScaled(250,1,5);
    cube(0.7,0.7,0.7);
    glPopMatrix();
}

void school_footpath()
{
    glPushMatrix();
    glTranslated(-45,-9,20);
    glScaled(100,1,5);
    cube(1,1,1);
    glPopMatrix();

    //
    glPushMatrix();
    glTranslated(-48,-9,20);
    glScaled(5,1,49);
    cube(1,1,1);
    glPopMatrix();


}

void road()
{
    glPushMatrix();
    glTranslated(-95,-10,75.5);
    glScaled(250,1,15);
    cube(0,0,0);

    glPopMatrix();
}

void divider()
{
    //whiteline
    glPushMatrix();
    glTranslated(-95,-9,75.5);
    glScaled(250,0.9,0.5);
    cube(1,1,1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-95,-10,91);
    glScaled(250,0.9,0.5);
    cube(1,1,1);
    glPopMatrix();

    //divided line
    glPushMatrix();
    glTranslated(-73,-8.8,83.5);
    glScaled(15,0.5,0.7);
    cube(1,1,1);
    glPopMatrix();


    glPushMatrix();
    glTranslated(-50,-8.8,83.5);
    glScaled(15,0.5,0.7);
    cube(1,1,1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-27,-8.8,83.5);
    glScaled(15,0.5,0.7);
    cube(1,1,1);
    glPopMatrix();



    glPushMatrix();
    glTranslated(-4,-8.8,83.5);
    glScaled(15,0.5,0.7);
    cube(1,1,1);
    glPopMatrix();


    glPushMatrix();
    glTranslated(19,-8.8,83.5);
    glScaled(15,0.5,0.7);
    cube(1,1,1);
    glPopMatrix();


    glPushMatrix();
    glTranslated(42,-8.8,83.5);
    glScaled(15,0.5,0.7);
    cube(1,1,1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(65,-8.8,83.5);
    glScaled(15,0.5,0.7);
    cube(1,1,1);
    glPopMatrix();



    glPushMatrix();
    glTranslated(88,-8.8,83.5);
    glScaled(15,0.5,0.7);
    cube(1,1,1);
    glPopMatrix();


    glPushMatrix();
    glTranslated(111,-8.8,83.5);
    glScaled(12,0.5,0.7);
    cube(1,1,1);
    glPopMatrix();

}


void bus()
{
    glPushMatrix();
    glTranslated(-10, -6, -6);

    glPushMatrix();
    glTranslated(11,-1,83.5);
    glScaled(20,7,5);
    cube(1,.7,0);
    glPopMatrix();

    //Left border line
    glPushMatrix();
    glTranslated(11,-0.92,88.6);
    glScaled(0.3,6.95,0);
    cube(1,1,1);
    glPopMatrix();

    //Middle Border line
    glPushMatrix();
    glTranslated(11,1.5,88.6);
    glScaled(24,0.3,0);
    cube(1,1,1);
    glPopMatrix();

    //Upper Border Line
    glPushMatrix();
    glTranslated(11,5.8,88.6);
    glScaled(20,0.3,0);
    cube(1,1,1);
    glPopMatrix();

    //divider
    glPushMatrix();
    glTranslated(15.8,1.5,88.6);
    glScaled(0.3,4.5,0);
    cube(1,1,1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(19.9,1.5,88.6);
    glScaled(0.3,4.5,0);
    cube(1,1,1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(23.9,1.5,88.6);
    glScaled(0.3,4.5,0);
    cube(1,1,1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(27.9,1.5,88.6);
    glScaled(0.3,4.5,0);
    cube(1,1,1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(11,-0.92,88.6);
    glScaled(0.3,6.95,0);
    cube(1,1,1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(30,-1,83.5);
    glScaled(5,3.5,5);
    cube(1,.7,0);
    glPopMatrix();

    glPushMatrix();
    glTranslated(13,2.5,88);
    glScaled(2,2,1);
    cube(1,1,1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(17,2.5,88);
    glScaled(2,2,1);
    cube(1,1,1);
    glPopMatrix();


    glPushMatrix();
    glTranslated(21,2.5,88);
    glScaled(2,2,1);
    cube(1,1,1);
    glPopMatrix();


    glPushMatrix();
    glTranslated(25,2.5,88);
    glScaled(2,2,1);
    cube(1,1,1);
    glPopMatrix();



    glPushMatrix();
    glTranslated(29,2.5,88);
    glScaled(1.7,2,1);
    cube(1,1,1);
    glPopMatrix();

    glPopMatrix();


}


void drawTire(float innerRadius, float outerRadius, float tireR, float tireG, float tireB)
{
    // Set the color of the tire (outer part)
    glColor3f(tireR, tireG, tireB);

    // Draw the tire as a torus (donut shape)
    glutSolidTorus(innerRadius, outerRadius, 30, 30);  // innerRadius, outerRadius, slices, stacks
}

void drawRim(float radius, float width, float rimR, float rimG, float rimB)
{
    // Set the color for the rim (center part)
    glColor3f(rimR, rimG, rimB);


    GLUquadric *quad;
    quad = gluNewQuadric();

    // Rim outer cylinder
    gluCylinder(quad, radius, radius, width, 30, 30);


    glPushMatrix();
    glTranslatef(0.0f, 0.0f, 0.0f); // Front face
    gluDisk(quad, 0, radius, 30, 1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, 0.0f, width); // Back face
    gluDisk(quad, 0, radius, 30, 1);
    glPopMatrix();

    gluDeleteQuadric(quad);
}

void drawWheels()
{

    glPushMatrix();
    glTranslatef(6.0, -6.5, 83.5);  // Position the wheel
    glScaled(0.7, 0.7, 0.7);

    drawTire(0.5f, 2.0f, 0.1f, 0.1f, 0.1f); // Dark tire color


    drawRim(1.5f, 0.3f, 0.8f, 0.8f, 0.8f); // Silver rim
    glPopMatrix();


    glPushMatrix();
    glTranslatef(17, -6.5, 83.5);  // Position the wheel
    glScaled(0.7, 0.7, 0.7);

    drawTire(0.5f, 2.0f, 0.1f, 0.1f, 0.1f); // Dark tire color


    drawRim(1.5f, 0.3f, 0.8f, 0.8f, 0.8f); // Silver rim
    glPopMatrix();

}




void chair(float x, float y, float z){

    // seat
    glPushMatrix();
    glTranslatef(x+4.8,y+.85,z-4.5);
    glScaled(1,.1,-3);
    cube(0.87058,0.721568,0.525490);
    glPopMatrix();

    //chair leg back
    glPushMatrix();
    glTranslatef(x+5.3,y+.1,z-4.6);
    glScaled(.1,.8,.1);
    cube(0.21176,0.270588,0.309803);
    glPopMatrix();

    //chair leg back base
    glPushMatrix();
    glTranslatef(x+4.8,y+.1,z-4.6);
    glScaled(1,.1,.1);
    cube(0.21176,0.270588,0.309803);
    glPopMatrix();


    //chair leg front
    glPushMatrix();
    glTranslatef(x+5.3,y+.1,z-7.5);
    glScaled(.1,.8,.1);
    cube(0.21176,0.270588,0.309803);
    glPopMatrix();

    //chair leg front base
    glPushMatrix();
    glTranslatef(x+4.8,y+.1,z-7.5);
    glScaled(1,.1,.1);
    cube(0.21176,0.270588,0.309803);
    glPopMatrix();


    z+=5;
    // seat2
    glPushMatrix();
    glTranslatef(x+4.8,y+.85,z-4.5);
    glScaled(1,.1,-3);
    cube(0.87058,0.721568,0.525490);
    glPopMatrix();

    //chair leg back
    glPushMatrix();
    glTranslatef(x+5.3,y+.1,z-4.6);
    glScaled(.1,.8,.1);
    cube(0.21176,0.270588,0.309803);
    glPopMatrix();

    //chair leg back base
    glPushMatrix();
    glTranslatef(x+4.8,y+.1,z-4.6);
    glScaled(1,.1,.1);
    cube(0.21176,0.270588,0.309803);
    glPopMatrix();


    //chair leg front
    glPushMatrix();
    glTranslatef(x+5.3,y+.1,z-7.5);
    glScaled(.1,.8,.1);
    cube(0.21176,0.270588,0.309803);
    glPopMatrix();

    //chair leg front base
    glPushMatrix();
    glTranslatef(x+4.8,y+.1,z-7.5);
    glScaled(1,.1,.1);
    cube(0.21176,0.270588,0.309803);
    glPopMatrix();


}

void roottop(){

    glPushMatrix();
    glTranslated(-10,-10,70);
    glScaled(13,9,.5);
    cube(0.5, 0.3,0);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-10,-10,70);
    glScaled(.5,9,3);
    cube(0.6,0.3,0.1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(3,-10,70);
    glScaled(.5,9,3);
    cube(0.6,0.3,0.1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-10,-1,70);
    glScaled(13.5,.5,4);
    cube(0.6,0.7,0.7);
    glPopMatrix();

}
void bus_stop()
{
    glPushMatrix();
    glTranslated(-15, 0 ,0);
    roottop();
    glPushMatrix();
    glRotatef(90, 0,1,0);
    chair(-79,-8,1); // z,y,x
    glPopMatrix();

    glPopMatrix();


}
void background_windows()
{
    glPushMatrix();
    glTranslated(-127, -6 ,-55.5);
    windows();
    glPopMatrix();

    glPushMatrix();
    glTranslated(-137, -6 ,-55.5);
    windows();
    glPopMatrix();

    glPushMatrix();
    glTranslated(-147, -6 ,-55.5);
    windows();
    glPopMatrix();

}

void background_windows_2()
{
    glPushMatrix();
    glTranslated(-127, -6 ,-55.5);
    window();
    glPopMatrix();

    glPushMatrix();
    glTranslated(-137, -6 ,-55.5);
    window();
    glPopMatrix();

    glPushMatrix();
    glTranslated(-147, -6 ,-55.5);
    window();
    glPopMatrix();

}

void background()
{
    glPushMatrix();
    glTranslated(20, 0 ,0);


    glPushMatrix();
    glTranslated(-150, -10 ,-65);
    glScaled(30, 40, 10);
    cube(1,.6,0);
    glPopMatrix();
    background_windows();


    glPushMatrix();
    glTranslated(0, 12 ,0);
    background_windows();
    glPopMatrix();


    glPushMatrix();
    glTranslated(0, 25 ,0);
    background_windows();
    glPopMatrix();

//2nd one
    glPushMatrix();
    glTranslated(-190, -10 ,-65);
    glScaled(30, 50, 10);
    cube(0.82f, 0.57f, 0.47f);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-40, 0 ,0);
    background_windows_2();
    glPopMatrix();


    glPushMatrix();
    glTranslated(-40, 12 ,0);
    background_windows_2();
    glPopMatrix();


    glPushMatrix();
    glTranslated(-40, 25 ,0);
    background_windows_2();
    glPopMatrix();

    //3rd

    glPushMatrix();
    glTranslated(-240, -11 ,-65);
    glScaled(42, 50, 10);
    cube(0.68f, 0.72f, 0.56f);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-85, 0 ,0);
    background_windows();
    glPopMatrix();


    glPushMatrix();
    glTranslated(-85, 12 ,0);
    background_windows();
    glPopMatrix();


    glPushMatrix();
    glTranslated(-85, 25 ,0);
    background_windows();
    glPopMatrix();

    glPushMatrix();
    glTranslated(-85, 36 ,0);
    background_windows();
    glPopMatrix();


//4th
    glPushMatrix();
    glTranslated(-110, -10 ,-65);
    glScaled(30, 65, 10);
    cube(0.60f, 0.70f, 0.72f);
    glPopMatrix();

    glPushMatrix();
    glTranslated(40, 0 ,0);
    background_windows();
    glPopMatrix();


    glPushMatrix();
    glTranslated(40, 12 ,0);
    background_windows();
    glPopMatrix();


    glPushMatrix();
    glTranslated(40, 25 ,0);
    background_windows();
    glPopMatrix();

    glPushMatrix();
    glTranslated(40, 37 ,0);
    background_windows();
    glPopMatrix();

    glPushMatrix();
    glTranslated(40, 49 ,0);
    background_windows();
    glPopMatrix();

//5th

    glPushMatrix();
    glTranslated(-71, -10 ,-65);
    glScaled(40, 45, 10);
    cube(1,.5,0);
    glPopMatrix();

    glPushMatrix();
    glTranslated(85, 0 ,0);
    background_windows_2();
    glPopMatrix();


    glPushMatrix();
    glTranslated(85, 12 ,0);
    background_windows_2();
    glPopMatrix();


    glPushMatrix();
    glTranslated(85, 25 ,0);
    background_windows_2();
    glPopMatrix();

//5th

    glPushMatrix();
    glTranslated(-25, -10 ,-65);
    glScaled(40, 45, 10);
    cube(0 , 0 ,1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(130, 0 ,0);
    background_windows();
    glPopMatrix();


    glPushMatrix();
    glTranslated(130, 12 ,0);
    background_windows();
    glPopMatrix();


    glPushMatrix();
    glTranslated(130, 25 ,0);
    background_windows();
    glPopMatrix();

    //6th

    glPushMatrix();
    glTranslated(20, -10 ,-65);
    glScaled(40, 45, 10);
    cube(0.8, 0, 0);
    glPopMatrix();

    glPushMatrix();
    glTranslated(170, 0 ,0);
    background_windows();
    glPopMatrix();


    glPushMatrix();
    glTranslated(170, 12 ,0);
    background_windows();
    glPopMatrix();


    glPushMatrix();
    glTranslated(170, 25 ,0);
    background_windows();
    glPopMatrix();

//7th

    glPushMatrix();
    glTranslated(70, -10 ,-65);
    glScaled(50, 45, 10);
    cube(0.6, 0, 0);
    glPopMatrix();


    glPushMatrix();
    glTranslated(230, 0 ,0);
    background_windows();
    glPopMatrix();


    glPushMatrix();
    glTranslated(230, 12 ,0);
    background_windows();
    glPopMatrix();


    glPushMatrix();
    glTranslated(230, 25 ,0);
    background_windows();
    glPopMatrix();



//8th
    glPushMatrix();
    glTranslated(130, -10 ,-65);
    glScaled(50, 55, 10);
    cube(0.68f, 0.73f, 0.62f);
    glPopMatrix();

    glPushMatrix();
    glTranslated(290, 0 ,0);
    background_windows();
    glPopMatrix();


    glPushMatrix();
    glTranslated(290, 12 ,0);
    background_windows();
    glPopMatrix();


    glPushMatrix();
    glTranslated(290, 25 ,0);
    background_windows();
    glPopMatrix();

    glPushMatrix();
    glTranslated(290, 37 ,0);
    background_windows();
    glPopMatrix();



    //9th

    glPushMatrix();
    glTranslated(200, -10 ,-65);
    glScaled(40, 55, 10);
    cube(1,.9,0);
    glPopMatrix();

    glPushMatrix();
    glTranslated(355, 0 ,0);
    background_windows_2();
    glPopMatrix();


    glPushMatrix();
    glTranslated(355, 12 ,0);
    background_windows_2();
    glPopMatrix();


    glPushMatrix();
    glTranslated(355, 25 ,0);
    background_windows_2();
    glPopMatrix();

    glPushMatrix();
    glTranslated(355, 37 ,0);
    background_windows_2();
    glPopMatrix();


    //10th

    glPushMatrix();
    glTranslated(260, -10 ,-65);
    glScaled(40, 45, 10);
    cube(1,.6,0);
    glPopMatrix();


    glPushMatrix();
    glTranslated(410, 0 ,0);
    background_windows();
    glPopMatrix();


    glPushMatrix();
    glTranslated(410, 12 ,0);
    background_windows();
    glPopMatrix();


    glPushMatrix();
    glTranslated(410, 25 ,0);
    background_windows();
    glPopMatrix();

    glPopMatrix();

}


