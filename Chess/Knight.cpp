#include "Knight.hpp"

Knight::Knight(int X, int Y) : Piece(X, Y) {}
Knight::Knight(int X, int Y, std::string id) : Piece(X, Y, id) {}
bool Knight::hit(int X, int Y) const
{
	int x = getX(), y = getY();
	for (int i = -2; i < 3; ++i) 
	{
		if (i != 0) {
			if (y + i == Y && (x - (3 - abs(i))) == X)
			{
				return true;
			}
			if (y + i == Y && (x + (3 - abs(i))) == X)
			{
				return true;
			}
		}
	}
	return false;
}
