//
// Created by mathe on 24/11/2021.
//

#ifndef PROJETCLUEDO_GROUPE3F_SAUVETAGE_CASE_H
#define PROJETCLUEDO_GROUPE3F_SAUVETAGE_CASE_H
#include <iostream>
#include <SFML/Graphics.hpp>

class Cases{

private:
    int m_position_pixel_x;
    int m_position_pixel_y;
    std :: string m_type;

public:
    Cases(int position_pixel_x=0, int position_pixel_y=0,int position_x=0, int position_y=0, std::string type = "normale");
    ~Cases();

    void set_x (int x);
    void set_y(int y);
    void set_type(std::string type);
    std::string get_type();
    int get_position_pix_x();
    int get_position_pix_y();
};
void initialiserCasePlateau (std::vector<std::vector<Cases>>&tab);
void creation_plateau(std::vector<std::vector<Cases>>&tab);

#endif //PROJETCLUEDO_GROUPE3F_SAUVETAGE_CASE_H
