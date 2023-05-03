#pragma once

#include <SFML/Graphics.hpp>


class Figure
{
protected:
	sf::Shape* figure;
	sf::Color new_color;
	sf::Color transparent_color;
	sf::Color color;
	bool show = true;
	bool selected;
public:
	Figure();
	Figure(const Figure& );
	~Figure();
	virtual void set_show(bool) ;
	virtual bool get_show() ;
	virtual sf::Shape* get_figure() = 0;
	virtual sf::Color get_new_color() =0;
	virtual sf::Color get_transparent_color() =0;
	virtual sf::Color  get_color()=0;
	virtual bool  get_selected()=0;
	virtual void set_transparency() = 0;
	virtual sf::FloatRect get_global_bounds() = 0;
	virtual void set_scale(float x, float y) = 0;
	virtual void change_color(sf::Color) = 0;
	virtual void set_default() = 0;
	virtual void auto_move(sf::Vector2f) = 0;
	virtual void draw(sf::RenderWindow& window) = 0;
	virtual void set_position(float x, float y) = 0;
	virtual void move(float x, float y) = 0;
	virtual void set_outline(float thickness) = 0;
	virtual void set_outline(float thickness, sf::Color)=0;
	virtual Figure* clone() = 0;
	virtual std::string get_figure_name() = 0;

};

