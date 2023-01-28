#pragma once
#include <iostream>
#include "Objekt.h"
#include <SFML/Graphics.hpp>
class Meteor : public Objekt
{
private:
	sf::Texture tekstura;
	sf::Sprite obj;
public:
	Meteor(float xx, float yy, float akut, float R)
	{
		setX(xx);
		setY(yy);
		setKut(akut);
		setR(R);
		if (!tekstura.loadFromFile("Slike/Meteor.png"))
		{
			std::cout << "Greska ucitavanja teksture!" << std::endl;
			system("pause");
		}
		obj.setTexture(tekstura);
		obj.setOrigin(65, 65);
		obj.setScale(0.7,0.7);
		setDx(2.0+rand() % 8 - 4.0);
		setDy(2.0+rand() % 8 - 4.0);
		setZivot(true);
		setIme("meteor");
	};
	void crtaj(sf::RenderWindow& win)
	{
		win.draw(obj);
	}
	void kretanje(int w, int h)
	{
		setX(getX() + getDx() * 0.2);
		setY(getY() + getDy() * 0.2);
		if (getX() > w) setX(0);
		if (getX() < 0) setX(w);
		if (getY() > h) setY(0);
		if (getY() < 0) setY(h);
		obj.setPosition(getX(), getY());
		obj.setRotation(getKut() + 90);
	}
};