#include "Triangle.h"

Triangle::Triangle(float height) {
	triangle = new sf::CircleShape(height, 3);
	color = sf::Color::Green;
	new_color = color;
	transparent_color = sf::Color(0, 0, 0, 0);
	triangle->setFillColor(color);
}
Triangle::~Triangle() {
	delete triangle;
}
Triangle::Triangle(const Triangle& other) {
	triangle = new sf::CircleShape(3);
	(*triangle) = (*other.triangle);
	show = other.show;
	color = other.color;
	new_color = other.new_color;
	transparent_color = other.transparent_color;
	selected = other.selected;
}
Triangle* Triangle::clone() {
	return new Triangle(*this);
}
void Triangle::set_position(float x, float y) {
	float left_x = triangle->getGlobalBounds().left;
	float top_y = triangle->getGlobalBounds().top;
	x = left_x + (x - left_x);
	y = top_y + (y - top_y);
	triangle->setPosition(x, y);

	if (x < 0.f || x + triangle->getGlobalBounds().width > 700) {
		if (x < 0.f) {
			x = 0;
			triangle->setPosition(x, y);
		}
		if (x + triangle->getGlobalBounds().width > 700) {
			x = 700 - triangle->getGlobalBounds().width;
			triangle->setPosition(x, y);

		}
	}
	if (y < 0.f || y + triangle->getGlobalBounds().height > 650) {
		if (y < 0.f) {
			y = 0;
			triangle->setPosition(x, y);
		}
		if (y + triangle->getGlobalBounds().height > 650) {
			y = 650 - triangle->getGlobalBounds().height;
			triangle->setPosition(x, y);
		}
	}
}
void Triangle::move(float x, float y) {
	triangle->move(x, y);
}
void Triangle::draw(sf::RenderWindow& window) {
	window.draw(*triangle);
}
sf::FloatRect Triangle::get_global_bounds() {
	return triangle->getGlobalBounds();
}
bool Triangle::get_selected() {
	return selected;
}
void Triangle::set_selected(bool is_selected) {
	selected = is_selected;
}
void Triangle::set_outline(float thickness) {
	triangle->setOutlineThickness(thickness);
}
void Triangle::set_outline(float thickness, sf::Color color) {
	triangle->setOutlineThickness(thickness);
	triangle->setOutlineColor(color);
}
void Triangle::set_show(bool is_show) {
	show = is_show;
}
bool Triangle::get_show() {
	return show;
}
std::string Triangle::get_figure_name() {
	return "triangle";
}
sf::CircleShape* Triangle::get_figure() {
	return triangle;
}
sf::Color Triangle::get_color() {
	return color;
}
sf::Color Triangle::get_new_color() {
	return new_color;
}
sf::Color Triangle::get_transparent_color() {
	return transparent_color;
}
void Triangle::set_transparency() {
	if (get_show() == false) {
		triangle->setFillColor(transparent_color);
	}
	else {
		triangle->setFillColor(new_color);
	}
}
void Triangle::change_color(sf::Color color) {
	new_color = color;
	triangle->setFillColor(new_color);
}
void Triangle::set_scale(float x, float y) {
	triangle->scale(x, y);
}
void Triangle::set_default() {
	new_color = color;
	triangle->setFillColor(new_color);
	triangle->setScale(1.f, 1.f);
}
void Triangle::auto_move(sf::Vector2f mouse) {
	float x = mouse.x - (triangle->getGlobalBounds().left + triangle->getGlobalBounds().width / 2);
	float y = mouse.y - (triangle->getGlobalBounds().top + triangle->getGlobalBounds().height / 2);
	float width = triangle->getGlobalBounds().width;
	float height = triangle->getGlobalBounds().height;
	float move_x_sec = x / 100;
	float move_y_sec = y / 100;

	if (triangle->getPosition().x <= 0.f || triangle->getPosition().x + width >= 700.f) {
		move_x_sec = 0;
		move_y_sec = 0;
	}
	if (triangle->getPosition().y <= 0.f || triangle->getPosition().y + height >= 650.f) {
		move_x_sec = 0;
		move_y_sec = 0;
	}
	triangle->move(move_x_sec, move_y_sec);
}