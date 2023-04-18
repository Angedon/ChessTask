#pragma once
#include "Piece.hpp"

class Queen : public Piece
{
public:
	Queen(int X, int Y);
	Queen(int X, int Y, std::string name);
	bool hit(int X, int Y) const override;
};