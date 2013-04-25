#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "UnicornInclusion.h"

#include "niveau.h"
#include "acteur.h"

#include "joueur.h"
#include "chargeurNiveau.h"

int main (int argc, const char * argv[])
{
    // Creation de la fenetre
    sf::RenderWindow window(sf::VideoMode(800, 600), "Like A Sir");

    sf::View view = sf::View(sf::FloatRect(0,0,160,120));
    
    joueur hommeAuChapeau;
    
    
    sf::Texture texture;
    texture.loadFromFile("tuiles.png");
    
    sf::Image image;
    image.loadFromFile("niveau.png");
    
    std::map<int, tuile> comparaison;
    sf::Color col(255,255,255);
    
    tuile Tuile;
    Tuile.identifiant = 0;
    Tuile.mur = false;
    Tuile._sprite.setTexture(texture);
    
    comparaison[convertirCouleurEnInt(col)] = Tuile;
    
    col = sf::Color(0,0,0);
    
    Tuile.identifiant = 1;
    Tuile.mur = true;
    Tuile._sprite.setTexture(texture);
    
    comparaison[convertirCouleurEnInt(col)] = Tuile;
    
    niveau superNiveau = chargeurNiveau::chargerNiveauDeImage(image, comparaison);
    
    hommeAuChapeau.setPosition(10, 10);
    
    superNiveau.ajouterActeur(&hommeAuChapeau);
    
    // Début de la boucle principale
    while (window.isOpen())
    {
        view.setCenter(hommeAuChapeau.getPosition());
        window.setView(view);
            
        // Récupération des évènements de la fenêtre
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed)
                window.close();
            
            // Escape pressed : exit
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                window.close();
        }

        superNiveau.rafraichir(1.0f);
        
        // Efface le contenu de l'écran
        window.clear();

        int y1, y2, x1, x2;
        
        x1 = view.getCenter().x - view.getSize().x / 2;
        x1 /= 8;
        
        x1--;
        
        x2 = view.getCenter().x + view.getSize().x / 2;
        x2 /= 8;
        
        x2++;
        
        y1 = view.getCenter().y - view.getSize().y / 2;
        y1 /= 8;
        
        y1--;
        
        y2 = view.getCenter().y + view.getSize().y / 2;
        y2 /= 8;
        
        y2++;
        
        if(x1 < 0)
            x1 = 0;
        
        if(x2 > 99)
            x2 = 99;
        
        if(y1 < 0)
            y1 = 0;
        
        if(y2 > 99)
            y2 = 99;
        
        for(int i = y1 ; i < y2; i++) {
            for(int j = x1 ; j < x2; j++) {
                
                if(superNiveau.getTuile(j, i)->identifiant != 0)
                    window.draw(superNiveau.getTuile(j, i)->_sprite);
            }
        }
        
        hommeAuChapeau.afficher(&window);
        
        // Rafraichit l'écran
        window.display();
    }

    return EXIT_SUCCESS;
}
