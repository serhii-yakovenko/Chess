#pragma once
#include "include.h"

class BoardCell;
class King;
class Queen;
class Bishop;
class Knight;
class Rook;
class Pawn;

class Player
{
public:
	Player();
	Player(const bool colour, BoardCell* board[8][8]);
	~Player();

	bool colour;
	bool check = 0;
	std::vector<Figure*> figures;
	King *k;
	Queen *q;
	Bishop *b[2];
	Knight *n[2];
	Rook *r[2];
	Pawn *p[8];
	std::map<std::string, int> lastMove;
	Figure* tempFigure; 

};

