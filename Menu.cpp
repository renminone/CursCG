#include "Menu.h"
int l = 1;

int Menu::menu()
{
	Figure paral_1(0), paral_2(1);//Создание обёкта 2 пар-дов, инициализация по умолчанию
	char choice = '0';
	do
	{
		if (l == 1) { initwindow(1920, 1080); l = 0; } //Чтоб окна не открывались постоянно.
		system("cls");
		cout << "Меню: " << endl;
		cout << "Для выхода нажмите 0. Любая другая клавиша нарисует фигуры и отправит в выбор режима." << endl;
		choice = _getch();
		if (choice == '0') break;
		menu_par(par1, par2);
	} while (1);
	return 0;
}
void Menu::moving(Figure& obg, Figure& par)
{
	cout << "Режим перемещения: " << endl;
	cout << "WS - по оси y." << endl;
	cout << "AD - по оси x" << endl;
	cout << "QE - по оси z" << endl;
	do
	{
		if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) { cout << "Выход из режима перемещения успешно!" << endl; break; }
		if (GetAsyncKeyState((unsigned short)'Q') & 0x8000) //Перемещение по Z вперед
		{ clearviewport(); obg.move(9); par.move(9); par.draw(); obg.draw(); }
		if (GetAsyncKeyState((unsigned short)'S') & 0x8000) //Перемещение по Y вниз
		{ clearviewport(); obg.move(2); par.move(2); par.draw(); obg.draw(); }
		if (GetAsyncKeyState((unsigned short)'E') & 0x8000) //перемещение по Z назад
		{ clearviewport(); obg.move(7); par.move(7); par.draw(); obg.draw(); }
		if (GetAsyncKeyState((unsigned short)'W') & 0x8000) //Перемещение по Y вверх
		{ clearviewport(); obg.move(8); par.move(8); par.draw(); obg.draw(); }
		if (GetAsyncKeyState((unsigned short)'D') & 0x8000) //Перемещение по X вправо
		{ clearviewport(); obg.move(6); par.move(6); par.draw(); obg.draw(); }
		if (GetAsyncKeyState((unsigned short)'A') & 0x8000) //перемещение по X влево
		{ clearviewport(); obg.move(4); par.move(4); par.draw(); obg.draw(); }
	}
	while (1);
}

void Menu::scaling(Figure& obg, Figure& par)
{
	cout << "Режим масштабирования: " << endl;
	cout << "W - расширение." << endl;
	cout << "S - сжатие." << endl;
	do
	{
		if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) break;
		if (GetAsyncKeyState((unsigned short)'W') & 0x8000) //Расширение
		{ clearviewport(); obg.scale(3); par.scale(3); par.draw(); obg.draw(); }
		if (GetAsyncKeyState((unsigned short)'S') & 0x8000) //Сжатие
		{ clearviewport(); obg.scale(1); par.scale(1); par.draw(); obg.draw(); }
	}
	while (1);
}

void Menu::rotating(Figure& obg, Figure& par)
{
	cout << "Режим вращения: " << endl;
	cout << "WS - по оси y." << endl;
	cout << "AD - по оси x" << endl;
	cout << "QE - по оси z" << endl;
	do
	{
		if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) break;
		if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) break;
		if (GetAsyncKeyState((unsigned short)'A') & 0x8000) //Вращать вокруг х против часовой
		{ clearviewport(); obg.rotate(1, 0); par.rotate(1, 0); par.draw(); obg.draw(); }
		if (GetAsyncKeyState((unsigned short)'D') & 0x8000) //Вращать вокруг х по часовой
		{ clearviewport(); obg.rotate(1, 1); par.rotate(1, 1); par.draw(); obg.draw(); }
		if (GetAsyncKeyState((unsigned short)'W') & 0x8000) //Вращать вокруг y по часовой
		{ clearviewport(); obg.rotate(2, 0); par.rotate(2, 0); par.draw(); obg.draw(); }
		if (GetAsyncKeyState((unsigned short)'S') & 0x8000) //Вращать вокруг y против часовой
		{ clearviewport(); obg.rotate(2, 1); par.rotate(2, 1); par.draw(); obg.draw(); }
		if (GetAsyncKeyState((unsigned short)'Q') & 0x8000) //Вращать вокруг z против часовой
		{ clearviewport(); obg.rotate(3, 0); par.rotate(3, 0); par.draw(); obg.draw(); }
		if (GetAsyncKeyState((unsigned short)'E') & 0x8000) //Вращать вокруг z по часовой
		{ clearviewport(); obg.rotate(3, 1); par.rotate(3, 1); par.draw(); obg.draw(); }
	} while (1);
}

void Menu::menu_par(Figure& obg, Figure& par)
{
	cout << "Выберите режим :" << endl;
	cout << "M - перемещение." << endl << "S - масштабирование." << endl << "R - вращение." << endl;
	par.draw(); obg.draw();
	do
	{
		if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) break;
		if (GetAsyncKeyState((unsigned short)'M') & 0x8000) moving(obg, par);
		if (GetAsyncKeyState((unsigned short)'S') & 0x8000) scaling(obg, par);
		if (GetAsyncKeyState((unsigned short)'R') & 0x8000) rotating(obg, par);
	} while (1);
}
