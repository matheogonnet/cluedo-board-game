//
// Created by mathe on 24/11/2021.
//

#include "../include/joueur.h"


//constructeur
Joueur :: Joueur(int numero,std::string pseudo, int niveau, int color, int score, int position_x, int position_y, int de)
        : m_pseudo{pseudo}, m_niveau(niveau), m_color(color), m_score(score), m_position_x(position_x), m_position_y(position_y),m_numeroIdentification{numero}, m_de(de)
{}

//destructeur
Joueur :: ~Joueur() = default;


//info joueurs
void Joueur :: demanderInfosJoueur (){

    //pseudo
    std :: cout<< "Joueur "<< m_numeroIdentification +1 << " : " << "saisissez votre pseudo pour la partie : "<< std :: endl;
    std :: cin >> m_pseudo;
    //niveau
    std :: cout<< "\nJoueur "<< m_numeroIdentification+1 << " : " << "saisissez votre niveau de jeu : "<< std :: endl;
    std :: cout<< "1 : Debutant "<< std :: endl;
    std :: cout<< "2 : Intermmediaire "<< std :: endl;
    std :: cout<< "3 : Avance "<< std :: endl;
    std :: cout<< "4 : Expert "<< std :: endl;
    std :: cin >> m_niveau;
    //couleur du pion
    std :: cout<< "\nJoueur "<< m_numeroIdentification+1<< " : " << "choisissez la couleur de votre pion : "<< std :: endl;
    std :: cout<< "1 : Jaune "<< std :: endl;
    std :: cout<< "2 : Bleu "<< std :: endl;
    std :: cout<< "3 : Vert "<< std :: endl;
    std :: cout<< "4 : Rouge "<< std :: endl;
    std :: cin >> m_color;

}

//recapulatif a afficher à la fin de la saisie de chaque joueur

void Joueur :: afficherInfosJoueurs (){
    std :: cout << "pseudo : " << m_pseudo << std :: endl << "niveau : " << m_niveau << std :: endl;
    std :: cout << "couleur : " << m_color << std :: endl << "score : " << m_score << std :: endl<<std :: endl<<std :: endl;
}

//affichage du pion du joueur selon la couleur selectionnée et sa position sur le plateau
//on connait la position en pixel car chaque case du plateau est associe a des coordonees en pixel
void Joueur :: afficherPion (sf :: RenderWindow &window, int coord_pix_x, int coord_pix_y){
    if(m_color == 1 ){
        sf::CircleShape cercle;
        cercle.setRadius(10);
        cercle.setPosition(coord_pix_x, coord_pix_y);
        cercle.setFillColor(sf :: Color :: Yellow);
        window.draw(cercle);
    }
    if(m_color == 2 ){
        sf::CircleShape cercle;
        cercle.setRadius(10);
        cercle.setPosition(coord_pix_x, coord_pix_y);
        cercle.setFillColor(sf :: Color :: Blue);
        window.draw(cercle);
    }
    if(m_color == 3 ){
        sf::CircleShape cercle;
        cercle.setRadius(10);
        cercle.setPosition(coord_pix_x, coord_pix_y);
        cercle.setFillColor(sf :: Color :: Green);
        window.draw(cercle);
    }
    if(m_color == 4 ){
        sf::CircleShape cercle;
        cercle.setRadius(10);
        cercle.setPosition(coord_pix_x, coord_pix_y);
        cercle.setFillColor(sf :: Color :: Red);
        window.draw(cercle);
    }
}

/********ACCESSEUR ET MUTATEUR********/
int Joueur ::get_pos_y() {
    return m_position_y;
}

int Joueur ::get_pos_x() {
    return m_position_x;
}

void Joueur :: set_position_x(int x){
    m_position_x=x;
}

void Joueur :: set_position_y(int y){
    m_position_y=y;
}

void Joueur :: aller_a_droite(){
    //colonne suivant ++
    m_position_y++;
    m_de--;


}
void Joueur :: aller_a_gauche(){
    //on decrémente la colonne de 1
    m_position_y--;
    m_de--;
}
void Joueur :: aller_en_haut(){
    //on passe à la ligne au dessus
    m_position_x--;
    m_de--;
}
void Joueur :: aller_en_bas(){
    m_position_x++;
    m_de--;
}


