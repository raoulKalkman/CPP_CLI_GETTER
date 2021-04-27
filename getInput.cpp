#include "getInput.h"

int getInput::integer(const int &min, const int &max)
{
	if(min > max)
	{
		std::cerr << "Wrong usage of function, min (" << min << ") bigger "
														  "than max(" << max
														  << ")\n";
		throw std::logic_error("Getting integer, wrong boundaries\n");
	}
	
	while(true)
	{
		std::cout << "Please input a whole number between [" << min << " , "
		<< max << "] inclusive\n";
		int in;
		std::cin >> in;
		
		if(std::cin.fail()) // in case a non-number was entered
		{
			std::cout << "This is not a valid input, please try again\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		} else
		{
			// check for boundaries
			if(in < min)
			{
				std::cout << in << " is smaller than the minimum: " << min <<
				"\nPlease try again\n";
			} else if (in > max)
			{
				std::cout << in << " is bigger than the maximum: " << max <<
				"\nPlease try again\n";
			} else
			{
				return in;
			}
		}
	}
}

size_t getInput::unsignedInteger(const size_t &min, const size_t &max)
{
	if(min > max)
	{
		std::cerr << "Wrong usage of function, min (" << min << ") bigger "
		                                                        "than max(" << max
		          << ")\n";
		throw std::logic_error("Getting unsigned integer, wrong boundaries\n");
	}
	
	while(true)
	{
		std::cout << "Please input a whole, non negative number between [" <<
		min << " , " << max << "] inclusive\n";
		size_t in;
		std::cin >> in;
		
		if(std::cin.fail()) // in case a non-number was entered
		{
			std::cout << "This is not a valid input, please try again\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		} else
		{
			// check for boundaries
			if(in < min)
			{
				std::cout << in << " is smaller than the minimum: " << min <<
				          "\nPlease try again\n";
			} else if (in > max)
			{
				std::cout << in << " is bigger than the maximum: " << max <<
				          "\nPlease try again\n";
			} else
			{
				return in;
			}
		}
	}
}

char getInput::character(const char &min, const char &max)
{
	if(!isalpha(min) || !isalpha(max))
	{
		std::cerr << "Wrong usage:\n"
			   "Trying to set borders to non alpha-romanic characters\n";
		throw std::logic_error("Getting character, wrong boundaries\n");
	}
	
	if(min > max)
	{
		std::cerr << "Wrong usage:\n"
			   "Trying to set min bigger than max\n";
		throw std::logic_error("Minimum set to be bigger than max\n");
	}
	
	while(true) {
		//todo: fixme: now appearing twice if cin isn't flushed
		std::cout << "Please input a character between " << min << " and " <<
		          max << "\n";
		std::string input;
		getline(std::cin, input);
		
		if(input.empty()){
			continue;
		}
		
		char in = input[0];
		
		if (!isalpha(in)) {
			std::cout << in << " is not a valid character, please try again\n";
		} else if (in < min || in > max) {
			std::cout << in << " is not within the range of " << min << " and "
			          << max << "\nPlease try again\n";
		} else {
			return min;
		}
	}
}