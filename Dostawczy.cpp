#include "Dostawczy.h"
#include "Osobowy.h"

#include <iostream>
using namespace std;

Dostawczy::Dostawczy(string nazwa, double ilosc_paliwa, double spalanie) {
	this->nazwa = nazwa;
	this->ilosc_paliwa = ilosc_paliwa;
	this->spalanie = spalanie;
	this->swiatla = false;
	this->przebieg = 0;
	this->wygranych_wyscigow = 0;
}

