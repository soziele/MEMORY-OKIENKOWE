#pragma once
#include"Karta.h"
#include"Plansza.h"


class ROZGRYWKA
{
private:
	
	sf::Texture obrazek_zakryta;

public:
	
	void aktualizuj(sf::RenderWindow*);
	
	ROZGRYWKA();
};
