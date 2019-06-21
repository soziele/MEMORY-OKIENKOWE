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
			if (zdarzenie.type == sf::Event::MouseMoved)
			{
				sf::Vector2i pozycja_myszy_ruch = sf::Mouse::getPosition(*Okno_gry);
			}
			if (zdarzenie.type == sf::Event::MouseButtonPressed && zdarzenie.mouseButton.button == sf::Mouse::Left)
			{
				sf::Vector2i pozycja_myszy_klik = sf::Mouse::getPosition(*Okno_gry);

			}
		}
	}
}