#pragma once

#include <iostream>
#include <string>
#include <stdexcept>

namespace Helper
{
	static int GetInteger(const std::string& prompt, int min, int max)
	{
		while (true)
		{
			std::string input;

			std::cout << prompt;

			if (!std::getline(std::cin, input))
			{
				throw std::runtime_error("Input stream closed.");
			}

			try
			{
				size_t position = 0;

				int value = std::stoi(input, &position);

				// Make sure the entire input is valid
				if (position != input.length())
				{
					throw std::invalid_argument("Invalid input.");
				}

				// Make sure the value is within range
				if (value < min || value > max)
				{
					throw std::out_of_range("Invalid range.");
				}

				return value;
			}
			catch (const std::invalid_argument&)
			{
				std::cout << "Invalid input. Please enter an integer.\n";
			}
			catch (const std::out_of_range&)
			{
				std::cout << "Please enter a number between " << min << " and " << max << ".\n";

			}
		}
	}
}