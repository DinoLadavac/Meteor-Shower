#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#define Max_number 7
class GameOver
{
private:
	sf::Text text[Max_number];
	sf::Font font;
	sf::Sprite obj;
	sf::Texture tekstura;
	bool kraj = false;
	int rezultat =0 ;
public:
	GameOver()
	{
		if (!font.loadFromFile("font/Quinquefive-Ea6d4.ttf"))
		{
			std::cout << "Greska fonta!" << std::endl;
			system("pause");
		}
		if (!tekstura.loadFromFile("Slike/Poz.jpg"))
		{
			std::cout << "Greska ucitavanja pozadine" << std::endl;
			system("pause");
		}
		obj.setTexture(tekstura);
		obj.setScale(2, 2);
		text[0].setFont(font);
		text[0].setCharacterSize(40);
		text[0].setFillColor(sf::Color::White);
		text[0].setString("Game over!");
		text[0].setPosition(sf::Vector2f(630,350));
		text[1].setFont(font);
		text[1].setCharacterSize(20);
		text[1].setFillColor(sf::Color::White);
		text[1].setString("Tvoj rezultat:");
		text[1].setPosition(sf::Vector2f(580, 430));
		text[2].setFont(font);
		text[2].setCharacterSize(20);
		text[2].setFillColor(sf::Color::White);
		text[2].setString("Najbolji rezultat:");
		text[2].setPosition(sf::Vector2f(580, 480));
		text[3].setFont(font);
		text[3].setCharacterSize(20);
		text[3].setFillColor(sf::Color::White);
		text[3].setString("Pretisni SPACE za nastavak");
		text[3].setPosition(sf::Vector2f(560, 850));
		text[4].setFont(font);
		text[4].setCharacterSize(20);
		text[4].setFillColor(sf::Color::White);
		text[4].setPosition(sf::Vector2f(1050, 420));
		text[5].setFont(font);
		text[5].setCharacterSize(20);
		text[5].setFillColor(sf::Color::White);
		text[5].setPosition(sf::Vector2f(1050, 470));
		text[6].setFont(font);
		text[6].setCharacterSize(20);
		text[6].setFillColor(sf::Color::Transparent);
		text[6].setPosition(sf::Vector2f(700, 600));
		text[6].setString("Novi rekord!");

	}
	void pokreni(sf::RenderWindow& window, int tvojRezultat,std::string Rekord)
	{
		window.clear();
		window.draw(obj);
		std::stringstream pretvori;
		pretvori << Rekord;
		pretvori >> rezultat;
		text[4].setString(std::to_string(tvojRezultat));
		text[5].setString(Rekord);
		if (tvojRezultat == rezultat)
		{
			text[6].setFillColor(sf::Color::White);
		}

		for (int i = 0; i < 7; i++)
		{
			window.draw(text[i]);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			this->setKraj(true);
		}
	}
	bool getKraj()
	{
		return kraj;
	}
	void setKraj(bool a)
	{
		kraj = a;
	}
};