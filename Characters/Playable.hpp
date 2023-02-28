#pragma once

#include "Character.hpp"

class Playable : public Character {
    bool moving_forward = false;
    bool moving_backward = false;
    bool moving_left = false;
    bool moving_right = false;
public:
    using Character::Character;

    void pollEvents(sf::Event& event, sf::Keyboard::Key forwards, sf::Keyboard::Key backwards, sf::Keyboard::Key left, sf::Keyboard::Key right) {
        if (event.type != sf::Event::KeyPressed && event.type != sf::Event::KeyReleased)
            return;

        if (event.key.code == forwards)
            move_by_y(-speed);

        if (event.key.code == backwards)
            move_by_y(speed);

        if (event.key.code == left)
            move_by_x(-speed);

        if (event.key.code == right)
            move_by_x(speed);
    }
};