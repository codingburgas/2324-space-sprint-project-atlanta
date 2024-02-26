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

    Font font;
    font.loadFromFile("font.ttf");

    Button start("Start", { 200, 50 }, 40, Color::Magenta, Color::White);
    start.setPosition({ 350, 300 }, 43.6,1 );
    start.setFont(font);

    Button rules("Rules", { 200, 50 }, 40, Color::Magenta, Color::White);
    rules.setPosition({ 350, 400 }, 40.5, 1);
    rules.setFont(font);

    Button exit("Exit", { 200, 50 }, 40, Color::Magenta, Color::White);
    exit.setPosition({ 350, 500 }, 62, 1);
    exit.setFont(font);

    Text rulesText;
    rulesText.setString("You have to go through all the \n\nplanets and read short descriptions \n\nfor each one of them \n\nThis information will \n\ngive you basic knowledge \n\nabout the solar system");
    rulesText.setCharacterSize(40);
    rulesText.setPosition(50.f, 250.f);
    rulesText.setFont(font);

    Text warningText;
    warningText.setString ("Please read the rules first");
    warningText.setCharacterSize(40);
    warningText.setPosition({160, 650});
    warningText.setFont(font);
 
    Text title;
    title.setString("Atlanta");
    title.setCharacterSize(100);
    title.setPosition({ 240, 100 });
    title.setFont(font);

    Button back("Back", { 200, 50 }, 40, Color::Magenta, Color::White);
    back.setPosition({ 350, 800 }, 50, 2);
    back.setFont(font);

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
            window.draw(title);
            start.drawTo(window);
            rules.drawTo(window);
            exit.drawTo(window);
            window.draw(warningText);
        }
        else {
            window.draw(title);
            start.drawTo(window);
            rules.drawTo(window);
            exit.drawTo(window);
        }
        window.display();
    }
}