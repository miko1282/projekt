#pragma once
#include "Pojazd.h"
#include <iostream>
class Dostawczy : public Pojazd
{
public:
	Dostawczy(string nazwa, double ilosc_paliwa, double spalanie);
};

