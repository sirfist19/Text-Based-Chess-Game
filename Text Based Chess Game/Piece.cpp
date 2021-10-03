#include "Piece.h"

Piece::Piece(int x, int y, std::string color, std::string type, char char0, Board* game)
	:m_char(char0), m_color(color), m_type(type), m_game(game)
{
	location.m_x = x;
	location.m_y = y;
}
void Piece::setCoord(int x, int y)
{
	location.m_x = x;
	location.m_y = y;
}

coord Piece::getCoord()
{
	return location;
}