/**********************************************************************
**Program Name:
**Author:
**Date:
**Description:
**********************************************************************/

#ifndef TOOL_HPP
#define TOOL_HPP

class Tool
{
public:
	Tool();
	Tool(const Tool&);
	~Tool();
	Tool & operator=(const Tool &RHS);
	void setStrength(int);
	void setType(char);
	char getType();
	int getStrength();
	char compareStrength(int, int);
	virtual char fight(Tool&) = 0;

protected:
	int strength;
	char type;
};

#endif // !TOOL_HPP