#include "Rock.hpp"
#include "Paper.hpp"
#include "Scissor.hpp"
#include "RPSGame.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <thread>

using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::rand;
using std::srand;
using std::time;
using std::system;
using std::size_t;

//using std::this_thread::sleep_for; use if want to add duration/tempo between rounds + steps


/***************************************************************************************************
* Default Constructor - Sets default strengths and sets randomization
* **************************************************************************************************/

RPSGame::RPSGame()
{
    humanPaperStrength = 100;
    humanRockStrength = 100;
    humanScissorStrength = 100;

	computerPaperStrength = 100;
    computerRockStrength = 100;
    computerScissorStrength = 100;
    std::chrono::seconds sleep(0);
    sleepDuration = sleep;

    srand(time(0));
}

RPSGame::~RPSGame() {}

/***************************************************************************************************
* buildComputerTool - Dynamically creates new human tool based on tool input
* **************************************************************************************************/

Tool* RPSGame::buildHumanTool(char toolSymbol)
{
	switch(toolSymbol)
	{
		case 'r':
		{
			return new Rock(humanRockStrength);
		}
		case 'p':
		{
			return new Paper(humanPaperStrength);
		}
        default:
		{
			return new Scissor(humanRockStrength);
		}
	}

}

/***************************************************************************************************
* buildComputerTool - Dynamically creates new computer tool based on tool input
* **************************************************************************************************/

Tool* RPSGame::buildComputerTool(char toolSymbol)
{
	switch(toolSymbol)
	{
		case 'r':
		{
			return new Rock(computerRockStrength);
		}
		case 'p':
		{
            return new Paper(computerPaperStrength);
		}
        default:
		{
            return new Scissor(computerRockStrength);
		}
	}
}

/***************************************************************************************************
* choiceToTool - Converts integer to tool symbol. 1 = rock, 2 = paper, 3 = scissor. Works in 
				 accordance with choiceMenu() and nextAIMove() (during random selection)
* **************************************************************************************************/


char RPSGame::choiceToTool(int inputChoice)
{
	switch(inputChoice)
	{
		case 1:
		{
			return 'r';
		}
		case 2:
		{
			return 'p';
		}
        default:
		{
			return 's';
		}
	}
}

/***************************************************************************************************
* nextAIMove - Chooses next move based on past user choice. Random before round 4. After round 4,
				randomly choose amongst tools stored in knowledgeBase, and pick the opposite tool.
				This punishes the user for picking one tool more frequently than the others,
				whilst maintaining an element of randomness. 
* **************************************************************************************************/

char RPSGame::nextAIMove(int inputRound)
{
	char outputTool;
	if (inputRound < 4) //if current round is less than 4, choose a random tool for the computer and let knowledgeBase increase
	{
		int randNumber;
		randNumber = rand()%(3-1+1)+1; //random number between 1 and 3
		outputTool = choiceToTool(randNumber);
		return outputTool;
	}
	else
	{
		int randIndex;
		size_t maxIndex = knowledgeBase.size() - 1;
		randIndex = rand()%(static_cast<int>(maxIndex) - 0 + 1) + 0; //random index in knowledgeBase
		outputTool = knowledgeBase[randIndex];
		
		//Opposite tool selection
		if (outputTool == 's')
		{
			outputTool = 'r';
		}
		else if (outputTool == 'r')
		{
			outputTool = 's';
		}
		else //output tool = 'p'
		{
			outputTool = 's';
		}
		
		return outputTool;	
	}
}

/***************************************************************************************************
* playGame - Interfaces user to play a game. Loops until user quits. Manages user tool selection
			 and computer tool selection. Prints results of each round. 
* **************************************************************************************************/

