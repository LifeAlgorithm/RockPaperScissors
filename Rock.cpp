/**********************************************************************
**Program Name:
**Author:
**Date:
**Description:
**********************************************************************/
#include "Rock.hpp"


/*********************************************************************
**Description:
**Arguments:
**Returns:
*********************************************************************/
Rock::Rock()
{
	this->strength = 0;
	this->type = 'r';
}

/*********************************************************************
**Description:
**Arguments:
**Returns:
*********************************************************************/
Rock::~Rock()
{
}

/*********************************************************************
**Description:
**Arguments:
**Returns:
*********************************************************************/
Rock::Rock(const Rock & rhs) : Tool(rhs)
{
}

/*********************************************************************
**Description:
**Arguments:
**Returns:
*********************************************************************/
Rock::Rock(int rStrength)
{
	this->setStrength(rStrength);
	this->setType('r');
}

/*********************************************************************
**Description:
**Arguments:
**Returns:
*********************************************************************/
void Rock::operator=(const Rock & rhs)
{
	Tool::operator=(rhs);
}

/*********************************************************************
**Description:
**Arguments:
**Returns:
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

	return outcome;
}

