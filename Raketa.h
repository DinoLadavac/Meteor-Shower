#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include "Objekt.h"

class Raketa : public Objekt
{
private:
	bool naprijed;
	int max_brzina = 3;
	float brzina;
	sf::Texture tekstura;
	sf::Sprite obj;


public:
	Raketa()
	{
		if (!tekstura.loadFromFile("Slike/Rocket.png"))
		{
			std::cout << "Greska ucitavanja teksture!" << std::endl;
			system("pause");
		}
		obj.setTexture(tekstura);
		obj.setOrigin(20, 20);
		setX(850);
		setY(450);
		setR(18);
		setDx(0);
		setDy(0);
		setKut(0);
	}
	void crtaj(sf::RenderWindow& win)
	{
		win.draw(obj);
	}
	void kretanje(int sirina, int visina)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			setKut(getKut()+1);
			if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
				naprijed = false;
			}
			else
			{
				naprijed = true;
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			setKut(getKut()-1);
			if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
				naprijed = false;
			}
			else
			{
				naprijed = true;
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			naprijed = true;
		}
		else
		{
			naprijed = false;
		}
		if (naprijed)
		{
			setDx(getDx()+cos(getKut() * getDEGTORAD())*0.2);
			setDy(getDy()+sin(getKut() * getDEGTORAD())*0.2);
		}
		else
		{
			setDx(getDx()*0.99);
			setDy(getDy()*0.99);
		}
		brzina = sqrt(getDx() * getDx() + getDy() * getDy());
		if (brzina > max_brzina)
		{
			setDx(getDx()* max_brzina / brzina);
			setDy(getDy()* max_brzina / brzina);
		}
		setX(getX()+getDx());
		setY(getY()+getDy());
		if (getX() >  sirina) setX(0);
		if (getX() < 0) setX(sirina);
		if (getY() > visina) setY(0);
		if (getY() < 0) setY(visina);
		obj.setPosition(getX(), getY());
		obj.setRotation(getKut() + 90);
	}	
};
