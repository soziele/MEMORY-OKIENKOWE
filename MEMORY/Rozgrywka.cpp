#include"Rozgrywka.h"
#include<fstream>
#include<stdlib.h>
#include<iostream>
using namespace sf;

ROZGRYWKA::ROZGRYWKA()
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
	/*
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 2; j++) {
			zestaw[i * 2 + j] = KARTA(i);
		}
	}
	*/
	zestaw[0] = karta1;
	zestaw[1] = karta2;
	zestaw[2] = karta3;
	zestaw[3] = karta4;
	zestaw[4] = karta5;
	zestaw[5] = karta6;
	zestaw[6] = karta7;
	zestaw[7] = karta8;
	zestaw[8] = karta9;
	zestaw[9] = karta10;
	zestaw[10] = karta11;
	zestaw[11] = karta12;
	//zestaw = { karta1,karta2,karta3,karta4,karta5,karta6,karta7,karta8,karta9,karta10,karta11,karta12 };

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
		Okno_menu->clear();
		Okno_menu->draw(start);
		Okno_menu->draw(co_to);
		Okno_menu->draw(wyjscie);
		

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
							sf::Text tekst;
							sf::Font font;
							font.loadFromFile("HandVetica.ttf");
							tekst.setString("Niniejsza aplikacja to gra polegajaca na \nodnajdywaniu par w zestawie zakrytych kart. \nKazda proba polaczenia kart w pare to jedna tura gracza. \nGra konczy sie w momencie, gdy wszystkie karty \nznikna z planszy. Powodzenia!");
							tekst.setFont(font);
							Okno_info.draw(tekst);
							Event event;
							while (Okno_info.pollEvent(zdarzenie))
								if (zdarzenie.type == sf::Event::Closed)
								{
									Okno_info.close();
								}
							Okno_info.display();
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
		sf::Vector2i pozycja_myszy_ruch = sf::Mouse::getPosition(*Okno_menu);
		if (pozycja_myszy_ruch.x > 685 && pozycja_myszy_ruch.x < 980 && pozycja_myszy_ruch.y > 300 && pozycja_myszy_ruch.y < 380)
		{
			start.setScale(1.05, 1.05);
		}
		else start.setScale(1, 1);

		if (pozycja_myszy_ruch.x > 650 && pozycja_myszy_ruch.x < 980 && pozycja_myszy_ruch.y > 400 && pozycja_myszy_ruch.y < 480)
		{
			co_to.setScale(1.05, 1.05);	
		}
		else co_to.setScale(1, 1);

		if (pozycja_myszy_ruch.x > 614 && pozycja_myszy_ruch.x < 980 && pozycja_myszy_ruch.y > 500 && pozycja_myszy_ruch.y < 580)
		{
			wyjscie.setScale(1.05, 1.05);
		}
		else wyjscie.setScale(1, 1);
		Okno_menu->draw(start);
		Okno_menu->draw(co_to);
		Okno_menu->draw(wyjscie);
		Okno_menu->display();
	}
}





void ROZGRYWKA::aktualizuj(sf::RenderWindow* Okno_gry)
{


	PLANSZA Plansza;
	


	Plansza.mieszaj(zestaw);
	
	
	int liczba_tur;


	while (Okno_gry->isOpen())
	{
		float X = 30, Y = 100;
		for (int i = 0; i < 6; i++)
		{
			Plansza.wczytaj_pliki(&zestaw[i]);
			Plansza.zaladuj_sprites(&zestaw[i]);
			Plansza.pozycja_sprite(&zestaw[i], X, Y);
			X += 160;
		}
		Y += 240;
		X -= 960;
		for (int i = 6; i < 12; i++)
		{
			Plansza.wczytaj_pliki(&zestaw[i]);
			Plansza.zaladuj_sprites(&zestaw[i]);
			Plansza.pozycja_sprite(&zestaw[i], X, Y);

			X += 160;
		}
		sf:Time time = sf::seconds(1);

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
					if (Plansza.czy_to_ta_karta(&zestaw[t], pozycja_myszy_klik))
					{
						
						if(zestaw[t].getStan() == zakryta)
						zestaw[t].setStan(odkryta);
						Plansza.zaladuj_sprites(&zestaw[t]);
						
						for (int u = 0; u < 12; u++)
						{
							if (u == t)
							{
								u++;
							}
							
							if (zestaw[u].getStan() == odkryta)
							{
								//liczba_tur++;
								if (zestaw[u].getIndex() == zestaw[t].getIndex())
								{
									zestaw[u].setStan(usunieta);
									zestaw[t].setStan(usunieta);
								}
								else
								{
									rysuj_wszystko(Okno_gry);
									sleep(time);
									zestaw[u].setStan(zakryta);
									zestaw[t].setStan(zakryta);
									
								}
							}
							
						}
					}
					/*
					for (int t = 0; t < 12; t++)
					{
						if (dwa != 2)
						{
							if (zestaw[t].getStan() == odkryta)
							{
								dwa++;

								if (k1 == 0)
								{
									k1 = t;
								}
								else
								{
									k2 = t;
								}
							}
						}
						else if (zestaw[k1].getIndex() == zestaw[k2].getIndex())
						{
							zestaw[k1].setStan(usunieta);
							zestaw[k2].setStan(usunieta);

							dwa = 0;
							k1 = 0;
							k2 = 0;

						}
						else
						{
							Plansza.podswietl(&zestaw[k2], 1);
							rysuj_wszystko(Okno_gry);
							sleep(time);
							zestaw[k1].setStan(zakryta);
							zestaw[k2].setStan(zakryta);

							dwa = 0;
							k1 = 0;
							k2 = 0;
							break;

						}

					}
					*/
					
				}

			}

			sf::Vector2i pozycja_myszy = sf::Mouse::getPosition(*Okno_gry);
			

			for (int t = 0; t < 12; t++)
			{

				if (Plansza.czy_to_ta_karta(&zestaw[t], pozycja_myszy))
				{
					Plansza.podswietl(&zestaw[t], 1.025);
				}
				else
				{
					Plansza.podswietl(&zestaw[t], 1);
				}
			}

			


			if (zestaw[0].getStan() == usunieta && zestaw[1].getStan() == usunieta && zestaw[2].getStan() == usunieta && zestaw[3].getStan() == usunieta && zestaw[4].getStan() == usunieta && zestaw[5].getStan() == usunieta && zestaw[6].getStan() == usunieta && zestaw[7].getStan() == usunieta && zestaw[8].getStan() == usunieta && zestaw[9].getStan() == usunieta && zestaw[10].getStan() == usunieta && zestaw[11].getStan() == usunieta)
			{
				Okno_gry->close();
			}


		}
		rysuj_wszystko(Okno_gry);
		}

	}

	void ROZGRYWKA::rysuj_wszystko(RenderWindow*Okno_gry)
	{
		Okno_gry->clear();
		for (int i = 0; i < 12; i++)
		{
			Okno_gry->draw(zestaw[i].getSprite());
		}
		Okno_gry->display();
	}
	
