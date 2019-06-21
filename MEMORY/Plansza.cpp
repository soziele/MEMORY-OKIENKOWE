#include"Plansza.h"

KARTA PLANSZA::wczytaj_pliki()
{
	
	for (int i = 0; i < 12; i++)
	{
		zestaw_kart[i].obrazek_zakryta->loadFromFile("kapczyk.jpg");
	}
	
	for (int i=0;i<2; i++)
	{
		zestaw_kart[i].obrazek_odkryta->loadFromFile("kapczyk.jpg");
	}
	for (int i = 2; i < 4; i++)
	{
		zestaw_kart[i].obrazek_odkryta->loadFromFile("kapczyk.jpg");
	}
	for (int i = 4; i < 6; i++)
	{
		zestaw_kart[i].obrazek_odkryta->loadFromFile("kapczyk.jpg");
	}
	for (int i = 6; i < 8; i++)
	{
		zestaw_kart[i].obrazek_odkryta->loadFromFile("kapczyk.jpg");
	}
	for (int i = 8; i < 10; i++)
	{
		zestaw_kart[i].obrazek_odkryta->loadFromFile("kapczyk.jpg");
	}
	for (int i = 10; i < 12; i++)
	{
		zestaw_kart[i].obrazek_odkryta->loadFromFile("kapczyk.jpg");
	}
	return *zestaw_kart;
}

KARTA PLANSZA::zaladuj_sprites()
{
	for (int i = 0; i < 12; i++)
	{
		if (zestaw_kart[i].stan_karty == zakryta)
		{
			zestaw_kart[i].obrazek.setTexture(obrazek_zakryta);
		}
		if (zestaw_kart[i].stan_karty == odkryta)
		{
			zestaw_kart[i].obrazek.setTexture(*obrazek_odkryta);
		}

	}
	return *zestaw_kart;
}

void PLANSZA::rysuj_sprites(sf::RenderWindow* okno_gry, KARTA zestaw_kart[12])
{
	
	
	
}