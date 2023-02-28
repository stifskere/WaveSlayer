#include <iostream>
#include "Characters/Characters.h"
#include <sfml/Graphics.hpp>

int main() {
    sf::RenderWindow game_window{{800, 600}, "dique ventana"};
    sf::Event event{};

    sf::View game_view{{0.f, 0.f, 800.f, 600.f * 0.75f}};
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
        float current_window_ratio = (float)current_window_size.x / (float)current_window_size.y;
        sf::Vector2f current_view_size = game_view.getSize();
        float current_view_ratio = (float)current_window_size.x / (float)current_view_size.y;

        sf::FloatRect viewport;
        if (current_window_ratio < current_view_ratio) {
            float width = current_window_ratio / current_view_ratio;
            float xOffset = (1.f - width) / 2.0f;
            viewport = sf::FloatRect{xOffset, 0.0f, width, 1.0f};
        } else {
            float height = current_view_ratio / current_window_ratio;
            float yOffset = (1.0f - height) / 2.0f;
            viewport = sf::FloatRect(0.0f, yOffset, 1.0f, height);
        }

        game_view.setViewport(viewport);
        game_window.setView(game_view);

        game_window.clear(sf::Color::Black);

        game_window.draw(player);

        game_window.display();
    }

    return 0;
}
