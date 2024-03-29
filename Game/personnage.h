/*
 * FICHIER: personnage.h
 * PROJET:  LikeASir
 *
 * AUTHEUR: Nathan
 * DATE:    2013-04-23
 *
 */

#ifndef __LikeASir__personnage__
#define __LikeASir__personnage__

#include <iostream>
#include "acteur.h"

class personnage : public acteur {
public:
    enum typePersonnage {
        NON_DEFINI = 0,
        JOUEUR,
        FIN_TYPE_ACTEUR
    };
    personnage();
    ~personnage();
    
    virtual void rafraichir(float delta) = 0;
    virtual void enCollisionAvecActeur(acteur &autre) = 0;
    
    typePersonnage getTypePersonnage();
    int getVie();
    float getDistanceVision();
    sf::Vector2f getDirectionVision();
    
    sf::Vector2f getAntenne1();
    sf::Vector2f getAntenne2();
    
    float getLongueurAntenne();
    
    void setDirectionVision(float x, float y);
    void setDirectionVision(sf::Vector2f vect);
    
    void setLongueurAntenne(float longeur);
    
    bool getAuSol();
    
    void setAuSol(bool val);
    
protected:
    int _vie;
    float _distanceVision;
    sf::Vector2f _directionVision;
    
    sf::Vector2f _antenne1, _antenne2;
    float _longueurAntennes;
    typePersonnage _typePersonnage;
    
    bool _auSol;    // Le héro est au sol?
};

#endif /* defined(__LikeASir__personnage__) */
