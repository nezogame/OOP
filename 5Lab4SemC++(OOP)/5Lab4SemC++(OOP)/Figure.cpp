#include "Figure.h"

void Figure::set_show(bool is_show) {
	show = is_show;
}
bool Figure::get_show() {
	return show;
}
void Figure::set_transparency()
{
}
sf::Shape* Figure::get_figure() {
	return figure;
}
sf::Color Figure::get_new_color() {
	return new_color;
}
sf::Color Figure::get_transparent_color() {
	return transparent_color;
}
sf::Color  Figure::get_color() {
	return color;
}
bool  Figure::get_selected() {
	return selected;
}
Figure::~Figure() {
}
Figure::Figure() {
	show = true;
	selected = false;
}
Figure::Figure(const Figure& other) {
	figure = other.figure;
	color = other.color;
	show = other.show;
	selected = other.selected;
}
Figure::Figure( sf::Shape& shape) {
	figure = &shape;
}