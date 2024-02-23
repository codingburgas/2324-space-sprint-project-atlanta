#include <iostream>
#include <SFML/Graphics.hpp>

#include "game.h"
#include "startMenu.h"
#include <cstdlib>
#include <ctime>

RenderWindow window;

Vector2i centerWindow((VideoMode::getDesktopMode().width / 2) - 640, (VideoMode::getDesktopMode().height / 2) - 480);

void drawStars(VertexArray& stars, int numStars, Vector2u windowSize) {
    srand(static_cast<unsigned int>(time(nullptr)));

    for (int i = 0; i < numStars; ++i) {
        float x = static_cast<float>(rand() % windowSize.x);
        float y = static_cast<float>(rand() % windowSize.y);
        stars.append(Vertex(Vector2f(x, y), Color::White));
    }
}

void spaceShip(int posX, int posY, float scale1, float scale2)
{
    Texture source;
    if (!source.loadFromFile("spaceship.jpg"))
    {
        cout << "Image not working";
    }
    Sprite image;
    image.setTexture(source);
    image.setPosition(posX, posY);
    image.setScale(scale1, scale2);
    window.draw(image);
}


void gameScreen() {
    window.create(VideoMode(1280, 900), "Atlanta", Style::Titlebar | Style::Close);
    window.setPosition(centerWindow);

    window.setKeyRepeatEnabled(true);

    VertexArray stars(sf::Points);

    drawStars(stars, 200, window.getSize());

    while (window.isOpen())
    {
        Event event;
        if (Keyboard::isKeyPressed(Keyboard::Escape))
        {
            window.close();
        }

        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case Event::Closed:
                window.close();
            case Event::MouseMoved:
                break;
            case Event::MouseButtonPressed:
                break;
            }
        }

        window.clear();
        window.draw(stars);
        spaceShip(15, 500, 0.3, 0.3);
        window.display();
    }
}		