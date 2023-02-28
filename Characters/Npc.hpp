#pragma once

#include <cmath>
#include "Character.hpp"

class Npc : public Character {
public:
    using Character::Character;

    bool hasTarget = false;

    void follow(const Character& character) {
        hasTarget = true;

        auto thread_lambda = [this, &character]() -> void {
            while (hasTarget) {
                sf::Vector2f target_position = character.getPosition();
                sf::Vector2f current_position = getPosition();

                auto distance = (float)std::sqrt(std::pow(target_position.x - current_position.x, 2) + std::pow(target_position.y - current_position.y, 2));
                if (distance > 50.0f) {
                    sf::Vector2f direction = target_position - current_position;
                    direction = direction / distance;
                    sf::Vector2f movement = direction * 5.0f;
                    move(movement);
                } else {
                    hasTarget = false;
                }

                std::this_thread::sleep_for(std::chrono::milliseconds(10));
            }
        };

        std::thread thread(thread_lambda);
        thread.detach();
    }
};