#include "Line.h"
Line::Line() {
	
	line = new sf::RectangleShape(sf::Vector2f(150, 5));
	color = sf::Color(160,87,69);
	new_color = color;
	transparent_color = sf::Color(0, 0, 0, 0);
	line->setFillColor(color);
}
Line::~Line() {
	delete line;
}
Line::Line(const Line& other) {
	line = new sf::RectangleShape();
	(*line) = (*other.line);
	show = other.show;
	color = other.color;
	new_color = other.new_color;
	transparent_color = other.transparent_color;
	selected = other.selected;
}
Line* Line::clone() {
	return new Line(*this);
}

void Line::set_position(float x, float y) {
	float left_x = line->getGlobalBounds().left;
	float top_y = line->getGlobalBounds().top;
	x = left_x + (x - left_x);
	y = top_y + (y - top_y);
	line->setPosition(x, y);

	if (x < 0.f || x + line->getGlobalBounds().width > 700) {
		if (x < 0.f) {
			x = 0;
			line->setPosition(x, y);
		}
		if (x + line->getGlobalBounds().width > 700) {
			x = 700 - line->getGlobalBounds().width;
			line->setPosition(x, y);

		}
	}
	if (y < 0.f || y + line->getGlobalBounds().height > 650) {
		if (y < 0.f) {
			y = 0;
			line->setPosition(x, y);
		}
		if (y + line->getGlobalBounds().height > 650) {
			y = 650 - line->getGlobalBounds().height;
			line->setPosition(x, y);
		}
	}
}
void Line::move(float x, float y) {
	line->move(x, y);
}
void Line::draw(sf::RenderWindow& window) {
	window.draw(*line) ;
}
sf::FloatRect Line::get_global_bounds() {
	return line->getGlobalBounds();
}
bool Line::get_selected() {
	return selected;
}
void Line::set_selected(bool is_selected) {
	selected = is_selected;
}
void Line::set_outline(float thickness) {
	line->setOutlineThickness(thickness);
}
void Line::set_outline(float thickness, sf::Color color) {
	line->setOutlineThickness(thickness);
	line->setOutlineColor(color);
}
void Line::set_show(bool is_show) {
	show = is_show;
}
bool Line::get_show() {
	return show;
}
std::string Line::get_figure_name() {
	return "line";
}
sf::RectangleShape* Line::get_figure() {
	return line;
}
sf::Color Line::get_color() {
	return color;
}
sf::Color Line::get_new_color() {
	return new_color;
}
sf::Color Line::get_transparent_color() {
	return transparent_color;
}
void Line::set_transparency() {
	if (get_show() == false) {
		line->setFillColor(transparent_color);
	}
	else {
		line->setFillColor(new_color);
	}
}
void Line::change_color(sf::Color color) {
	new_color = color;
	line->setFillColor(new_color);
}
void Line::set_scale(float x, float y) {
	line->scale(x, y);
}
void Line::set_default() {
	new_color = color;
	line->setFillColor(new_color);
	line->setScale(1.f, 1.f);
}
void Line::auto_move(sf::Vector2f mouse) {
	float x = mouse.x - (line->getGlobalBounds().left + line->getGlobalBounds().width / 2);
	float y = mouse.y - (line->getGlobalBounds().top + line->getGlobalBounds().height / 2);
	float width = line->getGlobalBounds().width;
	float height = line->getGlobalBounds().height;
	float move_x_sec = x / 100;
	float move_y_sec = y / 100;

	if (line->getPosition().x <= 0.f || line->getPosition().x + width >= 700.f) {
		move_x_sec = 0;
		move_y_sec = 0;
	}
	if (line->getPosition().y <= 0.f || line->getPosition().y + height >= 650.f) {
		move_x_sec = 0;
		move_y_sec = 0;
	}
	line->move(move_x_sec, move_y_sec);
}
