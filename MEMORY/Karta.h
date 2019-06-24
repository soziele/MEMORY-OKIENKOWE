#pragma once
#include<SFML/Graphics.hpp>
using namespace sf;

enum stan
{
	zakryta = 1,
	odkryta = 2,
	usunieta = 3
};

class KARTA
{
	friend class PLANSZA;
private:
	int indeks;
	stan stan_karty=zakryta;
	sf::Texture obrazek_odkryta;
	sf::Texture obrazek_zakryta;
	sf::Sprite obrazek;
public:
	Sprite getSprite()
	{
		return obrazek;
	}
	void setStan(stan stan)
	{
		this->stan_karty = stan;
	}
	stan getStan()
	{
		return stan_karty;
	}
	int getIndex()
	{
		return indeks;
	}
	KARTA(int indeks) : indeks(indeks) {};
	KARTA() {};

};