#pragma once
#include<vector>
#include<set>
#include "../Chess/King.hpp"
#include "../Chess/Queen.hpp"
#include "../Chess/Rook.hpp"
#include "../Chess/Bishop.hpp"
#include "../Chess/Knight.hpp"

class Test 
{
private:
	std::set<std::string> names;
public:
	Test();
	Test(std::string name[], int n);
	Test::Test(std::vector<std::string> name, int n);
	std::set<std::string> getNames() const;
	std::vector<std::string> getTokens(std::string line);
	std::vector<Piece*> getPieces(std::vector<std::vector<std::string>> lines);
	int getNumber(std::string line);
	bool isValidNumber(std::string line);
	bool isValidWord(std::string line);
	bool isCorrect(std::vector<std::vector<std::string>> lines);
};