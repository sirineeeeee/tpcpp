#include "headers/energy_card.h"

EnergyCard::EnergyCard(string _energyType):
Card("Energy"),
energyType(_energyType)
{}

EnergyCard::EnergyCard(string _cardName,string _energyType):
Card(_cardName),
energyType(_energyType)
{}

void EnergyCard::displayInfo(){
    cout << "Energy Card - Name : " << cardName << ", Type: " << energyType <<endl;
}

