#include "Menu.h"
#include <vector>
#include "Osobowy.h"
#include "Dostawczy.h"
#include "Pojazd.h"
#include <conio.h>
#include <string>
using namespace std;

void Menu::wyswietl_menu_glowne() {
	system("cls");
	cout << "--------------------------------" << endl;
	cout << "1. Dodaj nowy pojazd" << endl;
	cout << "2. Usun pojazd" << endl;
	cout << "3. Wyswietl liste pojazdow" << endl;
	cout << "4. Akcje" << endl;
	cout << "--------------------------------" << endl;
	cout << "Wybor: ";
	int x;
	cin >> x;
	if (x == 1) {
		this->dodaj_pojazd();
	}
	else if (x == 2) {
		this->usun_pojazd();
	}
	else if (x == 3) {
		this->wyswietl_pojazdy();
	}
	else if (x == 4) {
		this->mozliwosci();
	}
	else {
		this->wyswietl_menu_glowne();
	}
}

void Menu::mozliwosci() {
	system("cls");
	if (pojazdy.size() == 0) {
		cout << "Brak pojazdow w bazie!" << endl;
		cout << "Kliknij spacje aby powrocic do menu glownego!";
		char c = _getch();
		while (c != char(32)) {
			c = _getch();
		}
		this->wyswietl_menu_glowne();
	}
	else {
		for (int i = 0; i < pojazdy.size(); i++) {
			cout << i + 1 << ". " << pojazdy[i].getNazwa() << endl;
		}
		cout << "-----------------------------------" << endl;
		cout << "Ktory pojazd ma wykonac akcje: ";
		int x;
		cin >> x;
		int numer = x - 1;
		system("cls");
		if (numer > pojazdy.size()) {
			system("cls");
			cout << "Wybrano nieprawidlowy numer!" << endl;
			cout << "Kliknij spacje aby powrocic do menu glownego!";
			char c = _getch();
			while (c != char(32)) {
				c = _getch();
			}
			this->wyswietl_menu_glowne();
		}
		else {
			system("cls");
			cout << "1. Podroz" << endl;
			cout << "2. Wyscig" << endl;
			cout << "3. Zatankuj" << endl;
			cout << "------------------------------" << endl;
			cout << "Jaka akcja ma zostac wykonana pojazdem " << pojazdy[numer].getNazwa() << " :";
			int aa;
			cin >> aa;
			if (aa == 1) {
				this->menuPodroz(numer);
			}
			else if (aa == 2) {
				this->menuWyscig(numer);
			}
			else if (aa == 3) {
				this->menuTankowanie(numer);
			}
			else {
				cout << "Wybrano nieprawidlowy numer!" << endl;
				cout << "Kliknij spacje aby powrocic do menu glownego!";
				char c = _getch();
				while (c != char(32)) {
					c = _getch();
				}
				this->wyswietl_menu_glowne();
			}


		}
	}
}

void Menu::menuTankowanie(int x) {
	system("cls");
	cout << "-------------------------------" << endl;
	cout << "TANKOWANIE POJAZDU " << pojazdy[x].getNazwa() << endl;
	cout << "Aktualna ilosc paliwa: " << pojazdy[x].getIloscPaliwa() << " litrow" << endl;
	cout << "-------------------------------" << endl;
	cout << "Podaj ilosc paliwa (litry): ";
	int ile;
	cin >> ile;
	pojazdy[x].zatankuj(ile);
	this->wyswietl_menu_glowne();
}


void Menu::menuPodroz(int x) {
	system("cls");
	cout << "-------------------------------" << endl;
	cout << "PODROZ POJAZDEM " << pojazdy[x].getNazwa() << endl;
	cout << "Aktualna ilosc paliwa: " << pojazdy[x].getIloscPaliwa() << " litrow" << endl;
	cout << "-------------------------------" << endl;
	cout << "Podaj ilosc kilometrow: ";
	int km;
	cin >> km;
	pojazdy[x].jazda(km);
	this->wyswietl_menu_glowne();
}

