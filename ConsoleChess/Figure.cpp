#include "Figure.h"
#include "Game.h"
#include "Player.h"
#include"BoardCell.h"

Figure::Figure()
{
}

Figure::Figure(int x, int y, bool colour, std::string type) : colour(colour), x(x), y(y)
{
	if (colour == BLACK)
		this->type = 'b' + type;
	else
		this->type = 'w' + type;

}

int Figure::getX()
{
	return x;
}

int Figure::getY()
{
	return y;
}

void Figure::setX(int x)
{
	this->x = x;
}

void Figure::setY(int y)
{
	this->y = y;
}

bool Figure::getColour()
{
	return colour;
}

bool Figure::freeMove(int xTarge, int yTarget, BoardCell * board[8][8])
{
	return false;
}

bool Figure::checkMove(Game * curGame, int xTarget, int yTarget)
{
	return false;
}


void Figure::tempMove(Game* curGame, int xTarget, int yTarget)
{
	curGame->players[getColour()]->tempFigure = curGame->board[xTarget][yTarget]->figure;
	curGame->players[getColour()]->lastMove["startX"] = getX();
	curGame->players[getColour()]->lastMove["startY"] = getY();
	curGame->players[getColour()]->lastMove["targetX"] = xTarget;
	curGame->players[getColour()]->lastMove["targetY"] = yTarget;
	curGame->board[xTarget][yTarget]->figure = this;
	curGame->players[!getColour()]->figures.erase(
		std::find(curGame->players[!getColour()]->figures.begin(),
			curGame->players[!getColour()]->figures.end(),
			curGame->players[getColour()]->tempFigure));
	setX(xTarget);
	setY(yTarget);
}

void Figure::cancelMove(Game * curGame)
{
	auto t_player= curGame->players[colour];
	curGame->players[!getColour()]->figures.push_back(curGame->players[getColour()]->tempFigure);
	curGame->board[t_player->lastMove["startX"]][t_player->lastMove["startY"]]->figure = curGame->board[t_player->lastMove["targetX"]][t_player->lastMove["targetY"]]->figure;
	curGame->board[t_player->lastMove["targetX"]][t_player->lastMove["targetY"]]->figure = t_player->tempFigure;
	setX(t_player->lastMove["startX"]);
	setY(t_player->lastMove["startY"]);
}

Figure::~Figure()
{
}
