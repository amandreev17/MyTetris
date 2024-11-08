#include <SFML/Graphics.hpp>
#include "src/Button.cpp"

int main()
{
    sf::Texture image_button, image_button_press;
    image_button.loadFromFile("button.png");
    image_button_press.loadFromFile("button1.png");
    Button button(sf::Vector2f(0.0f, 550.0f), image_button, image_button_press);
    sf::RenderWindow window(sf::VideoMode(900, 700), "Tetris in your mind!");
    sf::Texture image;
    image.loadFromFile("background.png");
    sf::Sprite sprite(image);
    sf::Vector2f targetSize(900.0f, 700.0f); 
    sprite.setScale(targetSize.x / sprite.getLocalBounds().width, targetSize.y / sprite.getLocalBounds().height);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            
            if (event.type == sf::Event::KeyPressed) {
                 if (event.key.code == sf::Keyboard::Enter) {
                    button.checkClick(true);
                 }
            }
            if (event.type == sf::Event::KeyReleased) {
                 if (event.key.code == sf::Keyboard::Enter) {
                    button.checkClick(false);
                 }
            }
        }

        window.clear();
        window.draw(sprite);
        window.draw(*button.getSprite());
        window.display();
    }

    return 0;
}