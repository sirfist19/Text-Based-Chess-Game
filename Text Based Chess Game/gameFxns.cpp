#include "gameFxns.h"
#include <iostream>
#include <string>

coord convertChessCoord(std::string chessCoord)
{
	coord a;
	a.m_x = -1;
	a.m_y = -1;

	if (chessCoord == "a1")
	{
		a.m_x = 7;
		a.m_y = 0;
	}
	else if (chessCoord == "a2")
	{
		a.m_x = 6;
		a.m_y = 0;
	}
	else if (chessCoord == "a3")
	{
		a.m_x = 5;
		a.m_y = 0;
	}
	else if (chessCoord == "a4")
	{
		a.m_x = 4;
		a.m_y = 0;
	}
	else if (chessCoord == "a5")
	{
		a.m_x = 3;
		a.m_y = 0;
	}
	else if (chessCoord == "a6")
	{
		a.m_x = 2;
		a.m_y = 0;
	}
	else if (chessCoord == "a7")
	{
		a.m_x = 1;
		a.m_y = 0;
	}
	else if (chessCoord == "a8")
	{
		a.m_x = 0;
		a.m_y = 0;
	}


	if (chessCoord == "b1")
	{
		a.m_x = 7;
		a.m_y = 1;
	}
	else if (chessCoord == "b2")
	{
		a.m_x = 6;
		a.m_y = 1;
	}
	else if (chessCoord == "b3")
	{
		a.m_x = 5;
		a.m_y = 1;
	}
	else if (chessCoord == "b4")
	{
		a.m_x = 4;
		a.m_y = 1;
	}
	else if (chessCoord == "b5")
	{
		a.m_x = 3;
		a.m_y = 1;
	}
	else if (chessCoord == "b6")
	{
		a.m_x = 2;
		a.m_y = 1;
	}
	else if (chessCoord == "b7")
	{
		a.m_x = 1;
		a.m_y = 1;
	}
	else if (chessCoord == "b8")
	{
		a.m_x = 0;
		a.m_y = 1;
	}

	if (chessCoord == "c1")
	{
		a.m_x = 7;
		a.m_y = 2;
	}
	else if (chessCoord == "c2")
	{
		a.m_x = 6;
		a.m_y = 2;
	}
	else if (chessCoord == "c3")
	{
		a.m_x = 5;
		a.m_y = 2;
	}
	else if (chessCoord == "c4")
	{
		a.m_x = 4;
		a.m_y = 2;
	}
	else if (chessCoord == "c5")
	{
		a.m_x = 3;
		a.m_y = 2;
	}
	else if (chessCoord == "c6")
	{
		a.m_x = 2;
		a.m_y = 2;
	}
	else if (chessCoord == "c7")
	{
		a.m_x = 1;
		a.m_y = 2;
	}
	else if (chessCoord == "c8")
	{
		a.m_x = 0;
		a.m_y = 2;
	}

	if (chessCoord == "d1")
	{
		a.m_x = 7;
		a.m_y = 3;
	}
	else if (chessCoord == "d2")
	{
		a.m_x = 6;
		a.m_y = 3;
	}
	else if (chessCoord == "d3")
	{
		a.m_x = 5;
		a.m_y = 3;
	}
	else if (chessCoord == "d4")
	{
		a.m_x = 4;
		a.m_y = 3;
	}
	else if (chessCoord == "d5")
	{
		a.m_x = 3;
		a.m_y = 3;
	}
	else if (chessCoord == "d6")
	{
		a.m_x = 2;
		a.m_y = 3;
	}
	else if (chessCoord == "d7")
	{
		a.m_x = 1;
		a.m_y = 3;
	}
	else if (chessCoord == "d8")
	{
		a.m_x = 0;
		a.m_y = 3;
	}

	if (chessCoord == "e1")
	{
		a.m_x = 7;
		a.m_y = 4;
	}
	else if (chessCoord == "e2")
	{
		a.m_x = 6;
		a.m_y = 4;
	}
	else if (chessCoord == "e3")
	{
		a.m_x = 5;
		a.m_y = 4;
	}
	else if (chessCoord == "e4")
	{
		a.m_x = 4;
		a.m_y = 4;
	}
	else if (chessCoord == "e5")
	{
		a.m_x = 3;
		a.m_y = 4;
	}
	else if (chessCoord == "e6")
	{
		a.m_x = 2;
		a.m_y = 4;
	}
	else if (chessCoord == "e7")
	{
		a.m_x = 1;
		a.m_y = 4;
	}
	else if (chessCoord == "e8")
	{
		a.m_x = 0;
		a.m_y = 4;
	}

	if (chessCoord == "f1")
	{
		a.m_x = 7;
		a.m_y = 5;
	}
	else if (chessCoord == "f2")
	{
		a.m_x = 6;
		a.m_y = 5;
	}
	else if (chessCoord == "f3")
	{
		a.m_x = 5;
		a.m_y = 5;
	}
	else if (chessCoord == "f4")
	{
		a.m_x = 4;
		a.m_y = 5;
	}
	else if (chessCoord == "f5")
	{
		a.m_x = 3;
		a.m_y = 5;
	}
	else if (chessCoord == "f6")
	{
		a.m_x = 2;
		a.m_y = 5;
	}
	else if (chessCoord == "f7")
	{
		a.m_x = 1;
		a.m_y = 5;
	}
	else if (chessCoord == "f8")
	{
		a.m_x = 0;
		a.m_y = 5;
	}

	if (chessCoord == "g1")
	{
		a.m_x = 7;
		a.m_y = 6;
	}
	else if (chessCoord == "g2")
	{
		a.m_x = 6;
		a.m_y = 6;
	}
	else if (chessCoord == "g3")
	{
		a.m_x = 5;
		a.m_y = 6;
	}
	else if (chessCoord == "g4")
	{
		a.m_x = 4;
		a.m_y = 6;
	}
	else if (chessCoord == "g5")
	{
		a.m_x = 3;
		a.m_y = 6;
	}
	else if (chessCoord == "g6")
	{
		a.m_x = 2;
		a.m_y = 6;
	}
	else if (chessCoord == "g7")
	{
		a.m_x = 1;
		a.m_y = 6;
	}
	else if (chessCoord == "g8")
	{
		a.m_x = 0;
		a.m_y = 6;
	}

	if (chessCoord == "h1")
	{
		a.m_x = 7;
		a.m_y = 7;
	}
	else if (chessCoord == "h2")
	{
		a.m_x = 6;
		a.m_y = 7;
	}
	else if (chessCoord == "h3")
	{
		a.m_x = 5;
		a.m_y = 7;
	}
	else if (chessCoord == "h4")
	{
		a.m_x = 4;
		a.m_y = 7;
	}
	else if (chessCoord == "h5")
	{
		a.m_x = 3;
		a.m_y = 7;
	}
	else if (chessCoord == "h6")
	{
		a.m_x = 2;
		a.m_y = 7;
	}
	else if (chessCoord == "h7")
	{
		a.m_x = 1;
		a.m_y = 7;
	}
	else if (chessCoord == "h8")
	{
		a.m_x = 0;
		a.m_y = 7;
	}
	return a;

}

std::string getPieceType(std::string& input)
{
	char firstChar = input[0];
	std::string pieceType;
	switch (firstChar)
	{
	case 'K':
		pieceType = "King";
		break;
	case 'Q':
		pieceType = "Queen";
		break;
	case 'N':
		pieceType = "Knight";
		break;
	case 'R':
		pieceType = "Rook";
		break;
	case 'B':
		pieceType = "Bishop";
		break;
	case 'a':
	case 'b':
	case'c':
	case'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
		pieceType = "Pawn";
		break;
	default:
		pieceType = "";
		std::cerr << "Error with piece type. Character not known.";
		break;
	}
	if (pieceType != "" && pieceType != "Pawn")//takes the character representing the piece off
		input = input.substr(1, input.size() - 1);
	return pieceType;
}