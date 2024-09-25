//
// Created by mathe on 24/11/2021.
//

#ifndef PROJETCLUEDO_GROUPE3F_SAUVETAGE_DE_H
#define PROJETCLUEDO_GROUPE3F_SAUVETAGE_DE_H
#include"joueur.h"
#include <SFML/Graphics.hpp>



typedef struct {
    int m_face;
    sf::Texture m_image;
}De;

void initialiserDe(std::vector<De> &de);
void lancerDe(std::vector<De> de, sf::RenderWindow &window,std::vector<Joueur>&ensemble_des_joueurs, int i);
void afficher_image_de(sf::RenderWindow &window, const std::vector<De>de, int face);




#endif //PROJETCLUEDO_GROUPE3F_SAUVETAGE_DE_H
