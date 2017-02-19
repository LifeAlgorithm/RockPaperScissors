/**********************************************************************
**Program Name:		RPS Game
**Author:			Group 10
**Date:				2/18/17
**Description:		The tool class implementation file
**********************************************************************/
#include "Tool.hpp"

/*********************************************************************
**Description:	Default constructor
**Arguments:	none
**Returns:		none
*********************************************************************/
Tool::Tool()
{
	//sets values to default 0 and space.
	this->setStrength(0);
	this->setType(' ');
}

/*********************************************************************
**Description:	Tool constructor
**Arguments:	integer for strength
**Returns:		none
*********************************************************************/
Tool::Tool(int strengthIn) {
	this->setStrength(strengthIn);
	this->setType(' ');
}

/*********************************************************************
**Description:	Copy Constructor
**Arguments:	constant reference to a tool object
**Returns:		none
*********************************************************************/
Tool::Tool(const Tool &rhs)
{
	//copies data over to lhs
	this->strength = rhs.getStrength();
	this->type = rhs.getType();
}

/*********************************************************************
**Description:	Destructor
**Arguments:	none
**Returns:		none
*********************************************************************/
Tool::~Tool()
{
	//explicitely stated for good practice
}

/*********************************************************************
**Description:	Assignment operator overload
**Arguments:	constant reference to tool obj
**Returns:		none
*********************************************************************/
void Tool::operator=(const Tool & rhs)
{
	//check to make sure they arent equal
	if (&rhs != this) {
		//then set lhs equal to rhs
		this->strength = rhs.getStrength();
		this->type = rhs.getType();
	}
}

/*********************************************************************
**Description:	Sets the strength member variable
**Arguments:	integer for strength
**Returns:		none
*********************************************************************/
void Tool::setStrength(int strengthIn)
{
	strength = strengthIn;
}

/*********************************************************************
**Description:	sets the type member variable
**Arguments:	character for the type of tool
**Returns:		none
*********************************************************************/
void Tool::setType(char typeIn)
{
	type = typeIn;
}

/*********************************************************************
**Description:	gets the type of tool
**Arguments:	none
**Returns:		character representing the type of tool
*********************************************************************/
char Tool::getType()
{
	return type;
}

/*********************************************************************
**Description:	gets the member variable strength
**Arguments:	none
**Returns:		member variable strength
*********************************************************************/
int Tool::getStrength()
{
	return strength;
}

/*********************************************************************
**Description:	constant version of getType
**Arguments:	none
**Returns:		member variable type
*********************************************************************/
char Tool::getType() const
{
	return type;
}

/*********************************************************************
**Description:	constant version of getStrength
**Arguments:	none
**Returns:		member variable strength
*********************************************************************/
int Tool::getStrength() const
{
	return strength;
}

/*********************************************************************
**Description:	Compares two strength values 
**Arguments:	two strength values
**Returns:		char representing the outcome of the first strength value
*********************************************************************/
char Tool::compareStrength(int strength1, int strength2)
{
	char outcome;

	//series of conditionals to see what the outcome of the "battle" would be.
	if (strength1 > strength2) {
		outcome = 'w';
	}
	else if (strength1 < strength2) {
		outcome = 'l';
	}
	else {
		outcome = 't';
	}
	return outcome;
}

/*********************************************************************
**Description: get the long type (Rock, Paper, Scissor)
**Arguments: none
**Returns: string
*********************************************************************/
const std::string &Tool::getLongType() const {
    return longType;
}
