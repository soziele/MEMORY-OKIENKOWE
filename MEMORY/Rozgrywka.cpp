#include"Rozgrywka.h"

ROZGRYWKA::ROZGRYWKA()
{

}


void ROZGRYWKA::aktualizuj(sf::RenderWindow* Okno_gry)
{
	while (Okno_gry->isOpen())
	{

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