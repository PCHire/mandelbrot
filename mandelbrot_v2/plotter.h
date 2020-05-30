#pragma once
#include <utility>
#include <complex>
#include <SFML\Graphics.hpp>
#include <iostream>

#define ITERATIONS 20

class Plotter
{
public:
	Plotter();
	~Plotter();
	
	sf::Uint8 *plot(sf::RenderWindow &);
private:
	std::pair<int, int> xRange, yRange;
	int addColourToArray(sf::Uint8 *, sf::Uint8, sf::Uint8, sf::Uint8, int);
	std::pair<double, double> screenToAxes(int, int, sf::RenderWindow &);
};

