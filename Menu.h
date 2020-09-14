#pragma once
#include <vector>
#include "Pojazd.h"
using namespace std;
class Menu
{
private:
	vector<Pojazd> pojazdy;
public:
	Menu();
	void wyswietl_menu_glowne();
	void wyswietl_pojazdy();
	void usun_pojazd();
	void dodaj_pojazd();
	void menuPodroz(int x);
	void menuWyscig(int x);
	void mozliwosci();
	void menuTankowanie(int x);

};

