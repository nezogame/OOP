#pragma once
#include "Figure.h"


class Composite :
    public Figure
{
private:
	Figure** figures ;
	int figures_count;
	bool show = true;
public:
	Composite();
	~Composite();
	Composite(const Composite& other);
	Composite* clone();
	Figure** get_figures();
	int get_figure_index(Figure* figure);
	int get_figures_count();
	void add(Figure* figure);
	void add_comp(Composite &copy);
    void remove(Figure* figure);
	void set_position(float, float) override;
	void move(float, float) sealed;
	void draw(sf::RenderWindow&) override;
	sf::FloatRect get_global_bounds() override;
	void set_selected(bool is_selected);
	void set_outline(float thickness) override;
	void set_outline(float thickness, sf::Color)override;
	void set_show(bool) override;
	bool get_show() override;
	void set_transparency()override;
	void change_color(sf::Color)override;
	void set_scale(float x, float y)override;
	void set_default()override;
	void auto_move(sf::Vector2f) override;
	sf::Vector2f delta( sf::Vector2f);
	Figure* get_figure(int i);
	sf::RectangleShape* get_figure() override;
	sf::Color get_color() override;
	sf::Color get_new_color() override;
	sf::Color get_transparent_color() override;
	bool get_selected() override;
	std::string get_figure_name() override;
};

