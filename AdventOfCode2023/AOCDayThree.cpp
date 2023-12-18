#include "AOCDayThree.h"

AOCDayThree::AOCDayThree()
{
}

AOCDayThree::~AOCDayThree()
{
}


void AOCDayThree::Update(float dt)
{
}

void AOCDayThree::Solve(bool part)
{
	int sum = 0;
	std::vector<int> adjacentSymbolNums;
	std::vector<std::string> lines;
	gameRecords.open(files[0], std::ios::in);
	if (gameRecords.is_open())
	{
		while (!gameRecords.eof())
		{
			std::string line;
			std::getline(gameRecords, line);
			lines.push_back(line);
		}
	}
	gameRecords.close();

	//string of number, numStart, numEnd, row
	std::vector<std::tuple<std::string, int, int, int>> nums;
	std::vector<std::pair<int, int>> gears;
	std::vector<std::pair<int, int>> gearRatio;
	for (int row = 0; row < lines.size(); row++)
	{
		std::string current = lines[row];
		std::string digit;
		int numStart = -1;
		int numEnd = -1;
		for (int i = 0; i < current.size(); i++)
		{
			if (current[i] == '*')
			{
				if (numStart >= 0)
				{
					numEnd = i - 1;
					nums.push_back({ digit, numStart, numEnd, row });
					digit.clear();
					numStart = -1;
					numEnd = -1;
				}
				gears.push_back({ row, i, });
				gearRatio.push_back({ 1,0 });
			}
			else if (isdigit(current[i]))
			{
				digit += current[i];
				if (numStart == -1)
				{
					numStart = i;
				}
			}
			else if (numStart >= 0)
			{
				numEnd = i - 1;
				nums.push_back({ digit, numStart, numEnd, row });
				digit.clear();
				numStart = -1;
				numEnd = -1;
			}
		}
		if (digit.size() > 0)
		{
			nums.push_back({ digit, numStart, current.size() - 1, row });
		}
	}
	if (part)
	{
		for (int i = 0; i < nums.size(); i++)
		{
			std::string number;
			int numberStart;
			int numberEnd;
			int numberRow;
			std::tie(number, numberStart, numberEnd, numberRow) = nums[i];
			for (int j = 0; j < number.size(); j++)
			{
				if (numberRow == 0)
				{
					if (j == 0 && numberStart != 0)
					{
						if ('*' == lines[numberRow][numberStart - 1])
						{
							auto it = std::find_if(gears.begin(), gears.end(),
								[&](const auto& p) {return p.first == numberRow && p.second == numberStart - 1; });
							if (it != gears.end())
							{
								int iter = it - gears.begin();
								gearRatio[iter].first = std::stoi(number) * gearRatio[iter].first;
								gearRatio[iter].second = 1 + gearRatio[iter].second;
							}
						}
						if ('*' == lines[numberRow + 1][numberStart - 1])
						{
							auto it = std::find_if(gears.begin(), gears.end(),
								[&](const auto& p) {return p.first == numberRow + 1 && p.second == numberStart - 1; });
							if (it != gears.end())
							{
								int iter = it - gears.begin();
								gearRatio[iter].first = std::stoi(number) * gearRatio[iter].first;
								gearRatio[iter].second = 1 + gearRatio[iter].second;
							}
						}
						if ('*' == lines[numberRow + 1][numberStart])
						{
							auto it = std::find_if(gears.begin(), gears.end(),
								[&](const auto& p) {return p.first == numberRow + 1 && p.second == numberStart; });
							if (it != gears.end())
							{
								int iter = it - gears.begin();
								gearRatio[iter].first = std::stoi(number) * gearRatio[iter].first;
								gearRatio[iter].second = 1 + gearRatio[iter].second;
							}
						}
					}
					else if (j == number.size() - 1 && numberEnd != lines[numberRow].size() - 1)
					{
						if ('*' == lines[numberRow][numberEnd + 1])
						{
							auto it = std::find_if(gears.begin(), gears.end(),
								[&](const auto& p) {return p.first == numberRow && p.second == numberEnd + 1; });
							if (it != gears.end())
							{
								int iter = it - gears.begin();
								gearRatio[iter].first = std::stoi(number) * gearRatio[iter].first;
								gearRatio[iter].second = 1 + gearRatio[iter].second;
							}
						}
						if ('*' == lines[numberRow + 1][numberEnd + 1])
						{
							auto it = std::find_if(gears.begin(), gears.end(),
								[&](const auto& p) {return p.first == numberRow + 1 && p.second == numberEnd + 1; });
							if (it != gears.end())
							{
								int iter = it - gears.begin();
								gearRatio[iter].first = std::stoi(number) * gearRatio[iter].first;
								gearRatio[iter].second = 1 + gearRatio[iter].second;
							}
						}
						if ('*' == lines[numberRow + 1][numberEnd])
						{
							auto it = std::find_if(gears.begin(), gears.end(),
								[&](const auto& p) {return p.first == numberRow + 1 && p.second == numberEnd; });
							if (it != gears.end())
							{
								int iter = it - gears.begin();
								gearRatio[iter].first = std::stoi(number) * gearRatio[iter].first;
								gearRatio[iter].second = 1 + gearRatio[iter].second;
							}
						}
					}
					else
					{
						if ('*' == lines[numberRow + 1][numberStart + j])
						{
							auto it = std::find_if(gears.begin(), gears.end(),
								[&](const auto& p) {return p.first == numberRow + 1 && p.second == numberStart + j; });
							if (it != gears.end())
							{
								int iter = it - gears.begin();
								gearRatio[iter].first = std::stoi(number) * gearRatio[iter].first;
								gearRatio[iter].second = 1 + gearRatio[iter].second;
							}
						}
					}
				}
				else if (numberRow == lines.size() - 1)
				{
					if (j == 0 && numberStart != 0)
					{
						if ('*' == lines[numberRow][numberStart - 1])
						{
							auto it = std::find_if(gears.begin(), gears.end(),
								[&](const auto& p) {return p.first == numberRow && p.second == numberStart - 1; });
							if (it != gears.end())
							{
								int iter = it - gears.begin();
								gearRatio[iter].first = std::stoi(number) * gearRatio[iter].first;
								gearRatio[iter].second = 1 + gearRatio[iter].second;
							}
						}
						if ('*' == lines[numberRow - 1][numberStart - 1])
						{
							auto it = std::find_if(gears.begin(), gears.end(),
								[&](const auto& p) {return p.first == numberRow - 1 && p.second == numberStart - 1; });
							if (it != gears.end())
							{
								int iter = it - gears.begin();
								gearRatio[iter].first = std::stoi(number) * gearRatio[iter].first;
								gearRatio[iter].second = 1 + gearRatio[iter].second;
							}
						}
						if ('*' == lines[numberRow - 1][numberStart]) {
							auto it = std::find_if(gears.begin(), gears.end(),
								[&](const auto& p) {return p.first == numberRow - 1 && p.second == numberStart; });
							if (it != gears.end())
							{
								int iter = it - gears.begin();
								gearRatio[iter].first = std::stoi(number) * gearRatio[iter].first;
								gearRatio[iter].second = 1 + gearRatio[iter].second;
							}
						}
					}
					else if (j == number.size() - 1 && numberEnd != lines[numberRow].size() - 1)
					{
						if ('*' == lines[numberRow][numberEnd + 1]) {
							auto it = std::find_if(gears.begin(), gears.end(),
								[&](const auto& p) {return p.first == numberRow && p.second == numberEnd + 1; });
							if (it != gears.end())
							{
								int iter = it - gears.begin();
								gearRatio[iter].first = std::stoi(number) * gearRatio[iter].first;
								gearRatio[iter].second = 1 + gearRatio[iter].second;
							}
						}
						if ('*' == lines[numberRow - 1][numberEnd + 1])
						{
							auto it = std::find_if(gears.begin(), gears.end(),
								[&](const auto& p) {return p.first == numberRow - 1 && p.second == numberEnd + 1; });
							if (it != gears.end())
							{
								int iter = it - gears.begin();
								gearRatio[iter].first = std::stoi(number) * gearRatio[iter].first;
								gearRatio[iter].second = 1 + gearRatio[iter].second;
							}
						}
						if ('*' == lines[numberRow - 1][numberEnd])
						{
							auto it = std::find_if(gears.begin(), gears.end(),
								[&](const auto& p) {return p.first == numberRow - 1 && p.second == numberEnd; });
							if (it != gears.end())
							{
								int iter = it - gears.begin();
								gearRatio[iter].first = std::stoi(number) * gearRatio[iter].first;
								gearRatio[iter].second = 1 + gearRatio[iter].second;
							}
						}
					}
					else
					{
						if ('*' == lines[numberRow - 1][numberStart + j])
						{
							auto it = std::find_if(gears.begin(), gears.end(),
								[&](const auto& p) {return p.first == numberRow - 1 && p.second == numberStart + j; });
							if (it != gears.end())
							{
								int iter = it - gears.begin();
								gearRatio[iter].first = std::stoi(number) * gearRatio[iter].first;
								gearRatio[iter].second = 1 + gearRatio[iter].second;
							}
						}
					}
				}
				else
				{
					if (j == 0 && numberStart != 0 && number.size() == 1)
					{
						if ('*' == lines[numberRow - 1][numberStart])
						{
							auto it = std::find_if(gears.begin(), gears.end(),
								[&](const auto& p) {return p.first == numberRow - 1 && p.second == numberStart; });
							if (it != gears.end())
							{
								int iter = it - gears.begin();
								gearRatio[iter].first = std::stoi(number) * gearRatio[iter].first;
								gearRatio[iter].second = 1 + gearRatio[iter].second;
							}
						}
						if ('*' == lines[numberRow - 1][numberStart - 1])
						{
							auto it = std::find_if(gears.begin(), gears.end(),
								[&](const auto& p) {return p.first == numberRow - 1 && p.second == numberStart - 1; });
							if (it != gears.end())
							{
								int iter = it - gears.begin();
								gearRatio[iter].first = std::stoi(number) * gearRatio[iter].first;
								gearRatio[iter].second = 1 + gearRatio[iter].second;
							}
						}
						if ('*' == lines[numberRow][numberStart - 1])
						{
							auto it = std::find_if(gears.begin(), gears.end(),
								[&](const auto& p) {return p.first == numberRow && p.second == numberStart - 1; });
							if (it != gears.end())
							{
								int iter = it - gears.begin();
								gearRatio[iter].first = std::stoi(number) * gearRatio[iter].first;
								gearRatio[iter].second = 1 + gearRatio[iter].second;
							}
						}
						if ('*' == lines[numberRow + 1][numberStart - 1])
						{
							auto it = std::find_if(gears.begin(), gears.end(),
								[&](const auto& p) {return p.first == numberRow + 1 && p.second == numberStart - 1; });
							if (it != gears.end())
							{
								int iter = it - gears.begin();
								gearRatio[iter].first = std::stoi(number) * gearRatio[iter].first;
								gearRatio[iter].second = 1 + gearRatio[iter].second;
							}
						}
						if ('*' == lines[numberRow + 1][numberStart])
						{
							auto it = std::find_if(gears.begin(), gears.end(),
								[&](const auto& p) {return p.first == numberRow + 1 && p.second == numberStart; });
							if (it != gears.end())
							{
								int iter = it - gears.begin();
								gearRatio[iter].first = std::stoi(number) * gearRatio[iter].first;
								gearRatio[iter].second = 1 + gearRatio[iter].second;
							}
						}
						if ('*' == lines[numberRow + 1][numberEnd + 1])
						{
							auto it = std::find_if(gears.begin(), gears.end(),
								[&](const auto& p) {return p.first == numberRow + 1 && p.second == numberEnd + 1; });
							if (it != gears.end())
							{
								int iter = it - gears.begin();
								gearRatio[iter].first = std::stoi(number) * gearRatio[iter].first;
								gearRatio[iter].second = 1 + gearRatio[iter].second;
							}
						}
						if ('*' == lines[numberRow][numberEnd + 1])
						{
							auto it = std::find_if(gears.begin(), gears.end(),
								[&](const auto& p) {return p.first == numberRow && p.second == numberEnd + 1; });
							if (it != gears.end())
							{
								int iter = it - gears.begin();
								gearRatio[iter].first = std::stoi(number) * gearRatio[iter].first;
								gearRatio[iter].second = 1 + gearRatio[iter].second;
							}
						}
						if ('*' == lines[numberRow - 1][numberEnd + 1])
						{
							auto it = std::find_if(gears.begin(), gears.end(),
								[&](const auto& p) {return p.first == numberRow - 1 && p.second == numberEnd + 1; });
							if (it != gears.end())
							{
								int iter = it - gears.begin();
								gearRatio[iter].first = std::stoi(number) * gearRatio[iter].first;
								gearRatio[iter].second = 1 + gearRatio[iter].second;
							}
						}
					}
					else if (j == 0 && numberStart != 0 && number.size() > 1)
					{
						if ('*' == lines[numberRow - 1][numberStart])
						{
							auto it = std::find_if(gears.begin(), gears.end(),
								[&](const auto& p) {return p.first == numberRow - 1 && p.second == numberStart; });
							if (it != gears.end())
							{
								int iter = it - gears.begin();
								gearRatio[iter].first = std::stoi(number) * gearRatio[iter].first;
								gearRatio[iter].second = 1 + gearRatio[iter].second;
							}
						}
						if ('*' == lines[numberRow - 1][numberStart - 1])
						{
							auto it = std::find_if(gears.begin(), gears.end(),
								[&](const auto& p) {return p.first == numberRow - 1 && p.second == numberStart - 1; });
							if (it != gears.end())
							{
								int iter = it - gears.begin();
								gearRatio[iter].first = std::stoi(number) * gearRatio[iter].first;
								gearRatio[iter].second = 1 + gearRatio[iter].second;
							}
						}
						if ('*' == lines[numberRow][numberStart - 1])
						{
							auto it = std::find_if(gears.begin(), gears.end(),
								[&](const auto& p) {return p.first == numberRow && p.second == numberStart - 1; });
							if (it != gears.end())
							{
								int iter = it - gears.begin();
								gearRatio[iter].first = std::stoi(number) * gearRatio[iter].first;
								gearRatio[iter].second = 1 + gearRatio[iter].second;
							}
						}
						if ('*' == lines[numberRow + 1][numberStart - 1])
						{
							auto it = std::find_if(gears.begin(), gears.end(),
								[&](const auto& p) {return p.first == numberRow + 1 && p.second == numberStart - 1; });
							if (it != gears.end())
							{
								int iter = it - gears.begin();
								gearRatio[iter].first = std::stoi(number) * gearRatio[iter].first;
								gearRatio[iter].second = 1 + gearRatio[iter].second;
							}
						}
						if ('*' == lines[numberRow + 1][numberStart])
						{
							auto it = std::find_if(gears.begin(), gears.end(),
								[&](const auto& p) {return p.first == numberRow + 1 && p.second == numberStart; });
							if (it != gears.end())
							{
								int iter = it - gears.begin();
								gearRatio[iter].first = std::stoi(number) * gearRatio[iter].first;
								gearRatio[iter].second = 1 + gearRatio[iter].second;
							}
						}
					}
					else if (j == number.size() - 1 && numberEnd != lines[numberRow].size() - 1)
					{
						if ('*' == lines[numberRow - 1][numberEnd])
						{
							auto it = std::find_if(gears.begin(), gears.end(),
								[&](const auto& p) {return p.first == numberRow - 1 && p.second == numberEnd; });
							if (it != gears.end())
							{
								int iter = it - gears.begin();
								gearRatio[iter].first = std::stoi(number) * gearRatio[iter].first;
								gearRatio[iter].second = 1 + gearRatio[iter].second;
							}
						}
						if ('*' == lines[numberRow - 1][numberEnd + 1])
						{
							auto it = std::find_if(gears.begin(), gears.end(),
								[&](const auto& p) {return p.first == numberRow - 1 && p.second == numberEnd + 1; });
							if (it != gears.end())
							{
								int iter = it - gears.begin();
								gearRatio[iter].first = std::stoi(number) * gearRatio[iter].first;
								gearRatio[iter].second = 1 + gearRatio[iter].second;
							}
						}
						if ('*' == lines[numberRow][numberEnd + 1])
						{
							auto it = std::find_if(gears.begin(), gears.end(),
								[&](const auto& p) {return p.first == numberRow && p.second == numberEnd + 1; });
							if (it != gears.end())
							{
								int iter = it - gears.begin();
								gearRatio[iter].first = std::stoi(number) * gearRatio[iter].first;
								gearRatio[iter].second = 1 + gearRatio[iter].second;
							}
						}
						if ('*' == lines[numberRow + 1][numberEnd + 1])
						{
							auto it = std::find_if(gears.begin(), gears.end(),
								[&](const auto& p) {return p.first == numberRow + 1 && p.second == numberEnd + 1; });
							if (it != gears.end())
							{
								int iter = it - gears.begin();
								gearRatio[iter].first = std::stoi(number) * gearRatio[iter].first;
								gearRatio[iter].second = 1 + gearRatio[iter].second;
							}
						}
						if ('*' == lines[numberRow + 1][numberEnd])
						{
							auto it = std::find_if(gears.begin(), gears.end(),
								[&](const auto& p) {return p.first == numberRow + 1 && p.second == numberEnd; });
							if (it != gears.end())
							{
								int iter = it - gears.begin();
								gearRatio[iter].first = std::stoi(number) * gearRatio[iter].first;
								gearRatio[iter].second = 1 + gearRatio[iter].second;
							}
						}
					}
					else
					{
						if ('*' == lines[numberRow - 1][numberStart + j])
						{
							auto it = std::find_if(gears.begin(), gears.end(),
								[&](const auto& p) {return p.first == numberRow - 1 && p.second == numberStart + j; });
							if (it != gears.end())
							{
								int iter = it - gears.begin();
								gearRatio[iter].first = std::stoi(number) * gearRatio[iter].first;
								gearRatio[iter].second = 1 + gearRatio[iter].second;
							}
						}
						if ('*' == lines[numberRow + 1][numberStart + j])
						{
							auto it = std::find_if(gears.begin(), gears.end(),
								[&](const auto& p) {return p.first == numberRow + 1 && p.second == numberStart + j; });
							if (it != gears.end())
							{
								int iter = it - gears.begin();
								gearRatio[iter].first = std::stoi(number) * gearRatio[iter].first;
								gearRatio[iter].second = 1 + gearRatio[iter].second;
							}
						}
					}
				}
			}
		}
		for (std::pair<int, int> s : gearRatio)
		{
			if (s.second == 2)
			{
				sum += s.first;
			}
		}
	}
	else
	{
		for (int i = 0; i < nums.size(); i++)
		{
			std::string number;
			int numberStart;
			int numberEnd;
			int numberRow;
			std::tie(number, numberStart, numberEnd, numberRow) = nums[i];
			for (int j = 0; j < number.size(); j++)
			{
				if (numberRow == 0)
				{
					if (j == 0 && numberStart != 0)
					{
						if ((!isdigit(lines[numberRow][numberStart - 1]) && '.' != lines[numberRow][numberStart - 1]) ||
							(!isdigit(lines[numberRow + 1][numberStart - 1]) && '.' != lines[numberRow + 1][numberStart - 1]) ||
							(!isdigit(lines[numberRow + 1][numberStart]) && '.' != lines[numberRow + 1][numberStart]))
						{
							adjacentSymbolNums.push_back(std::stoi(number));
							j = number.size();
							break;
						}
					}
					else if (j == number.size() - 1 && numberEnd != lines[numberRow].size() - 1)
					{
						if ((!isdigit(lines[numberRow][numberEnd + 1]) && '.' != lines[numberRow][numberEnd + 1]) ||
							(!isdigit(lines[numberRow + 1][numberEnd + 1]) && '.' != lines[numberRow + 1][numberEnd + 1]) ||
							(!isdigit(lines[numberRow + 1][numberEnd]) && '.' != lines[numberRow + 1][numberEnd]))
						{
							adjacentSymbolNums.push_back(std::stoi(number));
							j = number.size();
							break;
						}
					}
					else
					{
						if (!isdigit(lines[numberRow + 1][numberStart + j]) && '.' != lines[numberRow + 1][numberStart + j])
						{
							adjacentSymbolNums.push_back(std::stoi(number));
							j = number.size();
							break;
						}
					}
				}
				else if (numberRow == lines.size() - 1)
				{
					if (j == 0 && numberStart != 0)
					{
						if ((!isdigit(lines[numberRow][numberStart - 1]) && '.' != lines[numberRow][numberStart - 1]) ||
							(!isdigit(lines[numberRow - 1][numberStart - 1]) && '.' != lines[numberRow - 1][numberStart - 1]) ||
							(!isdigit(lines[numberRow - 1][numberStart]) && '.' != lines[numberRow - 1][numberStart]))
						{
							adjacentSymbolNums.push_back(std::stoi(number));
							j = number.size();
							break;
						}
					}
					else if (j == number.size() - 1 && numberEnd != lines[numberRow].size() - 1)
					{
						if ((!isdigit(lines[numberRow][numberEnd + 1]) && '.' != lines[numberRow][numberEnd + 1]) ||
							(!isdigit(lines[numberRow - 1][numberEnd + 1]) && '.' != lines[numberRow - 1][numberEnd + 1]) ||
							(!isdigit(lines[numberRow - 1][numberEnd]) && '.' != lines[numberRow - 1][numberEnd]))
						{
							adjacentSymbolNums.push_back(std::stoi(number));
							j = number.size();
							break;
						}
					}
					else
					{
						if (!isdigit(lines[numberRow - 1][numberStart + j]) && '.' != lines[numberRow - 1][numberStart + j])
						{
							adjacentSymbolNums.push_back(std::stoi(number));
							j = number.size();
							break;
						}
					}
				}
				else
				{
					if (j == 0 && numberStart != 0 && number.size() == 1)
					{
						if ((!isdigit(lines[numberRow - 1][numberStart]) && '.' != lines[numberRow - 1][numberStart]) ||
							(!isdigit(lines[numberRow - 1][numberStart - 1]) && '.' != lines[numberRow - 1][numberStart - 1]) ||
							(!isdigit(lines[numberRow][numberStart - 1]) && '.' != lines[numberRow][numberStart - 1]) ||
							(!isdigit(lines[numberRow + 1][numberStart - 1]) && '.' != lines[numberRow + 1][numberStart - 1]) ||
							(!isdigit(lines[numberRow + 1][numberStart]) && '.' != lines[numberRow + 1][numberStart]) ||
							(!isdigit(lines[numberRow + 1][numberEnd + 1]) && '.' != lines[numberRow + 1][numberEnd + 1]) ||
							(!isdigit(lines[numberRow][numberEnd + 1]) && '.' != lines[numberRow][numberEnd + 1]) ||
							(!isdigit(lines[numberRow - 1][numberEnd + 1]) && '.' != lines[numberRow - 1][numberEnd + 1]))
						{
							adjacentSymbolNums.push_back(std::stoi(number));
							j = number.size();
							break;
						}
					}
					else if (j == 0 && numberStart != 0 && number.size() > 1)
					{
						if ((!isdigit(lines[numberRow - 1][numberStart]) && '.' != lines[numberRow - 1][numberStart]) ||
							(!isdigit(lines[numberRow - 1][numberStart - 1]) && '.' != lines[numberRow - 1][numberStart - 1]) ||
							(!isdigit(lines[numberRow][numberStart - 1]) && '.' != lines[numberRow][numberStart - 1]) ||
							(!isdigit(lines[numberRow + 1][numberStart - 1]) && '.' != lines[numberRow + 1][numberStart - 1]) ||
							(!isdigit(lines[numberRow + 1][numberStart]) && '.' != lines[numberRow + 1][numberStart]))
						{
							adjacentSymbolNums.push_back(std::stoi(number));
							j = number.size();
							break;
						}
					}
					else if (j == number.size() - 1 && numberEnd != lines[numberRow].size() - 1)
					{
						if ((!isdigit(lines[numberRow - 1][numberEnd]) && '.' != lines[numberRow - 1][numberEnd]) ||
							(!isdigit(lines[numberRow - 1][numberEnd + 1]) && '.' != lines[numberRow - 1][numberEnd + 1]) ||
							(!isdigit(lines[numberRow][numberEnd + 1]) && '.' != lines[numberRow][numberEnd + 1]) ||
							(!isdigit(lines[numberRow + 1][numberEnd + 1]) && '.' != lines[numberRow + 1][numberEnd + 1]) ||
							(!isdigit(lines[numberRow + 1][numberEnd]) && '.' != lines[numberRow + 1][numberEnd]))
						{
							adjacentSymbolNums.push_back(std::stoi(number));
							j = number.size();
							break;
						}
					}
					else
					{
						if ((!isdigit(lines[numberRow - 1][numberStart + j]) && '.' != lines[numberRow - 1][numberStart + j]) ||
							(!isdigit(lines[numberRow + 1][numberStart + j]) && '.' != lines[numberRow + 1][numberStart + j]))
						{
							adjacentSymbolNums.push_back(std::stoi(number));
							j = number.size();
							break;
						}
					}
				}
			}
		}
		for (int s : adjacentSymbolNums)
		{
			std::cout << s << std::endl;
			sum += s;
		}
	}


	std::cout << "The answer is " << sum;

	return;
}
