#pragma once
#include "FigureDecorator.h"
class RotateDecorator :
    public FigureDecorator
{
public:
	RotateDecorator(Figure* figure) : FigureDecorator(figure) {
	}
	void  change_color(sf::Color color) override;
};

