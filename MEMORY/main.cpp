#include<SFML/Graphics.hpp>
#include"Rozgrywka.h"


int main()
{
	sf::RenderWindow Okno_gry(sf::VideoMode(800, 600, 32), "MEMORY", sf::Style::Close);
	Okno_gry.setVerticalSyncEnabled(true);
	ROZGRYWKA Gra;
	while (Okno_gry.isOpen())
	{
		Gra.aktualizuj(&Okno_gry);
		Okno_gry.display();
	}


	return 0;
}
