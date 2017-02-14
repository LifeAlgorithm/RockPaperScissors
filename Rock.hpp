/**********************************************************************
**Program Name:
**Author:
**Date:
**Description:
**********************************************************************/

#ifndef ROCK_HPP
#define ROCK_HPP

#include "Tool.hpp"
class Rock :
	public Tool
{
public:
	Rock();
	~Rock();
	Rock(const Rock&);
	Rock(int, char);
	Rock &operator = (const Rock&);
	char fight(Tool&);
};

#endif // !ROCK_HPP