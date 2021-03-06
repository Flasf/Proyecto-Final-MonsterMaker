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
#include <fstream>
#include <stdlib.h>//system("CLS"), system("PAUSE")

#include "CMonster.h"

using std::cin; using std::cout;
using std::endl; using std::string;

//int CMonster<C>::iMonsterCount = 0;

void play();
void createMonster();
void openMonster();
void createMonster();
void loading();
void playMinigame();

bool notMonsterFound;

int main()
{
    if (notMonsterFound == true){system("CLS");}
    
    char choice = 0;
    cout << "Write a number\n";
    cin >> choice;
    cout << choice << endl;
    //menu
    do
    {

        cout << "Select a number"
             << "\n\t1. Play"
             << "\n\t2. Show Monsters created"
             << "\n\t3. Exit"
             << "\n\t4. Minigame" << endl;

        cin >>choice;

        if (choice == '1')
            play();
        else if (choice == '2')
            openMonster();
        else if (choice == '3')
            cout << "Bye Bye" << endl;
        else if (choice == '4')
            playMinigame();
        else
            cout << "Please choose again" << endl;

    } while (choice != '3');
    return 0;
}

void play()
{
    cout << "\nYou're playing" << endl<<endl;
    createMonster();
}

void openMonster(){

    system("CLS");
    cout << "Here are your monsters: " << endl;

    std::fstream AbreArchivo;
    AbreArchivo.open("monsters.txt", std::ios::in);
    if (AbreArchivo.is_open())
    {
        string line;
        while (getline(AbreArchivo, line))
        {
            cout << line << endl;
        }
        AbreArchivo.close();
    }else 
    {
        cout << "You haven't made monster's yet. Please play the game to create monsters." << endl;
        notMonsterFound = true;
        system("PAUSE");
    }
    main();
}

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

    cout << "\nYou can create 2 monsters, how would you like to name the first one?: ";
    
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

    Sleep(1000);

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

    cout << "Would you like to combine your monsters? (choose a number)\n\t1. Yes \n\t2. No, just save the game" << endl;
    cin >> choice;
    if (choice == '1')
    {
        // save monsters values to a file
        std::ofstream file;
        file.open("monsters.txt", std::ios::out);
        if (file.is_open())
        {
            file << "First monster atributes are: " << endl;
            file << "Name: " << monster1.getName() << endl;
            file << "Age: " << monster1.getAge() << endl;
            file << "Health: " << monster1.getHealth() << endl;
            file << "Size: " << monster1.getSize() << endl
                 << endl;
            file << "Second monster atributes are: " << endl;
            file << "Name: " << monster2.getName() << endl;
            file << "Age: " << monster2.getAge() << endl;
            file << "Health: " << monster2.getHealth() << endl;
            file << "Size: " << monster2.getSize() << endl
                 << endl;
            /* file << "Combined monster atributes are: " << endl;
            file << "Name: " << CombinedMonster.getName() << endl;
            file << "Age: " << CombinedMonster.getAge() << endl;
            file << "Health: " << CombinedMonster.getHealth() << endl;
            file << "Size: " << CombinedMonster.getSize() << endl << endl; */
            //! if operator overload worked
            file.close();
        }
    }
    else//if decided to not combine
    {
        std::ofstream file;
        file.open("monsters.txt", std::ios::out);
        if (file.is_open())
        {
            file << "First monster atributes are: " << endl;
            file << "Name: " << monster1.getName() << endl;
            file << "Age: " << monster1.getAge() << endl;
            file << "Health: " << monster1.getHealth() << endl;
            file << "Size: " << monster1.getSize() << endl
                 << endl;
            file << "Second monster atributes are: " << endl;
            file << "Name: " << monster2.getName() << endl;
            file << "Age: " << monster2.getAge() << endl;
            file << "Health: " << monster2.getHealth() << endl;
            file << "Size: " << monster2.getSize() << endl
                 << endl;
            file.close();
        }
        /* using string = basic_string<char>; */
        /* cout << "Combining monsters..." << endl;
        CMonster<string, int, int, double> operator+(const CMonster<string, int, int, double> &leftMonster, const CMonster<string, int, int, double> &rightMonster);
        CMonster<string, int, int, double> CombinedMonster;
        CMonster<string, int, int, double> CombinedMonster = monster1 + monster2;
        cout << CombinedMonster.getName() << endl;
        cout << CombinedMonster.getAge() << endl;
        cout << CombinedMonster.getHealth() << endl;
        cout << CombinedMonster.getName() << endl; */
    }

    }
    
void playMinigame(){
    system("CLS");
    cout << "Let's see how lucky you are..." << endl;
    Sleep(1000);

    srand((unsigned)time(NULL));//set seed to random number
    int iRandomNumber = rand() % 100 + 1;
    cout << iRandomNumber << " ";
    int iNum1 = iRandomNumber;
    // cout.flush();
    Sleep(1000);
    iRandomNumber = rand() % 100 + 1;
    cout << iRandomNumber << " ";
    int iNum2 = iRandomNumber;
    // cout.flush();
    Sleep(1000);
    iRandomNumber = rand() % 100 + 1;
    cout << iRandomNumber << endl;
    int iNum3 = iRandomNumber;

    if(iNum1 == iNum2 && iNum1 == iNum3)
        cout << "You won $100,000,000" << endl;
        
    else if(iNum1 == iNum2 && iNum1 != iNum3)
        cout << "You won $50" << endl;
    else if(iNum1 == iNum3 && iNum1 != iNum2)
        cout << "You won $50" << endl;

    else if(iNum1 != iNum2 && iNum1 != iNum3)
        cout << "You won $0" << endl;
    else if (iNum2 != iNum1 && iNum2 != iNum3)
        cout << "You won $0" << endl;
    else if (iNum3 != iNum2 && iNum3 != iNum1)
            cout << "You won $0" << endl;
    system("PAUSE");
    system("CLS");
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