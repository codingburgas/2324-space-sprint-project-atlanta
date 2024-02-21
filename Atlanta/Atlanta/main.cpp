#include <iostream>
#include <SFML/Graphics.hpp>

#include "startMenu.h"
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
    
    startButton btn1("Start", { 200, 50 }, 20, Color::Green, Color::Black);
    btn1.setPosition({ 350, 300 });
    btn1.setFont(arial);


    while (window.isOpen())
    {
        Event event;
        if (Keyboard::isKeyPressed(Keyboard::Return)) {
            
        }
        else if (Keyboard::isKeyPressed(Keyboard::Escape))
        {

        }

        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case Event::Closed:
                window.close();
            case Event::MouseMoved:
                if (btn1.isMouseOver(window)) {
                    btn1.setBackColor(Color::White);
                }
                else {
                    btn1.setBackColor(Color::Green);
                }
                break;
            case Event::MouseButtonPressed:
                if (btn1.isMouseOver(window)) {
                    cout << "Test";
                }

            }
        }

        window.clear();
        btn1.drawTo(window);
        window.display();
    }

}