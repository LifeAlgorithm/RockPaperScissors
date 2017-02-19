/************************************************************************
Author: GROUP 10
Date:  2/18/17
Description: Unit tests for selected functions
*************************************************************************/
#include <iostream>
#include "Scissor.hpp"
#include "Rock.hpp"
#include "Paper.hpp"

using std::cout;
using std::endl;

#define FAILED cout << "!!!! FAILED !!!!!  ";
#define PASSED cout << "Passed: ";

void deleteObjs(Rock* scissor, Paper* rock, Scissor* paper) {
    delete rock;
    delete paper;
    delete scissor;
}

int testFights() {
    Scissor* scissor = new Scissor(10);
    Rock* rock = new Rock(10);
    Paper* paper = new Paper(10);

    cout << "SCISSOR vs ROCK - ";
    if (scissor->fight(*rock) != 'l') {
        FAILED;
        cout << "scissor should not beat rock" << endl;
        deleteObjs(rock, paper, scissor);
        return -10;
    } else {
        PASSED;
        cout << "rock beat scissor" << endl;
    }

    cout << "SCISSOR vs PAPER - ";
    if (scissor->fight(*paper) != 'w') {
        FAILED;
        cout << "scissor should beat paper" << endl;
        deleteObjs(rock, paper, scissor);
        return -10;
    } else {
        PASSED;
        cout << "scissor beat paper" << endl;
    }

    cout << "ROCK vs PAPER - ";
    if (rock->fight(*paper) != 'w') {
        FAILED;
        cout << "rock should not beat paper" << endl;
        deleteObjs(rock, paper, scissor);
        return -10;
    } else {
        PASSED;
        cout << "paper beat rock" << endl;
    }

    deleteObjs(rock, paper, scissor);
    return 0;
}

int main() {

    return testFights();

}