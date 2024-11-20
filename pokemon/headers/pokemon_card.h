#ifndef POKCARD_H
#define POKCARD_H
#include <string>
#include "card.h"


class PokemonCard : public Card{
    public:
        PokemonCard(string,string,string,int,int,int,string,int,int,string,int);
        void displayInfo() override;
        tuple<int,int,string,int> attacks[2];
        int hp;
        int maxHP;
    private:
        string pokemonType;
        string familyName;
        int evolutionLevel;


        
};

#endif