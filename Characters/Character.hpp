#pragma once

#include <sfml/Graphics.hpp>
#include <thread>

class Character : public sf::Sprite {
    sf::Texture player_texture;
public:
    float health = 100.0f;
    float base_min_damage = 4.0f;
    float base_max_damage = 7.0f;
    float critical_damage = 10.0f;
    float speed = 5.0f;

    explicit Character(const std::string& file_path, const sf::Vector2f& size = {1, 1}, const sf::Vector2f& position = {0, 0}) {
        player_texture = sf::Texture{};
        player_texture.loadFromFile(file_path);
        setTexture(player_texture);
        setScale(size);
        setPosition(position);
    }

    explicit Character(const sf::Texture& texture, const sf::Vector2f& size = {1, 1}, const sf::Vector2f& position = {0, 0}) {
        player_texture = texture;
        setTexture(player_texture);
        setScale(size);
        setPosition(position);
    }

    void move_by_x(float movement) {
        sf::Vector2f position = getPosition();
        position.x += movement;
        setPosition(position);
    }

    void move_by_y(float movement) {
        sf::Vector2f position = getPosition();
        position.y += movement;
        setPosition(position);
    }

    void slide_by_x(float movement) {
        if (movement == 0 || speed == 0)
            return;

        std::function thread_lambda = [this, movement]() -> void {
            sf::Vector2f current_position = this->getPosition();
            slide_position(current_position, movement, true);
            this->setPosition(current_position);
        };

        std::thread thread(thread_lambda);
        thread.detach();
    }

    void slide_by_y(float movement) {
        if (movement == 0 || speed == 0)
            return;

        std::function thread_lambda = [this, movement]() -> void {
            sf::Vector2f current_position = this->getPosition();
            slide_position(current_position, movement, false);
            this->setPosition(current_position);
        };

        std::thread thread(thread_lambda);
        thread.detach();
    }
private:
    void slide_position(sf::Vector2f& position, float movement, bool slide_x) const {
        while (slide_x ? (position.x < movement) : (position.y < movement)) {
            float distance = slide_x ?
                    (movement > 0 ? std::min(movement - position.x, speed) : std::max(movement - position.x, -speed)) :
                    movement > 0 ? std::min(movement - position.y, speed) : std::max(movement - position.y, -speed);
            slide_x ? position.x += distance : position.y += distance;
        }
    }
};
