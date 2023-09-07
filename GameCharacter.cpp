// Drew Clark
// CS 355-01
// Assignment 3
// 9/1/2023
// This program simulates a battle between any number of characters, allowing
// decent but limited gameplay, primarily attacks and character combinations.
#include "GameCharacter.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// Name: constructor
// Disc: assigns each private member with its initial value
// Type: none
GameCharacter::GameCharacter(string charName, int maxH, int aP, int dP)
{
    name = charName;
    maxHealth = maxH;
    healthPoints = maxHealth;
    attackPoints = aP;
    defensePoints = dP;
    isAlive = true;
}

// Name: takeDamage
// Disc: used to simulate damage after lack of defense in a battle
// Type: void
void GameCharacter::takeDamage(int damage)
{
    if (healthPoints > 0)
    {
        healthPoints -= damage;
    }

    if (healthPoints <= 0)
    {
        isAlive = false;
        healthPoints = 0;
    }
}

// Name: attack
// Disc: used to simulate attacks
// Type: void
void GameCharacter::attack(GameCharacter& target)
{
    if (target.defensePoints > 0)
    {
        target.defensePoints -= attackPoints;
    }

    if (target.defensePoints <= 0)
    {
        target.defensePoints = 0;
        target.takeDamage(attackPoints);
    }
}

// Name: getLive
// Disc: added out of necesity to access this private member
// Type: bool
bool GameCharacter::getLive()
{
    return isAlive;
}

// Name: overloaded '+' operator
// Disc: used to combine two characters into one new character
// Type: GameCharacter
GameCharacter GameCharacter::operator+(GameCharacter const& obj)
{
    GameCharacter newCharacter("Combo", 0, 0, 0);

    newCharacter.maxHealth = maxHealth + obj.maxHealth;
    newCharacter.healthPoints = ((healthPoints + obj.healthPoints) / 2);
    newCharacter.attackPoints = ((attackPoints + obj.attackPoints) / 2);
    newCharacter.defensePoints = ((defensePoints + obj.defensePoints) / 2);

    return newCharacter;
}

// Name: overloaded '>' operator
// Disc: compares the health of two Character
// Type: bool
bool GameCharacter::operator>(GameCharacter const& obj)
{
    return (healthPoints > obj.healthPoints);
}

// Name: overloaded '<' operator
// Disc: compares the health of two chracters
// Type: bool
bool GameCharacter::operator<(GameCharacter const& obj)
{
    return (healthPoints < obj.healthPoints);
}

// Name: overloaded '<<' operator
// Disc: used to display the stats of a character at any given moment
// Type: ostream
ostream& operator<<(ostream& os, const GameCharacter& Character)
{
    os << "Name: " << Character.name << endl;
    os << "Max Health: " << Character.maxHealth << endl;
    os << "Health: " << Character.healthPoints << endl;
    os << "Attack: " << Character.attackPoints << endl;
    os << "Defense: " << Character.defensePoints << endl;
    os << "Living: " << Character.isAlive << endl;

    return os;
}

// Name: saveToFile
// Disc: saves current characteristics of a character to its save file
// Type: void
void GameCharacter::saveToFile(const string& filename) const
{
    ofstream outFile;
    outFile.open(filename, std::ios::out);
    if (outFile.fail())
    {
        cout << "Failed to save." << endl;
        exit(1);
    }

    outFile << name << endl;
    outFile << maxHealth << endl;
    outFile << healthPoints << endl;
    outFile << attackPoints << endl;
    outFile << defensePoints << endl;
    outFile << isAlive << endl;
}

// Name: loadFromFile
// Disc: loads previous save of a character from its save file
// Type: void
void GameCharacter::loadFromFile(const string& filename)
{
    ifstream inFile(filename);
    if(inFile.fail())
    {
        cout << "Failed to load save." << endl;
        exit(1);
    }
    getline(inFile, name);
    inFile >> maxHealth;
    inFile >> healthPoints;
    inFile >> attackPoints;
    inFile >> defensePoints;
    inFile >> isAlive;
}
