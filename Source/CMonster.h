//#pragma once
#ifndef CMONSTER_H
#define CMONSTER_H
#include <iostream>

using std::string;
template <class T, class C, class E, class F>

class CMonster{

private:
    T Name;
    C Health;
    C Age;
    F Size;

public:
    //static int iMonsterCount;
    //int CMonster<T, C, E, F>::iMonsterCount;
    T getName() const { return Name; }
    void setName(T name) { Name = name; }

    C getHealth() const { return Health; }
    void setHealth(C health) { Health = health; }

    C getAge() const { return Age; }
    void setAge(C age) { Age = age; }

    F getSize() const { return Size; }
    void setSize(F size) { Size = size; }
    CMonster();
    CMonster(const T name, const C health, const C age, const F size){
        Name = name;
        Health = health;
        Age = age;
        Size = size;
    }
    ~CMonster(){
        std::cout << "Monster has been destroyed." << std::endl;
    }
    /* friend CMonster<T, C, E, F> operator+(const CMonster<T, C, E, F> &leftMonster, const CMonster<T, C, E, F> &rightMonster)
    {
        CMonster<string, int, int, double> combinedResult;
        combinedResult.Name = leftMonster.Name + rightMonster.Name;
        combinedResult.Age = leftMonster.Age + rightMonster.Age;
        combinedResult.Health = leftMonster.Health + rightMonster.Health;
        combinedResult.Size = leftMonster.Size + rightMonster.Size;

        return combinedResult;
    } */
    CMonster<T, C, E, F> operator+(const CMonster<T, C, E, F> &rightMonster)
    {
        CMonster<string, int, int, double> combinedResult;
        combinedResult.Name = this->Name + rightMonster.Name;
        combinedResult.Age = this->Age + rightMonster.Age;
        combinedResult.Health = this->Health + rightMonster.Health;
        combinedResult.Size = this->Size + rightMonster.Size;

        return combinedResult;
    }
    // CMonster operator+(/*const CMonster<T,C,E,F> &leftMonster, */const CMonster<T,C,E,F> &rightMonster)
    // {
    //     CMonster Result;
    //     result = this->.Name + rightMonster.Name;
    //     result = this->.Age + rightMonster.Age;
    //     result = this->.Health + rightMonster.Health;
    //     result = this->.Size + rightMonster.Size;
        
    //     return result;
    // }
};

#endif // CMONSTER_H