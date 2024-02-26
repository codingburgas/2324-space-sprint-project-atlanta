#include <iostream>
#include <SFML/Graphics.hpp>

#include "game.h"
#include "startMenu.h"
#include <cstdlib>
#include <ctime>

RenderWindow window;

Vector2i centerWindow((VideoMode::getDesktopMode().width / 2) - 640, (VideoMode::getDesktopMode().height / 2) - 480);

Font font;

int i = 1;

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
    if (!source.loadFromFile("img/spaceship.jpg"))
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
    if (reps != 9) {
        spaceShip(200, 500, 0.3, 0.3);
    }
    Texture source;
    Sprite image;
    Text info;
    info.setCharacterSize(50);
    info.setPosition({ 100, 150 });
    info.setFont(font);
    if (reps == 1)
    {
        if (!source.loadFromFile("img/neptun.png"))
        {
                cout << "Image not working";
        }
        info.setString(" Neptune is blue and stormy \n and it has fourteen moons \n including Triton with \n retrograde orbit");
        image.setPosition(650, 250);
        image.setScale(1, 1);
    }
    if (reps == 2)
    {
        if (!source.loadFromFile("img/uranus.png"))
        {
            cout << "Image not working";
        }
        info.setString("Uranus is tilted \non its side and has a bluegreen \nhue and twentyseven moons \nand narrow rings");
        image.setPosition(650, 250);
        image.setScale(1, 1);
    }
    if (reps == 3)
    {
        if (!source.loadFromFile("img/saturn.png"))
        {
            cout << "Image not working";
        }
        info.setString("Saturn is famous \nfor its rings and has a \nhydrogenhelium atmosphere and \neightytwo moons");
        image.setPosition(650, 280);
        image.setScale(1, 1);
    }
    if (reps == 4)
    {
        if (!source.loadFromFile("img/jupiter.png"))
        {
            cout << "Image not working";
        }
        info.setString("Jupiter is the \nlargest planet and it has \ncolorful clouds and the \nGreat Red Spot and over \nseventynine moons");
        image.setPosition(650, 280);
        image.setScale(1, 1);
    }
    if (reps == 5)
    {
        if (!source.loadFromFile("img/mars.png"))
        {
            cout << "Image not working";
        }
        info.setString("Mars the Red Planet \nhas polar ice caps and volcanoes \nand two moons Phobos \nand Deimos");
        image.setPosition(650, 280);
        image.setScale(1, 1);
    }
    if (reps == 6)
    {
        if (!source.loadFromFile("img/earth.png"))
        {
            cout << "Image not working";
        }
        info.setString("The Earth is our home \nand it supports life with water \nand land and has one moon");
        image.setPosition(650, 280);
        image.setScale(1, 1);
    }
    if (reps == 7)
    {
        if (!source.loadFromFile("img/venus.png"))
        {
            cout << "Image not working";
        }
        info.setString("Venus is Earths sister \nplanet and it has a thick \ncarbon dioxide atmosphere \nand no moons");
        image.setPosition(650, 280);
        image.setScale(1, 1);
    }
    if (reps == 8)
    {
        if (!source.loadFromFile("img/mercury.png"))
        {
            cout << "Image not working";
        }
        info.setString("Mercury is closest \nto the Sun and has a rocky \nsurface and extreme temperatures \nand no moons");
        image.setPosition(650, 280);
        image.setScale(1, 1);
    }
    if (reps == 9)
    {
        if (!source.loadFromFile("img/sun.png"))
        {
            cout << "Image not working";
        }
        info.setCharacterSize(50);
        info.setPosition({ 250, 50 });
        info.setString("         Congratulations \n     you finished our little \n     informative space tour\nnow you have basic knowledge \n      about the solar system\n  thank you for participating");
        image.setPosition(370, 280);
        image.setScale(1.1, 1.1);
    }
    image.setTexture(source);
    window.draw(image);
    window.draw(info);
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

    Button next("NEXT", { 200, 50 }, 40, Color::Magenta, Color::White);
    next.setPosition({ 1050, 800 }, 50, 1);
    next.setFont(font);
    Button finish("FINISH", { 200, 50 }, 40, Color::Magenta, Color::White);
    finish.setPosition({ 550, 800 }, 45, 1);
    finish.setFont(font);

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
                if (next.isMouseOver(window)) {
                    next.setBackColor(Color::Transparent, Color::White);
                }
                else {
                    next.setBackColor(Color::Magenta, Color::White);
                }
                if (finish.isMouseOver(window)) {
                    finish.setBackColor(Color::Transparent, Color::White);
                }
                else {
                    finish.setBackColor(Color::Magenta, Color::White);
                }
                break;
            case Event::MouseButtonPressed:
                if (go.isMouseOver(window))
                {
                    start = true;
                }
                else if (next.isMouseOver(window))
                {
                    i += 1;
                    cout << i;
                }
                else if (finish.isMouseOver(window))
                {
                    window.close();
                }
            }
        }

        window.clear();
        window.draw(stars);
        if (start) {
            if (i != 9)
            {
                next.drawTo(window);
            }
            if (i == 1) {
                planetTravel(1);
            }
            else if (i == 2)
            {
                planetTravel(2);
            }
            else if (i == 3)
            {
                planetTravel(3);
            }
            else if (i == 4)
            {
                planetTravel(4);
            }
            else if (i == 5)
            {
                planetTravel(5);
            }
            else if (i == 6)
            {
                planetTravel(6);
            }
            else if (i == 7)
            {
                planetTravel(7);
            }
            else if (i == 8)
            {
                planetTravel(8);
            }
            else if (i == 9)
            {
                planetTravel(9);
                finish.drawTo(window);
            }
            
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