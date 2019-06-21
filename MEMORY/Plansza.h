#pragma once
#include"Karta.h"

class PLANSZA:private KARTA
{
private:
	KARTA zestaw_kart[12];
	sf::Texture obrazek_zakryta;
public:
	void wczytaj_pliki();
	PLANSZA(KARTA zestaw_kart[12]) {};
};