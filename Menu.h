#include <SFML/Graphics.hpp>
#include <iostream>
#define MAX_NUMBER_OF_ITEMS 2
class menu
{
public:
	void setText(sf::Text *j)
	{
		j->setFont(font);
		j->setCharacterSize(40);
		j->setFillColor(sf::Color::Color(85, 85, 85));
	}
	menu(float sirina, float visina)
	{
		if (!tekstura.loadFromFile("Slike/Menu.png"))
		{
			std::cout << "Greska ucitavanja pozadine" << std::endl;
			system("pause");
		}
		pozadina.setTexture(tekstura);
		pozadina.setScale(2, 2);
		if (!font.loadFromFile("font/Quinquefive-Ea6d4.ttf"))
		{
			std::cout << "Greska fonta!" << std::endl;
			system("pause");
		}
		
		Naslov.setFont(font);
		Naslov.setCharacterSize(70);
		Naslov.setFillColor(sf::Color::White);
		Naslov.setString("Meteor shower");
		Naslov.setPosition(sf::Vector2f(sirina/4.7, visina/18));
		this->setText(text);
		text[0].setString("Pokreni");
		text[0].setPosition(sf::Vector2f(sirina/34, visina/1.25));
		this->setText(text+1);
		text[1].setString("Izlaz");
		text[1].setPosition(sf::Vector2f(sirina/34, visina/1.11));
		IndexOdabira = 0;
		
	};
	void crtajMain(sf::RenderWindow &window)
	{
		window.draw(pozadina);
		window.draw(Naslov);
		for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
		{
			window.draw(text[i]);
		}
		
	};
	void OdabirGore()
	{
		if (IndexOdabira - 1 >= 0)
		{
			text[IndexOdabira].setFillColor(sf::Color::Color(85,85,85));
			IndexOdabira--;
			text[IndexOdabira].setFillColor(sf::Color::White);
		}
	}
	void OdabirDolje()
	{
		if (IndexOdabira + 1 < MAX_NUMBER_OF_ITEMS)
		{
			text[IndexOdabira].setFillColor(sf::Color::Color(85, 85, 85));
			IndexOdabira++;
			text[IndexOdabira].setFillColor(sf::Color::White);
		}
	}
	int Odabir()
	{
		return IndexOdabira;
	}
private:
	int IndexOdabira;
	sf::Font font;
	sf::Text text[MAX_NUMBER_OF_ITEMS];
	sf::Text Naslov;
	sf::Sprite pozadina;
	sf::Texture tekstura;
	
};