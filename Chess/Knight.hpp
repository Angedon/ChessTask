#pragma once
#include "Piece.hpp"

class Knight : public Piece
{
public:
	Knight(int X, int Y);
	Knight(int X, int Y, std::string id);
	bool hit(int X, int Y) const override;
};