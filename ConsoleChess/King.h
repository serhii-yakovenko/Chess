#pragma once
#include "Figure.h"
class King :
	public Figure
{
public:
	King();
	King(int x, int y, bool colour);

	~King();
};

