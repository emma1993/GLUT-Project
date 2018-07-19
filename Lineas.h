#ifndef LINEAS_H_INCLUDED
#define LINEAS_H_INCLUDED
#include <GL/glut.h>
#include <GL/freeglut.h>
#include <GL/gl.h>
void pixel(int x,int y);
void algoritmoBresenham(int xi, int xf,int yi, int yf);
void puntoMedio(int xc,int yc,int r);
void mediaElipse(int xc,int yc, int rx,int ry, int region);
void muslos(int xc, int yc,int r);
void perroPrimeraEntrega();
#include "Lineas.cpp"
#endif // LINEAS_H_INCLUDED

