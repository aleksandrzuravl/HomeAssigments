#ifndef AUTOBOT_H
#define AUTOBOT_H

#include "Transformer.h"
#include "Autobot.h"
#include "Decepticon.h"

class Decepticon;
class Dinobot;

// Declare class Autobot
class Autobot : public Transformer
{
public:
    Autobot();
    Autobot(unsigned int _good, bool _helping); // Overload constructor
    ~Autobot() override;

    // Virtual metods
    bool transform() override;
    bool fire() override;
    bool ultimate() override;

    // Helping
    void setHelping(bool help);

    bool getHelping() const;

    // Firepower
    void setgood(int good);

    unsigned int getdood() const;

    // This if frends operator
    friend std::ostream& operator<<(std::ostream& os, const Autobot& autobot);
    friend std::istream& operator>>(std::istream& is, Autobot& autobot);

    // This overload operators
    bool operator>(const Autobot& other) const;
    bool operator<(const Autobot& other) const;
    bool operator==(const Autobot& other) const;

    // This overload operators for other class
    bool operator>(const Decepticon& decepticon) const;
    bool operator<(const Decepticon& decepticon) const;
    bool operator==(const Decepticon& decepticon) const;

private:
    unsigned int _good;
    bool _helping;
};

#endif
