#include"Plansza.h"
#include <cstdlib>
#include <cstdio>
#include <ctime>

KARTA PLANSZA::wczytaj_pliki(KARTA zestaw_kart[12])
{
	
	for (int i = 0; i < 12; i++)
	{
		zestaw_kart[i].obrazek_zakryta.loadFromFile("kapczyk.bmp");
	}
	
	for (int i=0;i<2; i++)
	{
		zestaw_kart[i].obrazek_odkryta.loadFromFile("kapczyk.bmp");
	}
	for (int i = 2; i < 4; i++)
	{
		zestaw_kart[i].obrazek_odkryta.loadFromFile("kapczyk.bmp");
	}
	for (int i = 4; i < 6; i++)
	{
		zestaw_kart[i].obrazek_odkryta.loadFromFile("kapczyk.bmp");
	}
	for (int i = 6; i < 8; i++)
	{
		zestaw_kart[i].obrazek_odkryta.loadFromFile("kapczyk.bmp");
	}
	for (int i = 8; i < 10; i++)
	{
		zestaw_kart[i].obrazek_odkryta.loadFromFile("kapczyk.bmp");
	}
	for (int i = 10; i < 12; i++)
	{
		zestaw_kart[i].obrazek_odkryta.loadFromFile("kapczyk.bmp");
	}
	return *zestaw_kart;
}

KARTA PLANSZA::zaladuj_sprites(KARTA zestaw_kart[12])
{
	for (int i = 0; i < 12; i++)
	{
		if (zestaw_kart[i].stan_karty == zakryta)
		{
			zestaw_kart[i].obrazek.setTexture(obrazek_zakryta);
		}
		else if (zestaw_kart[i].stan_karty ==odkryta)
		{
			zestaw_kart[i].obrazek.setTexture(obrazek_odkryta);
		}
		

	}
	return *zestaw_kart;
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


void PLANSZA::rysuj_sprites(sf::RenderWindow* okno_gry, KARTA zestaw_kart[12])
{
	okno_gry->draw(zestaw_kart[1].obrazek);
	
}