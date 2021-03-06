﻿// ConsoleApplication26.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <math.h>
#include <stdio.h>
#include <windows.h>  //для захвата консоли используем WinAPI

#define M_PI 3.14

//функция возвращает расстояние между двумя точками
double fRetLen(double x1, double y1, double x2, double y2)
{
  return sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
}

//функция возвращает дирекционный угол
double fRetDir(double x1, double y1, double x2, double y2)
{
  double len = fRetLen(x1, y1, x2, y2);
  double dir;

  dir = acos((x2 - x1) / len);
  if (y2 - y1<0)
    dir = 2 * M_PI - dir;

  return dir;
}

//функция возвращает точку пересечения 2 прямых
void fAngleInt(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4, double *xo, double *yo)
{
  double k[2], r;

  k[0] = (x4 - x3)*(y3 - y1) - (y4 - y3)*(x3 - x1);
  k[1] = (x4 - x3)*(y2 - y1) - (y4 - y3)*(x2 - x1);

  r = k[0] / k[1];

  *xo = x1 + r*(x2 - x1);
  *yo = y1 + r*(y2 - y1);
}

int main()
{
  POINT pp[4];  //объявляем 4 структуры POINT для хранения координат

  int i;
  double ang[2];
  double xo = 0;
  double yo = 0;

  for (i = 0; i<4; i++)
  {
    printf("X%d=", i + 1);
    scanf_s("%d", &pp[i].x);
    printf("Y%d=", i + 1);
    scanf_s("%d", &pp[i].y);
  }
  //вводим координаты

  ang[0] = fRetDir(xo, yo, pp[0].x, pp[0].y);
  ang[1] = fRetDir(xo, yo, pp[2].x, pp[2].y); //получаем дирекционные углы

  fAngleInt(pp[0].x, pp[0].y, pp[1].x, pp[1].y, pp[2].x, pp[2].y, pp[3].x, pp[3].y, &xo, &yo); //получем координаты пересечения

  printf("Coordinate X=%f, Y=%f\n", xo, yo);
  printf("Angle = %f\n", ang[0] - ang[1]);

  system("pause");
}
