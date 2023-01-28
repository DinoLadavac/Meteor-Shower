#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Objekt.h"
class metak : public Objekt
{
private:
	sf::Texture tekstura;
	sf::Sprite obj;
public:
	metak(int xx, int yy, float akut, int ri)
	{
		if (!tekstura.loadFromFile("Slike/Metak.png"))
		{
			std::cout << "Greska ucitavanja teksture!" << std::endl;
			system("pause");
		}
		obj.setTexture(tekstura);
		obj.setScale(2, 2);
		setX(xx);
		setY(yy);
		setKut(akut);
		setR(ri);
		setZivot(true);
		setIme("metak");
	}
	void crtaj(sf::RenderWindow &window)
	{
		window.draw(obj);
	}
	void kretanje(int W,int H)
	{
		setDx(cos(getKut() * getDEGTORAD()) * 3.5);
		setDy(sin(getKut() * getDEGTORAD())* 3.5);
		setX(getX() + getDx());
		setY(getY() + getDy());
		if (getX() > W || getX() <0 || getY() >H || getY() < 0) setZivot(false);
		obj.setPosition(getX(), getY());
		obj.setRotation(getKut() + 90);
	}
};