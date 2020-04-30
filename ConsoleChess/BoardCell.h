#pragma once
#include "include.h"

class Figure;

class BoardCell
{
private:
	int x, y;
	bool colour;
	
public:
	BoardCell();
	void printCell();
	Figure* figure;
	BoardCell(int x, int y, Figure* figure);
	~BoardCell();
};

