/**********************************************************************
**Program Name:		RPS Game
**Author:			Group 10
**Date:				2/18/17
**Description:		Paper class header file.
**********************************************************************/

#ifndef PAPER_HPP
#define PAPER_HPP

#include "Tool.hpp"
class Paper : public Tool //child of Tool class
{
public:
	//default constructor
	Paper();
	//destructo
	~Paper();
	//copy constructor
	Paper(const Paper&);
	//constructor
	Paper(int);
	//overloaded assignment operator
	void operator = (const Paper&);	
	//overridden fight function prototype
	char fight(Tool&);
};

#endif // !PAPER_HPP