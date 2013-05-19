#include "Main.h"

sf::RenderWindow *app;

int main()
{
	std::cout << "AI_Test" << std::endl;
	
	app = new sf::RenderWindow(sf::VideoMode(800, 600, 32), "AI_Test");

	return 0;
}


bool ait::ClientInit()
{
	return false;
}


void ait::ClientLoop()
{
}