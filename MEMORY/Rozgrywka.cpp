#include"Rozgrywka.h"
#include<fstream>

ROZGRYWKA::ROZGRYWKA()
{
	
}


void ROZGRYWKA::aktualizuj(sf::RenderWindow* Okno_gry)
{
	
	KARTA karta1(1);
	KARTA karta2(1);
	KARTA karta3(2);
	KARTA karta4(2);
	KARTA karta5(3);
	KARTA karta6(3);
	KARTA karta7(4);
	KARTA karta8(4);
	KARTA karta9(5);
	KARTA karta10(5);
	KARTA karta11(6);
	KARTA karta12(6);

	KARTA zestaw[12] = { karta1,karta2,karta3,karta4,karta5,karta6,karta7,karta8,karta9,karta10,karta11,karta12 };

	PLANSZA Plansza(zestaw);

	Plansza.wczytaj_pliki(zestaw);
	
	
	while (Okno_gry->isOpen())
	{
		
		Plansza.zaladuj_sprites(zestaw);
		Plansza.mieszaj(zestaw);
		Plansza.rysuj_sprites(Okno_gry, zestaw);
		

		sf::Event zdarzenie;

		while (Okno_gry->pollEvent(zdarzenie))
		{
			if (zdarzenie.type == sf::Event::Closed)
			{
				Okno_gry->close();
			}
			/*
			if (zdarzenie.type == sf::Event::MouseMoved)
			{
				sf::Vector2i pozycja_myszy_ruch = sf::Mouse::getPosition(*Okno_gry);
			}
			*/
			if (zdarzenie.type == sf::Event::MouseButtonPressed && zdarzenie.mouseButton.button == sf::Mouse::Left)
			{
				sf::Vector2i pozycja_myszy_klik = sf::Mouse::getPosition(*Okno_gry);

			}

			sf::Vector2i pozycja_myszy = sf::Mouse::getPosition(*Okno_gry);

			int i = 0, j = 0, X, Y;
			X = pozycja_myszy.x;
			Y = pozycja_myszy.y;

			while (i < 6 && j < 2)
			{
				if (X > (30 + (i * 160)) && X < (169 + (i * 160)))
				{
					if (Y > (100 + (j * 240)) && Y < (319 + (j * 240)))
					{
						//Instrukcja Podœwietlania kart
						
					}
				}
				if (i == 5)
				{
					j++;
					i = -1;
				}
				i++;
			}
		}
	}
}