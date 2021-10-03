#include "Player.h"
#include <string>

void Player::removePieceFromVector(Piece* toRemove)
{
	for (std::vector<Piece*>::iterator it = m_pieces.begin(); it != m_pieces.end(); it++)
	{
		if (toRemove == (*it))
		{
			delete *it;
			m_pieces.erase(it);
			std::cout << "Captured piece!";
			break;
		}
	}
}
void Player::setGamePtr(Board* input)
{
	m_game = input;
}
std::vector<Piece*> Player::getPieceVector() const
{
	return m_pieces;
}
Player::~Player()
{
	for (unsigned int i = 0; i < m_pieces.size(); i++)
	{
		delete m_pieces[i];
	}
}
std::string Player::getName() const
{
	return m_name;
}

Player::Player(std::string inputName, std::string inputColor, Board* game)//this a causing a string error for some reason
	:m_name(inputName), m_color(inputColor), m_game(game)
{
	if (m_color == "White")
	{

		for (int i = 0; i < 8; i++)
		{
			m_pieces.push_back(new Pawn("White", 6, i, m_game));
		}
		m_pieces.push_back(new Rook("White", 7, 0, m_game));
		m_pieces.push_back(new Rook("White", 7, 7, m_game));
		m_pieces.push_back(new Knight("White", 7, 1, m_game));
		m_pieces.push_back(new Knight("White", 7, 6, m_game));
		m_pieces.push_back(new Bishop("White", 7, 2, m_game));
		m_pieces.push_back(new Bishop("White", 7, 5, m_game));
		m_pieces.push_back(new King("White", 7, 4, m_game));
		m_pieces.push_back(new Queen("White", 7, 3, m_game));
		//m_pieces.push_back(new Pawn("White", 6, 4, m_game)); 
		//m_pieces.push_back(new Pawn("White", 6, 7, m_game));
		//m_pieces.push_back(new Rook("White", 7, 0, m_game));
		//m_pieces.push_back(new Rook("White", 7, 7, m_game));
	}
	else if (m_color == "Black")
	{
		for (int i = 0; i < 8; i++)
		{
			m_pieces.push_back(new Pawn("Black", 1, i, m_game));
		}
		m_pieces.push_back(new Rook("Black", 0, 0, m_game));
		m_pieces.push_back(new Rook("Black", 0, 7, m_game));
		m_pieces.push_back(new Knight("Black", 0, 1, m_game));
		m_pieces.push_back(new Knight("Black", 0, 6, m_game));
		m_pieces.push_back(new Bishop("Black", 0, 2, m_game));
		m_pieces.push_back(new Bishop("Black", 0, 5, m_game));
		m_pieces.push_back(new King("Black", 0, 4, m_game));
		m_pieces.push_back(new Queen("Black", 0, 3, m_game));
		/*m_pieces.push_back(new Rook("Black", 0, 7, m_game));
		m_pieces.push_back(new Rook("Black", 1, 4, m_game));*/
	}


}