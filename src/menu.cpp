
//
// Created by mathe on 24/11/2021.
//

#include "menu.h"
#include "initialisation.h"
#include <SFML/Audio.hpp>

/**
 * Fonction qui initialise un rectangle pour le sous-menu dans le menu principal.
 */
sf::RectangleShape rectangle(const int gap) {
    sf::RectangleShape rect_shape(sf::Vector2f(400, 80));
    rect_shape.setPosition(300, 150 + static_cast<float>(gap));
    rect_shape.setFillColor(sf::Color::White);
    return rect_shape;
}

/**
 * Fonction qui dessine un contour rouge autour du rectangle du sous-menu lorsque la souris le survole.
 */
sf::RectangleShape dessinerTourRectangle(const int gap) {
    sf::RectangleShape rect_shape(sf::Vector2f(400, 80));
    rect_shape.setPosition(300, 150 + static_cast<float>(gap));
    rect_shape.setFillColor(sf::Color::Transparent);
    rect_shape.setOutlineThickness(6);
    rect_shape.setOutlineColor(sf::Color::Red);
    return rect_shape;
}

/**
 * Affiche le contour rouge autour du sous-menu lorsque la souris le survole.
 */
void afficherRectangle(const int pos_x, const int pos_y, sf::RenderWindow &window) {
    if (pos_x >= 300 && pos_x <= 700 && pos_y >= 150 && pos_y <= 230) {
        window.draw(dessinerTourRectangle(0));
        window.display();
    }
    if (pos_x >= 300 && pos_x <= 700 && pos_y >= 250 && pos_y <= 310) {
        window.draw(dessinerTourRectangle(100));
        window.display();
    }
    if (pos_x >= 300 && pos_x <= 700 && pos_y >= 350 && pos_y <= 430) {
        window.draw(dessinerTourRectangle(200));
        window.display();
    }
    if (pos_x >= 300 && pos_x <= 700 && pos_y >= 450 && pos_y <= 530) {
        window.draw(dessinerTourRectangle(300));
        window.display();
    }
}

/**
 * Affiche le contour rouge autour des options du nombre de joueurs lorsque la souris les survole.
 */
void afficherRectangleJoueur(const int pos_x, const int pos_y, sf::RenderWindow &window) {
    if (pos_x >= 300 && pos_x <= 700 && pos_y >= 310 && pos_y <= 360) {
        window.draw(dessinerTourRectangle(150));
        window.display();
    }
    if (pos_x >= 300 && pos_x <= 700 && pos_y >= 410 && pos_y <= 460) {
        window.draw(dessinerTourRectangle(250));
        window.display();
    }
    if (pos_x >= 300 && pos_x <= 700 && pos_y >= 510 && pos_y <= 560) {
        window.draw(dessinerTourRectangle(350));
        window.display();
    }
}

/**
 * Crée et retourne un objet sf::Text avec les propriétés spécifiées.
 */
sf::Text titre(sf::Font &font, std::string text, const int position_x, const int position_y, int size, sf::Color color) {
    sf::Text title;
    loadFont(font);
    title.setFont(font);
    title.setString(text);
    title.setCharacterSize(size);
    title.setFillColor(color);
    title.setPosition(static_cast<float>(position_x), static_cast<float>(position_y));
    return title;
}

/**
 * Affiche le menu principal avec ses options sur la fenêtre donnée.
 */
void afficherBaseMenu(sf::RenderWindow &window, sf::Font font) {
    window.clear(sf::Color(117, 137, 103));
    window.draw(titre(font, "Bienvenue dans le cluedo", 260, 50, 50, sf::Color::White));
    // Premier rectangle
    window.draw(rectangle(0));
    window.draw(titre(font, "Nouvelle partie", 340, 160, 50, sf::Color::Black));

    // Deuxième rectangle
    window.draw(rectangle(100));
    window.draw(titre(font, "Sauvegarde", 390, 260, 50, sf::Color::Black));

    // Troisième rectangle
    window.draw(rectangle(200));
    window.draw(titre(font, "Regles", 425, 360, 50, sf::Color::Black));

    // Quatrième rectangle
    window.draw(rectangle(300));
    window.draw(titre(font, "Quitter", 420, 460, 50, sf::Color::Black));
}

/**
 * Affiche le sous-menu pour demander le nombre de joueurs.
 */
