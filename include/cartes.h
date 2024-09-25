//
// Created by mathe on 25/11/2021.
//

#ifndef PROJETCLUEDO_GROUPE3F_SAUVETAGE_CARTES_H
#define PROJETCLUEDO_GROUPE3F_SAUVETAGE_CARTES_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include "image.h"
class Carte {
private:
    int m_numero;
    sf::Texture m_image;
    std::string m_type;
    std::string m_nom;
    bool m_distribue;
public:
    Carte(int numero, sf::Texture image, std::string type, std::string nom, bool distribue=false);
    ~Carte();
    int getNumero();
    bool getDistribue();
    void setDistribue(bool distribue);
    void afficherCarte(sf::RenderWindow &window, int ecart);
    std::string getNom();


};
void initialiserPacket(std::vector<Carte> &tableauDeCartes);


#endif //PROJETCLUEDO_GROUPE3F_SAUVETAGE_CARTES_H
