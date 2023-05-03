#include "RotateDecorator.h"

void  RotateDecorator::change_color(sf::Color color) {
	get_figure()->setRotation(45.f);
	FigureDecorator::change_color(color);
}