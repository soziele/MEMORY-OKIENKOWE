#pragma once
#include "Karta.h"
#include "Plansza.h"


class ROZGRYWKA
{
private:
	int liczba_tur=0;
	void rysuj_wszystko(RenderWindow*);
	KARTA zestaw[12];

	int kolor=0;

public:

	void menu(sf::RenderWindow*);
	void aktualizuj(sf::RenderWindow*);

	int getKolor()
	{
		return kolor;
	}

	void setKolor(int klr)
	{
		this->kolor = klr;
	}


	ROZGRYWKA();
};
