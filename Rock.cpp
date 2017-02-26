/**********************************************************************
**Program Name:		RPS Game
**Author:			Group 10
**Date:				2/18/17
**Description:		The Rock class implementation file
**********************************************************************/
#include "Rock.hpp"
#include <iostream>

using std::cout;
using std::endl;

/*********************************************************************
**Description:		Default constructor
**Arguments:		none
**Returns:			none
*********************************************************************/
Rock::Rock() :Tool()
{
	//rock specific
	this->type = 'r';
	this->longType = "Rock";
}

/*********************************************************************
**Description:		Destructor
**Arguments:		none	
**Returns:			none
*********************************************************************/
Rock::~Rock()
{
	//explicitly defined for good practice
}

/*********************************************************************
**Description:		Copy Constructor
**Arguments:		none
**Returns:			none
*********************************************************************/
Rock::Rock(const Rock & rhs) : Tool(rhs)
{
	//explicitly defined for good practice
}

/*********************************************************************
**Description:		Constructor that uses Tool class's constructor
**Arguments:		strength integer
**Returns:			none
*********************************************************************/
Rock::Rock(int rStrength): Tool(rStrength)
{
	//rock specific
	this->setType('r');
    this->longType = "Rock";
}

/*********************************************************************
**Description:		Operator overload
**Arguments:		constant Rock Reference
**Returns:			none
*********************************************************************/
void Rock::operator=(const Rock & rhs)
{
	//tool operator overload call
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
char Rock::fight(Tool & toolIn)
{
	//Temporary strength holders
	int tempRockStrength = this->strength;
	int tempToolInStrength = toolIn.getStrength();

	char outcome;

	//Rock vs. Scissors
	if (toolIn.getType() == 's') {
		tempRockStrength *= 2; //rock is strong against scissors, so strength is doubled
		tempToolInStrength /= 2; //scissors are weak to rock, so strength is halved
		outcome = compareStrength(tempRockStrength, tempToolInStrength); //compare
	}

	//Rock vs. Paper
	else if (toolIn.getType() == 'p') {
		tempRockStrength /= 2; //rock is weak to paper, so strength is halved
		tempToolInStrength *= 2;//paper is strong to rock, so strength is doubled
		outcome = compareStrength(tempRockStrength, tempToolInStrength); //compare
	}

	//Rock vs. Rock
	else {
		outcome = compareStrength(tempRockStrength, tempToolInStrength); //no temporary modifiers, compare
	}

	cout << this->longType << " strength: " << this->strength << " (" << tempRockStrength << ")" << endl;
	cout << toolIn.getLongType() << " strength: " << toolIn.getStrength() << " (" << tempToolInStrength << ")"  << endl;

	return outcome;
}
