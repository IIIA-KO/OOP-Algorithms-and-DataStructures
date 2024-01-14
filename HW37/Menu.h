#pragma once
#include "Deck.h"
#define BACKGROUND 7
#define FOREGROUNG 0
#define SELECTITEMMENU 15
#define LEFTMENU 60
#define TOPMENU 15
using namespace std;

void SetColor(unsigned short backColor, unsigned short foreColor);

void Set—ursor(unsigned short row, unsigned short col);

void paintMenu(const char** textMenu, size_t sizeMenu, size_t select = 0);

size_t Menu(const char** textMenu, size_t sizeMenu, size_t select = 0);