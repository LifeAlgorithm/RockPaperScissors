/****************************************************************
** Program Name: Group10 - Paper,Rock,Scissors
**    Group #10 Members
**      Sam Chew - 933191613
**      Riley Harrison
**      Patrick Huarng
**      Susan Onesky
**      Armand Parajon
**      Peter Yetti
**      Nathan Zimmerman
**
** 2017/02/26
** CS162_400_W2017
**
** Desc: 
**
**
**
** Execution Instructions: Utilize included makefile and run the
**    resulting playgame.exe. (There will be *.txt files created 
**    within the working directory, but the make clean should 
**    remove them.)
****************************************************************/

#include <iostream>

#include "Menu.hpp"

//Function Prototypes
void printHeader();
void screenClear();

int main()
{
	//Print Program Information
	screenClear();
	printHeader();
	
	//Call Start Game menu
	menuSetupGame();
	
	//Call main Game Play menu
	menuGamePlay();
	
	
	
	return 0;
}

void screenClear()
{
#ifdef __linux__ 
	system("clear");

#elif _WIN32
	system("cls");
#endif
}




//Utility Function to print Program Header to screen
void printHeader()
{
	//Print Program Information
	std::cout << "CS162_400_W2017 GroupProject - Paper, Rock, Scissors\n";
	std::cout << "\nGroup Members\n";
	std::cout << "  Sam Chew 933191613\n";
	std::cout << "  Riley Harrison\n";
	std::cout << "  Patrick Huarng\n";
	std::cout << "  Susan Onesky\n";
	std::cout << "  Armand Parajon\n";
	std::cout << "  Peter Yetti\n";
	std::cout << "  Nathan Zimmerman\n";
	std::cout << "\n";
	std::cout << "This program will allow the user to play Paper, Rock, Scissors with the PC.\n";
	std::cout << "\n";
	std::cout << "To begin, the user may select to play either default strengths or custom strengths.\n";
	std::cout << "After tool strengths are established, the user will follow instructions to play.\n";
	std::cout << std::endl;
}

