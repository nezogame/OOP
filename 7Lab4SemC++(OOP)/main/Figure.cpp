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
Shape* Figure::get_figure() {
	return figure;
}
Color Figure::get_new_color() {
	return new_color;
}
Color Figure::get_transparent_color() {
	return transparent_color;
}
Color  Figure::get_color() {
	return color;
}
bool  Figure::get_selected() {
	return selected;
}
Figure::~Figure() {
	delete figure;
}
Figure::Figure() {
	show = true;
	selected = false;
}
Figure::Figure(const Figure& other) {
	color = other.color;
	show = other.show;
	selected = other.selected;
}

bool Figure::check_intersection()
{
	if (target == nullptr) {
		return false;
	}
	if (get_global_bounds().intersects(target->get_global_bounds())) {

		set_outline(4);
		target->set_outline(4);
	}
	else {
		set_outline(0);
		target->set_outline(0);

	}
	return get_global_bounds().intersects(target->get_global_bounds());
}

void Figure::set_target(Figure* target) {
	this->target = target;
}

Figure* Figure::get_target() {
	return target;
}