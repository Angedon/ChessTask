#include "Rook.hpp"

Rook::Rook(int X, int Y) : Piece(X, Y) {}
Rook::Rook(int X, int Y, std::string id) : Piece(X, Y, id) {}
bool Rook::hit(int X, int Y) const 
{
	if (getX() == X || getY() == Y) 
	{
		return true;
	}
	return false;
}
