/*
 * FICHIER: interaction.cpp
 * PROJET:  LikeASir
 *
 * AUTHEUR: Nathan
 * DATE:    2013-04-23
 *
*/

#include "interaction.h"

interaction::interaction()
:acteur()
{
    _type = INTERACTIONNABLE;
    _typeInteraction = NON_DEFINI;
}

interaction::~interaction() {
    
}

interaction::typeInteraction interaction::getTypeInterraction() {
    return _typeInteraction;
}