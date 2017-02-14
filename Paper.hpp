/**********************************************************************
**Program Name:
**Author:
**Date:
**Description:
**********************************************************************/

#ifndef PAPER_HPP
#define PAPER_HPP

#include "Tool.hpp"
class Paper :
	public Tool
{
public:
	Paper();
	~Paper();
	Paper(const Paper&);
	Paper(int, char);
	Paper &operator = (const Paper&);
	char fight(Tool&);
};

#endif // !PAPER_HPP