void RPSGame::playGame()
{
	screenClear();
	int currentRound = 1;
	knowledgeBase.clear();
	bool gameRun = true;
	humanWins = 0;
	computerWins = 0;
	ties = 0;
	int tempUserChoice;
	char tempRoundResult;
	//starting new game text
	while (gameRun)
	{
		cout << "Round " << currentRound << endl;
		tempUserChoice = choiceMenu();
		if (tempUserChoice == 4)
		{
			screenClear();
			gameRun = false;	
			cout << "Game ending..." << endl;
			cout << "Final Score:      You: " << humanWins << "  Computer: " << computerWins << endl;
			cout << "Press enter to go back to main menu " << endl;
			screenContinue();
		}
		else 
		{
			humanTool = buildHumanTool(choiceToTool(tempUserChoice));
			computerTool = buildComputerTool(nextAIMove(currentRound));
			knowledgeBase.push_back(choiceToTool(tempUserChoice)); // can also use humanTool.getType()

            cout << humanTool->getLongType() << " vs " << computerTool->getLongType() << endl;
			tempRoundResult = humanTool->fight(*computerTool);
			
			if (tempRoundResult == 'w')
			{
				humanWins++;
			}
			
			else if (tempRoundResult == 'l')
			{
				computerWins++;
			}
			
			else //result = 't', tie
			{
				ties++;
			}

            printRoundResult(tempRoundResult);
			cout << endl << "Current Score:      You: " << humanWins << "  Computer: " << computerWins << endl;

			currentRound++;
			delete humanTool;
			delete computerTool;
			screenContinue();
			screenClear();

            std::this_thread::sleep_for(sleepDuration);
		}
	}
}

/***************************************************************************************************
* choiceMenu - Interfaces user to pick a tool (1-3) or quit (4)
* **************************************************************************************************/
int RPSGame::choiceMenu()
{

        int userChoice;

        cout << "Choose an option below: " << endl << endl;
		cout << "1) Rock" << endl;
		cout << "2) Paper" << endl;
		cout << "3) Scissors" << endl; 
		cout << "4) Quit " << endl << endl;
		cout << "Enter option (1-4): ";
		cin >> userChoice;
		userChoice = validateBetween(userChoice, 1, 4);
		return userChoice;     
}





/***************************************************************************************************
* mainMenu - Interfaces user to start a new game, modify tool settings, and quit
* **************************************************************************************************/

void RPSGame::mainMenu()
{

        bool runMain = true;
        int mainInput;

        while (runMain)
        {
                screenClear();
                cout << "Welcome to Rock Paper Scissors! " << "Choose an option below: " << endl << endl;
                cout << "1) Start New Game" << endl;
                cout << "2) Tool Settings" << endl;
                cout << "3) Quit" << endl << endl;

                cout << "Enter option (1-3): ";
                cin >> mainInput;
                mainInput = validateBetween(mainInput, 1, 3);

                switch (mainInput)
                {
                case 1: //Start new game
                {
                        playGame();
                        break;
                }
                case 2:
                {
                        toolSettingsMenu();
                        screenClear();
                        break;
                }
                case 3:
                {
                        runMain = false;
                        cout << "Goodbye!" << endl;
                }
                }
        }
}

/***************************************************************************************************
* toolSettingsMenu - Interfaces user to modify strengths of the computer and human tools. There
					is a sub-menu for the human and computer tools.
* **************************************************************************************************/

