#include "Queen.h"
#include "BoardCell.h"
#include "Game.h"

Queen::Queen()
{
}

Queen::Queen(int x, int y, bool colour) : Figure(x, y, colour, "q")
{
}

bool Queen::freeMove(int xTarget, int yTarget, BoardCell * board[8][8])
{
	if (xTarget == getX()) {
	
	}

	if (yTarget == getY()) {
	}
	for (int i = std::min(getX(), xTarget); i <= std::max(xTarget, getX()); i++) {
		if (board[i][yTarget]->figure != nullptr && board[i][yTarget]->figure != this)
			return false;
	}
	return true;
}

bool Queen::checkMove(Game * curGame, int xTarget, int yTarget)
{
	return false;
}


Queen::~Queen()
{
}
