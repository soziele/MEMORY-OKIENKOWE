#pragma once
#include"Karta.h"
#include"Rozgrywka.h"


class PLANSZA:public KARTA
{
private:
	KARTA zestaw_kart[12];
public:
	KARTA wczytaj_pliki(KARTA[12]);
	KARTA zaladuj_sprites(KARTA[12]);
	KARTA mieszaj(KARTA[12]);
	void rysuj_sprites(sf::RenderWindow*, KARTA[12]);
	PLANSZA(KARTA zestaw_kart[12]) {};
};