/**********************************************************************
**Program Name:		RPS Game
**Author:			Group 10
**Date:				2/18/17
**Description:		RPSGame class header file.  Represenents and abstraction
of a rock paper scissors game.  Allows a user to play against a computer.
To use the class simply create an object using the default constructor
and call the mainMenu function.  Menu functions allow tool strengths to be
set, and new games to be initiated.  Get functions return values that are
then printed to the screen to display score, tool choices, and strength
settings.
**********************************************************************/

#ifndef RPSGame_HPP
#define RPSGame_HPP

#include "Tool.hpp"
#include <chrono>
#include <vector>
using std::vector;


class RPSGame
{
private:
	vector<char> knowledgeBase;
	Tool* humanTool;
	Tool* computerTool;
	int humanWins;
	int computerWins;
	int ties;
	std::chrono::seconds sleepDuration;
	const int maxStrength = 1000000; //arbitrary max
	const int minStrength = 1;

protected:
	int humanRockStrength;
	int humanPaperStrength;
	int humanScissorStrength;
	int computerRockStrength;
	int computerPaperStrength;
	int computerScissorStrength;
	Tool *getHumanTool() const;
	Tool *getComputerTool() const;

public:
	RPSGame();
	virtual ~RPSGame();
	void mainMenu();
	virtual int choiceMenu();
	void toolSettingsMenu();
	Tool* buildHumanTool(char);
	Tool* buildComputerTool(char);
	virtual char choiceToTool(int);
	char nextAIMove(int);
	virtual void printRoundResult(char);
	virtual void playGame();
	void screenClear();
	void screenContinue();
	int validateBetween(int inputNumber, int validMin, int validMax);
	void setSleepDuration(int sleepDuration);
};

#endif
