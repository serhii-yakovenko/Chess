#pragma once
#include "Figure.h"

class Queen :
	public Figure
{
public:
	Queen();
	Queen(int x, int y, bool colour);
	bool freeMove(int xTarget, int yTarget, BoardCell * board[8][8]);
	bool checkMove(Game* curGame, int xTarget, int yTarget);
	~Queen();
};

