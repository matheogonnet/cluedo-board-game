
//
// Created by mathe on 24/11/2021.
//

#include "partieEnCours.h"

/**
 * Affiche l'image du plateau sur la fenêtre donnée.
 */
void afficherPlateau(sf::RenderWindow &window) {
    sf::Texture image;
    loadPlateau(image);
    sf::Sprite sprite;
    sprite.setScale(sf::Vector2f(1, 1));
    sprite.setOrigin(sf::Vector2f(0, 0));
    sprite.setTexture(image, true);
    window.draw(sprite);
}

/**
 * Fonction principale qui repeint toute la fenêtre avec le plateau et les pions des joueurs.
 */
void repeindre(sf::RenderWindow &window, std::vector<Joueur> playersList, const int numberOfPlayers, std::vector<std::vector<Cases>> board) {
    window.clear(sf::Color(0, 0, 0));
    afficherPlateau(window);
    for (int index = 0; index < numberOfPlayers; index++) {
        playersList[index].afficherPion(window,
            board[playersList[index].get_pos_x()][playersList[index].get_pos_y()].get_position_pix_x(),
            board[playersList[index].get_pos_x()][playersList[index].get_pos_y()].get_position_pix_y());
    }
}

/**
 * Vérifie si la souris clique sur le dé situé en bas à droite de la fenêtre.
 */
int sourisSurLeDe(int posX, int posY) {
    if (posX >= 900 && posX <= 1000 && posY >= 500 && posY <= 600) {
        return 1;
    }
    return 0;
}

/*********************** Passages secrets *********************************/

/**
 * Vérifie si le pion est dans le passage secret des toilettes et le déplace vers la boutique.
 */
int pionDansPSToilettes(int index, std::vector<Joueur> &playersList) {
    // On envoie le pion vers la boutique
    if (playersList[index].get_pos_x() == 0 && playersList[index].get_pos_y() == 0) {
        playersList[index].set_position_x(13);
        playersList[index].set_position_y(13);
        return 1;
    }
    return 0;
}

/**
 * Vérifie si le pion est dans le passage secret de la boutique et le déplace vers les toilettes.
 */
int pionDansPSBoutique(int index, std::vector<Joueur> &playersList) {
    if (playersList[index].get_pos_x() == 14 && playersList[index].get_pos_y() == 14) {
        // On envoie le joueur vers les toilettes
        playersList[index].set_position_x(1);
        playersList[index].set_position_y(2);
        return 1;
    }
    return 0;
}

/**
 * Vérifie si le pion est dans le passage secret de la billetterie et le déplace vers les archives.
 */
int pionDansPSBilletterie(int index, std::vector<Joueur> &playersList) {
    if (playersList[index].get_pos_x() == 0 && playersList[index].get_pos_y() == 14) {
        // On envoie le pion vers les archives
        playersList[index].set_position_x(12);
        playersList[index].set_position_y(1);
        return 1;
    }
    return 0;
}

/**
 * Vérifie si le pion est dans le passage secret des archives et le déplace vers la billetterie.
 */
int pionDansPSArchives(int index, std::vector<Joueur> &playersList) {
    if (playersList[index].get_pos_x() == 0 && playersList[index].get_pos_y() == 14) {
        // On envoie le pion vers la billetterie
        playersList[index].set_position_x(2);
        playersList[index].set_position_y(13);
        return 1;
    }
    return 0;
}

/**
 * Vérifie si le pion est sur une case de passage secret et effectue le déplacement si nécessaire.
 */
void verifierCasesPassagesSecrets(int index, std::vector<Joueur> &playersList, sf::RenderWindow &window, std::vector<std::vector<Cases>> board) {
    if (pionDansPSArchives(index, playersList) ||
        pionDansPSToilettes(index, playersList) ||
        pionDansPSBoutique(index, playersList) ||
        pionDansPSBilletterie(index, playersList)) {
        repeindre(window, playersList, index, board);
    }
}

/************************** Vérification portes - cases absorbantes *********************************/

/**
 * Vérifie si le pion est dans les toilettes et le déplace si nécessaire.
 */
int pionDansToilettes(int index, std::vector<Joueur> &playersList) {
    if (playersList[index].get_pos_x() == 4 && playersList[index].get_pos_y() == 1) {
        playersList[index].set_position_x(2);
        playersList[index].set_position_y(1);
        playersList[index].set_de(0);
        return 1;
    }
    return 0;
}

/**
 * Vérifie si le pion est dans la salle d'exposition 1 et le déplace si nécessaire.
 */
int pionDansSalleExpo1(int index, std::vector<Joueur> &playersList) {
    if (playersList[index].get_pos_x() == 2 && playersList[index].get_pos_y() == 4) {
        playersList[index].set_position_x(2);
        playersList[index].set_position_y(7);
        playersList[index].set_de(0);
        return 1;
    }
    return 0;
}

/**
 * Vérifie si le pion est dans la salle d'exposition 2 et le déplace si nécessaire.
 */
