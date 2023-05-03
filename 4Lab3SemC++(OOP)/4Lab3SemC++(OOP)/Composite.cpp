#include "Composite.h"

Composite::Composite() {
	figures = new Figure*;
	figures_count =0;
	show = true;
}
Composite::~Composite() {
	for (int i = 0; i < figures_count; ++i) {
		delete figures[i];
	}
	delete[] figures;
}

Composite::Composite(const Composite& other) {
	Figure** deep_copy = new Figure * [other.figures_count];

	for (int i = 0; i < other.figures_count; i++)
	{
		deep_copy[i] = other.figures[i]->clone();
	}
	figures = deep_copy;
	figures_count = other.figures_count;
	show = other.show;
}
Composite* Composite::clone() {
	return new Composite(*this);
}

Figure** Composite::get_figures() {
	return figures;
}

std::string Composite::get_figure_name() {
	return "composite";
}

sf::RectangleShape* Composite::get_figure() {
	return nullptr;
}
sf::Color Composite::get_color() {
	return sf::Color();
}
sf::Color Composite::get_new_color() {
	return sf::Color();
}
sf::Color Composite::get_transparent_color() {
	return sf::Color();
}
Figure* Composite::get_figure(int i) {
	bool check = i < figures_count && i>=0;
	if (check) {
		return figures[i];
	}
	return nullptr;
}

int Composite::get_figure_index(Figure* figure) {
	int res = -1;
	if (figure == nullptr) {
		return res;
	}
	for (int i = 0; i < figures_count; i++) {
		if (figures[i] == figure) {
			res = i;
		}
	}
	return res;
}
void Composite::add(Figure* figure) {

	if (figure == nullptr||get_figure_index(figure) >= 0)
		return;
	Figure** new_figures = new Figure * [figures_count + 1];
	for (int i = 0; i < figures_count; i++) {
		new_figures[i] = figures[i];
		figures[i] = nullptr;
		delete figures[i];
	}
	new_figures[figures_count++] = figure;


	delete[] figures;
	figures = new_figures;
}

void Composite::remove(Figure* figure) {
	int figure_index = get_figure_index(figure);
	if (figure_index < 0)
		return;

	int added_count = 0;
	Figure** new_figures = new Figure * [figures_count - 1];
	for (int i = 0; i < figures_count; i++) {
		if (i != figure_index) {
			new_figures[added_count++] = figures[i];
		}

		figures[i] = nullptr;
		delete figures[i];
	}
	delete[] figures;
	figures = new_figures;

	figures_count--;
}

void Composite::add_comp(Composite& copy) {
	
	Figure** new_figures = new Figure * [figures_count + copy.figures_count];
	for (int i = 0; i < figures_count; i++) {
		new_figures[i] = figures[i];
		figures[i] = nullptr;
		delete figures[i];
	}
	for (int i = 0; i < copy.figures_count; i++) {
		new_figures[figures_count+i] = copy.figures[i];
		copy.figures[i] = nullptr;
		delete copy.figures[i];
	}
	figures_count+= copy.figures_count;
	delete[] figures;
	figures = new_figures;
}
int Composite::get_figures_count() {
	return figures_count;
}


void Composite::set_position(float x, float y) {

	float left_x = x - get_global_bounds().left;
	float top_y = y - get_global_bounds().top;
	float width = get_global_bounds().width;
	float height = get_global_bounds().height;

	if (x <= 0.f || x + width >= 700) {
		if (x <= 0.f) {
			left_x = 0;
		}
		if (x + width >= 700) {
			left_x = 0;
		}
	}
	if (y <= 0.f || y + height >= 650) {
		if (y <= 0.f) {
			top_y = 0;
		}
		if (y + height >= 650) {
			top_y = 0;
		}
	}
	for (int i = 0; i < figures_count; i++) {
		figures[i]->move(left_x, top_y);
	}
}

void Composite::move(float, float)
{
}

void Composite::draw(sf::RenderWindow& window) {
	for (int i = 0; i < figures_count; i++) {
		figures[i]->draw(window);
	}
}
sf::FloatRect Composite::get_global_bounds() {
	float composite_left, composite_top, composite_right, composite_bottom, check_width = 0, check_height = 0;
	composite_left = figures[0]->get_global_bounds().left;
	composite_top = figures[0]->get_global_bounds().top;
	composite_right = figures[0]->get_global_bounds().left + figures[0]->get_global_bounds().width;
	composite_bottom = figures[0]->get_global_bounds().top + figures[0]->get_global_bounds().height;


	for (int i = 1; i < figures_count; i++) {
		composite_left = std::min(composite_left, figures[i]->get_global_bounds().left);
		composite_top = std::min(composite_top, figures[i]->get_global_bounds().top);
		composite_right = std::max(composite_right, figures[i]->get_global_bounds().left + figures[i]->get_global_bounds().width);
		composite_bottom = std::max(composite_bottom, figures[i]->get_global_bounds().top + figures[i]->get_global_bounds().height);
	}
	sf::FloatRect composite_bounds(composite_left, composite_top, composite_right - composite_left, composite_bottom - composite_top);

	return composite_bounds;
}
bool Composite::get_selected() {
	return selected;
}
void Composite::set_selected(bool is_selected) {
	selected = is_selected;
}
void Composite::set_outline(float thickness) {
	for (int i = 0; i < figures_count; i++) {
		figures[i]->set_outline(thickness, sf::Color(250, 150, 100));
	}
}
void Composite::set_outline(float thickness,sf::Color) {
}

void Composite::set_show(bool is_show) {
	show = is_show;
	for (int i = 0; i < figures_count; i++) {
		figures[i]->set_show(is_show);
	}
}
bool Composite::get_show() {
	return show;
}

void Composite::set_transparency() {
	for (int i = 0; i < figures_count; i++) {
		figures[i]->set_transparency();
	}
}
void Composite::change_color(sf::Color color) {
	for (int i = 0; i < figures_count; i++) {
		figures[i]->change_color(color);
	}
}
void Composite::set_scale(float x, float y) {
	for (int i = 0; i < figures_count; i++) {
		figures[i]->set_scale(x, y);
	}
}
void Composite::set_default() {
	for (int i = 0; i < figures_count; i++) {
		figures[i]->set_default();
	}
}

sf::Vector2f Composite::delta(sf::Vector2f figure) {
	float left = get_global_bounds().left;
	float width = get_global_bounds().width;
	float top = get_global_bounds().top;
	float height = get_global_bounds().height;
	return sf::Vector2f((left+ width /2)-figure.x , (top+ height /2)-figure.y  );
}

void Composite::auto_move(sf::Vector2f mouse)
{
	float width = get_global_bounds().width;
	float height = get_global_bounds().height;
	float left = get_global_bounds().left;
	float top = get_global_bounds().top;
	float left_x = mouse.x - (get_global_bounds().left + width / 2);
	float top_y = mouse.y -( get_global_bounds().top + height / 2);

	float move_x = left_x / 100;
	float move_y = top_y / 100;

	if (left <= 0.f || left + width >= 700.f) {
		move_x = 0;
		move_y = 0;
	}
	if (top <= 0.f || top + height >= 650.f) {
		move_x = 0;
		move_y = 0;
	}
	for (int i = 0; i < figures_count; i++) {
		figures[i]->move(move_x, move_y);
	}
}