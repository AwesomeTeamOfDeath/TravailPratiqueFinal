/*
 * FICHIER: Niveau.cpp
 * PROJET:  ProtoNinja
 *
 * AUTHEUR: Nathan
 * DATE:    2013-04-22
 *
*/

#include "niveau.h"

niveau::niveau() {
    _largeur = 0;
    _hauteur = 0;
}

niveau::~niveau(){
}

bool niveau::init(int largeur, int hauteur) {
    // Si les dimensions entrées sont invalides...
    if(largeur < 0 || hauteur < 0) {
        // On stoppe l'initialisation
        return false;
    }
    
    _largeur = largeur;
    _hauteur = hauteur;
    
    _tuiles.resize(_hauteur);
    
    for(int i = 0; i < _hauteur; i++)
        _tuiles[i].resize(_largeur);
    
    return true;
}

tuile* niveau::getTuile(int x, int y) {
    // SI on veut acceder à une case hors du tableau, on renvoie un pointeur null
    if(x < 0 || y < 0 || x >= _largeur || y >= _hauteur)
        return NULL;
    
    // Sinon on retourne un pointeur vers la tuile demandée
    return &_tuiles[y][x];
}

bool niveau::setTuile(int x, int y, tuile iTuile) {
    if(x < 0 || y < 0 || x >= _largeur || y >= _hauteur)
        return false;
    
    _tuiles[y][x] = iTuile;
    
    return true;
}