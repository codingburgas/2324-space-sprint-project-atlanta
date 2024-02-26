#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

void gameScreen();

void spaceShip(int posX, int posY, float scale1, float scale2);

void drawStars(VertexArray& stars, int numStars, Vector2u windowSize);

void planetTravel(int reps);