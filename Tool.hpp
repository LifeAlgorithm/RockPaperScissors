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
	Tool(int);
	Tool(const Tool&);
	virtual ~Tool();
	void operator=(const Tool &RHS);

	void setStrength(int);
	void setType(char);

	char getType();
	char getType() const;
	int getStrength();
	int getStrength() const;

	char compareStrength(int, int);
	virtual char fight(Tool&) = 0;

protected:
	int strength;
	char type;
};

#endif // !TOOL_HPP
