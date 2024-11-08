#include "Button.hpp"

Button::Button(sf::Vector2f location, const sf::Texture& normalCond, const sf::Texture& clickCond) {
    sf::Vector2f targetSize(300.0f, 150.0f);
    this->normalCondition.setTexture(normalCond);
    this->normalCondition.setScale(
    targetSize.x / normalCondition.getLocalBounds().width, 
    targetSize.y / normalCondition.getLocalBounds().height);
    this->clickCondition.setTexture(clickCond);
    this->clickCondition.setScale(
    targetSize.x / clickCondition.getLocalBounds().width, 
    targetSize.y / clickCondition.getLocalBounds().height);
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

bool Button::checkClick(bool click) {
    if (click) {
        setPress(click);
        return true;
    };
    setPress(false);
    return false;
}
