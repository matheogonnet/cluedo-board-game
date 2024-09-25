//
// Created by mathe on 25/11/2021.
//

#ifndef PROJETCLUEDO_GROUPE3F_SAUVETAGE_ENVELOPPE_H
#define PROJETCLUEDO_GROUPE3F_SAUVETAGE_ENVELOPPE_H
#include <iostream>
#include "cartes.h"
#include "image.h"

class Enveloppe {
protected :
    std::vector <Carte> m_3Cartes;
    bool m_enveloppeVide;

public :
    Enveloppe (bool enveloppeVide= true);
    ~Enveloppe();
    void remplirEnveloppe (std :: vector <Carte> &tableau_de_carte);
    void revelerEnveloppe (sf::RenderWindow &window);
    std::vector<Carte> getCarte();
};

#endif //PROJETCLUEDO_GROUPE3F_SAUVETAGE_ENVELOPPE_H
