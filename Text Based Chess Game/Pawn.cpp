#include "Pawn.h"
#include <string>

bool Pawn::move(int x, int y)//STILL NEED TO ADD IN EN PASSANT
{
	if (x < 0 || x>8 || y < 0 || y>8)
		return false;
	coord cur = getCoord();

	if (getColor() == "Black")
	{
		//moving one square forward
		if (x == cur.m_x + 1 && y == cur.m_y && !getBoard()->occupied(x,y))
		{
			setCoord(x, y);
			return true;
		}
		//moving two squares forward
		else if (x == cur.m_x + 2 && y == cur.m_y && cur.m_x == 1 
			&&!getBoard()->occupied(x,y) && !getBoard()->occupied(x-1,y))
		//makes sure the square in front and two in front are not occupied
		{
			setCoord(x, y);
			return true;
		}

		//captures
		bool capture = false;
		Piece* pieceToCapture = nullptr;

		if (x == cur.m_x + 1)//one square ahead
		{
			//capturing to left
			if (y == cur.m_y - 1)
			{
				if (getBoard()->occupied(x, y, pieceToCapture)
					&& pieceToCapture->getColor() != getColor())
					capture = true;
				if (pieceToCapture != nullptr && pieceToCapture->getColor() == getColor())
				{
					std::cout << "You can't capture you're own piece!";
					return false;
				}
			}
			//capturing to right
			if (y = cur.m_y + 1)
			{
				if (getBoard()->occupied(x, y, pieceToCapture)
					&& pieceToCapture->getColor() != getColor())
					capture = true;
				if (pieceToCapture != nullptr && pieceToCapture->getColor() == getColor())
				{
					std::cout << "You can't capture you're own piece!";
					return false;
				}
			}
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
				//move the pawn
				setCoord(x, y);
				return true;
			}
			
		}
		return false;
		//en passant
	}
	else if (getColor() == "White")
	{
		//moving one square forward
		if (x == cur.m_x - 1 && y == cur.m_y && !getBoard()->occupied(x, y))
		{
			setCoord(x, y);
			return true;
		}
		//moving two squares forward
		else if (x == cur.m_x - 2 && y == cur.m_y && cur.m_x == 6 
			&& !getBoard()->occupied(x, y) && !getBoard()->occupied(x+1,y))//moving two squares forward on first move
		{
			setCoord(x, y);
			return true;
		}
		
		//captures
		bool capture = false;
		Piece* pieceToCapture = nullptr;

		if (x == cur.m_x - 1)//one square ahead
		{
			//capturing to left
			if (y == cur.m_y - 1)
			{
				if (getBoard()->occupied(x, y, pieceToCapture)
					&& pieceToCapture->getColor() != getColor())
					capture = true;
				if (pieceToCapture != nullptr && pieceToCapture->getColor() == getColor())
				{
					std::cout << "You can't capture you're own piece!";
					return false;
				}
			}
			//capturing to right
			if (y == cur.m_y + 1)
			{
				if (getBoard()->occupied(x, y, pieceToCapture)
					&& pieceToCapture->getColor() != getColor())
					capture = true;
				if (pieceToCapture != nullptr && pieceToCapture->getColor() == getColor())
				{
					std::cout << "You can't capture you're own piece!";
					return false;
				}
			}
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
				setCoord(x, y);
				return true;
			}
			//move the pawn
			
			//en passant
		}
	}

	return false;//change this later so that it returns fail if the move doesn't work
}
Pawn::Pawn(std::string color, int x, int y, Board* game)
	:Piece(x, y, color, "Pawn", 'P', game)//calling the constructor of the base class
	//this avoids having to set everything with set functions
{
	if (color == "Black")
	{
		setChar('p');
	}
}