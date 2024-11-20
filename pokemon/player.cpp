#include "headers/player.h"
#include "headers/trainer_card.h"
#include "headers/energy_card.h"

Player::Player(string _playerName):
playerName(_playerName),
benchCards({}),
actionCards({})
{}

void Player::displayBench(){
    cout << "Bench cards for Player " << playerName << " :" << endl;
    for(Card * c : benchCards) 
        c->displayInfo();
}

void Player::displayAction(){
    cout << "Action cards for Player " << playerName << " :" << endl;
    for(PokemonCard * a : actionCards) 
        a->displayInfo();
}

void Player::attachEnergyCard(int energy_i, int pokemon_i){
    EnergyCard* energyCard = dynamic_cast<EnergyCard*>(benchCards[energy_i]);
    PokemonCard* pokemonCard = actionCards[pokemon_i];

    get<1>(pokemonCard->attacks[0])+=1;
    get<1>(pokemonCard->attacks[1])+=1;

    cout << playerName << " is attaching a Energy Card of type " << energyCard->energyType<<" to the Pokémon " << pokemonCard->cardName << endl;

    benchCards.erase(benchCards.begin() + energy_i);
}

void Player::addCardToBench(Card* c){
    benchCards.push_back(c);
}

void Player::activatePokemonCard(int i){
    actionCards.push_back((PokemonCard *)benchCards[i]);
    cout << playerName << " is activating a Pokémon Card: " << benchCards[i]->cardName <<endl;
    benchCards.erase(benchCards.begin() + i);
}

void Player::useTrainer(int trainer_id){
    TrainerCard* trainerCard = dynamic_cast<TrainerCard*>(benchCards[trainer_id]);

    for(PokemonCard * a : actionCards) 
        a->hp = a->maxHP;

    cout << playerName << " is using the Trainer Card to \"" << trainerCard->trainerEffect << "\"";
    benchCards.erase(benchCards.begin() + trainer_id);
}

void Player::attack(int pokemon_id, int attack_id,Player opponent,int opp_pokemon_id){
    cout << playerName << " attacking " << opponent.playerName << "’s Pokémon " << opponent.actionCards[opp_pokemon_id]->cardName << " with the Pokémon " << actionCards[pokemon_id]->cardName << " with its attack : " << get<2>(actionCards[pokemon_id]->attacks[attack_id]);
    cout << endl << "Reducing " << get<3>(actionCards[pokemon_id]->attacks[attack_id]) << " from " << opponent.playerName << "’s Pokémon HP" ;

    if (get<1>(actionCards[pokemon_id]->attacks[attack_id])>=get<0>(actionCards[pokemon_id]->attacks[attack_id])){
        opponent.actionCards[opp_pokemon_id]->hp -= get<3>(actionCards[pokemon_id]->attacks[attack_id]);
        get<1>(actionCards[pokemon_id]->attacks[0])-=get<0>(actionCards[pokemon_id]->attacks[attack_id]);
        get<1>(actionCards[pokemon_id]->attacks[1])-=get<0>(actionCards[pokemon_id]->attacks[attack_id]);
    }

    if (opponent.actionCards[opp_pokemon_id]->hp > 0) cout << endl << "Pokémon " << opponent.actionCards[opp_pokemon_id]->cardName << " is still alive"<<endl;
    else cout << endl << "Pokémon " << opponent.actionCards[opp_pokemon_id]->cardName << " is KO";
}
