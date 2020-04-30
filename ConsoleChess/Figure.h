#pragma once
#include "include.h"
class Game;
class BoardCell;
class Player;

class Figure
{
private:
	int x, y;
	bool colour;
public:
	Figure();
	Figure(int x, int y, bool colour, std::string type);
	std::string type;
	int getX();
	int getY();
	void setX(int x);
	void setY(int y);
	bool getColour();
	virtual bool freeMove(int xTarge, int yTarget, BoardCell* board[8][8]); // does figure has access to cell
	virtual bool checkMove(Game* curGame, int xTarget, int yTarget); // check ability of movement
	void tempMove(Game* curGame, int xTarget, int yTarget); // change coordinates of figure to check potential check
	void cancelMove(Game* curGame); // if move caused check - cancel it
	virtual ~Figure();
};
