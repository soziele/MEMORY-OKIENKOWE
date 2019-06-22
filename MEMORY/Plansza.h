#pragma once
#include"Karta.h"
#include"Rozgrywka.h"



class PLANSZA:public KARTA
{

public:
	KARTA wczytaj_pliki(KARTA);
	KARTA zaladuj_sprites(KARTA);
	KARTA mieszaj(KARTA[12]);
	KARTA rysuj_sprites(sf::RenderWindow*, KARTA, float, float);
	KARTA podswietl(KARTA, int, int, int, int);
	PLANSZA() {};
};