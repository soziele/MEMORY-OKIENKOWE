#pragma once
#include<SFML/Graphics.hpp>


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
	stan stan_karty=odkryta;
	sf::Texture obrazek_odkryta;
	sf::Texture obrazek_zakryta;
	sf::Sprite obrazek;
public:
	
	void setStan(stan stan)
	{
		this->stan_karty = stan;
	}
	stan getStan()
	{
		return stan_karty;
	}
	KARTA(int indeks) : indeks(indeks) {};
	KARTA() {};

};