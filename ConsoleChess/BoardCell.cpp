#include <iostream>
#include "BoardCell.h"
#include "Figure.h"


BoardCell::BoardCell()
{
}

void BoardCell::printCell()
{
	if (figure != nullptr)
		std::cout << figure->type << '|';
	else
		std::cout << "__|";
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
