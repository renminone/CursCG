#include "Menu.h"
int l = 1;

int Menu::menu()
{
	Figure paral_1(0), paral_2(1);//�������� ����� 2 ���-���, ������������� �� ���������
	char choice = '0';
	do
	{
		if (l == 1) { initwindow(1920, 1080); l = 0; } //���� ���� �� ����������� ���������.
		system("cls");
		cout << "����: " << endl;
		cout << "��� ������ ������� 0. ����� ������ ������� �������� ������ � �������� � ����� ������." << endl;
		choice = _getch();
		if (choice == '0') break;
		menu_par(par1, par2);
	} while (1);
	return 0;
}
void Menu::moving(Figure& obg, Figure& par)
{
	cout << "����� �����������: " << endl;
	cout << "WS - �� ��� y." << endl;
	cout << "AD - �� ��� x" << endl;
	cout << "QE - �� ��� z" << endl;
	do
	{
		if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) { cout << "����� �� ������ ����������� �������!" << endl; break; }
		if (GetAsyncKeyState((unsigned short)'Q') & 0x8000) //����������� �� Z ������
		{ clearviewport(); obg.move(9); par.move(9); par.draw(); obg.draw(); }
		if (GetAsyncKeyState((unsigned short)'S') & 0x8000) //����������� �� Y ����
		{ clearviewport(); obg.move(2); par.move(2); par.draw(); obg.draw(); }
		if (GetAsyncKeyState((unsigned short)'E') & 0x8000) //����������� �� Z �����
		{ clearviewport(); obg.move(7); par.move(7); par.draw(); obg.draw(); }
		if (GetAsyncKeyState((unsigned short)'W') & 0x8000) //����������� �� Y �����
		{ clearviewport(); obg.move(8); par.move(8); par.draw(); obg.draw(); }
		if (GetAsyncKeyState((unsigned short)'D') & 0x8000) //����������� �� X ������
		{ clearviewport(); obg.move(6); par.move(6); par.draw(); obg.draw(); }
		if (GetAsyncKeyState((unsigned short)'A') & 0x8000) //����������� �� X �����
		{ clearviewport(); obg.move(4); par.move(4); par.draw(); obg.draw(); }
	}
	while (1);
}

void Menu::scaling(Figure& obg, Figure& par)
{
	cout << "����� ���������������: " << endl;
	cout << "W - ����������." << endl;
	cout << "S - ������." << endl;
	do
	{
		if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) break;
		if (GetAsyncKeyState((unsigned short)'W') & 0x8000) //����������
		{ clearviewport(); obg.scale(3); par.scale(3); par.draw(); obg.draw(); }
		if (GetAsyncKeyState((unsigned short)'S') & 0x8000) //������
		{ clearviewport(); obg.scale(1); par.scale(1); par.draw(); obg.draw(); }
	}
	while (1);
}

void Menu::rotating(Figure& obg, Figure& par)
{
	cout << "����� ��������: " << endl;
	cout << "WS - �� ��� y." << endl;
	cout << "AD - �� ��� x" << endl;
	cout << "QE - �� ��� z" << endl;
	do
	{
		if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) break;
		if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) break;
		if (GetAsyncKeyState((unsigned short)'A') & 0x8000) //������� ������ � ������ �������
		{ clearviewport(); obg.rotate(1, 0); par.rotate(1, 0); par.draw(); obg.draw(); }
		if (GetAsyncKeyState((unsigned short)'S') & 0x8000) //������� ������ � �� �������
		{ clearviewport(); obg.rotate(1, 1); par.rotate(1, 1); par.draw(); obg.draw(); }
		if (GetAsyncKeyState((unsigned short)'W') & 0x8000) //������� ������ y �� �������
		{ clearviewport(); obg.rotate(2, 0); par.rotate(2, 0); par.draw(); obg.draw(); }
		if (GetAsyncKeyState((unsigned short)'S') & 0x8000) //������� ������ y ������ �������
		{ clearviewport(); obg.rotate(2, 1); par.rotate(2, 1); par.draw(); obg.draw(); }
		if (GetAsyncKeyState((unsigned short)'Q') & 0x8000) //������� ������ z ������ �������
		{ clearviewport(); obg.rotate(3, 0); par.rotate(3, 0); par.draw(); obg.draw(); }
		if (GetAsyncKeyState((unsigned short)'E') & 0x8000) //������� ������ z �� �������
		{ clearviewport(); obg.rotate(3, 1); par.rotate(3, 1); par.draw(); obg.draw(); }
	} while (1);
}

void Menu::menu_par(Figure& obg, Figure& par)
{
	cout << "�������� ����� :" << endl;
	cout << "M - �����������." << endl << "S - ���������������." << endl << "R - ��������." << endl;
	par.draw(); obg.draw();
	do
	{
		if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) break;
		if (GetAsyncKeyState((unsigned short)'M') & 0x8000) moving(obg, par);
		if (GetAsyncKeyState((unsigned short)'S') & 0x8000) scaling(obg, par);
		if (GetAsyncKeyState((unsigned short)'R') & 0x8000) rotating(obg, par);
	} while (1);
}
