#pragma once
#include <iostream>
#include "Meteor.h"
#include "Raketa.h"
#include "Metak.h"
#include "Objekt.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <math.h>
#include <fstream>
#include <sstream>
#define W 1700
#define H 900
#define MAX_ITEMS 2

class GamePlay
{
private:
	sf::Font font;
	sf::Sprite pozadina;
	sf::Text text[MAX_ITEMS];
	sf::Texture tekstura;
	std::vector<Objekt*> entiteti;
	Raketa *raketa = new Raketa;
	bool zivot;
	int rezultat = 0;
	std::fstream datoteka;
	std::string rekord;
	
	
public:
	int getRezultat()
	{
		return rezultat;
	}
	void setZivot(bool h)
	{
		zivot = h;
	}
	bool getZivot()
	{
		return zivot;
	}
	void setText(sf::Text *j)
	{
		if (!font.loadFromFile("font/Quinquefive-Ea6d4.ttf"))
		{
			std::cout << "Greska fonta!" << std::endl;
			system("pause");
		}
		j->setFont(font);
		j->setCharacterSize(20);
		j->setFillColor(sf::Color::White);
	}
	GamePlay(){
		if (!tekstura.loadFromFile("Slike/Poz.jpg"))
			{
			std::cout << "Greska ucitavanja pozadine" << std::endl;
			system("pause");
			}
		pozadina.setTexture(tekstura);
		pozadina.setScale(2, 2);
		this->crtajMeteore();
		this->setText(text);
		text[0].setString("Rezultat:");
		text[0].setPosition(sf::Vector2f(0, 0));
		this->setText(text + 1);
		text[1].setPosition(sf::Vector2f(220, 0));
		setZivot(true);
	}
	~GamePlay()
	{
		delete raketa;
		for (int i = 0; i < entiteti.size() - 1; i++)
		{
			delete entiteti[i];
		}
	}
	
	void pokreni(sf::RenderWindow& window)
	{
		window.clear();
		window.draw(pozadina);
		sf::Event dog;
		while (window.pollEvent(dog))
		{
			if (dog.type == sf::Event::KeyPressed) {
				switch (dog.key.code)
				{
				case sf::Keyboard::Space:
				{
					if (entiteti.size() < 20)
					{
						metak* puc = new metak(raketa->getX(), raketa->getY(), raketa->getKut(), 0.8);
						entiteti.push_back(puc);
					}
					break;
				}
				case sf::Keyboard::Escape:
				{
					zivot = false;
					break;
				}
				}
			}
		}
		if (!entiteti.empty())
		{
			//Crtaj meteore i metke ako su zivi
			for (int j = 0; j < entiteti.size(); j++)
			{
				if (entiteti[j]->getZivot() != false)
				{
					entiteti[j]->crtaj(window);
					entiteti[j]->kretanje(W, H);
				}
				else
				{
					delete entiteti[j];
					entiteti.erase(entiteti.begin() + j);
				}
			}
			//Brisi meteor i metak kad se sudare
			for (int i = 0; i < entiteti.size(); i++)
			{
				for (int j = 0; j < entiteti.size(); j++)
				{
					if (Sudar(entiteti[i], entiteti[j]) && entiteti[i]->getIme() == "meteor" && entiteti[j]->getIme() == "metak")
					{
						rezultat = rezultat + 50;
						entiteti[j]->setZivot(false);
						entiteti[i]->setZivot(false);
						delete entiteti[j];
						delete entiteti[i];
						entiteti.erase(entiteti.begin() + j);
						entiteti.erase(entiteti.begin() + i);
					}
				}
			}
		}
		else
		{
			this->crtajMeteore();
		}
		for (int i = 0; i < entiteti.size(); i++)
		{
			if (Sudar(raketa,entiteti[i]) && entiteti[i]->getIme() == "meteor")
			{
				setZivot(0);
			}
		}
		raketa->crtaj(window);
		raketa->kretanje(W, H);
		text[1].setString(std::to_string(rezultat));
				
		for (int i = 0; i < MAX_ITEMS; i++)
		{
			window.draw(text[i]);
		}
	}
	bool Sudar(Objekt* a, Objekt* b)
	{
		return (pow(b->getX() - a->getX(), 2) + pow(b->getY() - a->getY(), 2)) < (pow(b->getR() + a->getR(),2));
	}
	void crtajMeteore()
	{
		for (int i = 0; i < (10 + rand() % 8); i++)
		{
			Meteor* meteor = new Meteor(rand() % W, rand() % H, rand() % 360, 65);
			if (((meteor->getX()) >(raketa->getX() - 100) && (meteor->getX()) < (raketa->getX() + 100)) && 
				((meteor->getY()) > (raketa->getY() - 100) && (meteor->getY()) < (raketa->getY() + 100)))
			{
				meteor->setX(100);
				meteor->setY(100);
				entiteti.push_back(meteor);
			}
			else
			{	
				entiteti.push_back(meteor);
			}
		}
	}
	std::string getRekord()
	{
		datoteka.open("rekord.txt", std::ios::in | std::ios::app);
		std::getline(datoteka, rekord);
		datoteka.close();
		return rekord;
	}

	void setRekord()
	{
		std::stringstream pretvori;
		int rez;
		pretvori << this->getRekord();
		pretvori >> rez;
		if (this->getRezultat() > rez)
		{
			datoteka.open("rekord.txt", std::ios::out| std::ios::trunc);
			if (!datoteka.is_open())
			{
				std::cout << "Trebate dopustenje sustava za izmjenjivanje txt datoteke" << std::endl;
			}
			else
			{
				datoteka << std::to_string(this->getRezultat());
				datoteka.close();
			}
		}
	}
};