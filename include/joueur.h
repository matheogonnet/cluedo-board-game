//
// Created by mathe on 24/11/2021.
//

#ifndef PROJETCLUEDO_GROUPE3F_SAUVETAGE_JOUEUR_H
#define PROJETCLUEDO_GROUPE3F_SAUVETAGE_JOUEUR_H
#include <iostream>
#include "chargementPolice.h"
#include "cartes.h"
#include "enveloppe.h"

class Joueur {
protected:

    std:: string  m_pseudo;
    int m_score;
    int m_de;
    int m_niveau;
    int m_numeroIdentification;
    int m_color;
    int m_position_x;
    int m_position_y;
    std::vector<Carte> m_main;
public:
    Joueur(int numero,std :: string pseudo, int niveau=0, int color=0, int score = 0, int position_x = 5, int position_y=7, int de=0);
    ~Joueur();
    void demanderInfosJoueur ();
    void afficherInfosJoueurs ();
    void afficherPion (sf :: RenderWindow &window,int coord_pix_x, int coord_pix_y);
    int get_pos_x();
    int get_pos_y();
    void set_position_x(int x);
    void set_position_y(int y);
    void set_de(int n);
    int get_de() const;
    std::string get_nom();
    void aller_a_droite();
    void aller_a_gauche();
    void aller_en_haut();
    void aller_en_bas();
    void remplir_main(std::vector<Carte>&packet);
    void afficherMain(sf::RenderWindow &window);
    bool accuser(Enveloppe enveloppe);
};
void modifier_position_joueur(std::vector<Joueur>&ensemble_des_joueurs, int i, int x, int y);
void remplir_main_des_joueurs(std::vector<Joueur>&ensemble_des_joueurs, int nbJoueur, std::vector<Carte>&packet);
void initialiser_position_joueurs(std::vector<Joueur>&ensenble_des_joueurs, int nbJoueur);
#endif //PROJETCLUEDO_GROUPE3F_SAUVETAGE_JOUEUR_H
