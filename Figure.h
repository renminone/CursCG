#pragma once
#include <conio.h>
#include "Vertex.h"
#include "graphics.h"
#pragma comment(lib, "graphics.lib")
#include <cmath>
#include <iostream>
#include <stack>

using namespace std;
class Figure
{
	float A[8][4];//Матрица с точками параллелипипида
	float Matr_of_flat_equation[4][6];//Матрица уравнений плоскости
	float mull_equ_and_light[6];// Матрица произведений уравнений плоскости на вектор источника света
	float mull_equ_and_observer[6];//Матрица произведений уравнений плоскости на вектор наблюдателя
	int observer[4];//Точка наблюдения, задаётся в конструкторе
	int light[4];//Точка источника света(в бесконечности,типа =))), задаётся в конструкторе
	float center[3];
	int y_floor;
public:
	Figure(int flag);
	Figure(const Figure& F);
	Figure& operator=(Figure& f);
	Figure & operator*(Vertex & Bb);
	~Figure();
	void drawgran(float x0, float y0, float x1, float y1, float x2, float y2, float x3, float y3, int flag, int flag2);//Рисование грани
	void del_invisible_line();//Удаление невидимых граней
	void equation_of_flat(int num_of_flat, int T1, int T2, int T3, int T4);//num_of_flat номер плоскости результата, t1, t2, t3 порядок точек в матрице
	void draw();//Рисование фигуры
	int fill(int x_pixel, int y_pixel, int flag, bool** array_of_paint_pixel); // flag = 0 в тени, flag = 1 в цвете.
	void draw_shadow();//Рисование тени
	void move(int flag);//Перемешение
	void scale(int flag);//Масштабирование
	void rotate(int flag, int flag2);//Вращение
	bool going_abroad();//Проверка на выход за границу экрана
};
