/*
 * FICHIER: joueur.cpp
 * PROJET:  LikeASir
 *
 * AUTHEUR: Nathan
 * DATE:    2013-04-23
 *
*/

#include "joueur.h"

#include "unicorn.h"

joueur::joueur()
:personnage()
{
    _largeur = 6;
    _hauteur = 8;
    
    _antenne1.x = 0;
    _antenne1.y = _hauteur;
    
    _antenne2.x = _largeur - 1;
    _antenne2.y = _hauteur;
    
    _longueurAntennes = 1.0f;
}

joueur::~joueur() {
    
}

void joueur::rafraichir(float delta) {
    _velocite.x = 0;
    
    if(unicorn::InputListener::getInstance()->listen("d")) {
        _velocite.x += 0.05f;
    } 
    
    else if(unicorn::InputListener::getInstance()->listen("a")) {
        _velocite.x -= 0.05f;
    }
    
    if(unicorn::InputListener::getInstance()->listen("w") && _auSol == true) {
        _velocite.y -= 0.025f;
    }
    
    if(_velocite.y > 0.25f) {
        _velocite.y = 0.25f;
    }
    
    if(_velocite.y < -0.25f)
        _velocite.y = -0.25f;
    
    if(_auSol == true && _velocite.y > 0) {
        _velocite.y = 0;
    
    }
}

void joueur::enCollisionAvecActeur(acteur &autre) {
    
}

void joueur::afficher(sf::RenderTarget *destination) {
    acteur::afficher(destination);
    
    sf::RectangleShape boundingBox;
    boundingBox.setPosition(_position);
    boundingBox.setSize(sf::Vector2f(_largeur, _hauteur));
    boundingBox.setFillColor(sf::Color(255,0,255,100));
    
    destination->draw(boundingBox);
    
    sf::RectangleShape antenne;
    antenne.setSize(sf::Vector2f(1, _longueurAntennes));
    antenne.setPosition(_position + _antenne1);
    
    antenne.setFillColor(sf::Color(0,255,0));
    
    destination->draw(antenne);
    
    antenne.setPosition(_position + _antenne2);
    antenne.setFillColor(sf::Color(0,255,0));
    
    destination->draw(antenne);
}

bool joueur::getCache() {
    return _cache;
}

void joueur::setCache(bool val) {
    _cache = val;
}