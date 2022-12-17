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
	float A[8][4];//������� � ������� ���������������
	float Matr_of_flat_equation[4][6];//������� ��������� ���������
	float mull_equ_and_light[6];// ������� ������������ ��������� ��������� �� ������ ��������� �����
	float mull_equ_and_observer[6];//������� ������������ ��������� ��������� �� ������ �����������
	int observer[4];//����� ����������, ������� � ������������
	int light[4];//����� ��������� �����(� �������������,���� =))), ������� � ������������
	float center[3];
	int y_floor;
public:
	Figure(int flag);
	Figure(const Figure& F);
	Figure& operator=(Figure& f);
	Figure & operator*(Vertex & Bb);
	~Figure();
	void drawgran(float x0, float y0, float x1, float y1, float x2, float y2, float x3, float y3, int flag, int flag2);//��������� �����
	void del_invisible_line();//�������� ��������� ������
	void equation_of_flat(int num_of_flat, int T1, int T2, int T3, int T4);//num_of_flat ����� ��������� ����������, t1, t2, t3 ������� ����� � �������
	void draw();//��������� ������
	int fill(int x_pixel, int y_pixel, int flag, bool** array_of_paint_pixel); // flag = 0 � ����, flag = 1 � �����.
	void draw_shadow();//��������� ����
	void move(int flag);//�����������
	void scale(int flag);//���������������
	void rotate(int flag, int flag2);//��������
	bool going_abroad();//�������� �� ����� �� ������� ������
};