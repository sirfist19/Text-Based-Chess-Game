#ifndef Player_h
#define Player_h

#include <iostream>
#include <string>
#include "Piece.h"
#include "Pawn.h"
#include "Rook.h"
#include "Bishop.h"
#include "Queen.h"
#include "Knight.h"
#include "King.h"
#include<vector>
#include "gameFxns.h"

class Board;

class Player
{
private:
	std::string m_name;
	std::string m_color;
	std::vector<Piece*>m_pieces;
	//Piece* pieces[16];//a vector of pieces would be way better
	Board* m_game;

public:
	Player(std::string inputName, std::string inputColor, Board* game);//constructor
	virtual ~Player();
	std::vector<Piece*> getPieceVector() const;
	void removePieceFromVector(Piece* toRemove);
	std::string getName() const;
	void setGamePtr(Board* input);
};


#endif 

