#include <iostream>
#include "Autobot.h"
#include "Decepticon.h"
#include "Dinobot.h"
#include "Ability.h"

// Constructor Autobot
Autobot::Autobot() : Transformer(), _good(100), _helping(true)
{
    std::cout << "-> Autobot created" << std::endl;
}

Autobot::Autobot(unsigned int good, bool helping)
    : Transformer(), _good(good), _helping(helping) {}

// Deconstructor Autobot
Autobot::~Autobot()
{
    std::cout << "-> Autobot destroued" << std::endl;
}

// Setters and getters for autobot
void Autobot::setHelping(bool help)
{
    _helping = help;
}

bool Autobot::getHelping() const
{
    return _helping;
}

void Autobot::setgood(int good)
{
    _good = good;
}

unsigned int Autobot::getgood() const
{
    return _good;
}

// Overload operator << and >>
std::ostream& operator<<(std::ostream& os, const Autobot& autobot)
{
    os << "Autobot. good: " << autobot._good << ", helping: " << (autobot._helping ? "Yes" : "No");
    return os;
}

std::istream& operator>>(std::istream& is, Autobot& autobot)
{
    std::cout << "Enter good: ";
    is >> autobot._good;
    std::cout << "Is Autobot helping? (1 for Yes, 0 for No): ";
    is >> autobot._helping;
    return is;
}

// Overload operator <, > and ==
bool Autobot::operator>(const Autobot& other) const
{
    return _good > other._good;
}

bool Autobot::operator<(const Autobot& other) const
{
    return _good < other._good;
}

bool Autobot::operator==(const Autobot& other) const
{
    return _good == other._good;
}

// Overload operator <, > and == for Decepticon
bool Autobot::operator>(const Decepticon& decepticon) const
{
    return _good > decepticon.getevil();
}

bool Autobot::operator<(const Decepticon& decepticon) const
{
    return _good < decepticon.getevil();
}

bool Autobot::operator==(const Decepticon& decepticon) const
{
    return _good == decepticon.getevil();
}