void RPSGame::toolSettingsMenu() {
    bool runToolSettings = true;
    int settingsInput;

    while (runToolSettings) {
        screenClear();
        cout << "Tool Settings Menu" << endl << endl;
        cout << "1) Human Tool Strength" << endl;
        cout << "2) Computer Tool Strength" << endl;
        cout << "3) Back to main menu" << endl;

        //cout << "X) Tempo - (" << getTempo() << " seconds)" << endl;     If we want to add tempo between rounds

        cout << "Enter option (1-3): ";
        cin >> settingsInput;
        settingsInput = validateBetween(settingsInput, 1, 3);

        switch (settingsInput) {
            case 1: //Human tool Strength
            {
                bool humanToolSettingsRun = true;
                int tempUserChoice;


                while (humanToolSettingsRun) {
                    screenClear();
                    cout << "Human tool strength settings" << endl << endl;
                    cout << "1) Rock strength:  " << humanRockStrength << endl;
                    cout << "2) Paper strength: " << humanPaperStrength << endl;
                    cout << "3) Scissor strength: " << humanScissorStrength << endl;
                    cout << "4) Back to Tool settings menu" << endl;
                    cout << endl << endl << "Enter 1-4: ";
                    cin >> tempUserChoice;
                    tempUserChoice = validateBetween(tempUserChoice, 1, 4);
                    int tempStrength = 0;
                    switch (tempUserChoice) {
                        case 1: // Set Human rock strength
                        {
                            cout << endl << "Enter new rock strength: ";
                            cin >> tempStrength;
                            humanRockStrength = validateBetween(tempStrength, 1, maxStrength);
                            break;
                        }
                        case 2: // Set Human paper strength
                        {
                            cout << endl << "Enter new paper strength: ";
                            cin >> humanPaperStrength;
                            humanPaperStrength = validateBetween(tempStrength, 1, maxStrength);
                            break;
                        }
                        case 3: // Set Human scissor strength
                        {
                            cout << endl << "Enter new scissor strength: ";
                            cin >> humanScissorStrength;
                            humanScissorStrength = validateBetween(tempStrength, 1, maxStrength);
                            break;
                        }
                        case 4: {
                            humanToolSettingsRun = false;
                        }
                    }
                }
                break;
            }

            case 2: //Computer tool Strength
            {
                bool computerToolSettingsRun = true;
                int tempUserChoice;


                while (computerToolSettingsRun) {
                    screenClear();
                    cout << "Computer tool strength settings" << endl << endl;
                    cout << "1) Rock strength:  " << computerRockStrength << endl;
                    cout << "2) Paper strength: " << computerPaperStrength << endl;
                    cout << "3) Scissor strength: " << computerScissorStrength << endl;
                    cout << "4) Back to Tool settings menu" << endl;
                    cout << endl << endl << "Enter 1-4: ";
                    cin >> tempUserChoice;
                    tempUserChoice = validateBetween(tempUserChoice, 1, 4);
                    int tempStrength = 0;
                    switch (tempUserChoice) {
                        case 1: // Set Computer rock strength
                        {
                            cout << endl << "Enter new rock strength: ";
                            cin >> computerRockStrength;
                            computerRockStrength = validateBetween(tempStrength, 1, maxStrength);
                            break;
                        }
                        case 2: // Set Computer paper strength
                        {
                            cout << endl << "Enter new paper strength: ";
                            cin >> computerPaperStrength;
                            computerPaperStrength = validateBetween(tempStrength, 1, maxStrength);
                            break;
                        }
                        case 3: // Set Computer scissor strength
                        {
                            cout << endl << "Enter new scissor strength: ";
                            cin >> computerScissorStrength;
                            computerScissorStrength = validateBetween(tempStrength, 1, maxStrength);
                            break;
                        }
                        case 4: {
                            computerToolSettingsRun = false;
                        }
                    }
                }
                break;
            }
            case 3: {
                runToolSettings = false;
            }
        }
    }
}

int RPSGame::validateBetween(int inputNumber, int validMin, int validMax) {
    while ((cin.fail() || inputNumber < validMin || inputNumber > validMax)) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Please enter a valid integer >= " << validMin << " or <=  " << validMax << " : " << endl;
        cin >> inputNumber;
    }
    return inputNumber;
}

/***************************************************************************************************
* printRoundResult - Prints outcome of current round
* **************************************************************************************************/

void RPSGame::printRoundResult(char inputResult)
{
    switch(inputResult)
    {
        case 'w':
        {
            cout << "You win!" << endl;
            break;
        }
        case 'l':
        {
            cout << "Computer wins!" << endl;
            break;
        }
        case 't':
        {
            cout << "Tie." << endl;
        }
    }
}

/***************************************************************************************************
* screenClear - clears screen based on OS. Made this so I can test on Visual Studio as well
* **************************************************************************************************/
void RPSGame::screenClear() {
    #ifdef __linux__
            system("clear");

    #elif _WIN32
            system("cls");
    #endif
}

/***************************************************************************************************
* screenClear - Prompts press any key to continue based on OS.
* **************************************************************************************************/
void RPSGame::screenContinue() {
    #ifdef __linux__
            system("read");

    #elif _WIN32
            system("pause");
    #endif
}

Tool *RPSGame::getHumanTool() const {
    return humanTool;
}

Tool *RPSGame::getComputerTool() const {
    return computerTool;
}

void RPSGame::setSleepDuration(int sleepDuration) {
    std::chrono::seconds sleep(sleepDuration);
    this->sleepDuration = sleep;
}

