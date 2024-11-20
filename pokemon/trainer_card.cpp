#include "headers/trainer_card.h"

TrainerCard::TrainerCard(string _trainerName,string _trainerEffect):
Card(_trainerName), 
trainerEffect(_trainerEffect)
{}


void TrainerCard::displayInfo(){
    cout << "Trainer Card - Name : " << cardName << ", Effect: " << trainerEffect <<endl ;
}