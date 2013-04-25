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
    
    _tuiles[y][x]._sprite.setPosition(x * 8, y * 8);
    
    _tuiles[y][x]._sprite.setTextureRect(sf::IntRect((int)(_tuiles[y][x].identifiant % 5) * 8, (int)(_tuiles[y][x].identifiant/5) * 8,8,8));
    
    return true;
}

void niveau::ajouterActeur(acteur *_acteur) {
    _acteurs.push_back(_acteur);
}

void niveau::rafraichir(float delta) {
    std::list<acteur*>::iterator it;
    
    // On parcourt la liste des acteurs...
    for(it = _acteurs.begin(); it != _acteurs.end(); ++it) {
        // On ajoute la force gravitationnelle à la vélocité du héro
        (*it)->setVelocite((*it)->getVelocite().x, (*it)->getVelocite().y + 0.00015f);
        
        // On effectue sa mise à jours
        (*it)->rafraichir(delta);
        
        // On détecte quel type d'acteur il s'agit pour adapter les prochaines instructions...
        switch((*it)->getType()) {
            case acteur::NON_DEFINI:

                break;
                
            // Si c'est un personnage,
            case acteur::PERSONNAGE:
                // On convertie l'acteur en personnage pour manipuler les propriétés qui lui sont propre
                personnage *ActuelPersonnage = dynamic_cast<personnage*>(*it);
            
                //On récupère la position des antennes de détections du sol
                sf::Vector2f a1, a2;    // Les antennes
                
                a1 = ActuelPersonnage->getPosition() + ActuelPersonnage->getAntenne1();
                a2 = ActuelPersonnage->getPosition() + ActuelPersonnage->getAntenne2();
                
                
                // On détecte dans quel bloc les antennes touchent
                int x1, y1, x2, y2;
                
                x1 = a1.x / 8;
                x2 = a2.x / 8;
                
                y1 = a1.y / 8;
                y2 = a2.y / 8;
                
                
                // Si les deux antennes touches le sol, alors le personnage est considéré comme sur le sol
                if(_tuiles[y1][x1].mur == true && _tuiles[y2][x2].mur == true) {
                    ActuelPersonnage->setAuSol(true);
                }
                // Une antenne est dans le vide, on applique une force pour pousser le personnage dans le vide
                else if(_tuiles[y1][x1].mur == true && _tuiles[y2][x2].mur == false) {
                    ActuelPersonnage->setVelocite(ActuelPersonnage->getVelocite().x + 0.015f, ActuelPersonnage->getVelocite().y);
                    ActuelPersonnage->setAuSol(false);
                }
                else if(_tuiles[y1][x1].mur == false && _tuiles[y2][x2].mur == true) {
                    ActuelPersonnage->setVelocite(ActuelPersonnage->getVelocite().x - 0.015f, ActuelPersonnage->getVelocite().y);
                    ActuelPersonnage->setAuSol(false);
                }
                
                // Si les antennes ne détectent rien le personnage est dans les airs
                else {
                    ActuelPersonnage->setAuSol(false);
                }
                break;
        }
        
        // On déplace l'acteur en fonction de sa vélocité.
        (*it)->setPosition((*it)->getPosition().x + (*it)->getVelocite().x, (*it)->getPosition().y + (*it)->getVelocite().y);
    }
}