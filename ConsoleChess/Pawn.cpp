#include "Pawn.h"
#include "BoardCell.h"
#include "Game.h"


Pawn::Pawn()
{
}

Pawn::Pawn(int x, int y, bool colour) : Figure(x, y, colour, "p")
{
}

bool Pawn::freeMove(int xTarget, int yTarget, BoardCell * board[8][8])
{
	for (int i = std::min(getX(), xTarget); i <= std::max(xTarget, getX()); i++) {
		if (board[i][yTarget]->figure != nullptr && board[i][yTarget]->figure != this)
			return false;
	}
	return true;
}

bool Pawn::checkMove(Game* curGame, int xTarget, int yTarget) {
	if (xTarget > 7 || yTarget > 7 || abs(getY() - yTarget) > 1)
		return false;

	if ((getColour() == WHITE && xTarget - getX() >= 0) ||
		(getColour() == BLACK && xTarget - getX() <= 0))
		return false;

	if ((abs(xTarget - getX()) > 2 && !moved) || (abs(xTarget - getX()) != 1 && moved))
		return false;

	if (!freeMove(xTarget, yTarget, curGame->board))
		return false;

	if (abs(yTarget - getY()) == 1 &&
			(curGame->board[xTarget][yTarget]->figure != nullptr && curGame->board[xTarget][yTarget]->figure->getColour() != this->getColour())) {
		tempMove(curGame, xTarget, yTarget);
		if (!(curGame->checkCheck(getColour())).size())
			return true;
		else {
			cancelMove(curGame);
			return false;
		}
	}
	return freeMove(xTarget, yTarget, curGame->board);
}

Pawn::~Pawn()
{
}
