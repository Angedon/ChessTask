#pragma once
#include "Piece.hpp"

class Bishop : public Piece
{
public:
	Bishop(int X, int Y);
	Bishop(int X, int Y, std::string id);
	bool hit(int X, int Y) const override;
};