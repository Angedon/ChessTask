#include "King.hpp"

King::King(int x, int y) : Piece(x, y) {}
King::King(int X, int Y, std::string id) : Piece(X, Y, id) {}
bool King::hit(int X, int Y) const
{
	int x = getX(), y = getY();
	if (abs(x - X) <= 1 && abs(y - Y) <= 1) 
	{
		return true;
	}
	return false;
}
