#include <iostream>
#include "Autobot.h"
#include "Decepticon.h"

// Creation constructor Decepticon
Decepticon::Decepticon() : Transformer(), evil(100), _warrior(true)
{
    std::cout << "-> Decepticon created" << std::endl;
}

Decepticon::Decepticon(unsigned int evil, bool warrior)
    : Transformer(), _evel(evil), _warrior(warrior) {}

// Creation deconstructor Decepticon
Decepticon::~Decepticon()
{
    std::cout << "-> Decepticon destroyed" << std::endl;
}


// Setters and getters for Decepticon
void Decepticon::setevil(int evil)
{
    _evil = evil;
}

bool Decepticon::getevil() const
{
    return _evil;
}

void Decepticon::setwarrior(bool warrior)
{
    _warrior = warrior;
}

unsigned int Decepticon::gerwarrior() const
{
    return _warrior;
}

// Overload operator
std::ostream& operator<<(std::ostream& os, const Decepticon& decepticon)
{
    os << "Decepticon. evil: " << decepticon._evil << ", warior: " << (decepticon._warrior ? "Yes" : "No");
    return os;
}

std::istream& operator>>(std::istream& is, Decepticon& decepticon)
{
    std::cout << "Enter evil: ";
    is >> decepticon._evil;
    std::cout << "Is Decepticon warrior? (1 for Yes, 0 for No): ";
    is >> decepticon._warrior;
    return is;
}

// Overload operator <, > and ==
bool Decepticon::operator>(const Decepticon& other) const
{
    return _evil > other._evil;
}

bool Decepticon::operator<(const Decepticon& other) const
{
    return _evil < other._evil;
}

bool Decepticon::operator==(const Decepticon& other) const
{
    return _evil == other._evil;
}

// Overload operator <, > and == for Autobot
bool Decepticon::operator>(const Autobot& autobot) const
{
    return _evil > autobot.getgood();
}

bool Decepticon::operator<(const Autobot& autobot) const
{
    return _evil < autobot.getgood();
}

bool Decepticon::operator==(const Autobot& autobot) const
{
    return _evil == autobot.getgood();
}

