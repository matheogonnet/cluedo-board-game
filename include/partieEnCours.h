//
// Created by mathe on 24/11/2021.
//

#ifndef PROJETCLUEDO_GROUPE3F_SAUVETAGE_PARTIEENCOURS_H
#define PROJETCLUEDO_GROUPE3F_SAUVETAGE_PARTIEENCOURS_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include "image.h"
#include "case.h"
#include "initialisation.h"
#include <SFML/Audio.hpp>
#include "joueur.h"
#include "De.h"
#include "menu.h"
#include "enveloppe.h"
void afficherPartieEnCours (sf::Event &event,int nbJoueur, std::vector<Joueur>&ensemble_des_joueurs);

#endif //PROJETCLUEDO_GROUPE3F_SAUVETAGE_PARTIEENCOURS_H
