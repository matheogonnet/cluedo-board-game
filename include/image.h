//
// Created by mathe on 24/11/2021.
//

#ifndef PROJETCLUEDO_GROUPE3F_SAUVETAGE_IMAGE_H
#define PROJETCLUEDO_GROUPE3F_SAUVETAGE_IMAGE_H
#include <iostream>
#include <SFML/Graphics.hpp>

void loadPlateau(sf::Texture &imagefond);
void loadimageouverture(sf::Texture &imagefond);
void afficherImageDebut (sf :: Texture &image, sf::RenderWindow &windowww);
void loadimageouverture(sf::Texture &imagefond,const std::string& filename);
void loadImageEnveloppe(sf::Texture &imagefond);
#endif //PROJETCLUEDO_GROUPE3F_SAUVETAGE_IMAGE_H
