/************************************************************************
Author: GROUP 10
Date:  2/18/17
Description: Unit tests for selected functions
*************************************************************************/
#include <iostream>
#include "RPSGame.hpp"
#include "Scissor.hpp"
#include "Rock.hpp"
#include "Paper.hpp"

using std::cout;
using std::endl;

#define FAILED cout << "!!!! FAILED !!!!! ";
#define PASSED cout << "Passed: ";

class RPSGameStub : public RPSGame {
public:
    int count, exit, result = 0;

    RPSGameStub(int exit) {
        this->exit = exit;
    }

    ~RPSGameStub() override {}

    int getResult() const {
        return result;
    }

    int choiceMenu() {
        count++;
        if (count > exit) {
            return 4;
        }
        return rand()%(3-1+1)+1;
    }

    void printRoundResult(char result) override {
        char humanType = getHumanTool()->getType();
        char compType = getComputerTool()->getType();

        if (humanType == 'r' && compType == 'p' && result != 'l') {
            FAILED;
            cout << "ROCK vs PAPER - result: " << result << endl;
            this->result = -10;
            return;
        }

        if (humanType == 'r' && compType == 's' && result != 'w') {
            FAILED;
            cout << "ROCK vs SCISSOR - result: " << result << endl;
            this->result = -10;
            return;
        }

        if (humanType == 'r' && compType == 'r' && result != 't') {
            FAILED;
            cout << "ROCK vs ROCK - result: " << result << endl;
            this->result = -10;
            return;
        }

        if (humanType == 'p' && compType == 's' && result != 'l') {
            FAILED;
            cout << "PAPER vs SCISSOR - result: " << result << endl;
            this->result = -10;
            return;
        }

        if (humanType == 'p' && compType == 'r' && result != 'w') {
            FAILED;
            cout << "PAPER vs ROCK - result: " << result << endl;
            this->result = -10;
            return;
        }

        if (humanType == 'p' && compType == 'p' && result != 't') {
            FAILED;
            cout << "PAPER vs PAPER - result: " << result << endl;
            this->result = -10;
            return;
        }

        if (humanType == 's' && compType == 'r' && result != 'l') {
            FAILED;
            cout << "SCISSOR vs ROCK - result: " << result << endl;
            this->result = -10;
            return;
        }

        if (humanType == 's' && compType == 'p' && result != 'w') {
            FAILED;
            cout << "SCISSOR vs PAPER - result: " << result << endl;
            this->result = -10;
            return;
        }

        if (humanType == 's' && compType == 's' && result != 't') {
            FAILED;
            cout << "SCISSOR vs SCISSOR - result: " << result << endl;
            this->result = -10;
            return;
        }

        PASSED;
        cout << humanType << " vs " << compType << " - result: " << result << endl;
    }
};

void deleteTools(Rock *scissor, Paper *rock, Scissor *paper) {
    delete rock;
    delete paper;
    delete scissor;
}

int testDefaultStrenghtFights() {
    Scissor* scissor = new Scissor(100);
    Rock* rock = new Rock(100);
    Paper* paper = new Paper(100);

    cout << "SCISSOR vs SCISSOR - ";
    if (scissor->fight(*scissor) != 't') {
        FAILED;
        cout << "scissor vs scissor should be a tie" << endl;
        deleteTools(rock, paper, scissor);
        return -10;
    } else {
        PASSED;
        cout << "result was a tie" << endl;
    }

    cout << "ROCK vs ROCK - ";
    if (rock->fight(*rock) != 't') {
        FAILED;
        cout << "rock vs rock should be a tie" << endl;
        deleteTools(rock, paper, scissor);
        return -10;
    } else {
        PASSED;
        cout << "result was a tie" << endl;
    }

    cout << "PAPER vs PAPER - ";
    if (paper->fight(*paper) != 't') {
        FAILED;
        cout << "paper vs paper should be a tie" << endl;
        deleteTools(rock, paper, scissor);
        return -10;
    } else {
        PASSED;
        cout << "result was a tie" << endl;
    }

    cout << "SCISSOR vs ROCK - ";
    if (scissor->fight(*rock) != 'l') {
        FAILED;
        cout << "scissor should not beat rock" << endl;
        deleteTools(rock, paper, scissor);
        return -10;
    } else {
        PASSED;
        cout << "rock beat scissor" << endl;
    }

    cout << "SCISSOR vs PAPER - ";
    if (scissor->fight(*paper) != 'w') {
        FAILED;
        cout << "scissor should beat paper" << endl;
        deleteTools(rock, paper, scissor);
        return -10;
    } else {
        PASSED;
        cout << "scissor beat paper" << endl;
    }

    cout << "ROCK vs PAPER - ";
    if (rock->fight(*paper) != 'l') {
        FAILED;
        cout << "rock should not beat paper" << endl;
        deleteTools(rock, paper, scissor);
        return -10;
    } else {
        PASSED;
        cout << "paper beat rock" << endl;
    }

    deleteTools(rock, paper, scissor);
    return 0;
}

int testRPSGame() {
    cout << endl;
    RPSGameStub* rpsGame = new RPSGameStub(5);
    rpsGame->playGame();

    int result = rpsGame->getResult();
    delete rpsGame;
    return result;
}

int main() {

    return testDefaultStrenghtFights() + testRPSGame();

}