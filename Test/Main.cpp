#include<fstream>
#include<iostream>
#include "Test.hpp"

int main()
{
	std::ifstream fin("input.txt");
	std::string line;
	std::vector<std::vector<std::string>> lines;
	Test test = Test();

	if (fin.is_open())
	{
		while (getline(fin, line))
		{
			lines.push_back(test.getTokens(line));
		}
	}

	// Ѕудем провер€ть на корректность введенных данных
	bool correct = false;
	try
	{
		correct = test.isCorrect(lines);
		if (correct)
		{
			std::vector<Piece*> pieces = test.getPieces(lines);
			std::vector<std::string> log;
			char** map = new char*[8];
			for (int i = 0; i < 8; ++i)
			{
				map[i] = new char[8];
				for (int j = 0; j < 8; ++j) {
					map[i][j] = '0';
				}
			}
			int len = pieces.size();
			for (int i = 0; i < len; ++i)
			{
				// Knight и king начинаютс€ с одной буквы, пусть knight тогда будет на карте обозначатьс€,
				// как h (horse), а все остальные будут своей первой буквой обозначатьс€
				if (pieces[i]->getName() == "knight")
				{
					map[pieces[i]->getY() - 1][pieces[i]->getX() - 1] = 'h';
				}
				else
				{
					map[pieces[i]->getY() - 1][pieces[i]->getX() - 1] = pieces[i]->getName()[0];
				}


				for (int j = 0; j < len; ++j)
				{
					if (i != j)
					{

						if (pieces[i]->hit(pieces[j]->getX(), pieces[j]->getY()))
						{
							// —обираем лог сообщение, чтобы в конце его вывести в консоль
							log.push_back(pieces[i]->getName() + "(" + std::to_string(pieces[i]->getY()) + "," + std::to_string(pieces[i]->getX()) + ")" +
								" hit " + pieces[j]->getName() + "(" + std::to_string(pieces[j]->getY()) + "," + std::to_string(pieces[j]->getX()) + ")");
						}
					}
				}
			}

			for (int i = 0; i < log.size(); ++i)
			{
				std::cout << log[i] << std::endl;
			}

			std::cout << std::endl;

			for (int i = 0; i < 8; ++i)
			{
				for (int j = 0; j < 8; ++j)
				{
					std::cout << map[i][j];
				}
				std::cout << std::endl;
			}
		}
	}
	catch (std::string error)
	{
		// ¬ыводим ошибку
		std::cout << error << std::endl;
	}

	fin.close();
	system("pause");
	return 0;
}