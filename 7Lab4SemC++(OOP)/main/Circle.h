#pragma once
#include "Figure.h"
class Circle : public Figure
{
private:
	CircleShape* circle;
	bool show = true;
	Color color;
	Color new_color;
	Color transparent_color;
	bool selected = false;

public:
	Circle(float, Color);
	Circle(float);
	Circle(const Circle& original);
	Circle* clone();
	~Circle();
	void set_position(float, float) override;
	void move(float, float) override;
	void draw(RenderWindow&) override;
	FloatRect get_global_bounds() override;
	void set_selected(bool is_selected);
	void set_outline(float thickness) override;
	void set_outline(float thickness, Color) override;
	void set_show(bool) override;
	void set_transparency()override;
	void change_color(Color)override;
	void set_scale(float x, float y)override;
	void set_default()override;
	void auto_move(Vector2f) override;
	CircleShape* get_figure() override;
	bool get_show() override;
	Color get_color() override;
	Color get_new_color() override ;
	Color get_transparent_color() override;
	bool get_selected() override;
	std::string get_figure_name() override;
};

