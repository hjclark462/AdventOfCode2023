#include "AOCDayTwo.h"
AOCDayTwo::AOCDayTwo()
{

}

AOCDayTwo::~AOCDayTwo()
{

}

void AOCDayTwo::Update(float dt)
{

}

void AOCDayTwo::Solve(bool part)
{
	int sum = 0;
	std::vector<int> goodIDs;
	std::string line;	
	gameRecords.open(files[0], std::ios::in);
	if (gameRecords.is_open())
	{
		while (!gameRecords.eof())
		{			
			line.clear();
			std::getline(gameRecords, line);
			if (!line.empty())
			{
				size_t pos = 0;
				std::string id;

				std::string set;
				std::vector<std::string> sets;
								
				pos = line.find(" ");

				line.erase(0, pos + 1);

				pos = line.find(':');
				id = line.substr(0, pos);
				line.erase(0, pos + 1);

				while ((pos = line.find(';')) != std::string::npos)
				{
					set = line.substr(0, pos);
					sets.push_back(set);
					line.erase(0, pos + 1);
				}
				sets.push_back(line);
				bool tooMuch = true;
				int redMin = 0;
				int blueMin = 0;
				int greenMin = 0;
				for (std::string s : sets)
				{
					std::vector<std::string> rounds;
					while ((pos = s.find(' ')) != std::string::npos)
					{
						set = s.substr(0, pos);
						rounds.push_back(set);
						s.erase(0, pos + 1);
					}
					rounds.push_back(s);
					for (int i = 2; i < rounds.size(); i += 2)
					{
						if (rounds[i].find("red") != std::string::npos)
						{
							int currentRed = std::stoi(rounds[i - 1]);
							if (part && currentRed > redMin)
							{
								redMin = currentRed;
							}
							else if (!part && currentRed > red)
							{
								tooMuch = false;
							}
						}
						if (rounds[i].find("green") != std::string::npos)
						{
							int currentGreen = std::stoi(rounds[i - 1]);
							if (part && currentGreen > greenMin)
							{
								greenMin = currentGreen;
							}
							else if (!part && currentGreen > green)
							{
								tooMuch = false;
							}
						}
						if (rounds[i].find("blue") != std::string::npos)
						{
							int currentBlue = std::stoi(rounds[i - 1]);
							if (part && currentBlue > blueMin)
							{
								blueMin = currentBlue;
							}
							else if (!part && currentBlue > blue)
							{
								tooMuch = false;
							}
						}
					}
				}
				if (tooMuch)
				{
					if (part)
					{
						int roundPower = (redMin == 0 ? 1 : redMin) * (greenMin == 0 ? 1 : greenMin) * (blueMin == 0 ? 1 : blueMin);
						goodIDs.push_back(roundPower);						
					}
					else
					{
						goodIDs.push_back(std::stoi(id));
					}
				}
			}
		}
	}
	gameRecords.close();
	for (int s : goodIDs)
	{
		sum += s;
	}

	std::cout << "The answer is " << sum;

	return;
}