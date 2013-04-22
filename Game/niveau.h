/*
 * FICHIER: Niveau.h
 * PROJET:  ProtoNinja
 *
 * AUTHEUR: Nathan
 * DATE:    2013-04-22
 *
 */

#ifndef __ProtoNinja__Niveau__
#define __ProtoNinja__Niveau__

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>

using namespace std;

// Une tuile
struct tuile {
    int identifiant;        // Identifiant de la tuile
    sf::Sprite _sprite;     // Image de la tuile
    bool mur;               // Peut-on passer à travers?
};

// Un niveau
class niveau {
private:
    int _largeur, _hauteur; // En nombre de bloc
    vector<vector<tuile> > _tuiles; // Un matrice de tuile
    
public:
    niveau();
    ~niveau();
    
    bool init(int largeur, int hauteur);
    
    tuile* getTuile(int x, int y);
    bool setTuile(int x, int y, tuile tuile);
};

#endif /* defined(__ProtoNinja__Niveau__) */
