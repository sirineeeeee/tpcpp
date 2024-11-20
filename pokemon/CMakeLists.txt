cmake_minimum_required(VERSION 3.26)
project(pokemon)

set(CMAKE_CXX_STANDARD 20)

add_executable(pokemon main.cpp
        headers/card.h
        card.cpp
        headers/energy_card.h
        energy_card.cpp
        headers/pokemon_card.h
        pokemon_card.cpp
        headers/trainer_card.h
        trainer_card.cpp
        headers/player.h
        player.cpp        
        )
