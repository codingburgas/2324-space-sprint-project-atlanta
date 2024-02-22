#include <iostream>
#include <SFML/Graphics.hpp>

#include "startMenu.h"
#include "game.h"
using namespace sf;
using namespace std;
    
int main()
{
    RenderWindow window;

    Vector2i centerWindow((VideoMode::getDesktopMode().width / 2) - 445, (VideoMode::getDesktopMode().height / 2) - 480);

    window.create(VideoMode(900, 900), "Atlanta", Style::Titlebar | Style::Close);
    window.setPosition(centerWindow);

    window.setKeyRepeatEnabled(true);

    Font arial;
    arial.loadFromFile("arial.ttf");

    Button start("Start", { 200, 50 }, 20, Color::Green, Color::Black);
    start.setPosition({ 350, 300 });
    start.setFont(arial);

    Button rules("Rules", { 200, 50 }, 20, Color::Green, Color::Black);
    rules.setPosition({ 350, 400 });
    rules.setFont(arial);

    Button exit("Exit", { 200, 50 }, 20, Color::Green, Color::Black);
    exit.setPosition({ 350, 500 });
    exit.setFont(arial);

    Text rulesText;
    rulesText.setString("These are the game rules:\n1. Rule 1\n2. Rule 2\n3. Rule 3");
    rulesText.setCharacterSize(20);
    rulesText.setPosition(200.f, 250.f);
    rulesText.setFont(arial);

    Text warningText;
    warningText.setString("Please, read the rules first!");
    warningText.setCharacterSize(20);
    warningText.setPosition({350, 550});
    warningText.setFont(arial);

    Button back("Back", { 200, 50 }, 20, Color::Green, Color::Black);
    back.setPosition({ 350, 800 });
    back.setFont(arial);

    bool showRules = false;
    bool rulesRead = false;

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
                if (start.isMouseOver(window)) {
                    start.setBackColor(Color::White);
                }
                else {
                    start.setBackColor(Color::Green);
                }
                if (rules.isMouseOver(window)) {
                    rules.setBackColor(Color::White);
                }
                else {
                    rules.setBackColor(Color::Green);
                }
                if (back.isMouseOver(window)) {
                    back.setBackColor(Color::White);
                }
                else {
                    back.setBackColor(Color::Green);
                }

                if (exit.isMouseOver(window)) {
                    exit.setBackColor(Color::White);
                }
                else {
                    exit.setBackColor(Color::Green);
                }

                break;
            case Event::MouseButtonPressed:
                if (start.isMouseOver(window)) {
                    if (rulesRead) {
                        cout << "Start";
                        window.close();
                        gameScreen();
                    }
                }
                else if (rules.isMouseOver(window))
                {
                    showRules = !showRules;
               
                }
                else if (back.isMouseOver(window))
                {
                    rulesRead = true;
                    showRules = !showRules;

                }
                else if (exit.isMouseOver(window))
                {
                    window.close();
                }

            }
        }

        window.clear();

        if (showRules) {
            window.draw(rulesText);
            back.drawTo(window);
        }
        else if(!rulesRead){
            start.drawTo(window);
            rules.drawTo(window);
            exit.drawTo(window);
            window.draw(warningText);
        }
        else {
            start.drawTo(window);
            rules.drawTo(window);
            exit.drawTo(window);
        }
        window.display();
    }
}