/****************************************************************
** Utility Functions: User Input Validation
**
** Sam Chew       933191613
** 2017/02/11
** 
** Desc: This collection of utility functions provide modular
**    input validation. Intended for ongoing use for class projects
**
** Rev Log: v5
**    rev validateIntegerString to catch err: no digit provided
**    rev validatePositiveInt to allow >= 0
** Rev Log: v4 - officially started log
**    corrected validatePositiveInt function name typo
**    created menuListOptions
**    created validateDoubleString, validatePositiveDouble
*****************************************************************/

#ifndef CHEWSVALIDATION_HPP
#define CHEWSVALIDATION_HPP

#include <iostream>
	//using std::cin;
	//using std::cout;
	//using std::endl;
#include <string>
	//using std::string;
#include <fstream>
	//using std::ifstream;
	//using std::getline(std::ifstream, std::string);

bool validateIntegerString(std::string);
void validatePositiveInt(int&);
int menuListOptions(std::string);
bool validateDoubleString(std::string);
void validatePositiveDouble(double&);


#endif
