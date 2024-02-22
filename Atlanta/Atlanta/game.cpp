#include <iostream>
#include <SFML/Graphics.hpp>

#include "game.h"
#include "startMenu.h"

void gameScreen() {
    RenderWindow window;

    Vector2i centerWindow((VideoMode::getDesktopMode().width / 2) - 640, (VideoMode::getDesktopMode().height / 2) - 480);

    window.create(VideoMode(1280, 900), "Atlanta", Style::Titlebar | Style::Close);
    window.setPosition(centerWindow);

    window.setKeyRepeatEnabled(true);

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
        window.display();
    }
}		