#include "AOCDayOne.h"

AOCDayOne::AOCDayOne()
{
}

AOCDayOne::~AOCDayOne()
{
}

void AOCDayOne::Update(float dt)
{
}

void AOCDayOne::Solve(bool part)
{
	int sum = 0;
	std::vector<int> numberString;
	std::string line;
	std::fstream calibrationValues;
	calibrationValues.open("input.txt", std::ios::in);
	if (calibrationValues.is_open())
	{
		while (!calibrationValues.eof())
		{
			int first = -1;
			int second = -1;			
			line.clear();
			std::getline(calibrationValues, line);
			if (!line.empty())
			{
				int forward = line.size()-1;
				int backwards = 0;
				for (int i = 0; i < line.size(); i++)
				{
					if (isdigit(line.at(i)))
					{
						std::string dig = { line[i] };
						first = std::stoi(dig);
						forward = i;
						i = line.size();
					}
				}
				for (int i = line.size() - 1; i > 0; i--)
				{
					if (isdigit(line.at(i)))
					{
						std::string dig = { line[i] };
						second = std::stoi(dig);
						backwards = i;
						i = -1;
					}
				}
				if (part)
				{
					for (int i = 0; i < numStrings.size(); i++)
					{
						std::int32_t f = line.find(numStrings[i]);
						std::int32_t b = line.rfind(numStrings[i]);
						if (f != std::string::npos && f < forward)
						{
							first = std::stoi(stringNums[i]);
							forward = f;
						}
						if (b != std::string::npos && b > backwards)
						{
							second = std::stoi(stringNums[i]);
							backwards = b;
						}
					}
				}
				if (first == -1 && second != -1)
				{
					first = second;
				}
				else if (first != -1 && second == -1)
				{
					second = first;
				}
				int ss = first * 10 + second;
				numberString.push_back(ss);
			}
		}
	}
	calibrationValues.close();
	for (int s : numberString)
	{
		if (s >= 100 || s <=9)
		{
			std::cout << "fuck " << s << std::endl;
		}
		sum += s;
	}

	std::cout << "The answer is " << sum;

	return;
}
