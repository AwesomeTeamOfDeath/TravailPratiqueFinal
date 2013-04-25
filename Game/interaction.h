/*
 * FICHIER: interaction.h
 * PROJET:  LikeASir
 *
 * AUTHEUR: Nathan
 * DATE:    2013-04-23
 *
 */

#ifndef __LikeASir__interaction__
#define __LikeASir__interaction__

#include <iostream>
#include "acteur.h"

class interaction : public acteur{
public:
    enum typeInteraction {
        NON_DEFINI = 0,
        PORTE,
        CACHETTE,
        FIN_TYPE_INTERACTION
    };
    
    interaction();
    ~interaction();
    
    typeInteraction getTypeInterraction();
    
    // Rafraichir les informations de l'acteur [ABSTRAITE]
    virtual void rafraichir(float delta) = 0;
    
    virtual void enCollisionAvecActeur(acteur &autre) = 0;
    
protected:
    bool _active;
    typeInteraction _typeInteraction;
};

#endif /* defined(__LikeASir__interaction__) */
