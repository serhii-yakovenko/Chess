#pragma once
#include "Figure.h"
class Bishop :
	public Figure
{
public:
	Bishop();
	Bishop(int x, int y, bool colour);
	~Bishop();
};

