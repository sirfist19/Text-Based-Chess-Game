#include <iostream>
#include <string>
#include <cassert>
#include "Board.h"
#include "Player.h"
#include "Piece.h"
//#include "Pawn.h"
//#include "Rook.h"
//#include "Queen.h"
//#include "Knight.h"
//#include "King.h"
//#include "Bishop.h"
#include "gameFxns.h"
using namespace std;

int main()
{
	
	//Board* gamePtr = nullptr;
	//Player* white = new Player("Aidan", "White",gamePtr);
	//Player* black = new Player("Sirfist19", "Black", gamePtr);
	Board game;
	
	//if (&game == game.getBlack()->getPieceVector()[0]->getBoard())
		//std::cout << "Success!";
	game.updateBoard();
	game.display();
	while (true)
	{
		game.turn();
	}
	

	return 0;
}
/*
Chess Board

Ver.1
+-+-+-+-+-+-+-+-+
|R|N|B|Q|K|B|N|R|
+-+-+-+-+-+-+-+-+
|P|P|P|P|P|P|P|P|
+-+-+-+-+-+-+-+-+
| | | | | | | | |
+-+-+-+-+-+-+-+-+
| | | | | | | | |
+-+-+-+-+-+-+-+-+
| | | | | | | | |
+-+-+-+-+-+-+-+-+
| | | | | | | | |
+-+-+-+-+-+-+-+-+
|P|P|P|P|P|P|P|P|
+-+-+-+-+-+-+-+-+
|R|N|B|Q|K|B|N|R|
+-+-+-+-+-+-+-+-+

Ver.2

| |+---+---+---+---+---+---+---+---+
|8|| R | N | B | Q | K | B | N | R |
| |+---+---+---+---+---+---+---+---+
|7|| P | P | P | P | P | P | P | P |
| |+---+---+---+---+---+---+---+---+
|6||   |   |   |   |   |   |   |   |
| |+---+---+---+---+---+---+---+---+
|5||   |   |   |   |   |   |   |   |
| |+---+---+---+---+---+---+---+---+
|4||   |   |   |   |   |   |   |   |
| |+---+---+---+---+---+---+---+---+
|3||   |   |   |   |   |   |   |   |
| |+---+---+---+---+---+---+---+---+
|2|| P | P | P | P | P | P | P | P |
| |+---+---+---+---+---+---+---+---+
|1|| R | N | B | Q | K | B | N | R |
| |+---+---+---+---+---+---+---+---+
| || A | B | C | D | E | F | G | H |


+---+---+---+---+---+---+---+---+
| R | N | B | Q | K | B | N | R |
+---+---+---+---+---+---+---+---+
| P | P | P | P | P | P | P | P |
+---+---+---+---+---+---+---+---+
|   |   |   |   |   |   |   |   |
+---+---+---+---+---+---+---+---+
|   |   |   |   |   |   |   |   |
+---+---+---+---+---+---+---+---+
|   |   |   |   |   |   |   |   |
+---+---+---+---+---+---+---+---+
|   |   |   |   |   |   |   |   |
+---+---+---+---+---+---+---+---+
| P | P | P | P | P | P | P | P |
+---+---+---+---+---+---+---+---+
| R | N | B | Q | K | B | N | R |
+---+---+---+---+---+---+---+---+


Proto-board (the array you work with to start)


RNBQKBNR
PPPPPPPP
........
........
........
........
PPPPPPPP
RNBQKBNR



*/