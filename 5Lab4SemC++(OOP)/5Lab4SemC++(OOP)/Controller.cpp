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
	return figure;
}


void Controller::set_figure(sf::RenderWindow& window, Figure* figure) {
	float x = window.mapPixelToCoords(sf::Mouse::getPosition(window)).x;
	float y = window.mapPixelToCoords(sf::Mouse::getPosition(window)).y;
	float width = figure->get_global_bounds().width;
	float height = figure->get_global_bounds().height;

	figure->set_position(x - width / 2, y - height / 2);
}

void Controller::set_mouse(sf::RenderWindow& window, Figure* figure) {
	float left = figure->get_global_bounds().left;
	float top = figure->get_global_bounds().top;
	float width = figure->get_global_bounds().width;
	float height = figure->get_global_bounds().height;

	sf::Vector2i position = sf::Vector2i(left + width / 2, top + height / 2);
	sf::Mouse::setPosition(position, window);
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
bool Controller::get_is_composite() {
	return is_composite;
}

Figure* Controller::get_p_draggable_figure() {
	return p_draggable_figure;
}



std::vector<Figure*> Controller::get_figures() {
	return figures;
}


void Controller::event_handler(sf::RenderWindow& window) {
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed) {
			window.close();
		}
		else if (event.type == sf::Event::MouseWheelMoved) {
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
		else if (event.type == sf::Event::KeyPressed) {
			key_pressed(window);
		}
		else if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			if (p_draggable_figure != nullptr && is_figure) {
				set_figure(window, p_draggable_figure);
				check_intersects(get_figures(), p_draggable_figure);
				
			}
		}

		else if (event.mouseButton.button == sf::Mouse::Right) {
			int count_figure = 0;
			int count_composite = 0;
			for (auto& figure : get_figures())
			{
				if ((*figure).get_global_bounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
					set_outline(p_draggable_figure, 0.f);

					if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
						is_composite = false;
					}
					is_figure = true;
					p_draggable_figure = figure;
					set_outline(p_draggable_figure, DEFFOLT_THIKNESS);
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

void Controller::key_pressed(sf::RenderWindow& window) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		if (is_figure) {
			p_draggable_figure->set_default();
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
		if (is_figure) {
			Figure* internal_dec = new InternalColorDecorator(p_draggable_figure);
			internal_dec->change_color(sf::Color::Blue);
		}
		
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
		if (is_figure) {
		Figure* internal_dec = new InternalColorDecorator(p_draggable_figure);
		Figure* outline_dec = new OutlineColorDecorator(internal_dec);
		outline_dec->change_color(sf::Color::Green);
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
		if (is_figure) {
			Figure* outline_dec = new OutlineColorDecorator(p_draggable_figure);
			outline_dec->change_color(sf::Color::Blue);
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::T)) {
		if (is_figure) {
			Figure* outline_dec = new OutlineColorDecorator(p_draggable_figure);
			Figure* rotate_dec = new RotateDecorator(outline_dec);
			rotate_dec->change_color(sf::Color::Blue);
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::P)) {

		Figure* figure = nullptr;
		if (is_figure) {
			figure = p_draggable_figure->clone();
			set_figure(window, figure);
			set_figures(figure);
		}
		sleep(sf::Time(sf::milliseconds(10)));
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		if (is_figure) {
			srand(time(0));
			p_draggable_figure->change_color(sf::Color(rand() % 255, rand() % 255, rand() % 255));
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::C)) {
		Figure* circle = prototype[0]->clone();
		set_figure(window, circle);
		set_figures(circle);
		sleep(sf::Time(sf::milliseconds(10)));
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		Figure* square = prototype[1]->clone();
		set_figure(window, square);
		set_figures(square);
		sleep(sf::Time(sf::milliseconds(10)));
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::H)) {
		if (is_figure) {
			p_draggable_figure->set_show(!p_draggable_figure->get_show());
			p_draggable_figure->set_transparency();
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		sf::Vector2f mouse = window.mapPixelToCoords(sf::Mouse::getPosition(window));
		while (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			window.clear(sf::Color(239, 228, 176));
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

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::G) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		if (p_draggable_figure != nullptr ) {
			while (sf::Keyboard::isKeyPressed(sf::Keyboard::G)) {
				if (is_figure && p_draggable_figure != nullptr) {
					p_draggable_figure->draw(window);
					set_figure(window, p_draggable_figure);
				}
				window.display();
				sleep(sf::Time(sf::milliseconds(10)));
			}
		}
	}

}

Controller::Controller() {
	is_figure = false;
	is_composite = false;
	p_draggable_figure = nullptr;
	Circle* circle = new Circle(45.f);
	prototype.push_back(circle);
	Square* square = new Square(100.f);
	prototype.push_back(square);
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
Controller* Controller::get_instance() {
	static Controller s_instance;
	return &s_instance;
}




void Controller::test() {
	std::cout << "Singelton log:" << this << endl;
}