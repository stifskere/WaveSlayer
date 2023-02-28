#include <iostream>
#include "Characters/Characters.h"
#include <sfml/Graphics.hpp>

int main() {
    sf::RenderWindow game_window{{800, 600}, "dique ventana"};
    sf::Event event{};

    Playable player{"./Textures/Character.png", {1, 1}, {400, 300}};

    while (game_window.isOpen()) {
        while (game_window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                game_window.close();
                exit(0);
            }
            
            player.pollEvents(event, sf::Keyboard::W, sf::Keyboard::S, sf::Keyboard::A, sf::Keyboard::D);
        }

        game_window.clear(sf::Color::Black);

        game_window.draw(player);

        game_window.display();
    }

    return 0;
}
