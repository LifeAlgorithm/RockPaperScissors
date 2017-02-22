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




//(2/18/17) - Note to testers, I commented out Sam's old code at the bottom if we want to revisit. I also 
//                 got rid of screenClear() since it is in RPSGame(). The uncommented code should be our main - Armand



#include "RPSGame.hpp" //I think this is all we need

int main()
{
	RPSGame game;
	game.mainMenu();
	return 0;
	
}


//Old code below
/* 

#include <iostream>
#include "RPSGame.hpp"

//Function Prototypes
void printHeader();

int main()
{
    printHeader();
    RPSGame rpsGame;
    rpsGame.setSleepDuration(1);
    rpsGame.mainMenu();
	return 0;
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

*/
