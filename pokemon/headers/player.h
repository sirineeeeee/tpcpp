#ifndef PLAYER_H
#define PLAYER_H
#include "card.h"
#include "pokemon_card.h"

class Player {
    public:
        Player(string);

        void addCardToBench(Card*);
        void activatePokemonCard(int);
        void attachEnergyCard(int,int);

        void displayBench();
        void displayAction();
        void useTrainer(int);

        void attack(int,int,Player,int);


    private:
        string playerName;
        vector<Card*> benchCards;
        vector<PokemonCard*> actionCards;
};

#endif