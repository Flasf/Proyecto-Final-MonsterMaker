#include <iostream>

//Librerías para el random number generator
#include <cstdlib> //srand y rand
#include <ctime> //time

using std::cin; using std::cout;
using std::endl; using std::string;

int main()
{
    srand((unsigned)time(NULL));
    int iRandomNumber = rand()%100+1;
    cout << iRandomNumber << endl;
}