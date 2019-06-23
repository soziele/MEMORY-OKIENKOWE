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
		Okno_gry->clear();
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


		sf::Event zdarzenie;

		while (Okno_gry->pollEvent(zdarzenie))
		{

			if (zdarzenie.type == sf::Event::Closed)
			{
				Okno_gry->close();
			}


			if (zdarzenie.type == sf::Event::MouseButtonPressed && zdarzenie.mouseButton.button == sf::Mouse::Left)
			{

				sf::Vector2i pozycja_myszy_klik = sf::Mouse::getPosition(*Okno_gry);
				for (int t = 0; t < 12; t++)
				{
					if (Plansza.czy_to_ta_karta(zestaw[t], pozycja_myszy_klik) == true)
					{
						zestaw[t].setStan(zakryta);
						Plansza.zaladuj_sprites(zestaw[t]);

					}


				}



			}

			sf::Vector2i pozycja_myszy = sf::Mouse::getPosition(*Okno_gry);
			
			for (int t = 0; t < 12; t++)
			{

				if (Plansza.czy_to_ta_karta(zestaw[t], pozycja_myszy))
				{
					Plansza.podswietl(zestaw[t], 1.1);
					
					break;
				}
				else
				{
					Plansza.podswietl(zestaw[t], 1);
					
				}


			}
			
			Okno_gry->display();
		}
		
		
		}
	

	}
	
