/**********************************************************************
**Program Name:		RPS Game
**Author:			Group 10
**Date:				2/18/17
**Description:		Rock class header file.
**********************************************************************/

#ifndef TOOL_HPP
#define TOOL_HPP

#include <string>

class Tool
{
public:
	//default constructor
	Tool();
	//constructor
	Tool(int);
	//copy constructor
	Tool(const Tool&);
	//destructor
	virtual ~Tool();
	//assignment operator overload
	void operator=(const Tool &RHS);

	//setters
	void setStrength(int);
	void setType(char);

	//getters
	char getType();
	char getType() const;
	int getStrength();
	int getStrength() const;

	//function prototypes
	char compareStrength(int, int);
	virtual char fight(Tool&) = 0;

    const std::string &getLongType() const;

protected:
	int strength;
	char type;
	std::string longType;
};

#endif // !TOOL_HPP
