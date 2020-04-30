#include "Player.h"
#include "King.h"
#include "Queen.h"
#include "Bishop.h"
#include "Knight.h"
#include "Rook.h"
#include "Pawn.h"
#include "BoardCell.h"
#include "Game.h"

Player::Player()
{
	colour = WHITE;
}

Player::Player(bool colour, BoardCell* board[8][8]) : colour(colour)
{
	tempFigure = nullptr;
	lastMove = {{"startX", 0}, {"startY", 0}, {"targetX", 0}, {"targetY", 0}};

	for (int i = 0; i < 2; i++) {
		b[i] = new Bishop(7 * colour, 2 + i * 3, colour);
		figures.push_back(b[i]);
		board[b[i]->getX()][b[i]->getY()]->figure = b[i];

		n[i] = new Knight(7 * colour, 1 + i * 5, 0);
		board[n[i]->getX()][n[i]->getY()]->figure = n[i];
		figures.push_back(n[i]);

		r[i] = new Rook(7 * colour, 0 + i * 7, colour);
		board[r[i]->getX()][r[i]->getY()]->figure = r[i];
		figures.push_back(r[i]);
	}

	k = new King(7 * colour, 4, colour);
	board[k->getX()][k->getY()]->figure = k;
	figures.push_back(k);

	q = new Queen(7 * colour, 3, colour);
	board[q->getX()][q->getY()]->figure = q;
	figures.push_back(q);


	for (int i = 0; i < 8; i++) {
		p[i] = new Pawn(5 * colour + 1, i, colour);
		board[p[i]->getX()][p[i]->getY()]->figure = p[i];
		figures.push_back(p[i]);
	}
}


Player::~Player()
{
}