void afficherBaseDmdJoueur(sf::RenderWindow &window, sf::Font font) {
    window.clear(sf::Color(117, 137, 103));
    window.draw(titre(font, "Combien de joueurs ?", 260, 50, 50, sf::Color::White));
    // Premier rectangle
    window.draw(rectangle(150));
    window.draw(titre(font, "2 joueurs", 340, 310, 50, sf::Color::Black));

    // Deuxième rectangle
    window.draw(rectangle(250));
    window.draw(titre(font, "3 joueurs", 390, 410, 50, sf::Color::Black));

    // Troisième rectangle
    window.draw(rectangle(350));
    window.draw(titre(font, "4 joueurs", 425, 510, 50, sf::Color::Black));

    // Quatrième rectangle
    window.draw(rectangle(450));
    window.draw(titre(font, "Aucun", 420, 610, 50, sf::Color::Black));
}

/**
 * Récupère le nombre de joueurs sélectionné par l'utilisateur.
 * Retourne 1 si un nombre de joueurs a été sélectionné, 0 sinon.
 */
int combiendeJoueurs(sf::Event &event, int &number_of_players, int pos_x, int pos_y) {
    if (event.type == sf::Event::MouseButtonPressed && pos_x >= 300 && pos_x <= 700 && pos_y >= 310 && pos_y <= 360) {
        number_of_players = 2;
        return 1;
    }

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && pos_x >= 300 && pos_x <= 700 && pos_y >= 410 && pos_y <= 460) {
        number_of_players = 3;
        return 1;
    }
    // 4 joueurs max
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && pos_x >= 300 && pos_x <= 700 && pos_y >= 510 && pos_y <= 560) {
        number_of_players = 4;
        return 1;
    }
    return 0;
}

/**
 * Vérifie si la souris est sur le bouton "Nouvelle Partie".
 * Retourne 1 si oui, 0 sinon.
 */
int sourisDansNouvellePartie(int pos_x, int pos_y, sf::RenderWindow &window, sf::Font &font) {
    if (pos_x >= 300 && pos_x <= 700 && pos_y >= 150 && pos_y <= 230) {
        return 1;
    } else
        return 0;
}

/**
 * Vérifie si la souris est sur le bouton "Aide".
 * Retourne 1 si oui, 0 sinon.
 */
int sourisAide(int pos_x, int pos_y, sf::RenderWindow &window, sf::Font &font) {
    if (pos_x >= 300 && pos_x <= 700 && pos_y >= 350 && pos_y <= 430) {
        return 1;
    }
    return 0;
}

/**
 * Vérifie si la souris est sur le bouton "Quitter le Jeu".
 * Retourne 1 si oui, 0 sinon.
 */
int sourisquitterJEU(int pos_x, int pos_y, sf::RenderWindow &window, sf::Font &font) {
    if (pos_x >= 300 && pos_x <= 700 && pos_y >= 450 && pos_y <= 530) {
        return 1;
    }
    return 0;
}

/**
 * Affiche l'écran d'aide avec les règles du jeu.
 */
void afficherAide(sf::RenderWindow &window, sf::Font font, int pos_x, int pos_y) {
    window.clear(sf::Color(117, 137, 103));
    sf::RectangleShape rect_shape(sf::Vector2f(300, 80));

    window.draw(titre(font, "Retour Menu", 10, 525, 50, sf::Color::White));
    window.draw(titre(font, "Regles du jeu", 450, 50, 50, sf::Color::White));
    window.draw(titre(font, "L'enveloppe est remplie par un voleur, un outil de vol et la piece ", 10, 200, 30, sf::Color::White));
    window.draw(titre(font, "où est cachée la Joconde. Les cartes sont ensuite réparties entre les joueurs", 10, 240, 30, sf::Color::White));
    window.draw(titre(font, "Munissez-vous d'un bloc-notes et grâce à vos cartes trouvez l'énigme", 10, 280, 30, sf::Color::White));
    window.draw(titre(font, "Ramenez-nous la Joconde. Bonne chance !", 10, 335, 40, sf::Color::White));
}

/**
 * Dessine le contour rouge autour du bouton d'aide.
 */
sf::RectangleShape dessinerTourRectangleBoutonAide() {
    sf::RectangleShape rect_shape(sf::Vector2f(300, 80));
    rect_shape.setPosition(6, 514);
    rect_shape.setFillColor(sf::Color::Transparent);
    rect_shape.setOutlineThickness(6);
    rect_shape.setOutlineColor(sf::Color::Red);
    return rect_shape;
}

/**
 * Affiche le contour rouge autour du bouton "Retour Menu" lorsque la souris le survole.
 */
void sortirDeAide(int pos_x, int pos_y, sf::RenderWindow &window) {
    if (pos_x >= 0 && pos_x <= 300 && pos_y >= 520 && pos_y <= 600) {
        window.draw(dessinerTourRectangleBoutonAide());
        window.display();
    }
}

/**
 * Vérifie si la souris est sur le bouton "Retour Menu" dans l'écran d'aide.
 * Retourne 1 si oui, 0 sinon.
 */
