#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

#include "Composite.h"


class Memento //Memento prototype
{
	friend class Controller;
	std::vector<Figure*> figures;
	std::vector<Composite*> composites;
public:
	~Memento();
	Memento();
	void clean_figures();
	void clean_composites();
};