int pionDansSalleExpo2(int index, std::vector<Joueur> &playersList) {
    if (playersList[index].get_pos_x() == 12 && playersList[index].get_pos_y() == 10) {
        playersList[index].set_position_x(12);
        playersList[index].set_position_y(7);
        playersList[index].set_de(0);
        return 1;
    }
    return 0;
}

/**
 * Vérifie si le pion est dans la billetterie et le déplace si nécessaire.
 */
int pionDansBilletterie(int index, std::vector<Joueur> &playersList) {
    if (playersList[index].get_pos_x() == 4 && playersList[index].get_pos_y() == 13) {
        playersList[index].set_position_x(2);
        playersList[index].set_position_y(13);
        playersList[index].set_de(0);
        return 1;
    }
    return 0;
}

/**
 * Vérifie si le pion est dans la boutique et le déplace si nécessaire.
 */
int pionDansBoutique(int index, std::vector<Joueur> &playersList) {
    if (playersList[index].get_pos_x() == 10 && playersList[index].get_pos_y() == 13) {
        playersList[index].set_position_x(13);
        playersList[index].set_position_y(13);
        playersList[index].set_de(0);
        return 1;
    }
    return 0;
}

/**
 * Vérifie si le pion est dans les archives et le déplace si nécessaire.
 */
int pionDansArchives(int index, std::vector<Joueur> &playersList) {
    if (playersList[index].get_pos_x() == 13 && playersList[index].get_pos_y() == 13) {
        playersList[index].set_position_x(13);
        playersList[index].set_position_y(1);
        playersList[index].set_de(0);
        return 1;
    }
    return 0;
}

/**
 * Vérifie si le pion est sur une case absorbante et effectue le déplacement si nécessaire.
 */
void verifierCasesAbsorbantes(int index, std::vector<Joueur> &playersList, sf::RenderWindow &window, std::vector<std::vector<Cases>> board) {
    if (pionDansArchives(index, playersList) ||
        pionDansSalleExpo1(index, playersList) ||
        pionDansSalleExpo2(index, playersList) ||
        pionDansToilettes(index, playersList) ||
        pionDansBoutique(index, playersList) ||
        pionDansBilletterie(index, playersList)) {
        repeindre(window, playersList, index, board);
    }
}

/*********************************************************************************/

/**
 * Affiche l'écran de victoire pour le joueur donné.
 */
void afficherEcranVictoire(int index, std::vector<Joueur> playersList, sf::Font font, sf::RenderWindow &window) {
    sf::Texture victoryScreen;
    loadimageouverture(victoryScreen, "../assets/images/cartes_lieux/victoire.png");
    sf::Sprite sprite;
    sprite.setScale(sf::Vector2f(1, 1));
    sprite.setOrigin(sf::Vector2f(0, 0));
    sprite.setTexture(victoryScreen, true);
    window.draw(sprite);
    window.draw(titre(font, ("Bravo " + playersList[index].get_nom() + " vous avez retrouvé la Joconde"), 180, 450, 50, sf::Color::Black));
}

/**
 * Affiche l'écran de défaite pour le joueur donné.
 */
void afficherEcranDefaite(int index, std::vector<Joueur> playersList, sf::Font font, sf::RenderWindow &window) {
    window.clear(sf::Color(107, 137, 103));
    window.draw(titre(font, ("Non " + playersList[index].get_nom() + " vous n'avez pas trouvé la Joconde"), 180, 450, 50, sf::Color::Black));
}

/**********************************************************************************/

/**
 * Liste des événements à traiter dans la boucle principale du jeu.
 */
void listeDEvents(sf::RenderWindow &window, sf::Event event, int &level, sf::Font font, int numberOfPlayers, std::vector<Joueur> &playersList, int &currentIndex, Enveloppe &envelope, sf::Music &music) {
    if (event.type == sf::Event::Closed) {
        level = QUITTER_LE_JEU;
    }
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Space && level == INITIALISATION) {
            music.stop();
            level = DEBUT_TOUR;
        }
        if (event.key.code == sf::Keyboard::Space && (level == AFFICHER_PLATEAU || level == DEFAITE)) {
            currentIndex++;
            level = DEBUT_TOUR;
        }
        if (event.key.code == sf::Keyboard::A && level == AFFICHER_PLATEAU) {
            if (playersList[currentIndex].accuser(envelope)) {
                level = VICTOIRE;
            } else {
                level = DEFAITE;
            }
        }
        if (event.key.code == sf::Keyboard::Right && level == JOUER) {
            playersList[currentIndex].aller_a_droite();
        }
        if (event.key.code == sf::Keyboard::Left && level == JOUER) {
            playersList[currentIndex].aller_a_gauche();
        }
        if (event.key.code == sf::Keyboard::Down && level == JOUER) {
            playersList[currentIndex].aller_en_bas();
        }
        if (event.key.code == sf::Keyboard::Up && level == JOUER) {
            playersList[currentIndex].aller_en_haut();
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
        envelope.revelerEnveloppe(window);
        window.display();
        if (event.type == sf::Event::KeyReleased) {
            window.display();
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::C)) {
        playersList[currentIndex].afficherMain(window);
        window.display();
        if (event.type == sf::Event::KeyReleased) {
            window.display();
        }
    }
    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            if (sourisSurLeDe(event.mouseButton.x, event.mouseButton.y) == 1 && level == DEBUT_TOUR) {
                level = LANCER_DE;
            }
        }
    }
}

