#pragma once

#include "FigureDecorator.h"
float const DEFFOLT_THIKNESS = 4.f;
class OutlineColorDecorator: public FigureDecorator
{

public:
	OutlineColorDecorator(Figure* figure) : FigureDecorator(figure) {
	}
	void  change_color(sf::Color color) override;

};

