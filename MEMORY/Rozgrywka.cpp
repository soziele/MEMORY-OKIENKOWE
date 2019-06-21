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
	
	while (Okno_gry->isOpen())
	{
		sf::Vector2i pozycja_myszy_klik = sf::Mouse::getPosition(*Okno_gry);
		sf::Texture cos;
		cos.loadFromFile("kapczyk.bmp");
		sf::Sprite fajnecos;
		fajnecos.setTexture(cos);
		fajnecos.setPosition(100, 100);



		
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
				Okno_gry->draw(fajnecos);
				
			}

			
		}
		Okno_gry->display();
	}
}