int sourisBoutonRetourAide(int pos_x, int pos_y, sf::RenderWindow &window, sf::Font &font) {
    if (pos_x >= 0 && pos_x <= 400 && pos_y >= 525 && pos_y <= 600) {
        return 1;
    }
    return 0;
}

/**
 * Affiche un message demandant à l'utilisateur de saisir les pseudos dans la console.
 */
void afficherMessageSaisiPseudo(sf::RenderWindow &window, sf::Font font) {
    window.clear(sf::Color(117, 137, 103));
    window.draw(titre(font, "Saisissez les pseudos dans la console !", 200, 275, 50, sf::Color::White));
    window.draw(titre(font, "Appuyez sur Esc pour aller dans la console", 210, 325, 35, sf::Color::White));
}

/**
 * Gère les événements de la fenêtre en fonction du niveau actuel.
 */
void eventList(sf::RenderWindow &window, sf::Event event, int &level, sf::Font font, int &number_of_players) {
    if (event.type == sf::Event::Closed) {
        window.close();
    }
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Space && level == OUVERTURE) {
            level = MENU;
        }
        if (event.key.code == sf::Keyboard::Escape && level == DEMANDE_NB_JOUEUR) {
            level = SAISIE_DES_JOUEURS;
            window.close();
        }
        if (event.key.code == sf::Keyboard::Escape && level == MENU) {
            window.close();
            level = QUITTER_LE_JEU;
        }
    }
    if (event.type == sf::Event::MouseMoved) {
        if (level == MENU) {
            afficherRectangle(event.mouseMove.x, event.mouseMove.y, window);
        }
        if (level == NOUVELLEPARTIE) {
            afficherRectangleJoueur(event.mouseMove.x, event.mouseMove.y, window);
        }
        if (level == AIDE) {
            sortirDeAide(event.mouseMove.x, event.mouseMove.y, window);
        }
    }

    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            if (sourisDansNouvellePartie(event.mouseButton.x, event.mouseButton.y, window, font) == 1 && level == MENU) {
                level = NOUVELLEPARTIE;
            }
            if (sourisAide(event.mouseButton.x, event.mouseButton.y, window, font) && level == MENU) {
                level = AIDE;
            }
            if (sourisquitterJEU(event.mouseButton.x, event.mouseButton.y, window, font) && level == MENU) {
                level = QUITTER_LE_JEU;
            }
            if (combiendeJoueurs(event, number_of_players, event.mouseButton.x, event.mouseButton.y) && level == NOUVELLEPARTIE) {
                level = DEMANDE_NB_JOUEUR;
            }
            if (sourisBoutonRetourAide(event.mouseButton.x, event.mouseButton.y, window, font) && level == AIDE) {
                level = MENU;
            }
        }
    }
}

/**
 * Affiche le menu principal et gère le processus jusqu'à l'initialisation des joueurs.
 */
void afficherMenu(sf::Event &event, int &number_of_players, std::vector<Joueur> &player_list) {
    sf::RenderWindow window(sf::VideoMode(1000, 600), "Cluedo au musée");
    window.setPosition(sf::Vector2i(0, 0));
    sf::Texture board_image;
    sf::Texture start_image;
    int level = 0;
    sf::Music music;
    music.openFromFile("..assets/sounds/le-printemps-vivaldi.ogg");
    music.play();
    level = OUVERTURE;

    while (window.isOpen()) {
        sf::Font font;
        while (window.pollEvent(event)) {
            eventList(window, event, level, font, number_of_players);
        }
        if (level == OUVERTURE) {
            afficherImageDebut(start_image, window);
        }

        if (level == MENU) {
            afficherBaseMenu(window, font);
        }

        if (level == QUITTER_LE_JEU) {
            window.close();
        }

        if (level == AIDE) {
            afficherAide(window, font, event.mouseButton.x, event.mouseButton.y);
        }

        if (level == NOUVELLEPARTIE) {
            afficherBaseDmdJoueur(window, font);
        }

        if (level == DEMANDE_NB_JOUEUR) {
            afficherMessageSaisiPseudo(window, font);
        }

        if (level == SAISIE_DES_JOUEURS) {
            for (int i = 0; i < number_of_players; i++) {
                // Informations du joueur
                std::string nickname;
                Joueur player{i, nickname};
                player.demanderInfosJoueur();
                // Stockage du joueur dans le tableau des joueurs
                player_list.push_back(player);
            }
            // Affichage des informations de tous les joueurs dans la console
            for (int i = 0; i < number_of_players; i++) {
                player_list[i].afficherInfosJoueurs();
            }
        }
        window.display();
    }
    music.stop();
}
