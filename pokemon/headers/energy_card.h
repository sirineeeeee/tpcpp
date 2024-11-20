#ifndef ENCARD_H
#define ENCARD_H
#include <string>
#include "card.h"


class EnergyCard : public Card{
    public:
        EnergyCard(string);
        EnergyCard(string, string);
        void displayInfo() override;
        string energyType;
};

#endif