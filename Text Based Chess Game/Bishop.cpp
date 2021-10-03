#include "Bishop.h"
#include <string>

bool Bishop::move(int x, int y)
{
	coord cur = getCoord();
	int changeInX = x - cur.m_x;
	int changeInY = y - cur.m_y;
	int abs_changeInX;
	int abs_changeInY;

	if (changeInX < 0)
		abs_changeInX = -1 * changeInX;
	else
		abs_changeInX = changeInX;

	if (changeInY < 0)
		abs_changeInY = -1 * changeInY;
	else
		abs_changeInY = changeInY;

	int diagonal = changeInX * changeInY;//will be positive for the diagonal with positive slope, 
										//and negative for the other
	
	//std::cout << "Bishop is at " << cur.m_x << ", " << cur.m_y;
	if (((changeInX != changeInY) && (changeInX != -changeInY))
		|| ((x == cur.m_x) && (y == cur.m_y)))
	{
		std::cout << "Terminated early!";
		return false;
		//cannot move to the same square that you're already at
		//and if you the square isn't moving like a Bishop simply return false
	}
	//check the rank for pieces in the way
	
	//checking if the player moves down and left
		if (changeInY < 0 && changeInX > 0)
		{
			//check the squares other than the target
			int iterationCount = 0;
			for (int i = cur.m_x; i < x; i++)
			{
				if (i != cur.m_x)//not checking the square where the piece is
				{
					if (getBoard()->occupied(i, cur.m_y -iterationCount))
					{
						std::cout << "Piece at " << i << "," << cur.m_y - iterationCount;
						return false;
					}
				}
				iterationCount++;
			}
			
		}
		//checking if the player moves up and right
		if (changeInY > 0 && changeInX < 0)
		{
			//check the squares other than the target
			
			int iterationCount = 0;
			for (int i = cur.m_x; i > x; i--)
			{
				if (i != cur.m_x)//not checking the square where the piece is
				{
					//std::cout << "Checking at" << i << "," << cur.m_y + iterationCount;
					if (getBoard()->occupied(i, cur.m_y + iterationCount))
					{
						std::cout <<std::endl<<"Piece at " << i << "," << cur.m_y + iterationCount;
						return false;
					}
				}
				iterationCount++;
			}
		}	

		//checking if the player moves down and right
		if (changeInX > 0 && changeInY > 0)
		{
			
			int iterationCount = 0;
			for (int i = cur.m_x; i < x; i++)
			{
				if (i != cur.m_x)//not checking the square where the piece is
				{
					if (getBoard()->occupied(i, cur.m_y + iterationCount))
					{
						std::cout << "Piece at " << i << "," << cur.m_y + iterationCount;
						return false;
					}
				}
				iterationCount++;
			}
		}
		//checking if the player moves up and left
		if (changeInX < 0 && changeInY<0)
		{
			
			int iterationCount = 0;
			for (int i = cur.m_x; i > x; i--)
			{
				if (i != cur.m_x)//not checking the square where the piece is
				{
					if (getBoard()->occupied(i, cur.m_y - iterationCount))
					{
						std::cout << "Piece at "<<i<<","<< cur.m_y - iterationCount;
						return false;
					}
				}
				iterationCount++;
			}
		}
	

	//AT THIS POINT NO PIECE IS BLOCKING THE BISHOP
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
	//move the bishop
	setCoord(x, y);
	return true;

}
Bishop::Bishop(std::string color, int x, int y, Board* game)
	:Piece(x, y, color, "Bishop", 'B', game)//calling the constructor of the base class
	//this avoids having to set everything with set functions
{
	if (color == "Black")
	{
		setChar('b');
	}
}