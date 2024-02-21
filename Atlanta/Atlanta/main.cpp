#include <SFML/Graphics.hpp>

using namespace sf;
    
int main()
{
    RenderWindow window(VideoMode(800, 800), "Atlanta");
    window.setFramerateLimit(60);

    return 0;
}