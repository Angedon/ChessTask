#pragma once
#include "Piece.hpp"

class Rook : public Piece {
public:
	Rook(int X, int Y);
	Rook(int X, int Y, std::string name);
	bool hit(int X, int Y) const override;
};