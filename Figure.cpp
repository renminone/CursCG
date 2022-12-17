#include "Figure.h"
Figure::Figure(int flag)//Конструктор для инициализации вершин паралелипипедов(Инициализируется константными значениями)
{
	for (int i = 0; i < 6; i++)
	{
		mull_equ_and_light[i] = 0;
		mull_equ_and_observer[i] = 0;
	}
	if (flag == 0)
	{
		A[0][0] = 200; A[0][1] = 300; A[0][2] = 400; A[0][3] = 1;
		A[1][0] = 350; A[1][1] = 300; A[1][2] = 400; A[1][3] = 1;
		A[2][0] = 350; A[2][1] = 225; A[2][2] = 400; A[2][3] = 1;
		A[3][0] = 200; A[3][1] = 225; A[3][2] = 400; A[3][3] = 1;
		A[4][0] = 200; A[4][1] = 300; A[4][2] = 200; A[4][3] = 1;
		A[5][0] = 350; A[5][1] = 300; A[5][2] = 200; A[5][3] = 1;
		A[6][0] = 350; A[6][1] = 225; A[6][2] = 200; A[6][3] = 1;
		A[7][0] = 200; A[7][1] = 225; A[7][2] = 200; A[7][3] = 1;
	}
	else
	{
		A[0][0] = 250; A[0][1] = 350; A[0][2] = 350; A[0][3] = 1;
		A[1][0] = 400; A[1][1] = 350; A[1][2] = 350; A[1][3] = 1;
		A[2][0] = 400; A[2][1] = 275; A[2][2] = 350; A[2][3] = 1;
		A[3][0] = 250; A[3][1] = 275; A[3][2] = 350; A[3][3] = 1;
		A[4][0] = 250; A[4][1] = 350; A[4][2] = 200; A[4][3] = 1;
		A[5][0] = 400; A[5][1] = 350; A[5][2] = 200; A[5][3] = 1;
		A[6][0] = 400; A[6][1] = 275; A[6][2] = 200; A[6][3] = 1;
		A[7][0] = 250; A[7][1] = 275; A[7][2] = 200; A[7][3] = 1;
	}
	float a = 0, b = 0, c = 0;
	for (int i = 0; i < 8; i++) { a += A[i][0]; b += A[i][1]; c += A[i][2]; }
	a /= 8; b /= 8; c /= 8; //Если сразу в center сделать, будет исключение.
	center[0] = a; center[1] = b; center[2] = c;
	observer[0] = 0; observer[1] = 0; observer[2] = 2000; observer[3] = 1; //Вектор наблюдателя.
	light[0] = 0; light[1] = -1000; light[2] = 0; light[3] = 1; //Вектор света.
	y_floor = 700; //Пол
}
Figure::Figure(const Figure& F) { for (int i = 0; i < 8; i++) for (int j = 0; j < 4; j++) A[i][0] = F.A[i][0]; }
Figure& Figure::operator=(Figure& f)
{
	for (int i = 0; i < 8; i++) for (int j = 0; j < 4; j++) A[i][j] = f.A[i][j];
	return *this;
}
Figure& Figure::operator*(Vertex& Bb)
{
	// Умножение матриц A и Bb.b
	double tmp[8][4];
	for (int i = 0; i < 8; i++)
	{
		tmp[i][0] = (A[i][0] * Bb.B[0][0] + A[i][1] * Bb.B[0][1] + A[i][2] * Bb.B[0][2] + A[i][3] * Bb.B[0][3]);
		tmp[i][1] = (A[i][0] * Bb.B[1][0] + A[i][1] * Bb.B[1][1] + A[i][2] * Bb.B[1][2] + A[i][3] * Bb.B[1][3]);
		tmp[i][2] = (A[i][0] * Bb.B[2][0] + A[i][1] * Bb.B[2][1] + A[i][2] * Bb.B[2][2] + A[i][3] * Bb.B[2][3]);
		tmp[i][3] = (A[i][0] * Bb.B[3][0] + A[i][1] * Bb.B[3][1] + A[i][2] * Bb.B[3][2] + A[i][3] * Bb.B[3][3]);
	}
	for (int i = 0; i < 8; i++) for (int j = 0; j < 4; j++) A[i][j] = tmp[i][j];
	return *this;
}
Figure::~Figure() { }
void Figure::drawgran(float x0, float y0, float x1, float y1, float x2, float y2, float x3, float y3, int flag, int flag2)
//flag: 1 - цвет, 0 - тень. flag2: 0 - рёбра, отличные от тени.
{
	bool** array_of_paint_pixel;//Массив для закрашеных и не закрашеных пикселей
	array_of_paint_pixel = new bool* [770];
	for (int i = 0; i < 770; i++)
	{
		array_of_paint_pixel[i] = new bool[1370];
		for (int j = 0; j < 1370; j++) array_of_paint_pixel[i][j] = false;//Изначатьно все не закрашены
	}
	int color_1, color_2, color_3;
	if (flag == 1) { color_1 = 255; color_2 = color_3 = 0; } //Цвет.
	else
	{
		if (flag2 == 0) color_1 = color_2 = color_3 = 70;
		else { color_1 = color_2 = color_3 = 50; }
	}
	int B[5][3] = { {round(x0), round(y0),1} ,{round(x1),round(y1), 1}, {round(x2),round(y2), 1} ,{round(x3),round(y3), 1}, {round(x0),round(y0), 1} };
	for (int i = 0; i < 4; i++)
	{
		int dx = abs(B[i][0] - B[i + 1][0]);
		int dy = abs(B[i][1] - B[i + 1][1]);
		int sx = B[i][0] < B[i + 1][0] ? 1 : -1;
		int sy = B[i][1] < B[i + 1][1] ? 1 : -1;
		int err = (dx > dy ? dx : -dy) / 2;
		double e2 = err;
		while (1)
		{
			//setcolor(color_1);
			putpixel(B[i][0], B[i][1], RGB(color_1, color_2, color_3));
			array_of_paint_pixel[B[i][1]][B[i][0]] = true;
			if (B[i][0] == B[i + 1][0] && B[i][1] == B[i + 1][1]) break;
			e2 = err;
			if (e2 > -dx) { err -= dy; B[i][0] += sx; }
			if (e2 < dy) { err += dx; B[i][1] += sy; }
		}
	}
	//Заливка
	fill(round((x0 + x1 + x2 + x3) / 4), round((y0 + y1 + y2 + y3) / 4), flag, array_of_paint_pixel);
	for (int i = 0; i < 770; i++) delete[] array_of_paint_pixel[i];
	delete[] array_of_paint_pixel;
}
void Figure::del_invisible_line()
{
	for (int i = 0; i < 6; i++) for (int j = 0; j < 4; j++) Matr_of_flat_equation[j][i] = 0;
	for (int i = 0; i < 6; i++)
	{
		mull_equ_and_light[i] = 0;
		mull_equ_and_observer[i] = 0;
	}
	//получим матрицу уравнений плоскостей граней
	equation_of_flat(0, 0, 1, 3, 2);// грань из точек 0-1-2-3
	equation_of_flat(1, 6, 5, 7, 4);// грань из точек 4-5-6-7
	equation_of_flat(2, 0, 4, 1, 5);// грань из точек 0-1-5-4
	equation_of_flat(3, 1, 5, 2, 6);// грань из точек 5-1-2-6
	equation_of_flat(4, 2, 6, 3, 7);// грань из точек 6-2-3-7
	equation_of_flat(5, 3, 7, 0, 4);// грань из точек 7-3-0-4
	//Проверка через точку, лежащую в центре параллелепипеда
	float try_arr[4] = { center[0], center[1], center[2], 1 };
	float sum = 0;
	for (int i = 0; i < 6; i++)
	{
		sum = 0;
		for (int j = 0; j < 4; j++) sum += (try_arr[j] * Matr_of_flat_equation[j][i]);
		if (sum >= 0)// Следует домножить всё уравнение на -1
			for (int j = 0; j < 4; j++) Matr_of_flat_equation[j][i] *= -1;
	}
	//Центральные точки каждой грани
	float dot_of_center_of_edge[6][4] =
	{ { (A[0][0] + A[1][0] + A[2][0] + A[3][0]) / 4, (A[0][1] + A[1][1] + A[2][1] + A[3][1]) / 4 , (A[0][2] + A[1][2] + A[2][2] + A[3][2]) / 4, 1},
	{ (A[4][0] + A[5][0] + A[6][0] + A[7][0]) / 4, (A[4][1] + A[5][1] + A[6][1] + A[7][1]) / 4 , (A[4][2] + A[5][2] + A[6][2] + A[7][2]) / 4, 1},
	{ (A[0][0] + A[1][0] + A[5][0] + A[4][0]) / 4, (A[0][1] + A[1][1] + A[5][1] + A[4][1]) / 4 , (A[0][2] + A[1][2] + A[5][2] + A[4][2]) / 4, 1},
	{ (A[5][0] + A[1][0] + A[2][0] + A[6][0]) / 4, (A[5][1] + A[1][1] + A[2][1] + A[6][1]) / 4 , (A[5][2] + A[1][2] + A[2][2] + A[6][2]) / 4, 1},
	{ (A[6][0] + A[2][0] + A[3][0] + A[7][0]) / 4, (A[6][1] + A[2][1] + A[3][1] + A[7][1]) / 4 , (A[6][2] + A[2][2] + A[3][2] + A[7][2]) / 4, 1},
	{ (A[7][0] + A[3][0] + A[0][0] + A[4][0]) / 4, (A[7][1] + A[3][1] + A[0][1] + A[4][1]) / 4 , (A[7][2] + A[3][2] + A[0][2] + A[4][2]) / 4, 1} };
	for (int i = 0; i < 6; i++)
	{
		mull_equ_and_light[i] = 0;
		mull_equ_and_observer[i] = 0;
		for (int j = 0; j < 4; j++)
		{
			mull_equ_and_observer[i] += (Matr_of_flat_equation[j][i] * (observer[j] - dot_of_center_of_edge[i][j]));
			mull_equ_and_light[i] += (Matr_of_flat_equation[j][i] * (light[j] -	dot_of_center_of_edge[i][j]));
		}
	}
}
void Figure::equation_of_flat(int num_of_flat, int T1, int T2, int T3, int T4)
{
	float x1 = A[T1][0], x2 = A[T2][0], x3 = A[T3][0], x4 = A[T4][0],
		y1 = A[T1][1], y2 = A[T2][1], y3 = A[T3][1], y4 = A[T4][1],
		z1 = A[T1][2], z2 = A[T2][2], z3 = A[T3][2], z4 = A[T4][2];
	float v1[3] = { x2 - x1, y2 - y1, z2 - z1 };//v1
	float v2[3] = { x3 - x1, y3 - y1, z3 - z1 };//v2
	Matr_of_flat_equation[0][num_of_flat] = (v1[1] * v2[2] - v1[2] * v2[1]); //Находим коэфф А
	Matr_of_flat_equation[1][num_of_flat] = (v1[2] * v2[0] - v1[0] * v2[2]); //Находим коэфф B
	Matr_of_flat_equation[2][num_of_flat] = (v1[0] * v2[1] - v1[1] * v2[0]); //Находим коэфф C
	Matr_of_flat_equation[3][num_of_flat] = -(Matr_of_flat_equation[0][num_of_flat] * ((x1 + x2 + x3 + x4) / 4)
		+ Matr_of_flat_equation[1][num_of_flat] * ((y1 + y2 + y3 + y4) / 4)
		+ Matr_of_flat_equation[2][num_of_flat] * ((z1 + z2 + z3 + z4) / 4)); //Находим коэфф D
	for (int i = 0; i < 4; i++)
		Matr_of_flat_equation[i][num_of_flat] = Matr_of_flat_equation[i][num_of_flat] / Matr_of_flat_equation[3][num_of_flat];
}
void Figure::draw()// рисуем параллелипипед
{
	//Установка новых точек центра
	float a = 0, b = 0, c = 0;
	for (int i = 0; i < 8; i++) { a += A[i][0]; b += A[i][1]; c += A[i][2]; }
	a /= 8; b /= 8; c /= 8;
	center[0] = a; center[1] = b; center[2] = c;
	draw_shadow();//Рисуем тень
	del_invisible_line();// Вычисление удаляемых и теневых плоскостей
	//Рисование основной фигуры
	//Центральная проекция
	float L[8][2], zk = observer[2], zm = 600; //Задание данных подобрано вручную. zk - расстояние до глаза, zm расстояние от 3D-объекта до монитора.
	for (int i = 0; i < 8; i++)
	{
		L[i][0] = A[i][0] * (zk - zm) / (zk - A[i][2]);
		L[i][1] = A[i][1] * (zk - zm) / (zk - A[i][2]);
	}
	//Сделать заливку
	//Если матрица произведений уравнений плоскости на вектор источника света больше или равна 0, то грань не в тени. Иначе в тени.
	// грань из точек 0-1-2-3
	if (mull_equ_and_observer[0] >= 0)
	{
		if (mull_equ_and_light[0] >= 0) drawgran(L[0][0], L[0][1], L[1][0], L[1][1], L[2][0], L[2][1], L[3][0], L[3][1], 1, 0);
		else drawgran(L[0][0], L[0][1], L[1][0], L[1][1], L[2][0], L[2][1], L[3][0], L[3][1], 0, 1);
	}
	// грань из точек 4-5-6-7
	if (mull_equ_and_observer[1] >= 0)
	{
		if (mull_equ_and_light[1] >= 0) drawgran(L[4][0], L[4][1], L[5][0], L[5][1], L[6][0], L[6][1], L[7][0], L[7][1], 1, 0);
		else drawgran(L[4][0], L[4][1], L[5][0], L[5][1], L[6][0], L[6][1], L[7][0], L[7][1], 0, 1);
	}
	// грань из точек 0-1-5-4
	if (mull_equ_and_observer[2] >= 0)
	{
		if (mull_equ_and_light[2] >= 0) drawgran(L[0][0], L[0][1], L[1][0], L[1][1], L[5][0], L[5][1], L[4][0], L[4][1], 1, 0);
		else drawgran(L[0][0], L[0][1], L[1][0], L[1][1], L[5][0], L[5][1], L[4][0], L[4][1], 0, 1);
	}
	// грань из точек 5-1-2-6
	if (mull_equ_and_observer[3] >= 0)
	{
		if (mull_equ_and_light[3] >= 0) drawgran(L[5][0], L[5][1], L[1][0], L[1][1], L[2][0], L[2][1], L[6][0], L[6][1], 1, 0);
		else drawgran(L[5][0], L[5][1], L[1][0], L[1][1], L[2][0], L[2][1], L[6][0], L[6][1], 0, 1);
	}
	// грань из точек 6-2-3-7
	if (mull_equ_and_observer[4] >= 0)
	{
		if (mull_equ_and_light[4] >= 0) drawgran(L[6][0], L[6][1], L[2][0], L[2][1], L[3][0], L[3][1], L[7][0], L[7][1], 1, 0);
		else drawgran(L[6][0], L[6][1], L[2][0], L[2][1], L[3][0], L[3][1], L[7][0], L[7][1], 0, 1);
	}
	// грань из точек 7-3-0-4
	if (mull_equ_and_observer[5] >= 0)
	{
		if (mull_equ_and_light[5] >= 0) drawgran(L[7][0], L[7][1], L[3][0], L[3][1], L[0][0], L[0][1], L[4][0], L[4][1], 1, 0);
		else drawgran(L[7][0], L[7][1], L[3][0], L[3][1], L[0][0], L[0][1], L[4][0], L[4][1], 0, 1);
	}
}
int Figure::fill(int x_pixel, int y_pixel, int flag, bool** array_of_paint_pixel)
{
	stack <int> stack_obg;
	int color1 = 0, color2 = 0, color3 = 0;
	int x_left = 0, x_right = 0, x_now, y_now;
	int flag_fill = 0;
	if (array_of_paint_pixel[y_pixel][x_pixel] != true)
	{
		if (flag == 0) color1 = color2 = color3 = 70; //Цвет тени
		else { color1 = 255; color2 = 255; color3 = 0; }
		stack_obg.push(x_pixel);// Помещаем в стек затравочный x_pixel
		stack_obg.push(y_pixel);//Помещаем в стек затравочный y_pixel
		while (stack_obg.empty() != true)
		{
			//Извлекаем x и y с верхушки стэка
			y_now = stack_obg.top(); stack_obg.pop();
			x_now = stack_obg.top(); stack_obg.pop();
			x_right = x_now; //Для x_right
			while ((array_of_paint_pixel[y_now][x_right] != true) || (x_right == x_now))
			{
				array_of_paint_pixel[y_now][x_right] = true;
				putpixel(x_right, y_now, RGB(color1, color2, color3));
				x_right++;
				if (x_right == 1370) { return 1; }
			}
			x_left = x_now; //Для x _left
			while ((array_of_paint_pixel[y_now][x_left] != true) || (x_left == x_now))
			{
				array_of_paint_pixel[y_now][x_left] = true;
				putpixel(x_left, y_now, RGB(color1, color2, color3));
				x_left--;
				if (x_left == -1) { return 1; }
			}
			x_left++; x_right--;
			for (int i = x_left; i <= x_right; i++) putpixel(i, y_now, RGB(color1, color2, color3));
			//Проверка строки выше
			bool flag_1 = 0;
			int y = y_now + 1;
			for (int x = x_left; x <= x_right; x++)
			{
				if (array_of_paint_pixel[y][x] == false) flag_1 = 1;
				if ((flag_1 == 1) && (array_of_paint_pixel[y][x + 1] == true))
				{
					//Помещаем данный пиксель в стэк
					stack_obg.push(x);// Помещаем в стек затравочный x_pixel
					stack_obg.push(y);//Помещаем в стек затравочный y_pixel
					flag_1 = 0;
				}
				if ((x == x_right) && (flag_1 == 1))
				{
					//Помещаем данный пиксель в стэк
					stack_obg.push(x);// Помещаем в стек затравочный x_pixel
					stack_obg.push(y);//Помещаем в стек затравочный y_pixel
					flag_1 = 0;
				}
			}
			//Проверка строки ниже
			y = y_now - 1; flag_1 = 0;
			for (int x = x_left; x <= x_right; x++)
			{
				if (array_of_paint_pixel[y][x] == false) flag_1 = 1; 
				if ((flag_1 == 1) && (array_of_paint_pixel[y][x + 1] == true))
				{
					//Помещаем данный пиксель в стэк
					stack_obg.push(x);// Помещаем в стек затравочный x_pixel
					stack_obg.push(y);//Помещаем в стек затравочный y_pixel
					flag_1 = 0;
				}
				if ((x == x_right) && (flag_1 == 1))
				{
					//Помещаем данный пиксель в стэк
					stack_obg.push(x);// Помещаем в стек затравочный x_pixel
					stack_obg.push(y);//Помещаем в стек затравочный y_pixel
					flag_1 = 0;
				}
			}
		}
	}
	return 0;
}
void Figure::draw_shadow()
{
	float dot_of_shadow[8][4];
	int xl = light[0], yl = light[1], zl = light[2];
	int xp = 0, yp = 0, zp = 0;
	//dot_of_shadow[8][4]
	//Взять проекцую точек на плоскость пола
	for (int i = 0; i < 8; i++)
	{
		xp = A[i][0]; yp = A[i][1]; zp = A[i][2];
		dot_of_shadow[i][0] = xp; dot_of_shadow[i][1] = y_floor;
		dot_of_shadow[i][2] = zp; dot_of_shadow[i][3] = 1;
	}
	//Рисование и заливка тени
	float L[8][2], zk = observer[2], zm = 600; //Задание данных подобрано вручную. zk - расстояние до глаза, zm расстояние от 3D-объекта до монитора.
	for (int i = 0; i < 8; i++)
	{
		L[i][0] = dot_of_shadow[i][0] * (zk - zm) / (zk - dot_of_shadow[i][2]);
		L[i][1] = dot_of_shadow[i][1] * (zk - zm) / (zk - dot_of_shadow[i][2]);
	}
	
	drawgran(L[0][0], L[0][1], L[1][0], L[1][1], L[2][0], L[2][1], L[3][0], L[3][1], 0, 0); //грань из точек 0-1-2-3
	drawgran(L[4][0], L[4][1], L[5][0], L[5][1], L[6][0], L[6][1], L[7][0], L[7][1], 0, 0); //грань из точек 4-5-6-7
	drawgran(L[0][0], L[0][1], L[1][0], L[1][1], L[5][0], L[5][1], L[4][0], L[4][1], 0, 0); //грань из точек 0-1-5-4
	drawgran(L[5][0], L[5][1], L[1][0], L[1][1], L[2][0], L[2][1], L[6][0], L[6][1], 0, 0); //грань из точек 5-1-2-6
	drawgran(L[6][0], L[6][1], L[2][0], L[2][1], L[3][0], L[3][1], L[7][0], L[7][1], 0, 0); //грань из точек 6-2-3-7
	drawgran(L[7][0], L[7][1], L[3][0], L[3][1], L[0][0], L[0][1], L[4][0], L[4][1], 0, 0); //грань из точек 7-3-0-4
}
void Figure::move(int flag)
{
	Figure N(0);
	N = *this;
	double dx = 0, dy = 0, dz = 0;
	int d = 20;
	if (flag == 6) dx = d;
	if (flag == 4) dx = -d;
	if (flag == 8) dy = -d;
	if (flag == 2) dy = d;
	if (flag == 7) dz = -d;
	if (flag == 9) dz = d;
	Vertex B((1), (0), (0), (dx), (0), (1), (0), (dy), (0), (0), (1), (dz), (0), (0), (0), (1));
	N* B;
	//Проверка выхода за границы массива
	if (N.going_abroad() == false) * this = N;
}
void Figure::scale(int flag)
{
	Figure N(0);
	N = *this;
	double dx = 0, dy = 0, dz = 0;
	double S = 2, s = 0.5;//1.05; 0.95
	double k;
	if (flag == 3) k = S;
	if (flag == 1) k = s;
	for (int i = 0; i < 8; i++) { dx += A[i][0]; dy += A[i][1]; dz += A[i][2]; }
	dx /= 8; dy /= 8; dz /= 8;
	Vertex B((k), (0), (0), (0), (0), (k), (0), (0), (0), (0), (k), (0), (0), (0), (0), (1));
	Vertex Bd((1), (0), (0), (-dx), (0), (1), (0), (-dy), (0), (0), (1), (-dz), (0), (0), (0), (1));
	Vertex Bmd((1), (0), (0), (dx), (0), (1), (0), (dy), (0), (0), (1), (dz), (0), (0), (0), (1));
	N* Bd; N* B; N* Bmd;
	//Проверка выхода за границы массива
	if (N.going_abroad() == false) *this = N;
}
void Figure::rotate(int flag, int flag2)
{
	Figure N(0);
	N = *this;
	const double fi = 0.1;// 0.033
	double dx = 0, dy = 0, dz = 0;
	//находим центр
	for (int i = 0; i < 8; i++) { dx += A[i][0]; dy += A[i][1]; dz += A[i][2]; }
	dx /= 8; dy /= 8; dz /= 8;
	Vertex Bd((1), (0), (0), (-dx), (0), (1), (0), (-dy), (0), (0), (1), (-dz), (0), (0), (0), (1));
	Vertex Bmd((1), (0), (0), (dx), (0), (1), (0), (dy), (0), (0), (1), (dz), (0), (0), (0), (1));
	double U = flag2 ? fi : -fi;
	if (flag == 1)//вокруг х
	{
		Vertex B((1), (0), (0), (0), (0), (cos(U)), (-sin(U)), (0), (0), (sin(U)), (cos(U)), (0), (0), (0), (0), (1));
		N* Bd; N* B; N* Bmd;
	}
	if (flag == 2)// вокруг у
	{
		Vertex B((cos(U)), (0), (-sin(U)), (0), (0), (1), (0), (0), (sin(U)), (0), ((cos(U))), (0), (0), (0), (0), (1));
		N* Bd; N* B; N* Bmd;
	}
	if (flag == 3)// вокруг z
	{
		Vertex B((cos(U)), (-sin(U)), (0), (0), (sin(U)), (cos(U)), (0), (0), (0), (0), (1), (0), (0), (0), (0), (1));
		N* Bd; N* B; N* Bmd;
	}
	//Проверка выхода за границы массива
	if (N.going_abroad() == false) *this = N;
}
bool Figure::going_abroad()
{
	float L[8][2], zk = observer[2], zm = 600; //Задание данных подобрано вручную. zk - расстояние до глаза, zm расстояние от 3D-объекта до монитора.
	bool flag_1 = false;
	for (int i = 0; i < 8; i++)
	{
		L[i][0] = A[i][0] * (zk - zm) / (zk - A[i][2]);
		L[i][1] = A[i][1] * (zk - zm) / (zk - A[i][2]);
	}
	for (int i = 0; i < 8; i++)
	{
		if ((L[i][0] > 1368) || (L[i][0] < 0)) flag_1 = true; //x
		if ((A[i][1] >= y_floor) || (L[i][1] < 0)) flag_1 = true; //y
	}
	return flag_1;
}