//
// Created by mathe on 24/11/2021.
//

#include "image.h"



void loadPlateau(sf::Texture &imagefond){
    if(!imagefond.loadFromFile("../assets/images/Image Plateau/image_plateau.png")){
        std:: cout << "erreur de chargement image" << std :: endl;
    }
}
void loadimageouverture(sf::Texture &imagefond){
    if(!imagefond.loadFromFile("../assets/images/image ouverture/ouverture.jpg")){
        std:: cout << "erreur de chargement image" << std :: endl;
    }
}


void afficherImageDebut (sf :: Texture &image, sf::RenderWindow &windowww){
    loadimageouverture(image);
    sf::Sprite test;
    test.setScale(sf::Vector2f(1, 1));
    test.setOrigin(sf::Vector2f(0, 0));
    test.setTexture(image, true);
    windowww.draw(test);
}

void loadimageouverture(sf::Texture &imagefond,const std::string& nom){
    if(!imagefond.loadFromFile(nom)){
        std:: cout << "erreur de chargement image" << std :: endl;
    }
}
void loadImageEnveloppe(sf::Texture &imagefond){
    if(!imagefond.loadFromFile("../assets/images/envelopppe.png")){
        std:: cout << "erreur de chargement image enveloppe" << std :: endl;
    }
}