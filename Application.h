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
	std::string annettu_teksti{};		// Teksti, josta etsitään haluttuja teksti pätkää
	std::string etsittava_teksti{};		// Teksti pätkä, jota etsitään annetusta tekstistä
	std::string kayttajan_valinnat{};	// Kertoo käyttäjän valitut lisävalinnat

	std::ifstream tiedosto{};

	std::size_t tekstin_sijainti = -1;	// Numero, joka kertoo monennestako merkistä etsittävä teksti löytyi
	int tekstin_rivi{};					// Numero, joka kertoo monennestako rivistä etsittävä teksti löytyi
	int _laskuri{};						// Numero, joka kertoo montako kertoo etsittävä sana on löytynyt tekstistä

	bool teksti_bool{};					// Kertoo löytyikö etsittävää tekstiä

	// Funktiot
	void kysymykset();															// Kysyy lausetta ja sanaa
	void tekstin_etsiminen_rivista(std::string teksti, std::string annettu_teksti);		// Etsii haluttua teksti pätkää tekstistä
	void loppu_lauseen_maaritys(const std::string& teksti, const std::string& tiedoston_nimi);		// Kertoo montako kertaa etsitty teksti löytyi tiedostosta
	void vastauksen_maaritys();													// Kertoo löytyikö etsittävää tekstiä
	void valintojen_maaritys();												// Etsii haluttua teksti pätkää tiedostosta
	void virheiden_etsinta(std::ifstream&, const std::string&);								// Katsoo voiko tiedostoa avata


public:
	// Muuttujat
	
	bool ValintaBool[7]{};				// Kertoo mitä valintoja käyttäjä on tehnyt
	/*
	-[0] Kun käynnistää vain ohjelman, ilman mitään valintoja
	-[1] Kun käynnistää ohjelman, ja haluaa etsiä tekstiä tiedostosta (Ei lisävalintoja)
	-[2] Lisävalinta "l" -Tekstin rivi tulee näkyviin
	-[3] Lisävalinta "o" -Kertoo kuinka monta kertaa teksti esiintyy tiedostossa
	-[4] Lisävalinta "r" -Kertoo rivit, joissa teksti ei esiinny
	-[5] Lisävalinta "i" -Ei välitä isoista tai pienistä kirjaimista
	-[6] Lisävalinta "default" 
	*/
	
	Application();

	// Funktiot
	void TekstinEtsiminenTiedostosta(const std::string& teksti, const std::string& tiedoston_nimi);		// Etsii tekstiä tiedostosta
	void Alku(const char* valinta[]);								// Määrittää valinnat
	void Inkrementti1();									// Sisältää kaikki inkrementti 1 funktiot
};

