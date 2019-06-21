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
	stan stan_karty=zakryta;
	sf::Texture* obrazek_odkryta;
	sf::Texture*obrazek_zakryta;
	sf::Sprite obrazek;
public:
	KARTA(int indeks) : indeks(indeks) {};
	KARTA() {};

};