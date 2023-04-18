#include "Queen.hpp"

Queen::Queen(int X, int Y) : Piece(X, Y) {}
Queen::Queen(int X, int Y, std::string id) : Piece(X, Y, id) {}
bool Queen::hit(int X, int Y) const 
{
	int x = getX(), y = getY();
	if (abs(x - X) == abs(y - Y) || x == X || y == Y)
	{
		return true;
	}
		return false;
}
