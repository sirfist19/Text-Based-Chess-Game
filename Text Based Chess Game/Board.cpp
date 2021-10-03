#include "Board.h"
#include <string>

const char ODD_CHAR = '.';
const char EVEN_CHAR = '.';

char Board::getCharAtPos(int x, int y)
{
	return board[x][y];
}
Board::~Board()
{
	delete white;
	delete black;
}
void Board::turn()
{
	using namespace std;
	std::vector<Piece*> whitePieces = white->getPieceVector();
	std::vector<Piece*> blackPieces = black->getPieceVector();

	bool validWhiteMove = false;
	bool validBlackMove = false;

	//white's turn
	while (validWhiteMove == false)
	{

		int x, y;
		cout << endl << endl << "White's Turn" << endl << white->getName() << ": Enter the x and y coordinates to move your piece to." << endl;
		string chessCoord;
		getline(cin, chessCoord);
		string pieceTypeToMove = getPieceType(chessCoord);
		coord a = convertChessCoord(chessCoord);
		x = a.m_x;
		y = a.m_y;

		cout << pieceTypeToMove << " to " << a.m_x << ", " << a.m_y;
		for (unsigned int i = 0; i < whitePieces.size(); i++)
		{
			if (whitePieces[i]->getType() == pieceTypeToMove)
			{
				if (whitePieces[i]->move(x, y))
				{
					validWhiteMove = true;
					break;
				}
				if (i == whitePieces.size() - 1)
					cout << endl << endl << "Invalid move! Please enter another move." << endl;
			}
			
		}
		
	}

	system("CLS");
	updateBoard();
	display();


	//black's turn
	while (validBlackMove == false)
	{
		int x, y;
		cout << endl << endl << "Black's Turn" << endl << black->getName() << ": Enter the x and y coordinates to move your piece to." << endl;
		string chessCoord;
		getline(cin, chessCoord);
		string pieceTypeToMove = getPieceType(chessCoord);
		coord a = convertChessCoord(chessCoord);
		x = a.m_x;
		y = a.m_y;
		for (unsigned int i = 0; i < blackPieces.size(); i++)
		{
			if (blackPieces[i]->getType() == pieceTypeToMove)
			{
				if (blackPieces[i]->move(x, y))
				{
					validBlackMove = true;
					break;
				}
				
				if (i == blackPieces.size() - 1)
				{
					cout << endl << endl << "Invalid move! Please enter another move." << endl;
				}
					
			}
		}
	}
	system("CLS");
	updateBoard();
	display();
}

