/*
Author: Abdiel Baldonedo
Email: abdielr507@gmail.com
Assignment: final proyect for Object Orientes Programming
Last Changed: May 29, 2022
Description: Program a short game, using all tools learnd during the semester. Choose one of the following:
            * Battleships
            * A monster creator that allows you to fill all the attributes of your monster, and then combine it with other monsters that the program presents. (CHOSEN)
            * A short RPG that lets you buy weapons, armor and defeat enemies 

The game should have somewhere:
    * A Menu
    * UML Diagram of its classes (not IN the game but in its presentation/PPT)
    * Save the game
    * Operator overloading and class templates

*/

#include <iostream>
#include <cstdlib> //srand y rand
#include <ctime> //time
#include <Windows.h> //delay
#include <string>
#include <sstream>

#include "CMonster.h"

using std::cin; using std::cout;
using std::endl; using std::string;

//int CMonster<C>::iMonsterCount = 0;

void play();
void saveGame();
void createMonster();
void openMonster();
void createMonster();
void combineMonster();
void loading();
void seeMonsterInfo();

int main()
{
    srand((unsigned)time(NULL));
    int iRandomNumber = rand()%100+1;
    cout << iRandomNumber << " ";
    //cout.flush();
    Sleep(1000);
    cout << iRandomNumber << " ";
    //cout.flush();
    Sleep(1000);
    cout << iRandomNumber << endl;

    int choice = 0;
    cout << "Write a number\n";
    cin >> choice;
    cout << choice << endl;
    CMonster<string, int, int, double> monsterDePrueba("none", 1, 1, 1);
    //menu
    do
    {

        cout << "Select a number \n\t1. Play\n\t2. Save Game\n\t3. Exit" << endl;
        cin >> choice;

        if (choice == 1)
            play();
        else if (choice == 2)
            saveGame();
        else if (choice == 3)
            cout << "Bye Bye" << endl;
        else
            cout << "Please choose again" << endl;

    } while (choice != 3);
    return 0;
}

void play()
{
    cout << "You're playing" << endl<<endl;
    createMonster();
}

void saveGame(){
//file stuff
    exit(0);
}

void openMonster(){
//you have these monsters: bla bla bla (names) selecte which one...
}

void saveMonster(){/*call saveGame maybe*/}

void seeMonsterInfo(){/*see monster's info*/}

void createMonster(){
    string monstersName;
    int monstersAge;
    int monstersHealth;
    int timesCreateMonsterHasBeenUsed;
    double monstersSize;
    bool isMonster1Created;
    bool isMonster2Created;
    char choice;
    CMonster<string, int, int, double> monster1(monstersName, monstersAge, monstersHealth, monstersSize);
    CMonster<string, int, int, double> monster2(monstersName, monstersAge, monstersHealth, monstersSize);

    timesCreateMonsterHasBeenUsed = 0;

    cout << "You can create 2 monsters, how would you like to name the first one?: ";
    
    cin.ignore(); //If not, getline doesn't wait for input
    cin.clear();
    cin.sync();
    std::getline(std::cin, monstersName);
    cout << endl;

    cout << "Monster's age?: ";
    cin >> monstersAge;
    cout << endl;

    cout << "Monster's health?: ";
    cin >> monstersHealth;
    cout << endl;

    cout << "Monster's size?: ";
    cin >> monstersSize;
    cout << endl;

    
    //Adding gamification (the loading function)
    loading();

    Sleep(1000);
    cout << "First Monster created!" << endl;
    monster1.setHealth(monstersHealth);
    monster1.setName(monstersName);
    monster1.setAge(monstersAge);
    monster1.setSize(monstersSize);

    cout<< monster1.getName() << endl;
    
    cout << "You can create 2 monsters, how would you like to name the second one?: ";
    cin.ignore(); // If not, getline doesn't wait for input
    cin.clear();
    cin.sync();
    std::getline(std::cin, monstersName);
    cout << endl;

    cout << "Monster's age?: ";
    cin >> monstersAge;
    cout << endl;

    cout << "Monster's health?: ";
    cin >> monstersHealth;
    cout << endl;

    cout << "Monster's size?: ";
    cin >> monstersSize;
    cout << endl;

    loading();
    Sleep(1000);
    cout << "Second Monster created!" << endl;
    monster2.setHealth(monstersHealth);
    monster2.setName(monstersName);
    monster2.setAge(monstersAge);
    monster2.setSize(monstersSize);

    cout << monster2.getName() << endl;
    Sleep(1000);
    cout << "Would you like to combine your monsters? (choose a number)\n\t1. Yes \n\t2. No" << endl;
    cin >> choice;
    if (choice == 1) {
        char choice2;
        cout << "Would you like to save the game before combining?\n\t1. Yes \n\t2. No" << endl;

        if(choice2 == 1){
            saveGame();
        }else{
            cout << "Combining monsters..." << endl;
            CMonster<string, int, int, double> operator+(const CMonster<string, int, int, double> &leftMonster, const CMonster<string, int, int, double> &rightMonster);
            CMonster<string, int, int, double> CombinedMonster;
            CombinedMonster = monster1 + monster2;
            cout << CombinedMonster.getName() << endl;
            cout << CombinedMonster.getAge() << endl;
            cout << CombinedMonster.getHealth() << endl;
            cout << CombinedMonster.getName() << endl;
            }
    }else if (choice == 2) {
        cout<< "ok then" << endl;
    }
    }

void combineMonster(){
    exit(0);
    // CMonster Operator+(const CMonster& left, const CMonster& right){

    //     return left.
    // }
}
void loading(){
    cout << "1 ";
    Sleep(1000);
    cout << "2 ";
    Sleep(1000);
    cout << "3";
    Sleep(500);
    cout << ".";
    Sleep(500);
    cout << ".";
    Sleep(500);
    cout << ". ";
    Sleep(500);
    cout << "\nPuff! ";
}
int exit() { return 0; }