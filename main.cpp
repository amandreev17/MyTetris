#include </opt/homebrew/Cellar/sfml/2.6.1/include/SFML/Graphics.hpp>


int main()
{
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
        }

        window.clear();
        window.draw(sprite);
        window.display();
    }

    return 0;
}