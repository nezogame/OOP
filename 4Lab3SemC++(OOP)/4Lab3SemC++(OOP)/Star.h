#pragma once
#include "Figure.h"
class Star :
    public Figure
{
private:
	sf::ConvexShape* star;
	bool show = true;
	sf::Color color;
	sf::Color new_color;
	sf::Color transparent_color;
	bool selected = false;
public:
	Star();
	~Star();
	Star(const Star& other);
	Star* clone();
	void set_position(float, float) override;
	void move(float, float) override;
	void draw(sf::RenderWindow&) override;
	sf::FloatRect get_global_bounds() override;
	void set_selected(bool is_selected);
	void set_outline(float thickness) override;
	void set_show(bool) override;
	void set_transparency()override;
	void change_color(sf::Color)override;
	void set_scale(float x, float y)override;
	void set_default()override;
	void set_outline(float thickness, sf::Color)override;
	void auto_move(sf::Vector2f) override;
	sf::ConvexShape* get_figure() override;
	bool get_show() override;
	sf::Color get_color() override;
	sf::Color get_new_color() override;
	sf::Color get_transparent_color() override;
	bool get_selected() override;
	std::string get_figure_name() override;
};

