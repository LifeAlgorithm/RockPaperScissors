/***********************************************

Program: Project 2
Author: Group 10
Description: This is the scissor class that inherits
from the virtual/super-class tool. This class
defines specific methods and attributes that are
specific to the scissor functionality.

***********************************************/

// Header files to be included
#include "Scissor.hpp"
#include "Tool.hpp"
#include <iostream>

// Using objects to make life easier
// Intentionally blank

/***********************************************

Method: Scissor (constructor)
Description: Calls the constructor from the public tool
class and after initializing through inherited
constructor, changes the type member to 's'.

***********************************************/

Scissor::Scissor() : Tool()
{
	// Additional code specific to scissor
	this->type = 's';
}

/***********************************************

Method: Scissor (constructor)
Description: Calls the constructor with a user-
defined strength integer. Note that this is
inheriting code from the tool super-class.

***********************************************/

Scissor::Scissor(int str) : Tool(str)
{
	// Additional code specific to scissor
	this->type = 's';
}

/***********************************************

Method: Scissor (constructor)
Description: Calls the constructor with a copy
of another scissor object. Note that this is
inheriting code from the tool super-class

***********************************************/

Scissor::Scissor(const Scissor &copy) : Tool(copy)
{
	// Explicitly defined for good practice
}

/***********************************************

Method: Scissor (destructor)
Description: This is a virtual destructor by
argument that a destructor in the future might have
certain changes that require us to override
functionality.

***********************************************/

Scissor::~Scissor()
{
	// Explicitly defined for good practice
}

void Scissor::operator=(const Scissor &copy)
{
	// Deep copy for the equals '=' operator
	this->strength = copy.getStrength();
	// No need for copying type
}

/***********************************************

Method: fight
Description: This is a special method for fighting
between this object and that of a different tool.
The conditionals for fight are defined from a scissor
perspective.

***********************************************/

char Scissor::fight(Tool &toolIn)
{
	// Init variables
	char outcome;
	// Temporary strength values
	int tempScissorStr;
	int tempToolStr;

	// Scissor vs Rock
	if (toolIn.getType() == 'r')
	{
		// Rock is strong vs scissor
		tempScissorStr = strength / 2;
		tempToolStr = toolIn.getStrength() * 2;
	}
	// Scissor vs paper
	else if (toolIn.getType() == 'p')
	{
		// Scissor is strong vs paper
		tempScissorStr = strength * 2;
		tempToolStr = toolIn.getStrength() / 2;
	}
	else
	{
		tempScissorStr = strength;
		tempToolStr = toolIn.getStrength();
	}

	// Run the comparison
	outcome = compareStrength(tempScissorStr,
		tempToolStr);

	// Return variable
	return outcome;
}