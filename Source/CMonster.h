// #pragma once
//template functions HAVE to be implemented in the header.
template <class T, class C, class E, class F>
class CMonster{

private:
    T Name;
    C Health;
    C Age;
    F Size;

public:
    static int monsterCount;
    
    T getName() const { return Name; }
    void setName(T name) { Name = name; }

    C getHealth() const { return Health; }
    void setHealth(C health) { Health = health; }

    C getAge() const { return Age; }
    void setAge(C age) { Age = age; }

    F getSize() const { return Size; }
    void setSize(F size) { Size = size; }

};