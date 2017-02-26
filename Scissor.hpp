/***********************************************

Program: Project 2
Author: Group 10
Description: This is the scissor class that inherits
from the virtual/super-class tool. This class
defines specific methods and attributes that are
specific to the scissor functionality.

***********************************************/

#ifndef GROUP10_SCISSOR_HPP
#define GROUP10_SCISSOR_HPP

// Include libraries
#include "Tool.hpp"
#include <iostream>

using std::cout;
using std::endl;

// Class definitions
class Scissor : public Tool
{
private:
	// Private members
	// Intentionally blank
protected:
	// Protected members
	// Intentionally blank
public:
	// Constructors
	Scissor();
	Scissor(int);
	Scissor(const Scissor &);
	// Operator overloading
	void operator= (const Scissor &);
	// Destructors
	virtual ~Scissor();
	// Overridden methods
	virtual char fight(Tool &);
};

#endif
