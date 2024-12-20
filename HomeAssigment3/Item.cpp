#include "Item.h"

Item::Item() : _just_item(false), _isshield(false), _isgun(false) {}
Item::Item(bool item, bool shield, bool gun) : _just_item(item), _isshield(shield), _isgun(gun) {}

void Item::setisshield(bool shield);
{
    _isshield = isshield;
}

bool Item::getisshield() const;
{
    return _isshield;
}

void Item::setisgun(bool gun);
{
    _isgun = gun;
}

bool Item::getisgun() const;
{
    return _isgun;
}

void Item::setjust_item(bool item);
{
    _just_item = item;
}

bool Item::getjust_item() const;
{
    return _just_item;
}


