#include "Queen.h"
#include <string>
bool Queen::move(int x, int y)
{
	
	bool movingLikeRook = false;
	bool movingLikeBishop = false;
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


		//if not moving like a Rook
	if (((x == cur.m_x) && (y == cur.m_y)) || ((x != cur.m_x) && (y != cur.m_y)))
	{
		//std::cout << "Not a good queen move (rook)." << std::endl;
		
		//moving like rook stays false
		//cannot move to the same square that you're already at
		//and if you the square isn't moving like a rook simply return false
	}
	else
		movingLikeRook = true;
	if (!movingLikeRook)
	{
		//if not moving like a bishop
		if (((changeInX != changeInY) && (changeInX != -changeInY))
			|| ((x == cur.m_x) && (y == cur.m_y)))
		{
			std::cout << "Not a good queen move (bishop)!";
			return false;
			//cannot move to the same square that you're already at
			//and if you the square isn't moving like a Bishop simply return false
		}
		else
			movingLikeBishop = true;
	}
	
	
	if (movingLikeBishop)
	{


		//checking squares if moving like a bishop
		//checking if the player moves down and left
		if (changeInY < 0 && changeInX > 0)
		{
			//check the squares other than the target
			int iterationCount = 0;
			for (int i = cur.m_x; i < x; i++)
			{
				if (i != cur.m_x)//not checking the square where the piece is
				{
					if (getBoard()->occupied(i, cur.m_y - iterationCount))
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
						std::cout << std::endl << "Piece at " << i << "," << cur.m_y + iterationCount;
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
		if (changeInX < 0 && changeInY < 0)
		{

			int iterationCount = 0;
			for (int i = cur.m_x; i > x; i--)
			{
				if (i != cur.m_x)//not checking the square where the piece is
				{
					if (getBoard()->occupied(i, cur.m_y - iterationCount))
					{
						std::cout << "Piece at " << i << "," << cur.m_y - iterationCount;
						return false;
					}
				}
				iterationCount++;
			}
		}
	}
	if (movingLikeRook)
	{


		//checking squares if moving like a Rook
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
							std::cout << std::endl << "Piece at " << x << ", " << i;
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
							std::cout << std::endl << "Piece at " << x << ", " << i;
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
							std::cout << std::endl << "Piece at " << i << ", " << y;
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
							std::cout << std::endl << "Piece at " << i << ", " << y;
							return false;
						}
					}
				}
			}
		}
	}
		//AT THIS POINT NO PIECE IS BLOCKING THE QUEEN
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
		//move the Queen
		setCoord(x, y);
		return true;

}
Queen::Queen(std::string color, int x, int y, Board* game)
	:Piece(x, y, color, "Queen", 'Q', game)//calling the constructor of the base class
	//this avoids having to set everything with set functions
{
	if (color == "Black")
	{
		setChar('q');
	}
}