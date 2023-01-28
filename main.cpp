#include "Menu.h"
#include "GamePlay.h"
#include "GameOver.h"
#include "SFML/Graphics.hpp"
#include <iostream>
#define W 1700
#define H 900


int main()
{
	sf::RenderWindow GUI(sf::VideoMode(W, H), "Meteor shower");
	menu* meni = new menu(W, H);

	while (GUI.isOpen())
	{
		sf::Event dogadjaj;
		while (GUI.pollEvent(dogadjaj))
		{
			GamePlay* game = new GamePlay;
			GameOver* over = new GameOver();
			switch (dogadjaj.type) {
			case sf::Event::KeyReleased:
				switch (dogadjaj.key.code)
				{
				case sf::Keyboard::Up:
					meni->OdabirGore();
					break;
				case sf::Keyboard::Down:
					meni->OdabirDolje();
					break;
				case sf::Keyboard::Return:
					switch (meni->Odabir())
					{
					case 0:
						while (game->getZivot() == true)
						{
							game->pokreni(GUI);
							GUI.display();
						}
						while (game->getZivot() == false && over->getKraj() == false)
						{
							game->setRekord();
							over->pokreni(GUI, game->getRezultat(), game->getRekord());
							GUI.display();
						}
						delete over;
						delete game;
						break;
					case 1:
						GUI.close();
						break;
					}
					break;
				}
				break;
			case sf::Event::Closed:
				GUI.close();
				break;
			}
		}
		GUI.clear();
		meni->crtajMain(GUI);
		GUI.display();

	}

	delete meni;
	return 0;
		
}

	