#include"Plansza.h"
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include<fstream>

using namespace sf;

void PLANSZA::wczytaj_pliki(KARTA *karta) 
{
	
	karta->obrazek_zakryta.loadFromFile("zakryta.png");
	
	
	if(karta->indeks==1)
	{
		karta->obrazek_odkryta.loadFromFile("01.png");
	}
	else if(karta->indeks==2)
	{
		karta->obrazek_odkryta.loadFromFile("02.png");
	}
	else if(karta->indeks==3)
	{
		karta->obrazek_odkryta.loadFromFile("03.png");
	}
	else if(karta->indeks==4)
	{
		karta->obrazek_odkryta.loadFromFile("04.png");
	}
	else if(karta->indeks==5)
	{
	karta->obrazek_odkryta.loadFromFile("05.png");
	}
	else if(karta->indeks==6)
	{
		karta->obrazek_odkryta.loadFromFile("06.png");
	}
}

void PLANSZA::zaladuj_sprites(KARTA *karta)
{
		if (karta->stan_karty == zakryta)
		{
			karta->obrazek.setTexture(karta->obrazek_zakryta);
		}
		else if (karta->stan_karty ==odkryta)
		{
			karta->obrazek.setTexture(karta->obrazek_odkryta);
		}
}


void PLANSZA::mieszaj(KARTA zestaw_kart[12])
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
}


void PLANSZA::rysuj_sprites(sf::RenderWindow* okno_gry, KARTA* karta)
{
	okno_gry->draw(karta->obrazek);
	
}


void PLANSZA::podswietl(KARTA* karta,float i)
{
	
			karta->obrazek.setScale(i, i);
		
}



/*
KARTA PLANSZA::podswietl(KARTA karta, int x1, int x2, int y1, int y2)
{
	if (karta->obrazek.getPosition().x > x1 && karta->obrazek.getPosition().x < x2)
	{
		if (karta->obrazek.getPosition().y > y1 && karta->obrazek.getPosition().y < y2)
		{
			karta->obrazek.setScale(2, 2);
		}

	}
	return karta;
}
*/



void PLANSZA::pozycja_sprite(KARTA* karta, float x, float y)
{
	karta->obrazek.setPosition(x, y);
}

bool PLANSZA::czy_to_ta_karta(KARTA* karta, Vector2i myszka)
{
	if (karta->obrazek.getGlobalBounds().contains(myszka.x, myszka.y)) return true;
	return false;
}