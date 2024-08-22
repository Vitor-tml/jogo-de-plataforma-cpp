#include "CollisionManager.h"

CollisionManager::CollisionManager() {
    // Initialize any data members if needed
}

bool CollisionManager::checkCollision(const sf::Sprite& object1, const sf::Sprite& object2) const {
    return object1.getGlobalBounds().intersects(object2.getGlobalBounds());
}

void CollisionManager::handleCollisions(sf::Sprite& player, const std::vector<sf::Sprite>& platforms) const {
    for (const auto& platform : platforms) {
        if (checkCollision(player, platform)) {
            // Handle collision response (e.g., stop movement, adjust player position)
            player.setPosition(player.getPosition().x, platform.getPosition().y - player.getGlobalBounds().height);
            break; // Stop checking further once a collision is found
        }
    }
}
