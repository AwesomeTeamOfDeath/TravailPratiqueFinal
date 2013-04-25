/*
 * FICHIER: collectionnable.cpp
 * PROJET:  LikeASir
 *
 * AUTHEUR: Nathan
 * DATE:    2013-04-23
 *
*/

#include "collectionnable.h"

collectionnable::collectionnable()
:acteur()
{
    _type = COLLECTIONNABLE;
    _typeCollectionnable = NON_DEFINI;
}

collectionnable::~collectionnable() {
    
}

collectionnable::typeCollectionnable collectionnable::getTypeCollectionnable() {
    return _typeCollectionnable;
}