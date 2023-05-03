#pragma once

#include <SFML/Graphics.hpp>
#include <nlohmann/json.hpp>
#include <iostream>
#include <string>
#include"Circle.h"
#include"Star.h"
#include"Square.h"
#include"Line.h"
#include"Triangle.h"
#include "Composite.h"
#include "FiguresHistory.h"
#include <fstream>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace sf;
using namespace std;
using json = nlohmann::json;

class Controller //Originator for Memento class
{
private:

	bool is_figure;
	bool is_composite;

	Figure* p_draggable_figure;
	Composite* p_draggable_composite;
	Composite* p_adding_composite;
	vector<Figure*> figures;
	vector<Composite*> composites;
	FiguresHistory state;

	vector<Figure*> prototype;

	sf::Event event;
	Controller();
public:

	void event_handler(sf::RenderWindow&);
	~Controller();

	bool check(Composite*, Composite*);
	void set_mouse(sf::RenderWindow&, Figure*);
	void set_figure(sf::RenderWindow&, Figure*);
	void check_intersects(vector<Figure*>, Figure*);
	void check_intersects(vector<Composite*>, Figure*);
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
	Composite* get_p_draggable_composite();
	Composite* get_p_adding_composite();
	vector<Composite*> get_composites();
	vector<Figure*> get_figures();

	void set_composites(Composite*);
	void set_figures(Figure*);
	void key_pressed(sf::RenderWindow&);

	void set_memento();
	void get_memento();

	void clean_figures();
	void  clean_composites();

	void restore_figures(json);
	Figure* select_figure(std::string);

	void  add_json(json);
	void save_from_json(json);
	void save_from_json(json, Composite*);

	void test();
};