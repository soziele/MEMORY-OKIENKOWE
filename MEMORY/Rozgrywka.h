#pragma once
#include"Karta.h"
#include"Plansza.h"


class ROZGRYWKA
{
	friend class PLANSZA;
	
public:
	void menu(sf::RenderWindow*);
	void aktualizuj(sf::RenderWindow*);
	
	ROZGRYWKA();
};
