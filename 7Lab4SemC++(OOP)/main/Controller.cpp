#include "Controller.h"

void Controller::clean_figures() {
	for (auto f : figures) {
		figures.pop_back();
	}
}
Figure* Controller::select_figure(std::string name) {
	Figure* figure = nullptr;
	if (name == "circle") {
		figure = prototype[0]->clone();
	}
	else if (name == "square") {
		figure = prototype[1]->clone();
	}
	else if (name == "line") {
		figure = prototype[2]->clone();
	}
	else if (name == "star") {
		figure = prototype[3]->clone();
	}
	else if (name == "triangle") {
		figure = prototype[4]->clone();
	}
	return figure;
}


void Controller::set_figure(RenderWindow& window, Figure* figure) {
	float x = window.mapPixelToCoords(Mouse::getPosition(window)).x;
	float y = window.mapPixelToCoords(Mouse::getPosition(window)).y;
	float width = figure->get_global_bounds().width;
	float height = figure->get_global_bounds().height;

	figure->set_position(x - width / 2, y - height / 2);
}

void Controller::set_mouse(RenderWindow& window, Figure* figure) {
	float left = figure->get_global_bounds().left;
	float top = figure->get_global_bounds().top;
	float width = figure->get_global_bounds().width;
	float height = figure->get_global_bounds().height;

	Vector2i position = Vector2i(left + width / 2, top + height / 2);
	Mouse::setPosition(position, window);
}

void Controller::check_intersects(std::vector<Figure*> figures, Figure* p_draggable_figure) {
	if (p_draggable_figure == nullptr) {
		return;
	}
	for (auto& figure : figures)
	{
		if (figure->get_global_bounds().intersects(p_draggable_figure->get_global_bounds())) {

			figure->set_outline(4);
		}
		else {
			figure->set_outline(0);
		}
	}

}

void Controller::set_outline(Figure* figure, float outline) {
	if (figure != nullptr) {
		figure->set_outline(outline);
	}
}



void Controller::set_figures(Figure* figure) {
	figures.push_back(figure);
}
bool Controller::get_is_figure() {
	return is_figure;
}


Figure* Controller::get_p_draggable_figure() {
	return p_draggable_figure;
}




std::vector<Figure*> Controller::get_figures() {
	return figures;
}


void Controller::event_handler(RenderWindow& window) {
	while (window.pollEvent(event))
	{
		if (event.type == Event::Closed) {
			window.close();
		}
		
		else if (event.type == Event::MouseWheelMoved) {
			if (event.mouseWheel.delta > 0)
			{
				if (p_draggable_figure != nullptr && is_figure) {
					p_draggable_figure->set_scale(1.1, 1.1);
				}
				
			}
			else
			{
				if (p_draggable_figure != nullptr && is_figure) {
					p_draggable_figure->set_scale(0.9, 0.9);
				}
				

			}

		}
		else if (event.type == Event::KeyPressed) {
			key_pressed(window);
		}
		else if (Mouse::isButtonPressed(Mouse::Left)) {
			if (p_draggable_figure != nullptr && is_figure) {
				set_figure(window, p_draggable_figure);
				check_intersects(get_figures(), p_draggable_figure);
				


			}
			

		}

		else if (event.mouseButton.button == Mouse::Right) {
			int count_figure = 0;
			
			for (auto& figure : get_figures())
			{
				if ((*figure).get_global_bounds().contains(window.mapPixelToCoords(Mouse::getPosition(window)))) {
					set_outline(p_draggable_figure, 0.f);

		
					is_figure = true;
					p_draggable_figure = figure;
					set_outline(p_draggable_figure, 4.f);
					set_mouse(window, p_draggable_figure);
				}
				else {
					count_figure++;
				}

			}
			if (get_figures().size() == count_figure) {
				set_outline(p_draggable_figure, 0.f);
				p_draggable_figure ? p_draggable_figure = nullptr : 0;
				is_figure = false;
			}
		}
	}
}

void Controller::key_pressed(RenderWindow& window) {
	if (Keyboard::isKeyPressed(Keyboard::D)) {
		if (is_figure) {
			p_draggable_figure->set_default();
		}
		
	}
	
	else if (Keyboard::isKeyPressed(Keyboard::P)) {

		Figure* figure = nullptr;
		
		if (is_figure) {
			figure = p_draggable_figure->clone();
			set_figure(window, figure);
			set_figures(figure);
		}
		
		sleep(Time(milliseconds(10)));
	}
	else if (Keyboard::isKeyPressed(Keyboard::W)) {
		if (is_figure) {
			srand(time(0));
			p_draggable_figure->change_color(Color(rand() % 255, rand() % 255, rand() % 255));
		}
		

	}
	else if (Keyboard::isKeyPressed(Keyboard::C)) {
		Figure* circle = prototype[0]->clone();
		set_figure(window, circle);
		set_figures(circle);
		sleep(Time(milliseconds(10)));
	}
	else if (Keyboard::isKeyPressed(Keyboard::S)) {
		Figure* square = prototype[1]->clone();
		set_figure(window, square);
		set_figures(square);
		sleep(Time(milliseconds(10)));
	}
	else if (Keyboard::isKeyPressed(Keyboard::L)) {
		Figure* line = prototype[2]->clone();
		set_figure(window, line);
		set_figures(line);
		sleep(Time(milliseconds(10)));
	}
	else if (Keyboard::isKeyPressed(Keyboard::R)) {
		Figure* star = prototype[3]->clone();
		set_figure(window, star);
		set_figures(star);
		sleep(Time(milliseconds(10)));
	}
	else if (Keyboard::isKeyPressed(Keyboard::T)) {
		Figure* triangle = prototype[4]->clone();
		set_figure(window, triangle);
		set_figures(triangle);
		sleep(Time(milliseconds(10)));
	}
	else if (Keyboard::isKeyPressed(Keyboard::H)) {
		
		if (is_figure) {
			p_draggable_figure->set_show(!p_draggable_figure->get_show());
			p_draggable_figure->set_transparency();
		}
	}
	else if (Keyboard::isKeyPressed(Keyboard::A)) {
		Vector2f mouse = window.mapPixelToCoords(Mouse::getPosition(window));
		while (Keyboard::isKeyPressed(Keyboard::A)) {
			window.clear(Color(239, 228, 176));
			 if (is_figure) {
				p_draggable_figure->auto_move(mouse);
			}
			for (auto& figure : get_figures())
			{
				figure->draw(window);
			}
			
			window.display();
		}
	}

	else if (Keyboard::isKeyPressed(Keyboard::G) && Mouse::isButtonPressed(Mouse::Left)) {
		if (p_draggable_figure != nullptr ) {
			while (Keyboard::isKeyPressed(Keyboard::G)) {
				
				if (is_figure && p_draggable_figure != nullptr) {
					p_draggable_figure->draw(window);
					set_figure(window, p_draggable_figure);
				}
				window.display();
				sleep(Time(milliseconds(10)));
			}
		}
	}

}

