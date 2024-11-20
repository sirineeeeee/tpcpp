#ifndef TCARD_H
#define TCARD_H
#include <string>
#include "card.h"

class TrainerCard : public Card {
    public:
        TrainerCard(string,string);
        void displayInfo() override;
        string trainerEffect;
};

#endif