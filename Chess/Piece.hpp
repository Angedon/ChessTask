#pragma once
#include<cmath>
#include<string>
class Piece {
private:
	std::string name;
	int x, y;
public:
	Piece(int x, int y);
	Piece(int X, int Y, std::string id);
	int getX() const;
	int getY() const;
	std::string getName();
	virtual bool hit(int x, int y) const = 0;
};