//
// Created by mathe on 24/11/2021.
//

#include "chargementPolice.h"

//fonction qui charge la police
void loadFont(sf::Font &font){
    if(!font.loadFromFile("..assets/fonts/myPolice.ttf")){
        std::cout<< "Erreur chargement police"<< std::endl;
    }
}