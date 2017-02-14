/**********************************************************************
**Program Name:
**Author:
**Date:
**Description:
**********************************************************************/

#include "Paper.hpp"

/*********************************************************************
**Description:
**Arguments:
**Returns:
*********************************************************************/
Paper::Paper()
{
	this->strength = 0;
	this->type = 'p';
}

/*********************************************************************
**Description:
**Arguments:
**Returns:
*********************************************************************/
Paper::~Paper()
{
}

/*********************************************************************
**Description:
**Arguments:
**Returns:
*********************************************************************/
Paper::Paper(const Paper & rhs) : Tool(rhs)
{	
}

/*********************************************************************
**Description:
**Arguments:
**Returns:
*********************************************************************/
Paper::Paper(int pStrength, char pType)
{
	this->setStrength(pStrength);
	this->setType(pType);
}

/*********************************************************************
**Description:
**Arguments:
**Returns:
*********************************************************************/
Paper & Paper::operator=(const Paper &rhs)
{
	Tool::operator=(rhs);
	return *this;
}

/*********************************************************************
**Description:
**Arguments:
**Returns:
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
	
	return outcome;
}
