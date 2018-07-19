/*
 * GLUT Shapes Demo
 *
 * Written by Nigel Stewart November 2003
 *
 * This program is test harness for the sphere, cone
 * and torus shapes in GLUT.
 *
 * Spinning wireframe and smooth shaded shapes are
 * displayed until the ESC or q key is pressed.  The
 * number of geometry stacks and slices can be adjusted
 * using the + and - keys.
 */
#include <stdlib.h>
#include <math.h>
#include <fstream>
#include <iostream>
#include <string.h>
#include <sstream>
#include <vector>
#include "Lineas.h"
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif


GLint a=0;
GLint ancho=1200;
GLint alto=500;

/* GLUT callback Handlers */
void reshape(int width, int height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(50.0f, (GLfloat)width/(GLfloat)height, 1.0f, 100.0f);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0, 0, 50, 0, 0, 0, 0, 1, 0);

    glMatrixMode(GL_MODELVIEW);

    ancho = width;
    alto = height;
}

void casa(){
    //HOUSE
    //Base
    glPushMatrix();
    glColor3ub(204,255,0);
    glTranslatef(0,0,-4);
    glutSolidCube(7);
    glPopMatrix();
    //Roof
    glPushMatrix();
    glColor3ub(1,255,221);
    glTranslatef(0,2,-4);
    glRotatef(-90,1,0,0);
    glRotatef(40,0,0,1);
    glutSolidCone(8,5,4,4);
    glPopMatrix();
    //Main entrance
    glPushMatrix();
    glColor3ub(97,56,11);
    glTranslatef(0,0,0);
    glBegin(GL_QUADS);
    glVertex3f( 1,0,0);
    glVertex3f(-1,0,0);
    glVertex3f(-1,-3.7,0);
    glVertex3f(1,-3.7,0);
    glEnd();
    glPopMatrix();
}
void nube(){
    //NUBE
    glColor3ub(255,0,191);
    glPushMatrix();
    glTranslatef(0,0,0);
    glutSolidSphere(2,10,10);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(1.5,0,0);
    glutSolidSphere(2,10,10);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(3,0,0);
    glutSolidSphere(2,10,10);
    glPopMatrix();
}
void arbol(){
    //arbol 1
    glPushMatrix();
    glColor3ub(97,56,11);
    glTranslatef(53,-23.5,-4);
    glRotatef(-90,1,0,0);
    glutSolidCone(2,10,10,10);
    glPopMatrix();
    glPushMatrix();
    glColor3ub(254,100,46);
    glTranslatef(53,-13.5,-4);
    glutSolidSphere(5,10,10);
    glPopMatrix();
}
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    gluLookAt(0,0,0.8,0,0,0,0,1,0);
    //PISO
    glPushMatrix();
    glColor3ub(0,255,0);
    glBegin(GL_QUADS);
    glVertex3f( 60.0f,-23.5f,0.0f);
    glVertex3f(-60.0f,-23.5f,0.0f);
    glVertex3f(-60.0f,-23.5f,-50.0f);
    glVertex3f( 60.0f,-23.5f,-50.0f);
    glEnd();
    glPopMatrix();
    //LAterales Izq
    glPushMatrix();
    glColor3ub(255,255,0);
    glBegin(GL_QUADS);
    glVertex3f( -60.0f,-23.5f,0.0f);
    glVertex3f(-60.0f,-23.5f,-50.0f);
    glVertex3f(-60.0f,50.5f,-50.0f);
    glVertex3f( -60.0f,50.5f,0.0f);
    glEnd();
    glPopMatrix();
    //Lateral Der
    glPushMatrix();
    glColor3ub(255,255,0);
    glBegin(GL_QUADS);
    glVertex3f( 60.0f,-23.5f,0.0f);
    glVertex3f(60.0f,-23.5f,-50.0f);
    glVertex3f(60.0f,50.5f,-50.0f);
    glVertex3f( 60.0f,50.5f,0.0f);
    glEnd();
    glPopMatrix();
    //Fondo
    glPushMatrix();
    glColor3ub(255,255,0);
    glBegin(GL_QUADS);
    glVertex3f( 60.0f,-23.5,-49.0f);
    glVertex3f(-60.0f,-23.5,-49.0f);
    glVertex3f(-60.0f,48.5f,-49.0f);
    glVertex3f( 60.0f,48.5f,-49.0f);
    glEnd();
    glPopMatrix();
    //arbol1
    arbol();
    //arbol2
    glPushMatrix();
    glTranslatef(0,0,-20);
    arbol();
    glPopMatrix();
    //Arbol 3
    glPushMatrix();
    glTranslatef(0,0,-42);
    arbol();
    glPopMatrix();
    //arbol 4
    glPushMatrix();
    glTranslatef(-105,0,0);
    arbol();
    glPopMatrix();
    //arbol 5
    glPushMatrix();
    glTranslatef(-105,0,-20);
    arbol();
    glPopMatrix();
    //arbol 6
    glPushMatrix();
    glTranslatef(-105,0,-42);
    arbol();
    glPopMatrix();
    //Casa 1
    glPushMatrix();
    glTranslatef(20,-20.5,-20);
    casa();
    glPopMatrix();
    //Casa 2
    glPushMatrix();
    glTranslatef(5,-20.5,-20);
    casa();
    glPopMatrix();
    //Casa 3
    glPushMatrix();
    glTranslatef(-10,-20.5,-20);
    casa();
    glPopMatrix();
     //Casa 4
    glPushMatrix();
    glTranslatef(-25,-20.5,-20);
    casa();
    glPopMatrix();
     //Casa 5
    glPushMatrix();
    glTranslatef(-40,-20.5,-20);
    casa();
    glPopMatrix();
     //Casa 6 Der
    glPushMatrix();
    glTranslatef(35,-20.5,-20);
    casa();
    glPopMatrix();
    //Nube 1
    glPushMatrix();
    glTranslatef(-20,0,-50);
    glScalef(2,2,2);
    nube();
    glPopMatrix();
        //Nube 2
    glPushMatrix();
    glTranslatef(-10,0,-50);
    glScalef(2,2,2);
    nube();
    glPopMatrix();
        //Nube 3
    glPushMatrix();
    glTranslatef(40,0,-50);
    glScalef(2,2,2);
    nube();
    glPopMatrix();
        //Nube 4
    glPushMatrix();
    glTranslatef(-50,0,-50);
    glScalef(2,2,2);
    nube();
    glPopMatrix();
    //Nube5
    glPushMatrix();
    glTranslatef(15,0,-50);
    glScalef(2,2,2);
    nube();
    glPopMatrix();
    //sol
    glPushMatrix();
    glColor3ub(180,95,4);
    glTranslatef(40,25,-50);
    glScalef(2,2,2);
    glutSolidSphere(4,7,7);
    glPopMatrix();
    //Chiguiro
    glPushMatrix();
    glColor3ub(0,0,0);
    glTranslatef(-20,-20,0);
    glScalef(0.01,0.01,0.01);
    perroPrimeraEntrega();
    glPopMatrix();

   glutSwapBuffers();
}

void init()
{
  glShadeModel(GL_SMOOTH);
  glClearColor(0.0f, 0.0f, 0.0f, 0.5f);
  glClearDepth(1.0f);
  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LEQUAL);
  glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

/* Program entry point */

int main(int argc, char *argv[])
{

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB|GLUT_DEPTH);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(ancho, alto);
    glutCreateWindow("Segunda Entrega Proyecto");
    init();
    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
