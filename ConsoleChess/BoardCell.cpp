#include <iostream>
#include "BoardCell.h"
#include "Figure.h"


BoardCell::BoardCell()
{
}

void BoardCell::printCell()
{
	std::cout << figure->type << '|';
}

BoardCell::BoardCell(int x, int y, Figure* figure) : x(x), y(y), figure(figure)
{
	if ((x + y) % 2 == 0)
		colour = WHITE;
	else
		colour = BLACK;
}


BoardCell::~BoardCell()
{
}
