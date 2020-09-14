#pragma once
#include "Pojazd.h"
#include <iostream>
using namespace std;

class Osobowy : public Pojazd
{
public:
	Osobowy(string nazwa, double ilosc_paliwa, double spalanie);
};

