#include "Piece.hpp"

Piece::Piece(int X, int Y) : x(X), y(Y) {}

Piece::Piece(int X, int Y, std::string id) : x(X), y(Y), name(id) {}

int Piece::getX() const
{
	return x;
}

int Piece::getY() const
{
	return y;
}

std::string Piece::getName() 
{
	return name;
}