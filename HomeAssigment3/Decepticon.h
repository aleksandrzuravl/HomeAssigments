#ifndef DECEPTICON_H
#define DECEPTICON_H

#include "Transformer.h"
#include "Autobot.h"
#include "Decepticon.h"

class Autobot;

// Declare class Decepticon
class Decepticon : public Transformer
{
public:
    Decepticon();
    Decepticon(unsigned int _evil, bool _warrior); // Overload constructor
    ~Decepticon() override;

    // Virtual metods
    bool transform() override;
    bool fire() override;
    bool ultimate() override;

    // Bloodines
    void setevil(bool evil);

    bool getevil() const;

    // Firepower
    void setwarrior(int warrior);

    unsigned int getwarrior() const;

    // This if frends operator
    friend std::ostream& operator<<(std::ostream& os, const Decepticon& decepticon);
    friend std::istream& operator>>(std::istream& is, Decepticon& decepticon);

    // This overload operators
    bool operator>(const Decepticon& other) const;
    bool operator<(const Decepticon& other) const;
    bool operator==(const Decepticon& other) const;

    // This overload operators for oter class
    bool operator>(const Autobot& autobot) const;
    bool operator<(const Autobot& autobot) const;
    bool operator==(const Autobot& autobot) const;


private:
    unsigned int _evil;
    bool _warrior;
};

#endif
