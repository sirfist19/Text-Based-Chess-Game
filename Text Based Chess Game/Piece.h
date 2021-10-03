#ifndef Piece_h
#define Piece_h

#include <string>
#include "gameFxns.h"
class Board;
class Player;


class Piece//abstract base class
{
private:
	//coordinate
	coord location;

	//color
	std::string m_color;//either "White" or "Black"

	//name and character
	std::string m_type;//Ex: Pawn, King, etc.
	char m_char;//Ex: P, N, Q ...
	Board* m_game;

protected:
	Piece(int x, int y, std::string color, std::string type, char m_char, Board* game);//constructor ... may not need this though
	
	void setCoord(int x, int y);
	void setChar(char char0)
	{
		m_char = char0;
	}
	//virtual void capture() = 0;
	//virtual void destroy() = 0;//when a piece is taken

public:
	virtual bool move(int x, int y) = 0;
	coord getCoord();
	/*void setColor(string color)
	{
		m_color = color;
	}*/
	std::string getColor()
	{
		return m_color;
	}
	/*void setType(string type)
	{
		m_type = type;
	}*/
	std::string getType()
	{
		return m_type;
	}
	
	char getChar()
	{
		return m_char;
	}
	Board* getBoard()
	{
		return m_game;
	}

};




#endif // !Piece_h

