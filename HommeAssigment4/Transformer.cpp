#include <iostream>
#include "Transformer.h"

// Class constructor implementation
Transformer::Transformer() : _ammo(5), _level(15), _strength(100), _fuel(20), _weapon(10, true) {}

// Class deconstructor implementation
Transformer::~Transformer() {}

// Function fire implementation
bool Transformer::fire()
{
    if (_item.getisgun() &&  _ammo > 0) 
    {
        _ammo--// Transformer shot
        std::cout << "-> Transformer fire from gun babax..." << std::endl << std::endl;
        std::cout << "Ammo after firing: " << _ammo << std::endl << std::endl;
        return true;
    }
    else
    {
        std::cout << "-> Can't fire" << std::endl;
        return false;
    }
}

// Ammo ( getter and setter )
void Transformer::setAmmo(unsigned int ammo)
{
    _ammo = ammo;
}

unsigned int Transformer::getAmmo()
{
    return _ammo;
}

// Level ( getter and setter )
void Transformer::setLevel(unsigned int level)
{
    _level = level;
}

unsigned int Transformer::getLevel()
{
    return _level;
}

// Fuel ( getter and setter )
void Transformer::setFuel(unsigned int fuel)
{
    _fuel = fuel;
}

unsigned int Transformer::getFuel()
{
    return _fuel;
}

// Function turn implementation
bool Transformer::turn(Direction dir)
{
    if (_fuel == 0)
    {
        std::cout << "-> fuel is lost" << std::endl << std::endl;
        return false;
    }
    _fuel--; // Turning
    switch (dir)
    {
    case Direction::Left:
        std::cout << "-> Turning left.." << std::endl << std::endl;
        break;
    case Direction::Right:
        std::cout << "-> Turning right.." << std::endl << std::endl;
        break;
    case Direction::Up:
        std::cout << "-> Turning up.." << std::endl << std::endl;
        break;
    case Direction::Down:
        std::cout << "-> Turning down.." << std::endl << std::endl;
        break;
    }
    std::cout << "-> Left fuel: " << _fuel << std::endl << std::endl;
    return true;
}

// Mini function for transformer implementation

// Ultimate for Transform ( implementation associative class )
bool Transformer::ultimate()
{
    if (_item.getisgun() && _ammo >= 50)
    {
        std::cout << "-> BIG BOOM BABAX ..." << std::endl;
        _ammo = _ammo - 50
        std::cout << "-> Left ammo: " << _ammo << std::endl << std::endl;
    }
    else if (_item.getisshield() && _strenght >= 25)
    {
        std::cout << "-> BIG SHIELD ACTIVATED ..." << std::endl;
        _streight = _streight - 25
        std::cout << "-> Left streight: " << _streight << std::endl << std::endl;
    }
    else if (_item.getjust_item())
    {
        std::cout << "-> ITEM POWER ACTIVATED ..." << std::endl;
    }
    else
    {
        std::cout << "-> Can't ult" << std::endl << std::endl;
        return false;
    }
    return true;
}

// Transformation for Transform
bool Transformer::transform()
{
    if (_level < 5)
    {
        std::cout << "-> Not enogh level" << std::endl << std::endl;
        return false;
    }
    std::cout << "-> Transforming..." << std::endl << std::endl;
    return true;
}

// Moving for Transform
bool Transformer::move()
{
    if (_fuel == 0)
    {
        std::cout << "-> Fuel is lost" << std::endl << std::endl;
        return false;
    }
    _fuel--;
    std::cout << "-> Moving..." << std::endl << std::endl;
    std::cout << "-> Left fuel: " << _fuel << std::endl << std::endl;
    return true;
}

// Overload operator <, > and ==
bool Transformer::operator>(const Transformer& other) const
{
    return _level > other._level;
}

bool Transformer::operator<(const Transformer& other) const
{
    return _level < other._level;
}

bool Transformer::operator==(const Transformer& other) const
{
    return _level == other._level;
}
