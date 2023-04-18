#include "Test.hpp"


Test::Test()
{
	names.insert("king");
	names.insert("queen");
	names.insert("rook");
	names.insert("bishop");
	names.insert("knight");
}

Test::Test(std::string name[], int n)
{
	for (int i = 0; i < n; ++i)
	{
		names.insert(name[i]);
	}
}

Test::Test(std::vector<std::string> name, int n)
{
	int len = name.size();
	for (int i = 0; i < len; ++i)
	{
		names.insert(name[i]);
	}
}

std::set<std::string> Test::getNames() const
{
	return Test::names;
}

	// Разбиваем каждую строку на отдельные слова в виде вектора
	std::vector<std::string> Test::getTokens(std::string line)
	{
		std::vector<std::string> tokens;
		std::string  buffer = "";
		int i = 0, len = line.size(), k = 0;
		while (i < len)
		{
			if (line[i] == ' ')
			{
				if (buffer.size() != 0)
				{
					tokens.push_back(buffer);
					buffer = "";
				}
			}
			else
			{
				buffer += line[i];
				if (i == len - 1)
				{
					tokens.push_back(buffer);
				}
			}
			i++;
		}
		return tokens;
	}

	// Переводим строку в число, до этого проводится проверка на корректность
	int Test::getNumber(std::string line)
	{
		int number = 0, i = line.size() - 1, k = 1;
		while (i >= 0)
		{
			number += k * (line[i] - '0');
			k *= 10;
			i--;
		}
		return number;
	}

	bool Test::isValidNumber(std::string line)
	{
		int len = line.size();
		int i = line[0] == '-' ? 1 : 0;

		// Проверка валидности числа
		while (i < len)
		{
			if (line[i] < '0' || line[i] > '9')
			{
				return false;
			}
			i++;
		}

		// Если число валидно, то проверяем из правильного ли диапазона оно
		if (getNumber(line) < 1 || getNumber(line) > 8)
		{
			return false;
		}
		return true;
	}

	bool Test::isValidWord(std::string line)
	{
		int len = line.size(), i = 0;
		while (i < len)
		{
			if ((line[i] < 'a' || line[i] > 'z') &&
				(line[i] < 'A' || line[i] > 'Z'))
			{
				return false;
			}
			i++;
		}

		// Проверка, что слово не является английским названием шахматной фигуры
		if (Test::names.find(line) == Test::names.end()) 
		{
			return false;
		}
		return true;
	}

	// Проверка на корректность введенных данных
	bool Test::isCorrect(std::vector<std::vector<std::string>> lines)
	{
		if (lines.size() == 0) 
		{
			throw std::string{ "Empty file!" };
			return false;
		}
		int len = lines.size();
		for (int i = 0; i < len; ++i)
		{
			if (lines[i].size() != 3)
			{
				return false;
			}
			else
			{
				if (!isValidWord(lines[i][0]) ||
					!isValidNumber(lines[i][1]) ||
					!isValidNumber(lines[i][2]))
				{
					if (!isValidWord(lines[i][0])) throw std::string{ "Not a valid word!" };
					else throw std::string{ "Not a valid number!" };
					return false;
				}
			}
		}
		return true;
	}

	// Получаем наши шахматные фигуры в одном векторе
	std::vector<Piece*> Test::getPieces(std::vector<std::vector<std::string>> lines) 
	{
		int len = lines.size();
		std::vector<Piece*> pieces;
		for (int i = 0; i < len; ++i) 
		{
			if (lines[i][0] == "king") 
			{
				pieces.push_back(new King(getNumber(lines[i][2]), getNumber(lines[i][1]), lines[i][0]));
			}
			else if (lines[i][0] == "queen")
			{
				pieces.push_back(new Queen(getNumber(lines[i][2]), getNumber(lines[i][1]), lines[i][0]));
			}
			else if (lines[i][0] == "rook")
			{
				pieces.push_back(new Rook(getNumber(lines[i][2]), getNumber(lines[i][1]), lines[i][0]));
			}
			else if (lines[i][0] == "bishop")
			{
				pieces.push_back(new Bishop(getNumber(lines[i][2]), getNumber(lines[i][1]), lines[i][0]));
			}
			else if (lines[i][0] == "knight")
			{
				pieces.push_back(new Knight(getNumber(lines[i][2]), getNumber(lines[i][1]), lines[i][0]));
			}
		}
		return pieces;
	}
