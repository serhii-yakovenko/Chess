#pragma once
#include "include.h"
class Player;
class BoardCell;

class Game
{
public:
	bool currentPlayer;
	Player* players[2];
	BoardCell *board[8][8];
	
	std::vector<Figure*> checkCheck(const bool colour); //
	bool ceckCheckmate(const bool colour);
	Game();
	Game(std::string myfile);
	int letter_to_num(char let); //convert letter in coordinates to number
	void printBoard();

	~Game();
};

