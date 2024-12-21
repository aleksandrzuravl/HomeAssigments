#ifndef ITEM_H
#define ITEM_H


class Item
{
public:
    Item();
    Item(bool isshield , bool isgun, bool just_item); // Overload constructor

    void setisshield(bool hav);

    bool getisshield() const;
    
    void setisgun(bool hav);

    bool getisgun() const;
    
    void setjust_item(bool hav);

    bool getjust_item() const;

private:
    bool _isshield;
    bool _is_gun;
    bool _just_item
};

#endif
