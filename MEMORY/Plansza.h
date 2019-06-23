#pragma once
#include"Karta.h"
#include"Rozgrywka.h"



class PLANSZA:public KARTA
{

public:
	bool czy_to_ta_karta(KARTA, Vector2i);
	KARTA pozycja_sprite(KARTA, float, float);
	KARTA wczytaj_pliki(KARTA);
	KARTA zaladuj_sprites(KARTA);
	KARTA mieszaj(KARTA[12]);
	KARTA rysuj_sprites(sf::RenderWindow*, KARTA);
	KARTA podswietl(KARTA,float);
	
	PLANSZA() {};
};