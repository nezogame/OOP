#pragma once

#include "FigureDecorator.h"

class InternalColorDecorator : public FigureDecorator
{
public:
    InternalColorDecorator(Figure* figure) : FigureDecorator(figure) {
    }
    void change_color(sf::Color color) override;
};

