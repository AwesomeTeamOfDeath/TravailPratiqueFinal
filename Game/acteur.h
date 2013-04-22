/*
 * FICHIER: Acteurs.h
 * PROJET:  LikeASir
 *
 * AUTHEUR: Nathan
 * DATE:    2013-04-22
 *
 * Un acteur correspond à n'importe quoi comme le personnage, un monstre, une clef, une porte, un projectile, un lapin, etc.
 */

#ifndef __LikeASir__Acteurs__
#define __LikeASir__Acteurs__

#include <iostream>
#include <SFML/Graphics.hpp>

typedef unsigned long ulong;

class acteur {    
public:
    enum typeActeur {
        NON_DEFINI = 0,
        PERSONNAGE,
        COLLECTIONNABLE,
        INTERACTIONNABLE,
        FIN_TYPE_ACTEUR
    };

private:
    static unsigned long _autoID;
    
protected:
    sf::Sprite _sprite;
    sf::Vector2f _position;
    sf::Vector2f _deplacement, _velocite;
    
    float _largeur, _hauteur;
    
    ulong _id;
    typeActeur _type;
    
public:
    // Constructeur
    acteur();
    
    // Destructeur
    ~acteur();
    
    // Setters
    void setPosition(sf::Vector2f val);
    void setPosition(float x, float y);
    void setDeplacement(sf::Vector2f val);
    void setDeplacement(float x, float y);
    void setVelocite(sf::Vector2f val);
    void setVelocite(float x, float y);
    
    void setLargeur(float largeur);
    void setHauteur(float hauteur);
    
    // Getters
    sf::Vector2f getPosition();
    sf::Vector2f getDeplacement();
    sf::Vector2f getVelocite();
    
    float getLargeur();
    float getHauteur();
    
    ulong getId();
    typeActeur getType();
};

#endif /* defined(__LikeASir__Acteurs__) */
