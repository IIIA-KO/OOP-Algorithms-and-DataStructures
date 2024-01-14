#include "Menu.h"

void SetColor(unsigned short backColor, unsigned short foreColor) {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	WORD color = ((backColor & 0x0F) << 4) + (foreColor & 0x0F);
	SetConsoleTextAttribute(h, color);
}
void SetÑursor(unsigned short row, unsigned short col) {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord{ col, row };
	SetConsoleCursorPosition(h, coord);
}
void paintMenu(const char** textMenu, size_t sizeMenu, size_t select) {
	system("cls");
	SetÑursor(TOPMENU, LEFTMENU - 32);
	cout << "/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/ DRUNKARD /--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/" << endl;
	for (size_t i = 0; i < sizeMenu; i++)
	{
		SetÑursor(TOPMENU + i + 1, LEFTMENU + 15);
		if (i == select) {
			SetColor(BACKGROUND, FOREGROUNG);
			cout << "=> " << textMenu[i] << endl;
		}
		else {
			cout << "  " << textMenu[i] << endl;
		}
		SetColor(BACKGROUND, FOREGROUNG);
	}
}
size_t Menu(const char** textMenu, size_t sizeMenu, size_t select) {
	unsigned char c = 80;
	while (true)
	{
		if (c == 72 || c == 80)
			paintMenu(textMenu, sizeMenu, select);
		c = _getch();
		switch (c) {
		case 13:
			return select;
		case 72:
			if (select == 0) select = sizeMenu;
			select--;
			break;

		case 80:
			select++;
			if (select == sizeMenu) select = 0;
			break;
		}
	}
	return 0;
}