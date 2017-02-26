/**********************************************************************
**Program Name:		RPS Game
**Author:			Group 10
**Date:				2/18/17
**Description:		The Paper class implementation file
**********************************************************************/
#include "Paper.hpp"
#include <iostream>

using std::cout;
using std::endl;

/*********************************************************************
**Description:		Default constructor, uses Tool class constructor
					to set strength to 0.
**Arguments:		none
**Returns:			none
*********************************************************************/
Paper::Paper() : Tool()
{
	//paper specific
	this->type = 'p';
	this->longType = "Paper";
}

/*********************************************************************
**Description:		Destructor
**Arguments:		none
**Returns:			none
*********************************************************************/
Paper::~Paper()
{
	//explicitly defined for good practice
}

/*********************************************************************
**Description:		Copy Constructor
**Arguments:		Constant Reference to Paper object
**Returns:
*********************************************************************/
Paper::Paper(const Paper & rhs) : Tool(rhs)
{
	//explicitly defined for good practice
}

/*********************************************************************
**Description:		Constructor, uses Tool Constructor to set strength
**Arguments:		strength
**Returns:			none
*********************************************************************/
Paper::Paper(int pStrength) :Tool(pStrength)
{
	//paper specific
	this->setType('p');
    this->longType = "Paper";
}

/*********************************************************************
**Description:		Assingment operator overload
**Arguments:		constant reference to Paper obj
**Returns:			none
*********************************************************************/
void Paper::operator=(const Paper &rhs)
{
	//call tool assignment operator overload
	Tool::operator=(rhs);
}

/*********************************************************************
**Description:		Fight function.  Has two tool objects "fight".
					Strength values are modified depending on type.
					CompareStrength() is called to compare the strengths of
					the two objects and the result of the fight is returned
					as a char.
**Arguments:		reference to tool object
**Returns:			character representing the outcome of the fight.
*********************************************************************/
char Paper::fight(Tool &toolIn)
{
	//Temporary strength holders
	int tempPaperStrength = this->strength;
	int tempToolInStrength = toolIn.getStrength();

	char outcome;

	//Paper vs Rock
	if (toolIn.getType() == 'r') {
		tempPaperStrength *= 2; //paper is strong against rock, so strength is doubled
		tempToolInStrength /= 2; //rock is weak to paper, so strength is halved
		outcome = compareStrength(tempPaperStrength, tempToolInStrength); //compare
	}

	//Paper vs. Scissors
	else if (toolIn.getType() == 's') {
		tempPaperStrength /= 2; //paper is weak to scissors, so strength is halved
		tempToolInStrength *= 2;//scissors are strong to paper, so strength is doubled
		outcome = compareStrength(tempPaperStrength, tempToolInStrength); //compare
	}

	//Paper vs. Paper
	else {
		outcome = compareStrength(tempPaperStrength, tempToolInStrength); //no temporary modifiers, compare
	}

	cout << this->longType << " strength: " << this->strength << " (" << tempPaperStrength << ")" << endl;
	cout << toolIn.getLongType() << " strength: " << toolIn.getStrength() << " (" << tempToolInStrength << ")"  << endl;

	return outcome;
}
