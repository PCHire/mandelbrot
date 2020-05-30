#include "pch.h"
#include "plotter.h"


Plotter::Plotter()
{
	this->xRange = std::make_pair(-2, 1);
	this->yRange = std::make_pair(-1, 1);
}

int Plotter::addColourToArray(sf::Uint8 *pixels, sf::Uint8 r, sf::Uint8 g, sf::Uint8 b, int ptr)
{
	pixels[ptr] = r;
	pixels[ptr + 1] = g;
	pixels[ptr + 2] = b;
	pixels[ptr + 3] = 255;
	return 4;
}

std::pair<double, double> Plotter::screenToAxes(int x, int y, sf::RenderWindow &window) {
	//Gets screen sizes
	int screenX = window.getSize().x;
	int screenY = window.getSize().y;

	//Range of axes of the graph
	int axesX = this->xRange.second - this->xRange.first;
	int axesY = this->yRange.second - this->yRange.first;

	//Defines the step from pixel to pixel
	double xStep = static_cast<double>(axesX) / static_cast<double>(screenX);
	double yStep = static_cast<double>(axesY) / static_cast<double>(screenY);

	//Creates co-ords
	double convertedX = xRange.first + xStep * x;
	double convertedY = yRange.first + yStep * y;

	return std::make_pair(convertedX, convertedY);
}

sf::Uint8 * Plotter::plot(sf::RenderWindow &window)
{
	//Gets screen sizes
	int screenX = window.getSize().x;
	int screenY = window.getSize().y;
	sf::Uint8 *pixels = new sf::Uint8[screenX * screenY * 4];
	int ptr = 0;

	for (int y = 0; y < screenY; ++y) {
		for (int x = 0; x < screenX; ++x) {
			std::pair<double, double> pos = this->screenToAxes(x, y, window);

			//std::cout << pos.first << ", " << pos.second << "\n";

			std::complex<double> z (pos.first, pos.second);
			std::complex<double> c = z;
			bool gtTwo = false;

			for (int i = 0; i < ITERATIONS; ++i) {
				z = pow(z, 2) + c;
				if (abs(z) > 2) {
					ptr += addColourToArray(pixels, 255, 0, 0, ptr);
					gtTwo = true;
					break;
				}
			}
			if (!gtTwo) {
				ptr += addColourToArray(pixels, 0, 255, 0, ptr);
			}
		}
	}
	return pixels;
}

Plotter::~Plotter()
{
}

