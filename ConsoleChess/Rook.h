#pragma once
#include "Figure.h"
class Rook :
	public Figure
{
public:
	Rook();
	Rook(int x, int y, bool colour);
	~Rook();
};

