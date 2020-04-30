#include "Game.h"
#include "Player.h"
#include "BoardCell.h"
#include "King.h"

std::vector<Figure*> Game::checkCheck(bool colour)
{
	players[colour]->k;
	std::vector<Figure*> checkFigures;
	for (auto i = players[!colour]->figures.begin(); i != players[!colour]->figures.end(); i++) {
		auto x = *i;
		if ((*i)->checkMove(this, players[colour]->k->getX(), players[colour]->k->getY()))//////////////
		checkFigures.push_back(*i);
	}
	return checkFigures;
}

bool Game::ceckCheckmate(const bool colour)
{
	return false;////////////////
}

Game::Game()
{
	currentPlayer = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			board[i][j] = new BoardCell(i, j, nullptr);
		}
	}
	
	players[WHITE] = new Player(WHITE, board);
	players[BLACK] = new Player(BLACK, board);
	
}

Game::Game(std::string myfile)
{
	std::fstream saveFile;
	saveFile.open(myfile);
}

int Game::letter_to_num(char let)
{
	let = toupper(let);
	return static_cast<int>(let) - 64;
}

void Game::printBoard()
{
	std::cout << "  A  B  C  D  E  F  G  H\n";
	for (int i = 0; i < 8; i++) {
		std::cout << i + 1 << "|";
		for (int j = 0; j < 8; j++) {
			board[i][j]->printCell();
		}
		std::cout << "\n";
		std::cout << "________________________\n";
	}
}


Game::~Game()
{
}
