#include <iostream>
#include "include.h"
#include "Game.h"
void menu() {

}


int main(){
	menu();
	Game* game = new Game();
	game->printBoard();
	getchar();
	return 0;
}