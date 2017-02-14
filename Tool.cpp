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

/*********************************************************************
**Description:
**Arguments:
**Returns:
*********************************************************************/
Tool::Tool(const Tool &RHS)
{
	this->strength = RHS.strength;
	this->type = RHS.type;
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
Tool & Tool::operator=(const Tool & RHS)
{
	if (&RHS != this) {
		this->strength = RHS.strength;
		this->type = RHS.type;
	}
	return *this;
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
