#ifndef CARD_H
#define CARD_H
#include <iostream>
using namespace std;
#include <string>

class Card {
    public:
        Card(string);
        virtual ~Card();
        virtual void displayInfo();
        string cardName;
};

#endif