#pragma once
#include"Karta.h"
#include"Rozgrywka.h"



class PLANSZA:public KARTA
{

public:
	bool czy_to_ta_karta(KARTA*, Vector2i);
	void pozycja_sprite(KARTA*, float, float);
	void wczytaj_pliki(KARTA*);
	void zaladuj_sprites(KARTA*);
	void mieszaj(KARTA[12]);
	void rysuj_sprites(sf::RenderWindow*, KARTA*);
	void podswietl(KARTA*,float);
	
	PLANSZA() {};
};