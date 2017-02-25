/**********************************************************************
**Program Name:		RPS Game
**Author:			Group 10
**Date:				2/18/17
**Description:		Rock class header file.
**********************************************************************/

#ifndef ROCK_HPP
#define ROCK_HPP

#include "Tool.hpp"
class Rock : public Tool
{
public:
	//default constructor
	Rock();
	//destructor
	~Rock();
	//copy constructor
	Rock(const Rock&);
	//constructor
	Rock(int);
	//overloaded assignment operator
	void operator = (const Rock&);
	//overridden fight function
	char fight(Tool&);
};

#endif // !ROCK_HPP