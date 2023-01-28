#include <SFML/Graphics.hpp>
#pragma once

class Objekt
{	
private:

	float x, y, kut, r, dx, dy;
	std::string ime;
	bool zivot; 
	float DEGTORAD = 0.017453f;
public:
	Objekt(float xx, float yy, float akut, float R)
	{
		x = xx;
		y = yy;
		kut = akut;
		r = R;
		dx = 0;
		dy = 0;
		zivot = 1;
	};
	Objekt() 
	{
		x = 0;
		y = 0;
	};
	virtual void crtaj(sf::RenderWindow& window) = 0;
	virtual void kretanje(int w, int h) = 0;
	bool getZivot()
	{
		return zivot;
	};
	void setZivot(bool a)
	{
		zivot = a;
	}
	float getX()
	{
		return x;
	};
	void setX(float a)
	{
		x = a;
	}
	float getY()
	{
		return y;
	};
	void setY(float a)
	{
		y = a;
	}
	float getDx()
	{
		return dx;
	};
	void setDx(float a)
	{
		dx = a;
	}
	float getDy()
	{
		return dy;
	};
	void setDy(float a)
	{
		dy = a;
	}
	float getKut()
	{
		return kut;
	};
	void setKut(float a)
	{
		kut = a;
	}
	float getR()
	{
		return r;
	};
	void setR(float a)
	{
		r = a;
	}
	void setIme(std::string h)
	{
		ime = h;
	}
	std::string getIme()
	{
		return ime;
	}
	float getDEGTORAD()
	{
		return DEGTORAD;
	}
};

