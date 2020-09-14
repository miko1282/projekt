#pragma once
#include <iostream>
using namespace std;

class Pojazd
{
protected:
	string nazwa;
	double spalanie;
	double przebieg;
	double ilosc_paliwa;
	bool swiatla;
	int wygranych_wyscigow;

public:
	void jazda(int kilometry);
	void zatankuj(int paliwo);
	void wlacz_swiatla();
	void wylacz_swiatla();
	void klakson();
	void informacje();
	string getNazwa();
	double getIloscPaliwa();
	void wyscig(Pojazd przeciwnik);
	void wygral_wyscig();
};

