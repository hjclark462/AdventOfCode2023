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

void AOCDayOne::Solve()
{
	int sum = 0;
	std::vector<std::string> numberString;
	int forward = INT_MAX;
	int backwards = -1;
	char first = {};
	char second = {};
	std::string line;
	std::fstream calibrationValues;
	calibrationValues.open("test.txt", std::ios::in);
	if (calibrationValues.is_open())
	{
		while (!calibrationValues.eof())
		{
			std::vector<std::string> numbers;
			std::vector<int> digits;
			line.clear();
			std::getline(calibrationValues, line);
			if (!line.empty())
			{
				for (int i = 0; i < numberString.size(); i++)
				{
					int f = line.find_first_of(numberString[i]);
					int b = line.find_last_of(numberString[i]);
					if (f < forward)
					{
						first = (char)(i + 1);
					}
					if (b > backwards)
					{
						second = (char)(i + 1);
					}
				}
				for (int i = 0; i < (forward < line.size() ? forward : line.size()-1); i++)
				{
					if (isdigit(line.at(i)))
					{
						first = line.at(i);
						i = line.size();
					}
				}
				for (int i = line.size() - 1; i >= (backwards > 0 ? backwards : 0); i--)
				{
					if (isdigit(line.at(i)))
					{
						second = line.at(i);
						i = -1;
					}
				}
				std::stringstream ss;
				ss << first << second;
				numberString.push_back(ss.str());
			}
		}
	}
	calibrationValues.close();
	for (std::string s : numberString)
	{
		sum += std::stoi(s);
	}

	std::cout << "The answer is " << sum;

	return;
}
