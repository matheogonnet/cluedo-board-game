//
// Created by mathe on 24/11/2021.
//

#include "case.h"

//constructeur
Cases :: Cases(int position_pixel_x, int position_pixel_y,int position_x, int position_y, std::string type)
        : m_type{type}, m_position_pixel_y{position_pixel_y}, m_position_pixel_x{position_pixel_x}
{}
//destructeur
Cases :: ~Cases() = default;



//accesseurs et mutateurs

void Cases :: set_x(int x){
    m_position_pixel_x = x;
}
void Cases :: set_y(int y){
    m_position_pixel_y = y;
}
void Cases :: set_type(std::string type){
    m_type = type;
}

std::string Cases :: get_type(){
    return m_type;
};
int Cases :: get_position_pix_x(){
    return m_position_pixel_x;
}


int Cases :: get_position_pix_y(){
    return m_position_pixel_y;
}





//fonction qui créée un tableau en lui reservant des espaces memoires
void creation_plateau(std::vector<std::vector<Cases>>&tab){
    for(int lignes=0;lignes<15; lignes++){
        tab.push_back(std::vector<Cases>());
        for(int colonnes=0; colonnes<15; colonnes++){
            tab[lignes].push_back(Cases());
        }
    }
}

//ici on initialise le plateau avec le type de chaques cases ainsi que des coordonnes en pixel
// des coordonees qui seront utile pour l'affichage du pion

void initialiserCasePlateau (std::vector<std::vector<Cases>>&tab){
    Cases case_a_ajouter;

    for (int i =0; i< 15; i++){
        for(int j = 0; j<15; j++){
            case_a_ajouter.set_x((j*45.9)+160);
            case_a_ajouter.set_y((i*30)+80);

            //partie du haut du plateau
            if(i>=0 && i<=3){
                //les cases de la pièce toilettes
                if(j>=0 && j<=3){
                    case_a_ajouter.set_type("toilettes");
                    tab[i][j]=case_a_ajouter;
                }
                //les cases de la pièce salle d'exposition 1
                if(j>=5 && j<=10){
                    case_a_ajouter.set_type("salle_exposition1");
                    tab[i][j]=case_a_ajouter;
                }
                //les cases de la pièce billetterie
                if(j>=12 && j<=14){
                    case_a_ajouter.set_type("billetterie");
                    tab[i][j]=case_a_ajouter;
                }
            }
            //case normale
            if(i>=4 && i<=10){
                if(j>=0 && j<=5){
                    tab[i][j]=case_a_ajouter;
                }
                if(j>=9 && j<=14){
                    tab[i][j]=case_a_ajouter;
                }
            }
            if(i>=0 && i<=3){
                if((j>=3 && j<=5) || (j>=10 && j<=12)){
                    tab[i][j]=case_a_ajouter;
                }
            }
            if(i>=11 && i<=14){
                if((j>=3 && j<=5) || (j>=10 && j<=12)){
                    tab[i][j]=case_a_ajouter;
                }
            }
            //partie du bas du plateau
            if(i>=11 && i<=14){
                //les cases de la pièce archives
                if(j>=0 && j<=3){
                    case_a_ajouter.set_type("archives");
                    tab[i][j]=case_a_ajouter;
                }
                //les cases de la pièce salle d'exposition 2
                if(j>=5 && j<=10){
                    case_a_ajouter.set_type("salle_exposition2");
                    tab[i][j]=case_a_ajouter;
                }
                //les cases de la pièce boutique
                if(j>=12 && j<=14){
                    case_a_ajouter.set_type("boutique");
                    tab[i][j]=case_a_ajouter;
                }
            }
            //case depart
            if(i==7 && j==5){
                case_a_ajouter.set_type("depart");
                tab[i][j]=case_a_ajouter;
            }
            if(i>=6 && i<=9){
                if(j>=6 && j<=9){
                    case_a_ajouter.set_type("interdit");
                    tab[i][j]=case_a_ajouter;
                }
            }
        }
    }
}



