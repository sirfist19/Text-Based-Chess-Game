#include "Knight.h"
#include <string>
bool Knight::move(int x, int y)
{
	bool occupied = false;


	coord cur = getCoord();
	if (occupied == false)
	{
		int changeInX = cur.m_x - x;
		int changeInY = cur.m_y - y;

		if ((changeInX == 1 || changeInX == -1) && !((x == cur.m_x) && (y == cur.m_y)))
		{
			if (changeInY == 2 || changeInY == -2)
			{
				setCoord(x, y);
				return true;
			}
		}

		if ((changeInX == 2 || changeInX == -2) && !((x == cur.m_x) && (y == cur.m_y)))
		{
			if (changeInY == 1 || changeInY == -1)
			{
				setCoord(x, y);
				return true;
			}
		}
	}


	//captures
	return false;

}
Knight::Knight(std::string color, int x, int y, Board* game)
	:Piece(x, y, color, "Knight", 'N', game)//calling the constructor of the base class
	//this avoids having to set everything with set functions
{
	if (color == "Black")
	{
		setChar('n');
	}
}