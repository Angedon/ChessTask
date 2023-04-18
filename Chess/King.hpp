#pragma once
#include "Piece.hpp"

class King : public Piece 
{
public:
	King(int x, int y);
	King(int X, int Y, std::string id);
	bool hit(int X, int Y) const override;
};