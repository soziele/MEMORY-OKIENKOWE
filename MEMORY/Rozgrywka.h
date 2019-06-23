#pragma once
#include "Karta.h"
#include "Plansza.h"


class ROZGRYWKA
{
private:
	void rysuj_wszystko(RenderWindow*);
	KARTA zestaw[12];

public:

	void menu(sf::RenderWindow*);
	void aktualizuj(sf::RenderWindow*);
	
	ROZGRYWKA();
};
