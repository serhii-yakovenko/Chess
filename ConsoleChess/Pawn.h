#pragma once
#include "Figure.h"


class Pawn :
	public Figure
{
public:
	bool moved = 0;
	Pawn();
	Pawn(int x, int y, bool colour);
	bool freeMove(int xTarget, int yTarget, BoardCell * board[8][8]);
	bool checkMove(Game* curGame, int xTarget, int yTarget);
	~Pawn();
};

