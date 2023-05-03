#include "Square.h"
Square::Square(float x) {

	square = new sf::RectangleShape(sf::Vector2f(x, x));
	color = sf::Color(5, 224, 224);
	new_color = color;
	transparent_color = sf::Color(0, 0, 0, 0);
	square->setFillColor(color);
}
Square::Square(float x, float y) {

	square = new sf::RectangleShape(sf::Vector2f(x, y));
	srand(time(0));
	color = sf::Color(rand() % 255, rand() % 255, rand() % 255);
	new_color = color;
	square->setFillColor(color);
}
Square::~Square() {
	delete square;
}
Square::Square(const Square& other) {

	square = new sf::RectangleShape();
	(*square) = (*other.square);
	show = other.show;
	color = other.color;
	new_color = other.new_color;
	transparent_color = other.transparent_color;
	selected = other.selected;
}
Square* Square::clone() {
	return new Square(*this);
}
void Square::set_position(float x, float y) {
	square->setPosition(x, y);

	if (x < 0.f || x + square->getGlobalBounds().width > 700) {
		if (x < 0.f) {
			x = 0;
			square->setPosition(x, y);
		}
		if (x + square->getGlobalBounds().width > 700) {
			x = 700 - square->getGlobalBounds().width;
			square->setPosition(x, y);

		}
	}
	if (y < 0.f || y + square->getGlobalBounds().height > 650) {
		if (y < 0.f) {
			y = 0;
			square->setPosition(x, y);
		}
		if (y + square->getGlobalBounds().height > 650) {
			y = 650 - square->getGlobalBounds().height;
			square->setPosition(x, y);
		}
	}
}
void Square::move(float x, float y) {
	square->move(x, y);
}
void Square::draw(sf::RenderWindow& window) {
	window.draw(*square);
}
sf::FloatRect Square::get_global_bounds() {
	return square->getGlobalBounds();
}
bool Square::get_selected() {
	return selected;
}
sf::RectangleShape* Square::get_figure() {
	return square;
}
std::string Square::get_figure_name() {
	return "square";
}
sf::Color Square::get_color() {
	return color;
}
sf::Color Square::get_new_color() {
	return new_color;
}
sf::Color Square::get_transparent_color() {
	return transparent_color;
}

void Square::set_selected(bool is_selected) {
	selected = is_selected;
}
void Square::set_outline(float thickness) {
	square->setOutlineThickness(thickness);
}
void Square::set_outline(float thickness, sf::Color color) {
	square->setOutlineThickness(thickness);
	square->setOutlineColor(color);
}
void Square::set_show(bool is_show) {
	show = is_show;
}
bool Square::get_show() {
	return show;
}
void Square::set_transparency() {
	if (get_show() == false) {
		square->setFillColor(transparent_color);
	}
	else {
		square->setFillColor(new_color);
	}
}
void Square::change_color(sf::Color color) {
	new_color = color;
	square->setFillColor(new_color);
}
void Square::set_scale(float x, float y) {
	square->scale(x, y);
}
void Square::set_default() {
	new_color = color;
	square->setFillColor(new_color);
	square->setScale(1.f, 1.f);
	square->setOutlineColor(sf::Color::White);
	square->setRotation(0);
}
void Square::auto_move(sf::Vector2f mouse) {
	float width = square->getGlobalBounds().width;
	float height = square->getGlobalBounds().height;
	float x = mouse.x - (square->getGlobalBounds().left + width / 2);
	float y = mouse.y - (square->getGlobalBounds().top + height / 2);
	float move_x_sec = x / 100;
	float move_y_sec = y / 100;

	square->move(move_x_sec, move_y_sec);
	if (square->getPosition().x + width >= 700.f) {
		square->setPosition(700.f - width, square->getPosition().y);
	}
	else if (square->getPosition().x <= 0.f) {
		square->setPosition(0.f, square->getPosition().y);
	}
	if (square->getPosition().y + height >= 650.f) {
		square->setPosition(square->getPosition().x, 650.f - height);
	}
	else if (square->getPosition().y <= 0.f) {
		square->setPosition(square->getPosition().x, 0.f);
	}

}