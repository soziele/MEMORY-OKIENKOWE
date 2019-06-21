#pragma once
#include"Karta.h"
#include"Rozgrywka.h"

class PLANSZA:public KARTA
{
private:
	KARTA zestaw_kart[12];
	sf::Texture obrazek_zakryta;
public:
	KARTA wczytaj_pliki();
	KARTA zaladuj_sprites();
	void rysuj_sprites(sf::RenderWindow*, KARTA[12]);
	PLANSZA(KARTA zestaw_kart[12]) {};
};