/**
 * Affiche la partie en cours et gère la boucle principale du jeu.
 */
void afficherPartieEnCours(sf::Event &event, int numberOfPlayers, std::vector<Joueur> &playersList) {
    // Réouverture d'une nouvelle fenêtre
    sf::RenderWindow window(sf::VideoMode(1000, 600), "Cluedo au musée");
    window.setPosition(sf::Vector2i(0, 0));
    // Variables
    sf::Font font;
    sf::Texture boardImage;
    sf::Texture startImage;
    int level = 0;
    int currentPlayer = 0;
    int dieFace;
    sf::Texture image;
    std::string type;
    sf::Music music;
    music.openFromFile("../assets/sounds/alarme-bruitage.ogg");

    /****** TABLEAUX VECTEURS ******/
    // Création du plateau de 15 lignes et 15 colonnes
    std::vector<std::vector<Cases>> board;
    // Création du dé
    std::vector<De> die;
    // Création du paquet de cartes
    std::vector<Carte> deck;
    // Création de l'enveloppe
    Enveloppe envelope;
    /*******************************/

    // Initialisation
    level = INITIALISATION;
    loadFont(font);
    initialiserDe(die);
    creation_plateau(board);
    initialiserCasePlateau(board);
    initialiserPacket(deck);
    envelope.remplirEnveloppe(deck);
    remplir_main_des_joueurs(playersList, numberOfPlayers, deck);
    initialiser_position_joueurs(playersList, numberOfPlayers);

    /*
     * Une partie repose sur le principe de niveaux (level). Chaque action précise dans
     * le déroulement d'un tour est régie par un enum qui est ensuite associé
     * à cette variable level. Les événements appelés tout au long de la partie sont stockés
     * dans la fonction listeDEvents() et utilisent donc aussi ce principe de level.
     */

    music.play();

    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            listeDEvents(window, event, level, font, numberOfPlayers, playersList, currentPlayer, envelope, music);
        }
        afficherPlateau(window);
        if (level == INITIALISATION) {
            // envelope.revelerEnveloppe(window);
            window.draw(titre(font, "Appuyez sur Espace pour commencer la partie", 210, 360, 35, sf::Color::Black));
            // Appuyer sur Espace pour commencer le tour des joueurs
        }
        if (level == DEBUT_TOUR) {
            if (currentPlayer == numberOfPlayers) {
                currentPlayer = 0;
            }
            dieFace = 0;
            repeindre(window, playersList, numberOfPlayers, board);
            playersList[currentPlayer].afficherPion(window,
                board[playersList[currentPlayer].get_pos_x()][playersList[currentPlayer].get_pos_y()].get_position_pix_x(),
                board[playersList[currentPlayer].get_pos_x()][playersList[currentPlayer].get_pos_y()].get_position_pix_y());
            afficher_image_de(window, die, dieFace);
        }
        if (level == LANCER_DE) {
            lancerDe(die, window, playersList, currentPlayer);
            dieFace = playersList[currentPlayer].get_de() - 1;
            level = JOUER;
        }
        if (level == JOUER) {
            repeindre(window, playersList, numberOfPlayers, board);
            verifierCasesAbsorbantes(currentPlayer, playersList, window, board);
            // Si cases absorbantes, proposer de soupçonner
            verifierCasesPassagesSecrets(currentPlayer, playersList, window, board);
            afficher_image_de(window, die, dieFace);
            if (playersList[currentPlayer].get_de() == 0) {
                level = AFFICHER_PLATEAU;
            }
        }
        if (level == AFFICHER_PLATEAU) { // Afficher à la fin de chaque tour
            repeindre(window, playersList, numberOfPlayers, board);
            afficher_image_de(window, die, dieFace);
            window.draw(titre(font, "Pour accuser appuyez sur A sinon Joueur suivant appuyez sur Espace", 210, 360, 25, sf::Color::Black));
        }
        if (level == VICTOIRE) {
            window.clear(sf::Color(0, 0, 0));
            afficherEcranVictoire(currentPlayer, playersList, font, window);
        }
        if (level == DEFAITE) {
            afficherEcranDefaite(currentPlayer, playersList, font, window);
            window.draw(titre(font, "Joueur suivant appuyez sur Espace", 180, 360, 35, sf::Color::Black));
        }
        if (level == QUITTER_LE_JEU) {
            window.close();
        }
        window.display();
    }
}
