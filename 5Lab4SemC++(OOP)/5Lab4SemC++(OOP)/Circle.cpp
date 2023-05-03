#include "Circle.h"
Circle::Circle(float radius, sf::Color color) {
	circle = new sf::CircleShape(radius);
	this->color = color;
	this->new_color = color;
	transparent_color = sf::Color(0, 0, 0, 0);
	circle->setFillColor(color);
	circle->setOrigin(radius, radius);
}
Circle::Circle(float radius)  {
	circle = new sf::CircleShape(radius);
	color = sf::Color::Red;
	new_color = color;
	transparent_color = sf::Color(0, 0, 0, 0);
	circle->setFillColor(color);

}
Circle::Circle(const Circle& other) {
	circle = new sf::CircleShape();
	(*circle) = (*other.circle);
	show = other.show;
	color = other.color;
	new_color = other.new_color;
	transparent_color = other.transparent_color;
	selected = other.selected;
}

Circle::~Circle() {
	delete circle;
}

Circle* Circle::clone() {
	return new Circle(*this);
}
void Circle::set_position(float x, float y) {
	float left_x = circle->getGlobalBounds().left;
	float top_y = circle->getGlobalBounds().top;
	x = left_x + (x - left_x);
	y = top_y + (y - top_y);
	circle->setPosition(x, y);

	if (x < 0.f || x + circle->getGlobalBounds().width > 700) {
		if (x < 0.f) {
			x = 0;
			circle->setPosition(x, y);
		}
		if (x + circle->getGlobalBounds().width > 700) {
			x = 700 - circle->getGlobalBounds().width;
			circle->setPosition(x, y);

		}
	}
	if (y < 0.f || y + circle->getGlobalBounds().height > 650) {
		if (y < 0.f) {
			y = 0;
			circle->setPosition(x, y);
		}
		if (y + circle->getGlobalBounds().height > 650) {
			y = 650 - circle->getGlobalBounds().height;
			circle->setPosition(x, y);
		}
	}
}
void Circle::move(float x, float y) {
	circle->move(x, y);
}

std::string Circle::get_figure_name() {
	return "circle";
}

sf::CircleShape* Circle::get_figure() {
	return circle;
}
sf::Color Circle::get_color() {
	return color;
}
sf::Color Circle::get_new_color() {
	return new_color;
}
sf::Color Circle::get_transparent_color() {
	return transparent_color;
}
void Circle::draw(sf::RenderWindow& window) {
	window.draw(*circle);
}
sf::FloatRect Circle::get_global_bounds() {
	return  circle->getGlobalBounds();
}
bool Circle::get_selected() {
	return selected;
}
void Circle::set_selected(bool is_selected) {
	selected = is_selected;
}
void Circle::set_outline(float thickness) {
	circle->setOutlineThickness(thickness);
}
void Circle::set_outline(float thickness, sf::Color color) {
	circle->setOutlineThickness(thickness);
	circle->setOutlineColor(color);
}
void Circle::set_show(bool is_show) {
	show = is_show;
}
bool Circle::get_show() {
	return show;
}
void Circle::set_transparency() {
	if (get_show() == false) {
		circle->setFillColor(transparent_color);
	}
	else {
		circle->setFillColor(new_color);
	}
}
void Circle::change_color(sf::Color color) {
	new_color = color;
	circle->setFillColor(new_color);
}
void Circle::set_scale(float x, float y) {
	circle->scale(x, y);
}
void Circle::set_default() {
	new_color = color;
	circle->setFillColor(new_color);
	circle->setScale(1.f, 1.f);
	circle->setOutlineColor(sf::Color::White);
	circle->setRotation(0);
}
void Circle::auto_move(sf::Vector2f mouse) {
	float x = mouse.x - (circle->getGlobalBounds().left + circle->getGlobalBounds().width / 2);
	float y = mouse.y - (circle->getGlobalBounds().top + circle->getGlobalBounds().height / 2);
	float width = circle->getGlobalBounds().width;
	float height = circle->getGlobalBounds().height;
	float move_x_sec = x / 100;
	float move_y_sec = y / 100;

	if (circle->getPosition().x <= 0.f || circle->getPosition().x + width >= 700.f) {
		move_x_sec = 0;
		move_y_sec = 0;
	}
	if (circle->getPosition().y <= 0.f || circle->getPosition().y + height >= 650.f) {
		move_x_sec = 0;
		move_y_sec = 0;
	}
	circle->move(move_x_sec, move_y_sec);

}

