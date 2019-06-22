#include"Plansza.h"
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include<fstream>

using namespace sf;

KARTA PLANSZA::wczytaj_pliki(KARTA karta)
{
	
		obrazek_zakryta.loadFromFile("zakryta.png");
	
	
	if(indeks=1)
	{
		obrazek_odkryta.loadFromFile("kapczyk.bmp");
	}
	if(indeks=2)
	{
		obrazek_odkryta.loadFromFile("kapczyk.bmp");
	}
	if(indeks=3)
	{
		obrazek_odkryta.loadFromFile("kapczyk.bmp");
	}
	if(indeks=4)
	{
		obrazek_odkryta.loadFromFile("kapczyk.bmp");
	}
	if(indeks=5)
	{
		obrazek_odkryta.loadFromFile("kapczyk.bmp");
	}
	if(indeks=6)
	{
		obrazek_odkryta.loadFromFile("kapczyk.bmp");
	}
	return karta;
}

KARTA PLANSZA::zaladuj_sprites(KARTA karta)
{
		if (stan_karty == zakryta)
		{
			obrazek.setTexture(obrazek_zakryta);
		}
		else if (stan_karty ==odkryta)
		{
			obrazek.setTexture(obrazek_odkryta);
		}
		
	return karta;
}


KARTA PLANSZA::mieszaj(KARTA zestaw_kart[12])
{
	KARTA przechowanie;
	int x;
	srand(time(NULL));
	for (int i = 0; i < 12; i++)
	{
		przechowanie = zestaw_kart[i];
		x = (rand() % 8);
		zestaw_kart[i] = zestaw_kart[x];
		zestaw_kart[x] = przechowanie;
	}
	return *zestaw_kart;
}


KARTA PLANSZA::rysuj_sprites(sf::RenderWindow* okno_gry, KARTA karta, float x, float y)
{
	
	obrazek.setPosition(x,y);
	okno_gry->draw(obrazek);
	
	return karta;
}

KARTA PLANSZA::podswietl(KARTA karta, int x1, int x2, int y1, int y2)
{
	if (obrazek.getPosition().x > x1 && obrazek.getPosition().x < x2)
	{
		if (obrazek.getPosition().y > y1 && obrazek.getPosition().y < y2)
		{
			obrazek.setScale(2, 2);
		}

	}
	return karta;
}
