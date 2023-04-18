#include "Bishop.hpp"

Bishop::Bishop(int X, int Y) : Piece(X, Y) {}

Bishop::Bishop(int X, int Y, std::string id) : Piece(X, Y, id) {}

bool Bishop::hit(int X, int Y) const
{
	int x = getX(), y = getY();
	if (abs(x - X) == abs(y - Y))
	{
		return true;
	}
	return false;
}
