#include "King.h"
#include <string>
bool King::move(int x, int y)
{
	bool occupied = false;
	/*if (charAtSpot != '#' && charAtSpot != '-')
	{
		occupied = true;
	}*/

	coord cur = getCoord();
	if (occupied == false)
	{
		int changeInX = cur.m_x - x;
		int changeInY = cur.m_y - y;

		//moving like a Rook one square
		if (((x == cur.m_x && (changeInY == 1 || changeInY == -1)) || (y == cur.m_y && (changeInX == 1 || changeInX == -1))) && !((x == cur.m_x) && (y == cur.m_y)))
			//moving in ranks or files but not staying the same
		{
			setCoord(x, y);
			return true;
		}
		//moving like a bishop one square
		else if ((changeInX == changeInY) || (changeInX == -changeInY) && ((changeInX == -1) || (changeInX == 1) && !((x == cur.m_x) && (y == cur.m_y))))
			//moving in ranks or files but not staying the same
		{
			setCoord(x, y);
			return true;
		}
	}


	//captures
	return false;

}
King::King(std::string color, int x, int y, Board* game)
	:Piece(x, y, color, "King", 'K', game)//calling the constructor of the base class
	//this avoids having to set everything with set functions
{
	if (color == "Black")
	{
		setChar('k');
	}
}