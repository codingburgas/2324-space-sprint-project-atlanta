#include <iostream> 
#include <stdio.h> 

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

    Button start("Start", { 200, 50 }, 20, Color::Magenta, Color::White);
    start.setPosition({ 350, 300 });
    start.setFont(arial);

    Button rules("Rules", { 200, 50 }, 20, Color::Magenta, Color::White);
    rules.setPosition({ 350, 400 });
    rules.setFont(arial);

    Button exit("Exit", { 200, 50 }, 20, Color::Magenta, Color::White);
    exit.setPosition({ 350, 500 });
    exit.setFont(arial);

    Text rulesText;
    rulesText.setString("These are the game rules:\n1. Rule 1\n2. Rule 2\n3. Rule 3");
    rulesText.setCharacterSize(20);
    rulesText.setPosition(200.f, 250.f);
    rulesText.setFont(arial);

    Text warningText;
    warningText.setString ("Please, read the rules first!");
    warningText.setCharacterSize(40);
    warningText.setPosition({200, 550});
    warningText.setFont(arial);
 


    Button back("Back", { 200, 50 }, 20, Color::Magenta, Color::White);
    back.setPosition({ 350, 800 });
    back.setFont(arial);

    bool showRules = false;
    bool rulesRead = false;

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
                if (start.isMouseOver(window)) {
                    start.setBackColor(Color::Transparent, Color::White);
                }
                else {
                    start.setBackColor(Color::Magenta, Color::White);
                }
                if (rules.isMouseOver(window)) {
                    rules.setBackColor(Color::Transparent, Color::White);
                }
                else {
                    rules.setBackColor(Color::Magenta, Color::White);
                }
                if (back.isMouseOver(window)) {
                    back.setBackColor(Color::Transparent, Color::White);
                }
                else {
                    back.setBackColor(Color::Magenta, Color::White);
                }

                if (exit.isMouseOver(window)) {
                    exit.setBackColor(Color::Transparent, Color::White);
                }
                else {
                    exit.setBackColor(Color::Magenta, Color::White);
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
        window.draw(stars);
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