void Menu::menuWyscig(int x) {
	if (pojazdy.size() == 0) {
		system("cls");
		cout << "Brak pojazdow w bazie!" << endl;
		cout << "Kliknij spacje aby powrocic do menu glownego!";
		char c = _getch();
		while (c != char(32)) {
			c = _getch();
		}
		this->wyswietl_menu_glowne();
	}
	else {
		system("cls");
		for (int i = 0; i < pojazdy.size(); i++) {
			cout << i + 1 << ". " << pojazdy[i].getNazwa() << endl;
		}
		cout << "-----------------------------------" << endl;
		cout << "Wybierz przeciwnika w wyscigu dla " << pojazdy[x].getNazwa() <<" :";
		int wybor;
		cin >> wybor;
		int numer = wybor - 1;
		if (numer > pojazdy.size()) {
			system("cls");
			cout << "Wybrano nieprawidlowy numer!" << endl;
			cout << "Kliknij spacje aby powrocic do menu glownego!";
			char c = _getch();
			while (c != char(32)) {
				c = _getch();
			}
			this->wyswietl_menu_glowne();
		}
		else {
			if (pojazdy[x].getNazwa() == pojazdy[numer].getNazwa()) {
				system("cls");
				cout << "Pojazd nie moze sie scigac sam ze soba!" << endl;
				cout << "Kliknij spacje aby powrocic do menu glownego!";
				char c = _getch();
				while (c != char(32)) {
					c = _getch();
				}
				this->wyswietl_menu_glowne();
			}
			else {
				pojazdy[x].wyscig(pojazdy[numer]);
				this->wyswietl_menu_glowne();
			}
		}


	}
}

void Menu::dodaj_pojazd() {
	system("cls");
	cout << "1. Osobowy" << endl;
	cout << "2. Dostawczy" << endl;
	cout << "Jakiego typu pojazd chcesz dodac: ";
	int x;
	cin >> x;
	string nazwaNowy;
	double spalanieNowy;
	double iloscPaliwaNowy;
	cout << "Nazwa nowego pojazdu: ";
	cin.ignore();
	getline(cin, nazwaNowy);
	cout << "Spalanie nowego pojazdu: ";
	cin >> spalanieNowy;
	cout << "Ilosc paliwa nowego pojazdu: ";
	cin >> iloscPaliwaNowy;
	if (x == 1) {
		Osobowy nowy(nazwaNowy, iloscPaliwaNowy, spalanieNowy);
		this->pojazdy.push_back(nowy);
		this->wyswietl_menu_glowne();
	}
	else if (x == 2) {
		Dostawczy nowy(nazwaNowy, iloscPaliwaNowy, spalanieNowy);
		this->pojazdy.push_back(nowy);
		this->wyswietl_menu_glowne();
	}
}

void Menu::usun_pojazd() {
	system("cls");
	if (pojazdy.size() == 0) {
		cout << "Brak pojazdow w bazie!" << endl;
		cout << "Kliknij spacje aby powrocic do menu glownego!";
		char c = _getch();
		while (c != char(32)) {
			c = _getch();
		}
		this->wyswietl_menu_glowne();
	}
	else {
		for (int i = 0; i < pojazdy.size(); i++) {
			cout << i + 1 << ". " << pojazdy[i].getNazwa() << endl;
		}
		cout << "-----------------------------------" << endl;
		cout << "Ktory pojazd chcesz usunac: ";
		int x;
		cin >> x;
		system("cls");
		int numer = x - 1;
		if (numer > pojazdy.size()) {
			cout << "Wybrano nieprawidlowy numer!" << endl;
			cout << "Kliknij spacje aby powrocic do menu glownego!";
			char c = _getch();
			while (c != char(32)) {
				c = _getch();
			}
			this->wyswietl_menu_glowne();
		}
		else {
			pojazdy.erase(pojazdy.begin() + numer);
			this->wyswietl_menu_glowne();
		}
	}
}

void Menu::wyswietl_pojazdy() {
	system("cls");
	if (pojazdy.size() == 0) {
		cout << "Brak pojazdow w bazie!" << endl;
		cout << "Kliknij spacje aby powrocic do menu glownego!";
		char c = _getch();
		while (c != char(32)) {
			c = _getch();
		}
		this->wyswietl_menu_glowne();
	}
	else {
		for (int i = 0; i < pojazdy.size(); i++) {
			cout << i + 1 << ". " << pojazdy[i].getNazwa() << endl;
		}
		cout << "-----------------------------------" << endl;
		cout << "Informacje o jakim pojezdzie chcesz wyswietlic: ";
		int x;
		cin >> x;
		system("cls");
		int numer = x - 1;
		if (numer > pojazdy.size()) {
			cout << "Wybrano nieprawidlowy numer!" << endl;
			cout << "Kliknij spacje aby powrocic do menu glownego!";
			char c = _getch();
			while (c != char(32)) {
				c = _getch();
			}
			this->wyswietl_menu_glowne();
		}
		else {
			system("cls");
			pojazdy[numer].informacje();
			cout << "Kliknij spacje aby powrocic do menu glownego!";
			char c = _getch();
			while (c != char(32)) {
				c = _getch();
			}
			this->wyswietl_menu_glowne();
		}
	}
}

Menu::Menu() {
	this->wyswietl_menu_glowne();
}
