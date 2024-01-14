#pragma once
#include <iostream>
#include <iomanip>
#include<conio.h>
#include <Windows.h>
#define BACKGROUND 0
#define FOREGROUNG 2
#define SELECTITEMMENU 15
#define LEFTMENU 85
#define TOPMENU 20
using namespace std;
#include <datetimeapi.h>

void SetColor(unsigned short backColor, unsigned short foreColor);

void Setcursor(unsigned short row, unsigned short col);

void paintMenu(const char** textMenu, size_t sizeMenu, size_t select = 0);

size_t Menu(const char** textMenu, size_t sizeMenu, size_t select = 0);