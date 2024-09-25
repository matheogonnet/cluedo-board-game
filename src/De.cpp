//
// Created by mathe on 24/11/2021.
//

#include "De.h"

/*

//constructeur
De::De(int face, sf::Texture image) : m_face{face}, m_image{image}
{}
//destructeur
De :: ~De()=default;

//accesseur
sf::Texture De::get_image(){
    return m_image;
};
*/


//fonction d'initialisation des 6 faces du dé sur le dé

void initialiserDe(std::vector<De> &de) {
    //face 1
    sf::Texture imageface1;
    loadimageouverture(imageface1, "../assets/images/faces_de/face1.png");
    De face1{1,imageface1};
    de.push_back(face1);
    //face 2
    sf::Texture imageface2;
    loadimageouverture(imageface2, "../assets/images/faces_de/face2.png");
    De face2{2,imageface2};
    de.push_back(face2);
    //face 3
    sf::Texture imageface3;
    loadimageouverture(imageface3, "../assets/images/faces_de/face3.png");
    De face3{3,imageface3};
    de.push_back(face3);
    //face 4
    sf::Texture imageface4;
    loadimageouverture(imageface4, "../assets/images/faces_de/face4.png");
    De face4{4,imageface4};
    de.push_back(face4);
    //face 5
    sf::Texture imageface5;
    loadimageouverture(imageface5, "../assets/images/faces_de/face5.png");
    De face5{5,imageface5};
    de.push_back(face5);
    //face 6
    sf::Texture imageface6;
    loadimageouverture(imageface6, "../assets/images/faces_de/face6.png");
    De face6{6,imageface6};
    de.push_back(face6);
}

//fonction de lancé du dé
void afficher_image_de(sf::RenderWindow &window,const std::vector<De>de, int face){
    sf::Sprite test;
    test.setScale(sf::Vector2f(0.1, 0.1));
    test.setOrigin(sf::Vector2f(20, 20));
    test.setPosition(920,520);
    test.setTexture(de[face].m_image, true);
    window.draw(test);
}



void lancerDe(std::vector<De> de, sf::RenderWindow &window, std::vector<Joueur>&ensemble_des_joueurs, int i){
    int n;
    sf::Sprite test;
    test.setScale(sf::Vector2f(0.1, 0.1));
    test.setOrigin(sf::Vector2f(20, 20));
    test.setPosition(920,520);
    srand(time(nullptr));
    n = rand() % 6;
    if(n==0){

        test.setTexture(de[0].m_image, true);
        // on dit que le joeur pourra avancer de 1 case max
        ensemble_des_joueurs[i].set_de(1);
        window.draw(test);
    }
    else if(n==1){

        test.setTexture(de[1].m_image, true);
        // on dit que le joeur pourra avancer de deux cases max
        ensemble_des_joueurs[i].set_de(2);
        window.draw(test);
    }
    else if(n==2){

        test.setTexture(de[2].m_image, true);
        ensemble_des_joueurs[i].set_de(3);
        window.draw(test);
    }
    else if(n==3){

        test.setTexture(de[3].m_image, true);
        ensemble_des_joueurs[i].set_de(4);
        window.draw(test);
    }
    else if(n==4){

        test.setTexture(de[4].m_image, true);
        ensemble_des_joueurs[i].set_de(5);
        window.draw(test);
    }
    else if(n==5){

        test.setTexture(de[5].m_image, true);
        ensemble_des_joueurs[i].set_de(6);
        window.draw(test);
    }

}
