#include"Zasoby.h"

ZASOBY::ZASOBY()
{

}

void ZASOBY::wczytaj_zasoby(sf::Texture zakryta, sf::Texture odkryte_z_pliku[6])
{
	zakryta.loadFromFile("einz.jpg");
	for (int i = 0; i < 6; i++)
	{
		odkryte_z_pliku[i].loadFromFile("zwei.jpg");
	}

}