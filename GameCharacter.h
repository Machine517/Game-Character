// Drew Clark
// CS 355-01
// Assignment 3
// 9/1/2023
// This program simulates a battle between any number of characters, allowing
// decent but limited gameplay, primarily attacks and character combinations.
#ifndef GAMECHARACTER_H
#define GAMECHARACTER_H

#include <string>
#include <iostream>

using namespace std;

class GameCharacter
{
// friends of the class / overloaded operators
    friend ostream& operator<<(ostream& os, const GameCharacter& Character);

// public member functions
public:

    // Constructor
    GameCharacter(string charName, int maxH,  int aP, int dP);

    // Mutators
    void takeDamage(int damage);
    void attack(GameCharacter& target);
    void loadFromFile(const string& filename);

    // Accessors
    bool getLive();
    void saveToFile(const string& filename) const;

    // overloaded operators
    GameCharacter operator+(GameCharacter const& obj);
    bool operator>(GameCharacter const& obj);
    bool operator<(GameCharacter const& obj);

// private member attributes
private:

    string name;
    int maxHealth;
    int healthPoints;
    int attackPoints;
    int defensePoints;
    bool isAlive;

};

#endif
