#include <SFML/Graphics.hpp>
#include <iostream>

#define PLAYER_SIZE 20
#define WIDTH 1000
#define HEIGHT 1000

void displayWindow();
void playerMovement();
void drawMap();

    sf::RectangleShape player(sf::Vector2f(PLAYER_SIZE, PLAYER_SIZE));
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Doom!");
    sf::Event event;
    double pX = 50, pY = 50;

int main()
{
    player.setFillColor(sf::Color::Red);

    while (window.isOpen())
    {
        if(window.pollEvent(event) && event.type == sf::Event::Closed)
            window.close();
        
        playerMovement();
        displayWindow();
    }

    return 0;
}

void displayWindow()
{
    window.clear(sf::Color::Cyan);
    drawMap();
    window.draw(player);
    window.display();
}

void playerMovement()
{
    if (event.type == sf::Event::KeyPressed)
    {
        if (event.key.code == sf::Keyboard::Up)
            pY -= 0.5;
        else if (event.key.code == sf::Keyboard::Down)
            pY += 0.5;
        else if (event.key.code == sf::Keyboard::Right)
            pX += 0.5;
        else if (event.key.code == sf::Keyboard::Left)
            pX -= 0.5;
    }
    player.setPosition(pX, pY);
}

void drawMap()
{
    int mapX = 10, mapY = 10, mapSize = mapX * mapY;
    int map[] =
    {
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
        1, 0, 0, 0, 1, 0, 0, 0, 0, 1,
        1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
        1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
        1, 0, 0, 0, 0, 1, 1, 0, 0, 1,
        1, 0, 1, 1, 1, 1, 1, 0, 0, 1,
        1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
        1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1
    };


}