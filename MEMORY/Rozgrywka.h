#pragma once
#include"Karta.h"
#include"Zasoby.h"

class ROZGRYWKA
{
private:
	KARTA zestaw_kart[12];
	sf::Texture obrazek_zakryta;

public:
	void aktualizuj(sf::RenderWindow*);
	
	ROZGRYWKA();
};
