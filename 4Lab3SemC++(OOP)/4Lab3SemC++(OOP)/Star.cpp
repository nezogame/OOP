#include "Star.h"
#include <iostream>
Star::Star() {
	star = new sf::ConvexShape();
	star->setPointCount(10);
	color = sf::Color(61,77,169);
	new_color = color;
	transparent_color = sf::Color(0, 0, 0, 0);
	star->setFillColor(color);
	star->setPoint(0, sf::Vector2f(60, 0));
	star->setPoint(1, sf::Vector2f(72, 40));
	star->setPoint(2, sf::Vector2f(110, 40));
	star->setPoint(3, sf::Vector2f(80, 60));
	star->setPoint(4, sf::Vector2f(100, 100));
	star->setPoint(5, sf::Vector2f(60, 75));
	star->setPoint(6, sf::Vector2f(20, 100));
	star->setPoint(7, sf::Vector2f(40, 60));
	star->setPoint(8, sf::Vector2f(10, 40));
	star->setPoint(9, sf::Vector2f(48, 40));
}
Star::~Star() {
	delete star;
}
Star::Star(const Star& other) {
	star = new sf::ConvexShape();
	(*star) = (*other.star);
	show = other.show;
	color = other.color;
	new_color = other.new_color;
	transparent_color = other.transparent_color;
	selected = other.selected;
}
Star* Star::clone() {
	return new Star(*this);
}
void Star::set_position(float x, float y) {

	std::cout << star->getPosition().x << ":" << star->getPosition().y << "\n";
	star->setPosition(x, y);

	if (x < 0.f || x + star->getGlobalBounds().width > 700) {
		if (x < 0.f) {
			x = 0;
			star->setPosition(x, y);
		}
		if (x + star->getGlobalBounds().width > 700) {
			x = 700 - star->getGlobalBounds().width;
			star->setPosition(x, y);

		}
	}
	if (y < 0.f || y + star->getGlobalBounds().height > 650) {
		if (y < 0.f) {
			y = 0;
			star->setPosition(x, y);
		}
		if (y + star->getGlobalBounds().height > 650) {
			y = 650 - star->getGlobalBounds().height;
			star->setPosition(x, y);
		}
	}
}
void Star::move(float x, float y) {
	star->move(x, y);
}
void Star::draw(sf::RenderWindow& window) {
	window.draw(*star);
}
sf::FloatRect Star::get_global_bounds() {
	return star->getGlobalBounds();
}
bool Star::get_selected() {
	return selected;
}
void Star::set_selected(bool is_selected) {
	selected = is_selected;
}
void Star::set_outline(float thickness) {
	star->setOutlineThickness(thickness);
}
void Star::set_outline(float thickness, sf::Color color) {
	star->setOutlineThickness(thickness);
	star->setOutlineColor(color);
}
void Star::set_show(bool is_show) {
	show = is_show;
}
bool Star::get_show() {
	return show;
}
std::string Star::get_figure_name() {
	return "star";
}
sf::ConvexShape* Star::get_figure() {
	return star;
}
sf::Color Star::get_color() {
	return color;
}
sf::Color Star::get_new_color() {
	return new_color;
}
sf::Color Star::get_transparent_color() {
	return transparent_color;
}
void Star::set_transparency() {
	if (get_show() == false) {
		star->setFillColor(transparent_color);
	}
	else {
		star->setFillColor(new_color);
	}
}
void Star::change_color(sf::Color color) {
	new_color = color;
	star->setFillColor(new_color);
}
void Star::set_scale(float x, float y) {
	star->scale(x, y);
}

void Star::set_default() {
	new_color = color;
	star->setFillColor(new_color);
	star->setScale(1.f, 1.f);
}
void Star::auto_move(sf::Vector2f mouse) {
	float x = mouse.x - (star->getGlobalBounds().left + star->getGlobalBounds().width / 2);
	float y = mouse.y - (star->getGlobalBounds().top + star->getGlobalBounds().height / 2);
	float width = star->getGlobalBounds().width;
	float height = star->getGlobalBounds().height;
	float move_x_sec = x / 100;
	float move_y_sec = y / 100;

	if (star->getPosition().x <= 0.f || star->getPosition().x + width >= 700.f) {
		move_x_sec = 0;
		move_y_sec = 0;
	}
	if (star->getPosition().y <= 0.f || star->getPosition().y + height >= 650.f) {
		move_x_sec = 0;
		move_y_sec = 0;
	}
	star->move(move_x_sec, move_y_sec);
}