#include "Menu.h"
int l = 1;

int Menu::menu()
{
	Figure paral_1(0), paral_2(1);//Ñîçäàíèå îá¸êòà 2 ïàð-äîâ, èíèöèàëèçàöèÿ ïî óìîë÷àíèþ
	char choice = '0';
	do
	{
		if (l == 1) { initwindow(1920, 1080); l = 0; } //×òîá îêíà íå îòêðûâàëèñü ïîñòîÿííî.
		system("cls");
		cout << "Ìåíþ: " << endl;
		cout << "Äëÿ âûõîäà íàæìèòå 0. Ëþáàÿ äðóãàÿ êëàâèøà íàðèñóåò ôèãóðû è îòïðàâèò â âûáîð ðåæèìà." << endl;
		choice = _getch();
		if (choice == '0') break;
		menu_par(par1, par2);
	} while (1);
	return 0;
}
void Menu::moving(Figure& obg, Figure& par)
{
	cout << "Ðåæèì ïåðåìåùåíèÿ: " << endl;
	cout << "WS - ïî îñè y." << endl;
	cout << "AD - ïî îñè x" << endl;
	cout << "QE - ïî îñè z" << endl;
	do
	{
		if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) { cout << "Âûõîä èç ðåæèìà ïåðåìåùåíèÿ óñïåøíî!" << endl; break; }
		if (GetAsyncKeyState((unsigned short)'Q') & 0x8000) //Ïåðåìåùåíèå ïî Z âïåðåä
		{ clearviewport(); obg.move(9); par.move(9); par.draw(); obg.draw(); }
		if (GetAsyncKeyState((unsigned short)'S') & 0x8000) //Ïåðåìåùåíèå ïî Y âíèç
		{ clearviewport(); obg.move(2); par.move(2); par.draw(); obg.draw(); }
		if (GetAsyncKeyState((unsigned short)'E') & 0x8000) //ïåðåìåùåíèå ïî Z íàçàä
		{ clearviewport(); obg.move(7); par.move(7); par.draw(); obg.draw(); }
		if (GetAsyncKeyState((unsigned short)'W') & 0x8000) //Ïåðåìåùåíèå ïî Y ââåðõ
		{ clearviewport(); obg.move(8); par.move(8); par.draw(); obg.draw(); }
		if (GetAsyncKeyState((unsigned short)'D') & 0x8000) //Ïåðåìåùåíèå ïî X âïðàâî
		{ clearviewport(); obg.move(6); par.move(6); par.draw(); obg.draw(); }
		if (GetAsyncKeyState((unsigned short)'A') & 0x8000) //ïåðåìåùåíèå ïî X âëåâî
		{ clearviewport(); obg.move(4); par.move(4); par.draw(); obg.draw(); }
	}
	while (1);
}

void Menu::scaling(Figure& obg, Figure& par)
{
	cout << "Ðåæèì ìàñøòàáèðîâàíèÿ: " << endl;
	cout << "W - ðàñøèðåíèå." << endl;
	cout << "S - ñæàòèå." << endl;
	do
	{
		if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) break;
		if (GetAsyncKeyState((unsigned short)'W') & 0x8000) //Ðàñøèðåíèå
		{ clearviewport(); obg.scale(3); par.scale(3); par.draw(); obg.draw(); }
		if (GetAsyncKeyState((unsigned short)'S') & 0x8000) //Ñæàòèå
		{ clearviewport(); obg.scale(1); par.scale(1); par.draw(); obg.draw(); }
	}
	while (1);
}

void Menu::rotating(Figure& obg, Figure& par)
{
	cout << "Ðåæèì âðàùåíèÿ: " << endl;
	cout << "WS - ïî îñè y." << endl;
	cout << "AD - ïî îñè x" << endl;
	cout << "QE - ïî îñè z" << endl;
	do
	{
		if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) break;
		if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) break;
		if (GetAsyncKeyState((unsigned short)'A') & 0x8000) //Âðàùàòü âîêðóã õ ïðîòèâ ÷àñîâîé
		{ clearviewport(); obg.rotate(1, 0); par.rotate(1, 0); par.draw(); obg.draw(); }
		if (GetAsyncKeyState((unsigned short)'D') & 0x8000) //Âðàùàòü âîêðóã õ ïî ÷àñîâîé
		{ clearviewport(); obg.rotate(1, 1); par.rotate(1, 1); par.draw(); obg.draw(); }
		if (GetAsyncKeyState((unsigned short)'W') & 0x8000) //Âðàùàòü âîêðóã y ïî ÷àñîâîé
		{ clearviewport(); obg.rotate(2, 0); par.rotate(2, 0); par.draw(); obg.draw(); }
		if (GetAsyncKeyState((unsigned short)'S') & 0x8000) //Âðàùàòü âîêðóã y ïðîòèâ ÷àñîâîé
		{ clearviewport(); obg.rotate(2, 1); par.rotate(2, 1); par.draw(); obg.draw(); }
		if (GetAsyncKeyState((unsigned short)'Q') & 0x8000) //Âðàùàòü âîêðóã z ïðîòèâ ÷àñîâîé
		{ clearviewport(); obg.rotate(3, 0); par.rotate(3, 0); par.draw(); obg.draw(); }
		if (GetAsyncKeyState((unsigned short)'E') & 0x8000) //Âðàùàòü âîêðóã z ïî ÷àñîâîé
		{ clearviewport(); obg.rotate(3, 1); par.rotate(3, 1); par.draw(); obg.draw(); }
	} while (1);
}

void Menu::menu_par(Figure& obg, Figure& par)
{
	cout << "Âûáåðèòå ðåæèì :" << endl;
	cout << "M - ïåðåìåùåíèå." << endl << "S - ìàñøòàáèðîâàíèå." << endl << "R - âðàùåíèå." << endl;
	par.draw(); obg.draw();
	do
	{
		if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) break;
		if (GetAsyncKeyState((unsigned short)'M') & 0x8000) moving(obg, par);
		if (GetAsyncKeyState((unsigned short)'S') & 0x8000) scaling(obg, par);
		if (GetAsyncKeyState((unsigned short)'R') & 0x8000) rotating(obg, par);
	} while (1);
}
