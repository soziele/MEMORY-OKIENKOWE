#include<SFML/Graphics.hpp>
#include"Karta.h"




void KARTA::wczytaj_tekstury(sf::Texture obrazek_zakryta, sf::Texture obrazek_odkryta)
{
	obrazek_zakryta.loadFromFile("einz.jpg");
	obrazek_odkryta.loadFromFile("zwei.jpg");
}

void KARTA::wyswietlaj_teksture(sf::Texture obrazek_zakryta, sf::Texture obrazek_odkryta, sf::Sprite obrazek, stan stan_karty)
{
	if (stan_karty == 1) obrazek.setTexture(obrazek_zakryta);
	else if (stan_karty == 2) obrazek.setTexture(obrazek_odkryta);

}

