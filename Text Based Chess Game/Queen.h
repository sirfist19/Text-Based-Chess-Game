#ifndef Queen_h
#define Queen_h
#include "Piece.h"
#include "Board.h"
#include <string>


class Queen : public Piece
{
private:
public:
	Queen(std::string color, int x, int y, Board* game);//constructor that needs color and coordinate

	virtual bool move(int x, int y);
	//passes in a coord and the function will check if it is a valid move
	//if it is a valid move, then the piece will be moved on the board
	//if not then the fxn returns false and the player will be asked to move again
};


#endif // !Rook_h


