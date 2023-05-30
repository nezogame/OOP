#pragma once

#include <SFML/Graphics.hpp>

#include <iostream>
#include <string>
#include"Circle.h"
#include"Star.h"
#include"Square.h"
#include"Line.h"
#include"Triangle.h"

#include <fstream>
#include <iostream>
#include <fstream>
#include <sstream>
#include <random>
#include <mutex>

using namespace sf;
using namespace std;

const int MAX_FIGURES = 10;

class Controller 
{
private:

	bool is_figure;

	int random_int(int min, int max);
	std::mutex figures_mutex;
	Figure* p_draggable_figure;
	
	vector<Figure*> figures;

	vector<Figure*> prototype;

	Event event;

	


public:

	
	void do_thread();
	void remove_figure();
	Figure* get_random_target(Figure*);
	void assign_new_targets();
	void add_figures();
	void move_figures_and_intersection_check();
	Controller();
	void event_handler(RenderWindow&);
	~Controller();


	void set_mouse(RenderWindow&, Figure*);
	void set_figure(RenderWindow&, Figure*);

	void check_intersects(vector<Figure*>, Figure*);

	void set_outline(Figure*, float);
	
	bool get_is_figure();

	Figure* get_p_draggable_figure();

	vector<Figure*> get_figures();

	void set_figures(Figure*);
	void key_pressed(RenderWindow&);


	void clean_figures();

	Figure* select_figure(std::string);
	void figure_target_intersection();
};