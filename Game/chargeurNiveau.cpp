/*
 * FICHIER: chargerNiveau.cpp
 * PROJET:  LikeASir
 *
 * AUTHEUR: Nathan
 * DATE:    2013-04-25
 *
*/

#include "chargeurNiveau.h"
//Cette méthode statique consiste à convertir chaque pixel en une case pour le niveau.
niveau chargeurNiveau::chargerNiveauDeImage(sf::Image &img, std::map<int, tuile> &map) {
    //On crée un niveau
    niveau niveau;
    //On l'initialise à la taille de l'image
    niveau.init(img.getSize().x, img.getSize().y);
    //On parcour l'image par chaque pixel et on vérifie sa couleur
    for(int i = 0 ; i < img.getSize().y; i++) {
        for(int j = 0; j < img.getSize().x; j++) {
            sf::Color color = img.getPixel(j, i);
            //Convertir une couleur en un entier
            int key = convertirCouleurEnInt(color);
            //Si la couleur est dans le tableau on set la tuile
            if(map.find(key) != map.end())
                niveau.setTuile(j, i, map[key]);
        }
    }
    
    return niveau;
}

int convertirCouleurEnInt(sf::Color &color) {
    return  color.r + (256 + color.g) + (512 + color.b);
}