#pragma once

#include <SFML/Graphics.hpp>
using namespace sf;

class Figure
{
protected:
	Shape* figure;
	Color new_color;
	Color transparent_color;
	Color color;
	bool show = true;
	bool selected;
	Figure* target = nullptr;

public:
	Figure();
	Figure(const Figure&);
	virtual ~Figure();
	virtual void set_show(bool);
	virtual bool get_show();
	virtual Shape* get_figure() = 0;
	virtual Color get_new_color() = 0;
	virtual Color get_transparent_color() = 0;
	virtual Color  get_color() = 0;
	virtual bool  get_selected() = 0;
	virtual void set_transparency() = 0;
	virtual FloatRect get_global_bounds() = 0;
	virtual void set_scale(float x, float y) = 0;
	virtual void change_color(Color) = 0;
	virtual void set_default() = 0;
	virtual void auto_move(Vector2f) = 0;
	virtual void draw(RenderWindow& window) = 0;
	virtual void set_position(float x, float y) = 0;
	virtual void move(float x, float y) = 0;
	virtual void set_outline(float thickness) = 0;
	virtual void set_outline(float thickness, Color) = 0;
	virtual Figure* clone() = 0;
	virtual std::string get_figure_name() = 0;
	virtual bool check_intersection();
	virtual void set_target(Figure*);
	virtual Figure* get_target();
};

