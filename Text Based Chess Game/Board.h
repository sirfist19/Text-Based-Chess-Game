#ifndef  Board_h
#define Board_h
#include "Player.h"
#include "Piece.h"
#include <string>
#include <vector>
#include "gameFxns.h"


class Board
{
private:
	char board[8][8];
	Player* white;
	Player* black;
	//a board has both black and white pieces
	
	/*Proto - board(the array you work with to start)

	At the start of the game
		RNBQKBNR
		PPPPPPPP
		........
		........
		........
		........
		PPPPPPPP
		RNBQKBNR

	The base array (this is the way it starts before you add pieces)
		........
		........
		........
		........
		........
		........
		........
		*/
public:
	void display();
	void updateBoard();
	char getCharAtPos(int x, int y);
	bool occupied(int x, int y);
	bool occupied(int x, int y, Piece*& pieceAtSpot);
	//returns true if the coord passed in is occupied and false if not
	Player* getWhite() const
	{
		return white;
	}
	Player* getBlack() const
	{
		return black;
	}

	void turn();//each time white and black plays goes through this fxn.
	//Board(Player* inputWhite, Player* inputBlack);
	Board();
	~Board();
};



#endif // ! Board_h
