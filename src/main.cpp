#include <SFML/Graphics.hpp>
#include "menu.h"
#include "partieEnCours.h"

int main() {
    // Déclaration de la fenêtre et des variables

    // Nombre de joueurs, initialisé à 0
    int player_count = 0;

    // Ensemble des joueurs : tableau de joueurs (vecteur d'objets de type Joueur)
    std::vector<Joueur> player_list;

    // Variables pour gérer les événements SFML et l'horloge
    sf::Event event_menu{}, event_game{};
    sf::Clock game_clock;

    // Afficher le menu et obtenir les informations du nombre de joueurs et des joueurs
    afficherMenu(event_menu, player_count, player_list);

    // Afficher l'état de la partie en cours après le menu
    afficherPartieEnCours(event_game, player_count, player_list);

    return 0;
}
