#ifndef gameFxns_h
#define gameFxns_h
#include <string>

struct coord//holds the x and y coordinates
{
	int m_x;//0 through 7 on x-axis
	int m_y;//0 through 7 going up from the white pieces
};

coord convertChessCoord(std::string chessCoord);
std::string getPieceType(std::string& input);

#endif
