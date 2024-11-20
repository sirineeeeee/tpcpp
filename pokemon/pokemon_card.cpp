#include "headers/pokemon_card.h"

PokemonCard::PokemonCard(string _pokemonName,string _pokeType,string _famName,int _evLevel,int _maxHP,int _energyCost1,string _attackDesc1,int _damageAttack1,int _energyCost2,string _attackDesc2,int _damageAttack2):
Card(_pokemonName), 
pokemonType(_pokeType),
familyName(_famName),
evolutionLevel(_evLevel),
maxHP(_maxHP),
hp(_maxHP)
{
    attacks[0] = make_tuple(_energyCost1,0,_attackDesc1,_damageAttack1);
    attacks[1] = make_tuple(_energyCost2,0,_attackDesc2,_damageAttack2);
}

void PokemonCard::displayInfo(){
    cout << "Pokémon Card - Name : " << cardName << ", Type: " << pokemonType << " , Evolution Level: " << to_string(evolutionLevel) << " of the family " << familyName << ", HP: " << to_string(hp) ;
    cout <<endl;
    cout << "Attacks :"<<endl;
    for (int i = 0; i < 2; ++i) {
        cout << "Attack #" + to_string(i) << endl;
        cout << "Attack cost: " << get<0>(attacks[i]) << endl ;
        cout << "Attack current energy storage: " << get<1>(attacks[i]) << endl;
        cout << "Attack description: " << get<2>(attacks[i]) << endl ;
        cout << "Attack damage: " << get<3>(attacks[i]) <<endl;
    }
        
}