#include <iostream>
#include <SFML/Graphics.hpp>

#include "game.h"
#include "startMenu.h"
#include <cstdlib>
#include <ctime>

RenderWindow window;

Vector2i centerWindow((VideoMode::getDesktopMode().width / 2) - 640, (VideoMode::getDesktopMode().height / 2) - 480);

Font font;

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

void planetTravel(int reps)
{
    spaceShip(200, 500, 0.3, 0.3);
    if (reps == 1)
    {
        Texture source;
        if (!source.loadFromFile("neptun.png"))
        {
                cout << "Image not working";
        }
        Sprite image;
        image.setTexture(source);
        image.setPosition(650, 250);
        image.setScale(1, 1);
        window.draw(image);
    }
}

void gameScreen() {
    window.create(VideoMode(1280, 900), "Atlanta", Style::Titlebar | Style::Close);
    window.setPosition(centerWindow);

    window.setKeyRepeatEnabled(true);

    VertexArray stars(sf::Points);

    drawStars(stars, 200, window.getSize());

    font.loadFromFile("font.ttf");

    Text ready;
    ready.setString("     Are you ready \n\nfor your space tour");
    ready.setCharacterSize(70);
    ready.setPosition({ 470, 150 });
    ready.setFont(font);

    Button go("GO", { 250, 80 }, 80, Color::Magenta, Color::White);
    go.setPosition({ 710, 400 }, 75, 15);
    go.setFont(font);


    bool start = false;

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
                if (go.isMouseOver(window)) {
                    go.setBackColor(Color::Transparent, Color::White);
                }
                else {
                    go.setBackColor(Color::Magenta, Color::White);
                }
                break;
            case Event::MouseButtonPressed:
                if (go.isMouseOver(window))
                {
                    cout << "GO!";
                    start = true;

                }
            }
        }

        window.clear();
        window.draw(stars);
        if (start) {
            planetTravel(1);
        }
        else {
            window.draw(stars);
            window.draw(ready);
            go.drawTo(window);
            spaceShip(15, 500, 0.3, 0.3);
        }
        window.display();
    }
}		