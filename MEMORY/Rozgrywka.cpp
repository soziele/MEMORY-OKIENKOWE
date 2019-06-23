#include"Rozgrywka.h"
#include<fstream>
#include<stdlib.h>
using namespace sf;

ROZGRYWKA::ROZGRYWKA()
{
	
}

void ROZGRYWKA::menu(sf::RenderWindow* Okno_menu)
{
	sf::Texture Tex_start;
	sf::Texture Tex_co_to;
	sf::Texture Tex_wyjscie;

	sf::Sprite start;
	sf::Sprite co_to;
	sf::Sprite wyjscie;

	Tex_start.loadFromFile("start.png");
	Tex_co_to.loadFromFile("co_to.png");
	Tex_wyjscie.loadFromFile("wyjscie.png");

	start.setTexture(Tex_start);
	co_to.setTexture(Tex_co_to);
	wyjscie.setTexture(Tex_wyjscie);
	start.setPosition(685, 300);
	co_to.setPosition(650, 400);
	wyjscie.setPosition(614, 500);
	while (Okno_menu->isOpen())
	{
		Okno_menu->draw(start);
		Okno_menu->draw(co_to);
		Okno_menu->draw(wyjscie);
		Okno_menu->display();

		sf::Event zdarzenie;
		while (Okno_menu->pollEvent(zdarzenie))
		{

			if (zdarzenie.type == sf::Event::MouseButtonPressed && zdarzenie.mouseButton.button == sf::Mouse::Left)
			{
				sf::Vector2i pozycja_myszy_klik = sf::Mouse::getPosition(*Okno_menu);
				if (pozycja_myszy_klik.x > 685 && pozycja_myszy_klik.x < 980)
				{
					if (pozycja_myszy_klik.y > 300 && pozycja_myszy_klik.y < 380)
					{
						Okno_menu->close();
					}
				}
				if (pozycja_myszy_klik.x > 650 && pozycja_myszy_klik.x < 980)
				{
					if (pozycja_myszy_klik.y > 400 && pozycja_myszy_klik.y < 480)
					{
						sf::RenderWindow Okno_info(sf::VideoMode(800, 400, 32), "MEMORY", sf::Style::Close);
						while (Okno_info.isOpen())
						{

						}
					}
				}
				if (pozycja_myszy_klik.x > 614 && pozycja_myszy_klik.x < 980)
				{
					if (pozycja_myszy_klik.y > 500 && pozycja_myszy_klik.y < 580)
					{
						exit(EXIT_FAILURE);
					}
				}
			}
		}
	}
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

	PLANSZA Plansza;

	Okno_gry->clear();
	/*
	sf::Texture cos;
	cos.loadFromFile("zakryta.png");
	sf::Sprite nwm;
	nwm.setTexture(cos);
	Okno_gry->draw(nwm);
	
	Plansza.zaladuj_sprites(karta1);
	Plansza.mieszaj(zestaw);
	Plansza.rysuj_sprites(Okno_gry, karta1);
	Okno_gry->display();
	*/

	Plansza.mieszaj(zestaw);
	
	
	while (Okno_gry->isOpen())
	{

		float X = 30, Y = 100;
		for (int i = 0; i < 6; i++)
		{
			Plansza.wczytaj_pliki(zestaw[i]);
			Plansza.zaladuj_sprites(zestaw[i]);
			Plansza.pozycja_sprite(zestaw[i], X, Y);
			Plansza.rysuj_sprites(Okno_gry, zestaw[i]);
			X += 160;
		}
		Y += 240;
		X -= 960;
		for (int i = 6; i < 12; i++)
		{
			Plansza.wczytaj_pliki(zestaw[i]);
			Plansza.zaladuj_sprites(zestaw[i]);
			Plansza.pozycja_sprite(zestaw[i], X, Y);
			Plansza.rysuj_sprites(Okno_gry, zestaw[i]);
			
			X += 160;
		}
		
		Okno_gry->display();
		
		

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
				for (int t = 0; t <12 ; t++)
				{
					
					zestaw[t].setStan(zakryta);
					Plansza.zaladuj_sprites(zestaw[t]);
					
					Plansza.rysuj_sprites(Okno_gry, zestaw[t]);
					Okno_gry->clear();
					Okno_gry->display();
					
				}

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
						for (int a = 0; a < 12; a++)
						{
							int x_owa1 = 30 + (i * 160);
							int x_owa2 = 169 + (i * 160);
							int y_owa1 = 100 + (j * 240);
							int y_owa2 = 319 + (j * 240);
						
							Plansza.podswietl(zestaw[a], x_owa1, x_owa2, y_owa1, y_owa2);

							Plansza.rysuj_sprites(Okno_gry, zestaw[a]);
						
						}

						
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