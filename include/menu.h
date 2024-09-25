//
// Created by mathe on 24/11/2021.
//

#ifndef PROJETCLUEDO_GROUPE3F_SAUVETAGE_MENU_H
#define PROJETCLUEDO_GROUPE3F_SAUVETAGE_MENU_H

#include <SFML/Graphics.hpp>
#include "joueur.h"

void afficherMenu(sf::Event &event, int &nbJoueur, std::vector<Joueur> &ensemble_des_joueurs);
sf::RectangleShape rectangle(int gap);
void afficherplateau (sf :: Texture &image, sf::RenderWindow &windowww);
sf::RectangleShape dessinerTourRectangle(int gap);
sf::Text titre(sf::Font &font, std::string texte, int position_x, int position_y, int size, sf::Color color);

#endif //PROJETCLUEDO_GROUPE3F_SAUVETAGE_MENU_H
