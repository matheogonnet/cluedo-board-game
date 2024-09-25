

**Note** : _Ce jeu a été développé dans un contexte académique pour appliquer les concepts de programmation orientée objet, de gestion de projet en groupe et d'utilisation de bibliothèques externes en C++._

---

# Cluedo au Louvre

Bienvenue dans **Cluedo au Louvre**, un jeu de plateau numérique où vous incarnez des détectives cherchant à résoudre le mystère du vol de la Joconde. Plongez au cœur du célèbre musée du Louvre et découvrez qui est le voleur, quel outil il a utilisé et dans quelle salle la précieuse œuvre est cachée.

## Sommaire

- [Description du projet](#description-du-projet)
- [Règles du jeu](#règles-du-jeu)
- [Technologies utilisées](#technologies-utilisées)
- [Architecture du projet](#architecture-du-projet)
- [Installation et exécution](#installation-et-exécution)
- [Contact](#contact)

## Description du projet

Ce projet a été réalisé en groupe dans le cadre du cours d'informatique en programmation C++ durant l'année 2022, lors de la deuxième année sur cinq du cursus ingénieur à l'**ECE Lyon**. L'objectif était de mettre en pratique les concepts avancés de C++ en développant un jeu de plateau avec une interface graphique.

## Règles du jeu

- **But du jeu** : Trouver le voleur de la Joconde, l'outil utilisé et la salle où elle est cachée.
- **Déroulement** :
  - Une enveloppe est remplie au hasard avec une carte de voleur, une carte d'outil et une carte de salle.
  - Les cartes restantes sont distribuées équitablement entre les joueurs.
  - Les joueurs utilisent leurs cartes et déductions pour éliminer des suspects et trouver la combinaison secrète.
- **Conseil** : Munissez-vous d'un bloc-notes pour noter vos indices et avancer dans l'enquête.
- **Fin du jeu** : Le premier joueur à découvrir la combinaison exacte remporte la partie.

## Technologies utilisées

- **Langage** : C++
- **Bibliothèque graphique** : [SFML (Simple and Fast Multimedia Library)](https://www.sfml-dev.org/)
- **Outils de développement** :
  - **CMake** pour la gestion de la compilation et des dépendances.
  - **Git** pour le contrôle de version.
- **IDE recommandé** : Visual Studio Code ou CLion.

## Architecture du projet

Le projet est structuré de manière à séparer clairement les différentes composantes :

- **`src/`** : Contient les fichiers sources (.cpp) du projet.
- **`include/`** : Regroupe les fichiers d'en-tête (.h) utilisés.
- **`assets/`** : Contient les ressources du jeu telles que les images, sons et polices.
- **`CMakeLists.txt`** : Fichier de configuration pour CMake, spécifiant comment compiler le projet et lier les bibliothèques nécessaires.

## Installation et exécution

### Prérequis

- Un compilateur compatible avec C++14.
- CMake version 3.14 ou supérieure.
- La bibliothèque SFML installée sur votre système.

### Étapes d'installation

1. **Cloner le dépôt du projet** :

   ```bash
   git clone https://github.com/matheogonnet/cluedo-board-game.git
   cd cluedo-board-game
   ```

2. **Configurer le projet avec CMake** :

    ```bash
    Copier le code
    mkdir build
    cd build
    cmake ..
    ```

3. **Compiler le projet** :

    ```bash
    Copier le code
    cmake --build .
    Exécuter le jeu :
    ```
#### Sur Windows :

```bash
Copier le code
.\Debug\cluedo-board-game.exe
```
#### Sur Linux/macOS :
```bash
Copier le code
./cluedo-board-game-main
```
### Remarque
Assurez-vous que les bibliothèques dynamiques de SFML sont accessibles lors de l'exécution. Sur Windows, vous devrez peut-être copier les DLL de SFML dans le même répertoire que l'exécutable.

### Fonctionnalités supplémentaires ###
- Interface utilisateur intuitive : Grâce à SFML, le jeu propose une interface graphique agréable et facile à prendre en main.
- Musique et effets sonores : Une ambiance sonore pour immerger les joueurs dans le mystère du Louvre.
- Modularité du code : Le code est organisé de manière à faciliter l'ajout de nouvelles fonctionnalités ou l'amélioration des existantes.


## Contact
Pour toute question ou suggestion, n'hésitez pas à ouvrir une issue sur le dépôt GitHub ou à nous contacter directement.