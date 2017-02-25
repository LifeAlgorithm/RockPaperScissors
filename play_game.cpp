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
** Desc: Main file for playgame program. File creates a RPSGame
** object and then calls the mainMenu function.  Game loops in
** the mainMenu function until the user selects the correct exit
** command.
** Execution Instructions: Utilize included makefile and run the
**    resulting playgame.exe. (There will be *.txt files created 
**    within the working directory, but the make clean should 
**    remove them.)
****************************************************************/

#include "RPSGame.hpp"

int main()
{
	// Amount of time in seconds final score is displayed before game resets.
	int finalScoreDisplay = 5;

	RPSGame game;
	game.setSleepDuration(finalScoreDisplay);
	game.mainMenu();

	return 0;
}

