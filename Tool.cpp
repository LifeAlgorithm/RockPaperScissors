/**********************************************************************
**Program Name:
**Author:
**Date:
**Description:
**********************************************************************/
#include "Tool.hpp"


/*********************************************************************
**Description:
**Arguments:
**Returns:
*********************************************************************/
Tool::Tool()
{
	this->setStrength(0);
	this->setType(' ');
}

Tool::Tool(int strengthIn) {
	this->setStrength(strengthIn);
	this->setType(' ');
}

/*********************************************************************
**Description:
**Arguments:
**Returns:
*********************************************************************/
Tool::Tool(const Tool &rhs)
{
	this->strength = rhs.getStrength();
	this->type = rhs.getType();
}

/*********************************************************************
**Description:
**Arguments:
**Returns:
*********************************************************************/
Tool::~Tool()
{
}

/*********************************************************************
**Description:
**Arguments:
**Returns:
*********************************************************************/
void Tool::operator=(const Tool & rhs)
{
	if (&rhs != this) {
		this->strength = rhs.getStrength();
		this->type = rhs.getType();
	}
}

/*********************************************************************
**Description:
**Arguments:
**Returns:
*********************************************************************/
void Tool::setStrength(int strengthIn)
{
	strength = strengthIn;
}

/*********************************************************************
**Description:
**Arguments:
**Returns:
*********************************************************************/
void Tool::setType(char typeIn)
{
	type = typeIn;
}

/*********************************************************************
**Description:
**Arguments:
**Returns:
*********************************************************************/
char Tool::getType()
{
	return type;
}

/*********************************************************************
**Description:
**Arguments:
**Returns:
*********************************************************************/
int Tool::getStrength()
{
	return strength;
}

/*********************************************************************
**Description:
**Arguments:
**Returns:
*********************************************************************/
char Tool::getType() const
{
	return type;
}

/*********************************************************************
**Description:
**Arguments:
**Returns:
*********************************************************************/
int Tool::getStrength() const
{
	return strength;
}

/*********************************************************************
**Description:
**Arguments:
**Returns:
*********************************************************************/
char Tool::compareStrength(int strength1, int strength2)
{
	char outcome;
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
