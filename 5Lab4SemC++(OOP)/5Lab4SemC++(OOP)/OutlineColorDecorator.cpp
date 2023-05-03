#include "OutlineColorDecorator.h"

void OutlineColorDecorator::change_color( sf::Color color) {
	get_figure()->setOutlineColor(sf::Color::Red);
	FigureDecorator::change_color(color);
}