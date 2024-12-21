#ifndef TRANSFORMER_H
#define TRANSFORMER_H

#include "Item.h"

// class for indicate direction
enum class Direction { Left, Right, Up, Down};


class Transformer
{
public:
    Transformer();
    Transformer(unsigned int _ammo, unsigned int _level, unsigned int _strength, unsigned int _fuel, Weapon _weapon);
    virtual ~Transformer();

    virtual bool move();
    virtual bool turn(Direction dir);
    virtual bool fire();
    virtual bool ultimate();
    virtual bool transform();

    void setAmmo(unsigned int ammo);

    unsigned int getAmmo();

    void setLevel(unsigned int level);

    unsigned int getLevel();

    void setFuel(unsigned int fuel);

    unsigned int getFuel();

    friend std::ostream& operator<<(std::ostream& os, const Transformer& transformer);
    friend std::istream& operator>>(std::istream& is, Transformer& transformer);

    // overload operators
    bool operator>(const Transformer& other) const;
    bool operator<(const Transformer& other) const;
    bool operator==(const Transformer& other) const;

protected:
    unsigned int _ammo;
    unsigned int _level;
    unsigned int _strength;
    unsigned int _fuel;
    Item _item;  //composition class 
};

#endif
