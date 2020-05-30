#include "pch.h"
#include "setup.h"

sf::RenderWindow *setup() {
 sf::RenderWindow *window = new sf::RenderWindow(sf::VideoMode(640, 480), "Mandelbrot Set Test");
 return window;
}