Controller::Controller() {
	is_figure = false;
	p_draggable_figure = nullptr;
	Circle* circle = new Circle(45.f);
	prototype.push_back(circle);
	Square* square = new Square(100.f);
	prototype.push_back(square);
	Line* line = new Line();
	prototype.push_back(line);
	Star* star = new Star();
	prototype.push_back(star);
	Triangle* triangle = new Triangle(70.f);
	prototype.push_back(triangle);
}

Controller::~Controller() {

	for (auto f : figures) {
		delete f;
	}
	figures.clear();
	for (auto p : prototype) {
		delete p;
	}
	prototype.clear();
}


int Controller::random_int(int min, int max) {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist(min, max);

	return dist(gen);
}

void Controller::add_figures() {
	std::cout << "method add_figures START\n";

		figures_mutex.lock();
		std::cout << "LOOP START\n";
		if (figures.size() < MAX_FIGURES) {
			Figure* new_figure_first = prototype[random_int(0, 4)]->clone();
			new_figure_first->set_position(random_int(0, 550), random_int(0, 550));
			if (figures.size() < MAX_FIGURES) {
				figures.push_back(new_figure_first);
			}
			std::cout << "Added new figure. Total figures: " << figures.size() << std::endl;
		}
		std::cout << "LOOP END\n";

		figures_mutex.unlock();

	std::cout << "method add_figures END\n";

}


void Controller::move_figures_and_intersection_check(){
	std::cout << "method move_figures_and_intersection_check START\n";
	if (figures.empty()){
		std::cout << "CHECK figures.empty()\n";
		return;
	} 
		figures_mutex.lock();
		std::cout << "LOOP START\n";


		for (auto& figure : figures) {
			if (figure->get_target() != nullptr) {
				std::cout << "CHECK figure->get_target() != nullptr\n";

				auto target_left = figure->get_target()->get_global_bounds().left;
				auto target_top = figure->get_target()->get_global_bounds().top;
				auto target_width = figure->get_target()->get_global_bounds().width;
				auto target_height = figure->get_target()->get_global_bounds().height;

				figure->auto_move(Vector2f(target_left + target_width / 2, target_top + target_height / 2));
				figure->check_intersection();
			}
		}
		std::cout << "LOOP END\n";
		figures_mutex.unlock();
	std::cout << "method move_figures_and_intersection_check END\n";

}


void Controller::assign_new_targets(){
	std::cout << "method assign_new_targets START\n";

	figures_mutex.lock();
	for (auto& figure : figures)
	{
		std::cout << "LOOP START\n";

		if (figure->get_target() == nullptr) {
			std::cout << "CHECK figure->get_target() == nullptr\n";
			figure->set_target(get_random_target(figure));
			std::cout << "Set Target: "<< figure->get_target()<<" name: " << figure->get_target() << "\n";
		}
		std::cout << "LOOP END\n";

	}
	figures_mutex.unlock();
	std::cout << "method assign_new_targets END\n";

}

Figure* Controller::get_random_target(Figure* figure) {
	if (figures.empty()) {
		return nullptr;
	}
	auto target = figures[random_int(0, figures.size() - 1)];
	if (figure == target) {
		return nullptr;
	}
	return target;
}

void Controller::remove_figure() {
	std::cout << "method remove_figure START\n";
	figures_mutex.lock();
	if (figures.empty()) {
		figures_mutex.unlock();
		return;
	}
	for (auto & figure : figures){
		std::cout << "LOOP START\n";
		if (figure == nullptr) {
			figures_mutex.unlock();
			return;
		}
		if (figure->check_intersection()) {
			std::cout << "CHECK igure->check_intersection()\n";
			std::cout << "Removed figure: " << figure->get_figure_name() <<"at memory: "<< figure << std::endl;
			std::cout << "Removed figure TARGET: " << figure->get_target()->get_figure_name() << "at memory: "<< figure->get_target() << std::endl;
			auto it = find(figures.begin(), figures.end(), figure->get_target());
			if (it != figures.end()) {
				*it = nullptr;
				delete* it;
				figures.erase(it);
			}
			it = find(figures.begin(), figures.end(), figure);
			if (it != figures.end()) {
				*it=nullptr;
				delete* it;
				figures.erase(it);
			}
			
		}
		std::cout << "LOOP END\n";
	}
	figures_mutex.unlock();
	std::cout << "method remove_figure START\n";

}





