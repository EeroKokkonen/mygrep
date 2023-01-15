#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>


class Application
{
private:
	// Muuttujat
	std::string annettu_teksti{};		// Teksti, josta etsit��n haluttuja teksti p�tk��
	std::string etsittava_teksti{};		// Teksti p�tk�, jota etsit��n annetusta tekstist�
	std::string kayttajan_valinnat{};	// Kertoo k�ytt�j�n valitut lis�valinnat

	std::ifstream tiedosto{};

	std::size_t tekstin_sijainti = -1;	// Numero, joka kertoo monennestako merkist� etsitt�v� teksti l�ytyi
	int tekstin_rivi{};					// Numero, joka kertoo monennestako rivist� etsitt�v� teksti l�ytyi
	int _laskuri{};						// Numero, joka kertoo montako kertoo etsitt�v� sana on l�ytynyt tekstist�

	bool teksti_bool{};					// Kertoo l�ytyik� etsitt�v�� teksti�

	// Funktiot
	void kysymykset();															// Kysyy lausetta ja sanaa
	void tekstin_etsiminen_rivista(std::string teksti, std::string annettu_teksti);		// Etsii haluttua teksti p�tk�� tekstist�
	void loppu_lauseen_maaritys(const std::string& teksti, const std::string& tiedoston_nimi);		// Kertoo montako kertaa etsitty teksti l�ytyi tiedostosta
	void vastauksen_maaritys();													// Kertoo l�ytyik� etsitt�v�� teksti�
	void valintojen_maaritys();												// Etsii haluttua teksti p�tk�� tiedostosta
	void virheiden_etsinta(std::ifstream&, const std::string&);								// Katsoo voiko tiedostoa avata


public:
	// Muuttujat
	
	bool ValintaBool[7]{};				// Kertoo mit� valintoja k�ytt�j� on tehnyt
	/*
	-[0] Kun k�ynnist�� vain ohjelman, ilman mit��n valintoja
	-[1] Kun k�ynnist�� ohjelman, ja haluaa etsi� teksti� tiedostosta (Ei lis�valintoja)
	-[2] Lis�valinta "l" -Tekstin rivi tulee n�kyviin
	-[3] Lis�valinta "o" -Kertoo kuinka monta kertaa teksti esiintyy tiedostossa
	-[4] Lis�valinta "r" -Kertoo rivit, joissa teksti ei esiinny
	-[5] Lis�valinta "i" -Ei v�lit� isoista tai pienist� kirjaimista
	-[6] Lis�valinta "default" 
	*/
	
	Application();

	// Funktiot
	void TekstinEtsiminenTiedostosta(const std::string& teksti, const std::string& tiedoston_nimi);		// Etsii teksti� tiedostosta
	void Alku(const char* valinta[]);								// M��ritt�� valinnat
	void Inkrementti1();									// Sis�lt�� kaikki inkrementti 1 funktiot
};

