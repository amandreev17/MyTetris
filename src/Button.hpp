#include </opt/homebrew/Cellar/sfml/2.6.1/include/SFML/Graphics.hpp>
#include <iostream>

class Button {
    private:
        sf::Sprite normalCondition;
        sf::Sprite clickCondition;
        sf::Sprite* currentSpr;
        void setPress(bool);
    public:
        Button(sf::Vector2f location, const sf::Texture& normalCond, const  sf::Texture& clickCond);
        bool checkClick(bool click);
        sf::Sprite* getSprite();
};