//returns true if the (x,y) spot is occupied and return a ptr to that piece in pieceAtSpot
//returns false if the (x,y) spot is not occupied and nullptr for pieceAtSpot
bool Board::occupied(int x, int y)
{
	//look through the players to see if there's a piece at the square
	std::vector<Piece*> whitePieces = white->getPieceVector();
	std::vector<Piece*> blackPieces = black->getPieceVector();


	for (unsigned int i = 0; i < whitePieces.size(); i++)
	{
		coord cur = whitePieces[i]->getCoord();
		if (x == cur.m_x && y == cur.m_y)//the coords are the same
		{
			//pieceAtSpot = whitePieces[i];//return the pointer to the pointer of the correct piece
			return true;
		}
	}
	for (unsigned int i = 0; i < blackPieces.size(); i++)//places the white pieces
	{
		coord cur = blackPieces[i]->getCoord();
		if (x == cur.m_x && y == cur.m_y)//the coords are the same
		{
			//pieceAtSpot = blackPieces[i];//return the pointer to the pointer of the correct piece
			return true;
		}
	}
	return false;
}
bool Board::occupied(int x, int y, Piece*& pieceAtSpot)
{
	//look through the players to see if there's a piece at the square
	std::vector<Piece*> whitePieces = white->getPieceVector();
	std::vector<Piece*> blackPieces = black->getPieceVector();


	for (unsigned int i = 0; i < whitePieces.size(); i++)//places the white pieces
	{
		coord cur = whitePieces[i]->getCoord();
		if (x == cur.m_x && y == cur.m_y)//the coords are the same
		{
			pieceAtSpot = whitePieces[i];//return the pointer to the pointer of the correct piece
			return true;
		}
	}
	for (unsigned int i = 0; i < blackPieces.size(); i++)//places the white pieces
	{
		coord cur = blackPieces[i]->getCoord();
		if (x == cur.m_x && y == cur.m_y)//the coords are the same
		{
			pieceAtSpot = blackPieces[i];//return the pointer to the pointer of the correct piece
			return true;
		}
	}



	//if no piece found
	pieceAtSpot = nullptr;
	return false;

}
Board::Board()
	:white(new Player("Aidan", "White", this)), black(new Player("sirfist19", "Black", this))
{
	//makes a blank board
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (i % 2 == 0)//if i is even
			{
				//place spaces at even numbers
				if (j % 2 == 0)
				{
					board[i][j] = EVEN_CHAR;
				}
				else
					board[i][j] = ODD_CHAR;
			}
			if (i % 2 != 0)//if i is odd
			{
				//place spaces at odd numbers
				if (j % 2 != 0)
				{
					board[i][j] =EVEN_CHAR;
				}
				else
					board[i][j] = ODD_CHAR;
			}

		}
	}
}
/*
Board::Board(Player* inputWhite, Player* inputBlack)
	:white(inputWhite), black(inputBlack)
{
	//int size;
	//cout << white->getPieceArray(size)->getChar();//not working
	//makes a blank board
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (i % 2 == 0)//if i is even
			{
				//place spaces at even numbers
				if (j % 2 == 0)
				{
					board[i][j] = ' ';
				}
				else
					board[i][j] = '=';
			}
			if (i % 2 != 0)//if i is odd
			{
				//place spaces at odd numbers
				if (j % 2 != 0)
				{
					board[i][j] = ' ';
				}
				else
					board[i][j] = '=';
			}

		}
	}
}*/

void Board::updateBoard()
{
	std::vector<Piece*> whitePieces = white->getPieceVector();
	std::vector<Piece*> blackPieces = black->getPieceVector();
	//resets the board for the next move
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (i % 2 == 0)//if i is even
			{
				//place spaces at even numbers
				if (j % 2 == 0)
				{
					board[i][j] = EVEN_CHAR;
				}
				else
					board[i][j] = ODD_CHAR;
			}
			if (i % 2 != 0)//if i is odd
			{
				//place spaces at odd numbers
				if (j % 2 != 0)
				{
					board[i][j] = EVEN_CHAR;
				}
				else
					board[i][j] = ODD_CHAR;
			}
		}
	}

	for (unsigned int i = 0; i < whitePieces.size(); i++)//places the white pieces
	{
		coord cur = whitePieces[i]->getCoord();
		char curChar = whitePieces[i]->getChar();
		board[cur.m_x][cur.m_y] = curChar;
	}
	for (unsigned int i = 0; i < blackPieces.size(); i++)//places the black pieces
	{
		coord cur = blackPieces[i]->getCoord();
		char curChar = blackPieces[i]->getChar();
		board[cur.m_x][cur.m_y] = curChar;
	}

}
void Board::display()
{
	using std::cout;
	using std::endl;
	//cout << "  ----------" << endl;
	cout << "  ABCDEFGH" << endl << " ==========" << endl;
	//cout << "  ABCDEFGH"<<endl <<" ~~~~~~~~~~" << endl;
	for (int i = 0; i < 8; i++)
	{
		cout << 8 - i;
		cout << "|";
		for (int j = 0; j < 8; j++)
		{
			cout << board[i][j];
		}
		cout << "|";
		cout << 8 - i;
		cout << endl;
	}
	//cout <<"  ----------"<<endl<<"   ABCDEFGH";
	cout << " ==========" << endl << "  ABCDEFGH";
	//cout << " ~~~~~~~~~~" << endl << "  ABCDEFGH";
}

