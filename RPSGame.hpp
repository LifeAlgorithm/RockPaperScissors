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
	public:
		RPSGame();
		//RPSGame(const RPSGame);
		virtual ~RPSGame();
		//RPSGame& operator= (const RPSGame&);
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

protected:
    int humanRockStrength;
    int humanPaperStrength;
    int humanScissorStrength;
    int computerRockStrength;
    int computerPaperStrength;
    int computerScissorStrength;
    Tool *getHumanTool() const;
    Tool *getComputerTool() const;

};


#endif