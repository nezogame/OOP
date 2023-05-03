#include "Controller.h"

void Controller::set_memento() {
	json j;
	for (auto figure : figures) {

		j["figures"].push_back({
			{"name", figure->get_figure_name()},
			{"color", figure->get_figure()->getFillColor().toInteger()},
			{"scale",{
				{"x",figure->get_figure()->getScale().x},
				{"y",figure->get_figure()->getScale().y}
			}},
			{"position",{
				{"x", figure->get_figure()->getPosition().x},
				{"y", figure->get_figure()->getPosition().y}
			}}
			});
	}
	for (auto composite : composites) {
		json composite_json;
		for (int i = 0; i < composite->get_figures_count(); i++) {
			composite_json.push_back({
				{"name",composite->get_figures()[i]->get_figure_name()},
				{"color", composite->get_figures()[i]->get_figure()->getFillColor().toInteger()},
				{"scale",{
					{"x",composite->get_figures()[i]->get_figure()->getScale().x},
					{"y",composite->get_figures()[i]->get_figure()->getScale().y}
				}},
				{"position",{
					{"x", composite->get_figures()[i]->get_figure()->getPosition().x},
					{"y", composite->get_figures()[i]->get_figure()->getPosition().y}
				}}
				});
		}
		j["composites"].push_back({
		{"figures", composite_json}
			});
	}

	std::ofstream output_file("Memento.json");
	output_file << j.dump(2);;
	output_file.close();
}

void Controller::get_memento() {
	clean_figures();
	clean_composites();

	std::ifstream input_file("Memento.json");
	json input_json;
	input_file >> input_json;
	restore_figures(input_json);
	input_file.close();

}

void Controller::save_from_json(json figure_json) {
	Figure* figure = select_figure(figure_json["name"]);
	if (figure != nullptr) {
		figure->set_position(figure_json["position"]["x"], figure_json["position"]["y"]);
		figure->get_figure()->setFillColor(sf::Color(figure_json["color"]));
		figure->get_figure()->setScale(figure_json["scale"]["x"], figure_json["scale"]["y"]);

		set_figures(figure);
	}
	else {
		cout << "Error: Incorrect name of a figure\n";
	}
}
void Controller::save_from_json(json figure_json, Composite* composite) {
	Figure* figure = select_figure(figure_json["name"]);
	if (figure != nullptr) {
		figure->set_position(figure_json["position"]["x"], figure_json["position"]["y"]);
		figure->get_figure()->setFillColor(sf::Color(figure_json["color"]));
		figure->get_figure()->setScale(figure_json["scale"]["x"], figure_json["scale"]["y"]);

		composite->add(figure);
	}
	else {
		cout << "Error: Incorrect name of a figure\n";
	}
}

void Controller::clean_figures() {
	for (auto f : figures) {
		figures.pop_back();
	}
}
void  Controller::clean_composites() {
	for (auto c : composites) {
		composites.pop_back();
	}
}

