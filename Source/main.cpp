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

//Librerías para el random number generator
#include <cstdlib> //srand y rand
#include <ctime> //time
#include <Windows.h> //delay

using std::cin; using std::cout;
using std::endl; using std::string;

void play();
void saveGame();

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
    cout << "You're playing" << endl;
}

void saveGame(){

}