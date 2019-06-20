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
private:
	int indeks;
	stan stan_karty;
	bool wyrozniona;
	sf::Texture obrazek_zakryta;
	sf::Texture obrazek_odkryta;
	sf::Sprite obrazek;
public:
	void wczytaj_tekstury(sf::Texture, sf::Texture);
	void wyswietlaj_teksture(sf::Texture, sf::Texture, sf::Sprite, stan);
	KARTA() {};
	~KARTA() {};

};