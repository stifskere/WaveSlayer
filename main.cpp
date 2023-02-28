#include <iostream>
#include "Characters/Characters.h"
#include <sfml/Graphics.hpp>

int main() {
    sf::RenderWindow game_window{{800, 600}, "dique ventana"};
    sf::Event event{};

    sf::View game_view{{0.f, 0.f, 800.f, 600.f}};
    game_view.setViewport({0.f, 0.f, 1.f, 1.f});

    Playable player{"./Textures/Character.png", {1, 1}, {400, 300}};

    while (game_window.isOpen()) {
        while (game_window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                game_window.close();
                exit(0);
            }
            
            player.pollEvents(event, sf::Keyboard::W, sf::Keyboard::S, sf::Keyboard::A, sf::Keyboard::D);
        }

        sf::Vector2u current_window_size = game_window.getSize();
        game_view.setSize((float)current_window_size.x, (float)current_window_size.y);
        game_window.setView(game_view);

        game_window.clear(sf::Color::Black);

        game_window.draw(player);

        game_window.display();
    }

    return 0;
}
