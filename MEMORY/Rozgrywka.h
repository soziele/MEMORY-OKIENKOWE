#pragma once
#include"Karta.h"
#include"Plansza.h"


class ROZGRYWKA
{
	friend class PLANSZA;
	
public:
	
	void aktualizuj(sf::RenderWindow*);
	friend void rysuj_sprites(sf::RenderWindow*,KARTA[12]);
	ROZGRYWKA();
};
