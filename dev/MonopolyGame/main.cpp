// MonopolyGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <limits>

void PrintMainMenu()
{
	std::cout << "=====================================================================\n";
	std::cout << "                                        M O N O P O L Y\n";                                        
	std::cout << "=====================================================================\n\n";

	std::cout << "                                       [1] New Game\n";
	std::cout << "                                       [2] Load Game\n";
	std::cout << "                                       [3] How to Play\n";
	std::cout << "                                       [4] Settings\n";
	std::cout << "                                       [5] Exit Game\n\n";

	std::cout << "=====================================================================";
	std::cout << "Enter your selection: ";
}

int main()
{
	bool running = true;

	try
	{
		while (running)
		{
			PrintMainMenu();

			int selection = Helper::GetInteger("Enter your selection: ", 1, 5);

			switch (selection)
			{
			case 1:
				std::cout << "\nStarting a new game...\n";
				break;

			case 2:
				std::cout << "\nLoading saved game...\n";
				break;

			case 3:
				std::cout << "\nHow to Play\n";
				std::cout << "Roll dice, purchase properties, " << "and collect rent\n";
				std::cout << "Be the last player remaining!\n";
				break;

			case 4:
				std::cout << "\nOpening settings...\n";
				break;

			case 5:
				std::cout << "\nThank you for playing!\n";
				running = false;
				break;
			}

			if (running)
			{
				std::cout << "\nPress ENTER to continue...";

				std::string input;

				if (!std::getline(std::cin, input))
				{
					break;
				}

				std::cout << "\n\n";
			}
		}
	}
	catch (const std::exception& error)
	{
		std::cout << "\nGame ended: " << error.what() << '\n';
		return 1;
	}

	return 0;
}