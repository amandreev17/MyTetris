#include "include/Button.hpp"

Button::Button(sf::Vector2f location, const sf::Texture& normalCond, const sf::Texture& clickCond) {
    this->normalCondition.setTexture(normalCond);
    this->clickCondition.setTexture(clickCond);
    this->normalCondition.setPosition(location);
    this->clickCondition.setPosition(location);
    currentSpr = &this->normalCondition;
}

sf::Sprite* Button::getSprite() {
    return currentSpr;
}

void Button::setPress(bool click) {
    if (click) {
        currentSpr = &clickCondition;
        return;
    }
    currentSpr = &normalCondition;
}

bool Button::checkClick(sf::Vector2i mouseLocation) {
    if (mouseLocation.x > 0) {
        if (static_cast<float>(mouseLocation.x) > currentSpr->getPosition().x &&
        static_cast<float>(mouseLocation.x) < currentSpr->getPosition().x + currentSpr->getGlobalBounds().width &&
        static_cast<float>(mouseLocation.y) > currentSpr->getPosition().y &&
        static_cast<float>(mouseLocation.y) < currentSpr->getPosition().y + currentSpr->getGlobalBounds().height) {
            setPress(!press);
            return true;
        }
    }
    else {
        if (press) {
            setPress(!press);
            return true;
        }
    }
    return false;
}
