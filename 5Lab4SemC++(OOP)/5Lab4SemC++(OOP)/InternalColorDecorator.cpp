#include "InternalColorDecorator.h"

void InternalColorDecorator::change_color(sf::Color color) {
    get_figure()->setFillColor(sf::Color::Red);
    FigureDecorator::change_color(color);
}