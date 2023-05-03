#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include"Circle.h"
#include"Square.h"
#include"OutlineColorDecorator.h"
#include"InternalColorDecorator.h"
#include"RotateDecorator.h"


using namespace sf;
using namespace std;


class Controller //Originator for Memento class
{
private:

	bool is_figure;
	bool is_composite;

	Figure* p_draggable_figure;
	vector<Figure*> figures;


	vector<Figure*> prototype;

	sf::Event event;
	Controller();
public:

	void event_handler(sf::RenderWindow&);
	~Controller();

	void set_mouse(sf::RenderWindow&, Figure*);
	void set_figure(sf::RenderWindow&, Figure*);
	void check_intersects(vector<Figure*>, Figure*);
	void set_outline(Figure*, float);
	static Controller* get_instance();
	/**
	* Singletons should not be cloneable.
	*/
	Controller(Controller const&) = delete;
	/**
	 * Singletons should not be assignable.
	 */
	void operator=(Controller const&) = delete;
	bool get_is_figure();
	bool get_is_composite();
	Figure* get_p_draggable_figure();
	vector<Figure*> get_figures();

	void set_figures(Figure*);
	void key_pressed(sf::RenderWindow&);

	void clean_figures();

	Figure* select_figure(std::string);


	void test();
};