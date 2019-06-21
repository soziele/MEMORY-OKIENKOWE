#pragma once
#include<SFML/Graphics.hpp>


class ZASOBY
{
private:
	sf::Texture obrazki_odkryta_z_pliku[6];
	sf::Texture obrazek_zakryta_z_pliku;
public:
	void wczytaj_zasoby(sf::Texture, sf::Texture[6]);
	ZASOBY();
	~ZASOBY() {};
};

