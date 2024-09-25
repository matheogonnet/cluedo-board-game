//
// Created by mathe on 25/11/2021.
//

#include "cartes.h"


//constructeur
Carte::Carte(int numero, sf::Texture image, std::string type, std::string nom, bool distribue)
        : m_numero{numero}, m_nom{nom}, m_image{image}, m_type{type}, m_distribue{distribue}

{}
//destructeur
Carte::~Carte()=default;

//accesseur et mutateur
int Carte ::getNumero() {
    return m_numero;
}

bool Carte::getDistribue(){
    return m_distribue;
}
void Carte::setDistribue(bool distribue) {
    m_distribue=distribue;
}
std::string Carte::getNom(){
    return m_nom;
}





//fonction qui initialise le packet avec toutes les cartes
void initialiserPacket(std::vector<Carte> &tableauDeCartes){
    //carte0
    sf::Texture image0;
    loadimageouverture(image0, "../assets/images/cartes_lieux/archives.png");
    Carte carte0{0, image0, "lieu", "archives"};
    tableauDeCartes.push_back(carte0);
    //carte1
    sf::Texture image1;
    loadimageouverture(image1, "../assets/images/cartes_lieux/billeterie.png");
    Carte carte1{1, image1, "lieu", "billeterie"};
    tableauDeCartes.push_back(carte1);
    //carte2
    sf::Texture image2;
    loadimageouverture(image2, "../assets/images/cartes_lieux/boutique.png");
    Carte carte2{2, image2, "lieu", "boutique"};
    tableauDeCartes.push_back(carte2);
    //carte3
    sf::Texture image3;
    loadimageouverture(image3, "../assets/images/cartes_lieux/salle_exposition1.png");
    Carte carte3{3, image3, "lieu", "salle_exposition1"};
    tableauDeCartes.push_back(carte3);
    //carte4
    sf::Texture image4;
    loadimageouverture(image4, "../assets/images/cartes_lieux/salle_exposition2.png");
    Carte carte4{4, image4, "lieu", "salle_exposition2"};
    tableauDeCartes.push_back(carte4);
    //carte5
    sf::Texture image5;
    loadimageouverture(image5, "../assets/images/cartes_lieux/toilettes.png");
    Carte carte5{5, image5, "lieu", "toilettes"};
    tableauDeCartes.push_back(carte5);
    //carte6
    sf::Texture image6;
    loadimageouverture(image6, "../assets/images/cartes_personnages/femme_de_menage.png");
    Carte carte6{6, image6, "personnage", "femme_de_menage"};
    tableauDeCartes.push_back(carte6);
    //carte7
    sf::Texture image7;
    loadimageouverture(image7, "../assets/images/cartes_personnages/gardien.png");
    Carte carte7{7, image7, "personnage", "gardien"};
    tableauDeCartes.push_back(carte7);
    //carte8
    sf::Texture image8;
    loadimageouverture(image8, "../assets/images/cartes_personnages/guide_touristique.png");
    Carte carte8{8, image8, "personnage", "guide_touristique"};
    tableauDeCartes.push_back(carte8);
    //carte9
    sf::Texture image9;
    loadimageouverture(image9, "../assets/images/cartes_personnages/touriste.png");
    Carte carte9{9, image9, "personnage", "touriste"};
    tableauDeCartes.push_back(carte9);
    //carte10
    sf::Texture image10;
    loadimageouverture(image10, "../assets/images/cartes_armes/corde.png");
    Carte carte10{10, image10, "arme", "corde"};
    tableauDeCartes.push_back(carte10);
    //carte11
    sf::Texture image11;
    loadimageouverture(image11, "../assets/images/cartes_armes/coupe_verre.png");
    Carte carte11{11, image11, "arme", "coupe_verre"};
    tableauDeCartes.push_back(carte11);
    //carte12
    sf::Texture image12;
    loadimageouverture(image12, "../assets/images/cartes_armes/marteau.png");
    Carte carte12{12, image12, "arme", "marteau"};
    tableauDeCartes.push_back(carte12);
    //carte13
    sf::Texture image13;
    loadimageouverture(image13, "../assets/images/cartes_armes/corde.png");
    Carte carte13{13, image13, "arme", "corde"};
    tableauDeCartes.push_back(carte13);


}


//cette methode permet d'affficher la carte à l'ecran
void Carte::afficherCarte(sf::RenderWindow &window, int ecart){
    sf::Sprite test;
    test.setScale(sf::Vector2f(1, 1));
    test.setOrigin(sf::Vector2f(0, 0));
    test.setPosition(300+ecart,200);
    test.setTexture(m_image, true);
    window.draw(test);
}

