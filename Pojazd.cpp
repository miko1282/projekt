#include "Pojazd.h"
#include "Osobowy.h"
#include <iostream>
#include <Windows.h>
using namespace std;

void Pojazd::jazda(int kiloemtry) {
	double potrzebne_paliwo = (kiloemtry * this->spalanie) / 100;
	if (potrzebne_paliwo <= this->ilosc_paliwa) {
		this->przebieg += kiloemtry;
		this->ilosc_paliwa -= potrzebne_paliwo;
	}
	else {
		system("cls");
		cout << "Pojazd " << this->nazwa << " nie ma wystarczajacej ilosci paliwa! Potrzebne "<<potrzebne_paliwo<<" litrow paliwa!"<< endl;
		cout << "Zostaniesz przenesiony do menu glownego za 5 sekund!" << endl;
		Sleep(5000);
	}
}

void Pojazd::zatankuj(int paliwo) {
	this->ilosc_paliwa += paliwo;
}

void Pojazd::wlacz_swiatla() {
	this->swiatla = true;
	cout << "Wlaczono swiatla w pojezdzie "<< this->nazwa << endl;
}

void Pojazd::wylacz_swiatla() {
	this->swiatla = false;
	cout << "Wylaczono swiatla w pojezdzie " << this->nazwa << endl;
}

void Pojazd::klakson() {
	cout << "Bep Bep!" << endl;
}

void Pojazd::informacje() {
	cout << "--------------------------------------------------" << endl;
	cout << "NAZWA: " << this->nazwa << endl;
	cout << "PRZEBIEG: " << this->przebieg << endl;
	cout << "PALIWO (LITRY): " << this->ilosc_paliwa << endl;
	cout << "SWIATLA: ";
	if (this->swiatla)
		cout << " WLACZONE" << endl;
	else
		cout << "WYLACZONE" << endl;
	cout << "WYGRANYCH WYSCIGOW: " << this->wygranych_wyscigow << endl;
	cout << "--------------------------------------------------" << endl;
}

string Pojazd::getNazwa() {
	return this->nazwa;
}

double Pojazd::getIloscPaliwa() {
	return this->ilosc_paliwa;
}

void Pojazd::wygral_wyscig() {
	this->wygranych_wyscigow++;
}

void Pojazd::wyscig(Pojazd przeciwnik) {
	int x = rand() % 100;
	system("cls");
	if (x < 50) {
		cout << "Wyscig pomiedzy " << this->nazwa << " a " << przeciwnik.getNazwa() << " wygrywa " << this->nazwa << endl;
		this->wygral_wyscig();
	}
	else {
		cout << "Wyscig pomiedzy " << this->nazwa << " a " << przeciwnik.getNazwa() << " wygrywa " << przeciwnik.getNazwa() << endl;
		przeciwnik.wygral_wyscig();
	}
	cout << "Za 5 sekund zostaniesz przeniesiony do menu glownego!";
	Sleep(5000);
}