void Controller::restore_figures(json input_json) {
	bool is_composite;
	for (auto& figure_json : input_json["figures"]) {
		is_composite = false;
		save_from_json(figure_json);
	}
	for (auto& composites_json : input_json["composites"]) {
		is_composite = true;
		Composite* composite = new Composite();
		for (auto& figure_json : composites_json["figures"]) {
			save_from_json(figure_json, composite);
		}
		set_composites(composite);
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

bool  Controller::check(Composite* d_composite, Composite* a_composite) {
	return d_composite != a_composite && a_composite != nullptr;
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
void Controller::check_intersects(std::vector<Composite*> figures, Figure* p_draggable_figure) {
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


void Controller::set_composites(Composite* composite) {
	composites.push_back(composite);
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
Composite* Controller::get_p_draggable_composite() {
	return p_draggable_composite;
}

Composite* Controller::get_p_adding_composite() {
	return p_adding_composite;
}
std::vector<Composite*> Controller::get_composites() {
	return composites;
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
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			cout << "ADDING code block" << endl;
			bool is_conteined = false;
			if (p_draggable_composite != nullptr) {
				cout << "-	-	-composite- - -" << p_draggable_composite << endl;
				cout << "-	-	-p_adding_composite- - -" << p_adding_composite << endl;
				if (check(p_draggable_composite, p_adding_composite)) {
					p_draggable_composite->add_comp(*p_adding_composite);
					auto it = find(composites.begin(), composites.end(), p_adding_composite);
					if (it != composites.end()) {
						composites.erase(it);
					}
					p_adding_composite = nullptr;
				}
				cout << "-	-	-composite- - -" << p_draggable_composite << endl;
				cout << "-	-	-p_adding_composite- - -" << p_adding_composite << endl;
				p_draggable_composite->add(p_draggable_figure);
				auto it = find(figures.begin(), figures.end(), p_draggable_figure);
				if (it != figures.end()) {
					figures.erase(it);
				}
				p_draggable_figure = nullptr;
			}
			else if (p_draggable_figure != nullptr) {
				for (auto& composite : get_composites())
				{
					if (composite->get_figure_index(p_draggable_figure) != -1) {
						is_conteined = true;
					}
				}
				if (!is_conteined) {
					Composite* comp = new Composite();
					set_composites(comp);
					comp->add(p_draggable_figure);
					auto it = find(figures.begin(), figures.end(), p_draggable_figure);
					if (it != figures.end()) {
						figures.erase(it);
					}

				}
			}
			cout << "Exiting the ADDING code block" << endl;
		}
		else if (event.type == sf::Event::MouseWheelMoved) {
			if (event.mouseWheel.delta > 0)
			{
				if (p_draggable_figure != nullptr && is_figure) {
					p_draggable_figure->set_scale(1.1, 1.1);
				}
				else if (p_draggable_composite != nullptr && is_composite) {
					p_draggable_composite->set_scale(1.1, 1.1);
				}
			}
			else
			{
				if (p_draggable_figure != nullptr && is_figure) {
					p_draggable_figure->set_scale(0.9, 0.9);
				}
				else if (p_draggable_composite != nullptr && is_composite) {
					p_draggable_composite->set_scale(0.9, 0.9);
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
				check_intersects(get_composites(), p_draggable_figure);
				set_outline(p_draggable_composite, 4.f);


			}
			else if (p_draggable_composite != nullptr && is_composite) {
				set_figure(window, p_draggable_composite);
				check_intersects(get_composites(), p_draggable_composite);
				check_intersects(get_figures(), p_draggable_composite);
				set_outline(p_adding_composite, 4.f);

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
			for (auto& composite : get_composites())
			{
				cout << "Entering the composite code block" << endl;
				if (composite->get_global_bounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
					set_outline(p_draggable_composite, 0.f);

					is_figure = false;
					is_composite = true;
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
						cout << "-	-	-sf::Keyboard::Z" << endl;
						p_adding_composite = p_draggable_composite;
						cout << "-	-	-composite- - -" << composite << endl;
						cout << "-	-	-p_adding_composite- - -" << p_adding_composite << endl;
					}
					else {
						cout << "-	-	-NOTPressed" << endl;
						p_adding_composite = nullptr;
						cout << "-	-	-composite- - -" << composite << endl;
						cout << "-	-	-p_adding_composite- - -" << p_adding_composite << endl;
					}

					p_draggable_composite = composite;
					set_mouse(window, p_draggable_composite);
					set_outline(p_adding_composite, 4.f);

					set_outline(p_draggable_composite, 4.f);
					/*if (p_draggable_composite != nullptr) {
						composite->set_outline(4.f);
					}
					else {
						composite->set_outline(0.f);
						is_composite = false;
					}*/
				}
				else {
					count_composite++;
				}
				cout << "Exiting the composite code block" << endl;
			}
			if (get_composites().size() == count_composite && !sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
				set_outline(p_draggable_composite, 0.f);
				p_draggable_composite = nullptr;
				is_composite = false;
			}
		}
	}
}

void Controller::key_pressed(sf::RenderWindow& window) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		if (is_figure) {
			p_draggable_figure->set_default();
		}
		else if (is_composite) {
			p_draggable_composite->set_default();
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) && sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		state.save_state(*this);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) && sf::Keyboard::isKeyPressed(sf::Keyboard::L)) {
		state.load_state(*this);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::P)) {

		Figure* figure = nullptr;
		Composite* composite = nullptr;
		if (is_figure) {
			figure = p_draggable_figure->clone();
			set_figure(window, figure);
			set_figures(figure);
		}
		else if (is_composite) {
			composite = p_draggable_composite->clone();
			set_figure(window, composite);
			set_composites(composite);
		}
		sleep(sf::Time(sf::milliseconds(10)));
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		if (is_figure) {
			srand(time(0));
			p_draggable_figure->change_color(sf::Color(rand() % 255, rand() % 255, rand() % 255));
		}
		else if (is_composite) {
			srand(time(0));
			p_draggable_composite->change_color(sf::Color(rand() % 255, rand() % 255, rand() % 255));
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
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::L)) {
		Figure* line = prototype[2]->clone();
		set_figure(window, line);
		set_figures(line);
		sleep(sf::Time(sf::milliseconds(10)));
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
		Figure* star = prototype[3]->clone();
		set_figure(window, star);
		set_figures(star);
		sleep(sf::Time(sf::milliseconds(10)));
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::T)) {
		Figure* triangle = prototype[4]->clone();
		set_figure(window, triangle);
		set_figures(triangle);
		sleep(sf::Time(sf::milliseconds(10)));
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::H)) {
		if (is_composite) {
			p_draggable_composite->set_show(!p_draggable_composite->get_show());
			p_draggable_composite->set_transparency();
		}
		else if (is_figure) {
			p_draggable_figure->set_show(!p_draggable_figure->get_show());
			p_draggable_figure->set_transparency();
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		sf::Vector2f mouse = window.mapPixelToCoords(sf::Mouse::getPosition(window));
		while (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			window.clear(sf::Color(239, 228, 176));
			if (is_composite) {
				p_draggable_composite->auto_move(mouse);
			}
			else if (is_figure) {
				p_draggable_figure->auto_move(mouse);
			}
			for (auto& figure : get_figures())
			{
				figure->draw(window);
			}
			for (auto& composite : get_composites())
			{
				composite->draw(window);
			}
			window.display();
		}
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::G) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		if (p_draggable_figure != nullptr || p_draggable_composite != nullptr) {
			while (sf::Keyboard::isKeyPressed(sf::Keyboard::G)) {
				if (is_composite && p_draggable_composite != nullptr) {
					p_draggable_composite->draw(window);
					set_figure(window, p_draggable_composite);
				}
				else if (is_figure && p_draggable_figure != nullptr) {
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
	p_draggable_composite = nullptr;
	p_adding_composite = nullptr;
	state = FiguresHistory();
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
	for (auto c : composites) {
		delete c;
	}
	composites.clear();
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