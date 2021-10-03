#include "Rook.h"
#include <string>


bool Rook::move(int x, int y)
{
	coord cur = getCoord();
	std::cout << "Rook is at " << cur.m_x << ", " << cur.m_y;
	if (((x == cur.m_x) && (y == cur.m_y)) || ((x != cur.m_x) && (y != cur.m_y)))
	{
		return false;
		//cannot move to the same square that you're already at
		//and if you the square isn't moving like a rook simply return false
	}
	//check the rank for pieces in the way
	if (x == cur.m_x)
	{
		int moveUpwardVal = y - cur.m_y;
		//positive if the piece is moving upward, negative if moving downward
		if (moveUpwardVal > 0)
		{
			for (int i = cur.m_y; i < y; i++)//checks all squares except the target square
			{
				if (i != cur.m_y)//not checking the square where the piece is
				{
					if (getBoard()->occupied(x, i))
					{
						//std::cout << "a";
						return false;
					}
				}

			}
		}
		if (moveUpwardVal < 0)
		{
			for (int i = cur.m_y; i > y; i--)//checks all squares except the target square
			{
				if (i != cur.m_y)//not checking the square where the piece is
				{
					if (getBoard()->occupied(x, i))

					{
						//std::cout << "b";
						return false;
					}
				}
			}
		}
	}
	//check the file for pieces in the way (moveUpwardVal is really moveSideswaysVal here)
	if (y == cur.m_y)
	{
		int moveUpwardVal = x - cur.m_x;
		//positive if the piece is moving upward, negative if moving downward
		if (moveUpwardVal > 0)
		{
			for (int i = cur.m_x; i < x; i++)//checks all squares except the target square
			{
				if (i != cur.m_x)//not checking the square where the piece is
				{
					if (getBoard()->occupied(i, y))
					{
						//std::cout << "c";
						return false;
					}
				}
			}
		}
		if (moveUpwardVal < 0)
		{
			for (int i = cur.m_x; i > x; i--)//checks all squares except the target square
			{
				if (i != cur.m_x)//not checking the square where the piece is
				{
					if (getBoard()->occupied(i, y))
					{
						//std::cout << "d: square " << i << ", " << y << "is occupied";;
						return false;
					}
				}
			}
		}
	}

	//AT THIS POINT NO PIECE IS BLOCKING THE ROOK
	bool capture = false;
	Piece* pieceToCapture = nullptr;
	if (getBoard()->occupied(x, y, pieceToCapture) 
		&& pieceToCapture->getColor() != getColor())
		capture = true;
	if (pieceToCapture != nullptr && pieceToCapture->getColor() == getColor())
	{
		std::cout << "You can't capture you're own piece!";
		return false;
	}


	//if it's a capture remove the piece from the other player
	//MIGHT WANT TO MAKE THIS A CAPTURE FXN
	if (capture)
	{
		if (getColor() == "White")
		{
			getBoard()->getBlack()->removePieceFromVector(pieceToCapture);
		}
		else if (getColor() == "Black")
		{
			getBoard()->getWhite()->removePieceFromVector(pieceToCapture);
		}
	}
	//move the rook
	setCoord(x, y);
	return true;
}
Rook::Rook(std::string color, int x, int y, Board* game)
	:Piece(x, y, color, "Rook", 'R', game)//calling the constructor of the base class
	//this avoids having to set everything with set functions
{
	if (color == "Black")
	{
		setChar('r');
	}
}