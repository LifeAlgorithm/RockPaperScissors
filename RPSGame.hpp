#ifndef RPSGame_HPP
#define RPSGame_HPP
#include "Tool.hpp"
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
		int humanRockStrength;
		int humanPaperStrength;
		int humanScissorStrength;
		int computerRockStrength;
		int computerPaperStrength;
		int computerScissorStrength;
		const int maxStrength = 1000000; //arbitrary max
	public:
		RPSGame();
		//RPSGame(const RPSGame);
		//~RPSGame();
		//RPSGame& operator= (const RPSGame&);
		void mainMenu();
		int choiceMenu();
		void toolSettingsMenu();
		Tool* buildHumanTool(char);
		Tool* buildComputerTool(char);
		char choiceToTool(int);
		char nextAIMove(int);
		void printRoundResult(char);
		void playGame();
		void screenClear();
		void screenContinue();
        int validateBetween(int inputNumber, int validMin, int validMax);

};


#endif