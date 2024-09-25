//
// Created by mathe on 25/11/2021.
//

#include "enveloppe.h"


//constructeur
Enveloppe ::Enveloppe( bool enveloppeVide)
        : m_enveloppeVide{enveloppeVide}
{}
//destructeur
Enveloppe::~Enveloppe()=default;


//accesseur
std::vector<Carte> Enveloppe:: getCarte(){
    return m_3Cartes;
}


//methode qui remplie l'enveloppe ,avec les cartes du packet
// préalablement initialisé , et qui indique quelle est remplie a la fin

void Enveloppe:: remplirEnveloppe(std :: vector <Carte> &tableau_de_carte) {
    srand(time(nullptr));
    int x, y, z= 0;
    //carte lieux
    x = rand()%5;
    m_3Cartes.push_back(tableau_de_carte[x]);
    tableau_de_carte[x].setDistribue(true); //cette ligne dit que la carte est maitenant declaré comme deja utilsé

    //carte personnages
    y = rand()% (9 -6 +1) +6 ;
    m_3Cartes.push_back(tableau_de_carte[y]);
    tableau_de_carte[y].setDistribue(true);


    //carte armes
    z= rand()% (13 -10 +1) +10 ;
    m_3Cartes.push_back(tableau_de_carte[z]);
    tableau_de_carte[z].setDistribue(true);

    //on indique que l'enveloppe est plus vide, cond qu'elle est remplie
    m_enveloppeVide = false;
}


//ici methode qui affiche les trois cartes de l'enveloppe, avant on affiche une image d'enveloppe derriere
void Enveloppe ::revelerEnveloppe(sf::RenderWindow &window) {
    if(!m_enveloppeVide){
        sf::Texture image; sf::Sprite test;
        loadImageEnveloppe(image);
        test.setScale(sf::Vector2f(1, 1));
        test.setOrigin(sf::Vector2f(0, 0));
        test.setTexture(image, true);
        test.setPosition(200,160);
        window.draw(test);

        m_3Cartes[1].afficherCarte(window,100);
        m_3Cartes[0].afficherCarte(window,0);
        m_3Cartes[2].afficherCarte(window,200);
    }
}



