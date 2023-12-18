#include "AOCDayFour.h"

AOCDayFour::AOCDayFour()
{
}

AOCDayFour::~AOCDayFour()
{
}

void AOCDayFour::Update(float dt)
{
}

void AOCDayFour::Solve(bool part)
{
	int sum = 0;
	std::vector<std::string> lines;
	scratchCards.open(files[0], std::ios::in);
	if (scratchCards.is_open())
	{
		while (!scratchCards.eof())
		{
			std::string line;
			std::getline(scratchCards, line);
			lines.push_back(line);
		}
	}
	scratchCards.close();
	//string of number, numStart, numEnd, row
	std::vector<std::pair<int, int>> gameNo;
	std::vector<std::vector<int>> winningNums;
	std::vector<std::vector<int>> gameNums;
	std::vector<int> points;

	for (int row = 0; row < lines.size(); row++)
	{
		std::string line = lines[row];
		int32_t pos = 0;

		pos = line.find(' ');
		line.erase(0, pos + 1);

		pos = line.find(':');
		gameNo.push_back({ std::stoi(line.substr(0, pos)), 1 });
		line.erase(0, pos + 1);

		std::vector<int> currentNums;
		bool game = true;

		while (game)
		{
			pos = line.find(" ");
			std::string num = line.substr(0, pos);
			if (num == "|")
			{
				game = false;
			}
			else if (num.size() > 0)
			{
				currentNums.push_back(std::stoi(num));
			}
			line.erase(0, pos + 1);
		}
		winningNums.push_back(currentNums);
		currentNums.clear();
		game = true;
		while (game)
		{
			pos = line.find(" ");
			std::string num = line.substr(0, pos);
			if (pos == std::string::npos)
			{
				game = false;
			}
			else if (num.size() > 0)
			{
				currentNums.push_back(std::stoi(num));
			}
			line.erase(0, pos + 1);
		}
		currentNums.push_back(std::stoi(line));
		gameNums.push_back(currentNums);
	}

	if (part)
	{
		int originalCards = winningNums.size();
		for (int num = 0; num < winningNums.size(); num++)
		{
			int point = 0;
			for (int winN = 0; winN < winningNums[num].size(); winN++)
			{
				for (int roundNum = 0; roundNum < gameNums[num].size(); roundNum++)
				{
					if (winningNums[num][winN] == gameNums[num][roundNum])
					{
						point++;
					}
				}
			}			
			for (int i = 1; i <= point; i++)
			{
				gameNo[num + i].second += gameNo[num].second;
			}
		}
		for (auto gn : gameNo)
		{
			sum += gn.second;
		}
	}
	else
	{
		for (int num = 0; num < winningNums.size(); num++)
		{
			int point = 0;
			for (int winN = 0; winN < winningNums[num].size(); winN++)
			{
				for (int roundNum = 0; roundNum < gameNums[num].size(); roundNum++)
				{
					if (winningNums[num][winN] == gameNums[num][roundNum])
					{
						if (point == 0)
						{
							point++;
						}
						else
						{
							point *= 2;
						}
					}
				}
			}
			points.push_back(point);
		}

		for (int s : points)
		{
			sum += s;
		}
	}


	std::cout << "The answer is " << sum;

	return;
}
