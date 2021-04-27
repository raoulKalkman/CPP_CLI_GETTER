//
// Created by raoulkalkman on 28/04/2021.
//

#ifndef STANDARD_GETINPUT_H
#define STANDARD_GETINPUT_H

#include "iostream" // for cin and cout
#include "limits" // for clearing cin

class getInput {
public:
	getInput() = default;
	
	/**
	 * Get an integer from the cli, this must be between min and max (inclusive)
	 *
	 * @return the gathered int integer
	 * throws logic error if min > max
	 */
	int integer(const int &min, const int &max);
	
	/**
	 * Get an unsigned integer from the cli, this must be between min and max
	 * and bigger than 0
	 *
	 * @return the gathered size_t input
	 * throws logic error if min > max
	 */
	size_t unsignedInteger(const size_t &min, const size_t &max);
	
	/**
	 * Get a character from the cli, this must be between min and max
	 * character and this must be alphanumeric
	 *
	 * PRE: std::cin has to be flushed or it will appear buggy
	 *
	 * @return the character gotten from the input
	 * throws logic error if min or max is not alphanumeric
	 */
	char character(const char &min, const char &max);
};


#endif //STANDARD_GETINPUT_H
