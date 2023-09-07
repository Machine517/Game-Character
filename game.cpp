// Drew Clark
// CS 355-01
// Assignment 3
// 9/1/2023
// This program simulates a battle between any number of characters, allowing
// decent but limited gameplay, primarily attacks and character combinations.
#include "GameCharacter.h"
#include <iostream>
using namespace std;

int main()
{
    GameCharacter mario("Mario", 110, 175, 165);
    GameCharacter luigi("Luigi", 115, 130, 155);
    GameCharacter bowser("Bowser", 120, 190, 175);

    cout << mario << endl;
    cout << luigi << endl;
    cout << bowser << endl;

    // Commentary
    if (mario < bowser || luigi < bowser)
    {
        cout << "Mario and Luigi are the underdogs";
    }
    else
    {
        cout << "Bowser is overrated";
    }

    GameCharacter temp("N/A", 0, 0, 0);
    temp = mario + luigi;

    if (temp > bowser)
    {
        cout << ", but together they have a fighting chance!" << endl;
    }
    else
    {
        cout << ", and based on the average the odds are against them!" << endl;
    }

    // Simulation
    cout << "SIMULATION: AVERAGING ATTACKS" << endl;
    GameCharacter sim("Sim", 120, 190, 175);
    temp.attack(sim);
    cout << "Both combined attack Bowser!" << endl;

    if (sim.getLive())
    {
        cout << "RESULT: FAIL" << endl << endl;
    }

    // Battle
    cout << "However, if they seperate their attacks they stand a chance." << endl;

    mario.attack(bowser);
    cout << "Mario attacks Bowser!" << endl;

    luigi.attack(bowser);
    cout << "Luigi attacks Bowser!" << endl;

    if (!bowser.getLive())
    {
        cout << "Bowser is defeated!" << endl;
    }

    cout << endl;

    // Save Game and Results
    mario.saveToFile("mario.txt");
    luigi.saveToFile("luigi.txt");
    bowser.saveToFile("bowser.txt");

    mario.loadFromFile("mario.txt");
    luigi.loadFromFile("luigi.txt");
    bowser.loadFromFile("bowser.txt");

    cout << mario << endl;
    cout << luigi << endl;
    cout << bowser << endl;

    return 0;
}
