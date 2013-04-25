/*
 * FICHIER: joueur.h
 * PROJET:  LikeASir
 *
 * AUTHEUR: Nathan
 * DATE:    2013-04-23
 *
 */

#ifndef __LikeASir__joueur__
#define __LikeASir__joueur__

#include <iostream>
#include "personnage.h"

class joueur : public personnage {
public:
    joueur();
    ~joueur();
    
    virtual void rafraichir(float delta);
    virtual void enCollisionAvecActeur(acteur &autre);
    virtual void afficher(sf::RenderTarget *destination);
    
    bool getCache();
    void setCache(bool val);
    
private:
    bool _cache;    // Le héro est caché?
};

#endif /* defined(__LikeASir__joueur__) */