void Joueur::set_de(int n){
    m_de = n;
}

int Joueur :: get_de() const{
    return m_de;
}

std::string Joueur:: get_nom(){
    return m_pseudo;
}

/***************************************/






//méthode remplie la main du joueur
void Joueur ::remplir_main(std::vector<Carte> &packet){
    //on parcout le packet jusqu'a trouver une carte qui n'a pas été distribué
    int ok=0;
    srand(time(nullptr));
    while(ok!=1){
        //14 cartes au total donc le rand va jusqu'à 13
        int i = rand()%13;
        //le if verifie que la carte du paquet tirée n'a pas déjà été selectionné
        if(!packet[i].getDistribue()){
            m_main.push_back(packet[i]);
            packet[i].setDistribue(true);
            ok=1;
        }
        else ok=0;
    }
}

//fonction qui verifie si toutes les cartes du packet sont utlisées ou non
// si oui alors on arrete la distributino des cartes
int packet_vide(std::vector<Carte>&packet){
    int vide=0;
    for(int i=0; i<14; i++){
        if(packet[i].getDistribue()){
            vide++;
        }
    }
    return vide;
}

//fonction appelée au debut : lors de l'initialisation pour remplir la main de chaque de chaques joueurs
void remplir_main_des_joueurs(std::vector<Joueur>&ensemble_des_joueurs, int nbJoueur, std::vector<Carte>&packet){
    int ok=0;
    while(ok==0){
        for (int i = 0; i < nbJoueur; i++) {
            ensemble_des_joueurs[i].remplir_main(packet);
            if(packet_vide(packet)==13){
                ok=1;
                break;
            }
        }
    }
}

//fonction qui initialise la position de chaque joueur au debut de la partie
// pour les mettrent au centre du plateau
void initialiser_position_joueurs(std::vector<Joueur>&ensemble_des_joueurs, int nbJoueur){
    for(int i=0; i<nbJoueur; i++){
        modifier_position_joueur(ensemble_des_joueurs,i,7,5);
    }
}

//pour modifier la fonction du joueur en cours sur le plateau
void modifier_position_joueur(std::vector<Joueur>&ensemble_des_joueurs, int i, int x, int y){
    ensemble_des_joueurs[i].set_position_x(x);
    ensemble_des_joueurs[i].set_position_y(y);
}

void Joueur ::afficherMain(sf::RenderWindow &window) {

    sf::RectangleShape rectangle (sf::Vector2f(700, 350));
    rectangle.setPosition(150, 150);
    rectangle.setFillColor(sf :: Color :: White);
    window.draw(rectangle);
    std::vector<Carte> :: iterator i; int ecart =0;
    for(i=m_main.begin(); i!=m_main.end();i++){
        i->afficherCarte(window,ecart);
        ecart+=100;
    }
}

bool Joueur::accuser(Enveloppe enveloppe) {

    std::string lieux, personnage, arme;
    std::cout<<"\nQui est le voleur ?"<<std::endl;
    std::cout<<"-femme_de_menage\n-gardien\n-guide_touristique\n-touriste\n"<<std::endl;
    std::cin>>personnage;

    std::cout<<"\nAvec quel outil?"<<std::endl;
    std::cout<<"-corde\n-coupe_verre\n-marteau\n-pied_de_biche\n"<<std::endl;
    std::cin>>arme;

    std::cout<<"\nOu est cache la joconde ?"<<std::endl;
    std::cout<<"-archives\n-billeterie\n-boutique\n-salle_exposition1\n-salle_exposition2\n-toilletes\n"<<std::endl;
    std::cin>>lieux;

//ce if verifie que le joueur ne sait pas trompé en comparant ses reponses à celle de l'enveloppe
    if(lieux==enveloppe.getCarte()[0].getNom() && personnage==enveloppe.getCarte()[1].getNom() && arme==enveloppe.getCarte()[2].getNom()){
        std::cout<<"\n\nvictoire ! retournez sur la fenetre";
        return true;
    }
    else {
        std::cout<<"\n\ndefaite... retournez sur la fenetre";
        return false;
    }
}
