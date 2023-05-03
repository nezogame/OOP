#include "FigureDecorator.h"

FigureDecorator::FigureDecorator(Figure* figure):	Figure(*figure) {
	figure_ = figure;
}

FigureDecorator::~FigureDecorator() {
	delete figure_;
}

FigureDecorator* FigureDecorator::clone() {
	return new FigureDecorator(*this);
}

void FigureDecorator::set_position(float x, float y) {
	figure_->set_position(x, y);
}
void FigureDecorator::move(float x, float y) {
	figure_->move(x, y);
}
void FigureDecorator::draw(sf::RenderWindow& window) {
	figure_->draw(window);
}
sf::FloatRect FigureDecorator::get_global_bounds() {
	return figure_->get_global_bounds();
}
bool FigureDecorator::get_selected() {
	return selected;
}
sf::Shape* FigureDecorator::get_figure() {
	return figure_->get_figure();
}
std::string FigureDecorator::get_figure_name() {
	return "figure_";
}
sf::Color FigureDecorator::get_color() {
	return color;
}
sf::Color FigureDecorator::get_new_color() {
	return new_color;
}
sf::Color FigureDecorator::get_transparent_color() {
	return transparent_color;
}

void FigureDecorator::set_selected(bool is_selected) {
	selected = is_selected;
}
void FigureDecorator::set_outline(float thickness) {
	figure_->set_outline(thickness);
}
void FigureDecorator::set_outline(float thickness, sf::Color color) {
	figure_->set_outline(thickness, color);
}
void FigureDecorator::set_show(bool is_show) {
	show = is_show;
}
bool FigureDecorator::get_show() {
	return show;
}
void FigureDecorator::set_transparency() {
		figure_->set_transparency();
}
void FigureDecorator::change_color(sf::Color color) {
	new_color = color;
	figure_->change_color(new_color);
}
void FigureDecorator::set_scale(float x, float y) {
	figure_->set_scale(x, y);
}
void FigureDecorator::set_default() {
	figure_->set_default();
}
void FigureDecorator::auto_move(sf::Vector2f mouse) {
	figure_->auto_move(mouse);
}