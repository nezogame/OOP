
#include <SFML/Graphics.hpp>
#include <iostream>
#include"Circle.h"
#include"Star.h"
#include"Square.h"
#include"Line.h"
#include"Triangle.h"
#include "Controller.h"
#include <thread>
#include <mutex>


using namespace sf;
using namespace std;



int main()
{

	Controller* controller = new Controller();
	std::mutex mutex;
	ContextSettings settings;
	settings.antialiasingLevel = 8;
	RenderWindow window(VideoMode(700, 650), "leave me alone!", Style::Titlebar | Style::Close, settings);

	sf::Clock clock2;
	float timer;

	while (window.isOpen())
	{

		controller->event_handler(window);
		//controller->do_thread();

		window.clear(Color(239, 228, 176));

		sf::Time elapsed2 = clock2.getElapsedTime();
		timer = elapsed2.asMilliseconds();
		
		if (timer > 1000)
		{
			std::thread add_thread([&]() {

				controller->add_figures();

				});
			add_thread.join();
		}


		std::thread move_thread([&]() {controller->move_figures_and_intersection_check(); });
		move_thread.join();

		std::thread remove_intersection_thread([&]() {controller->remove_figure();});
		remove_intersection_thread.join();

		std::thread assign_target_thread([&]() {controller->assign_new_targets(); });
		assign_target_thread.join();
		

		for (auto& figure : controller->get_figures())
		{
			if (figure != nullptr) {
				figure->draw(window);
			}
		}





		window.display();
	}

	window.close();

}

