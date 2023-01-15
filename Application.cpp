#include "Application.h"

void Application::valintojen_maaritys()
{
	if (kayttajan_valinnat[0] == '-' && kayttajan_valinnat[1] == 'o')
	{
		ValintaBool[6] = true;
		for (int i = 2; i < kayttajan_valinnat.size(); i++)
		{
			if (kayttajan_valinnat[i] == 'l')
			{
				ValintaBool[2] = true;
			}
			else if (kayttajan_valinnat[i] == 'o')
			{
				ValintaBool[3] = true;
				ValintaBool[1] = true;
			}
			else if (kayttajan_valinnat[i] == 'r')
			{
				ValintaBool[4] = true;
			}
			else if (kayttajan_valinnat[i] == 'i')
				ValintaBool[5] = true;
			else
				std::cout << "Unknown option \"" << kayttajan_valinnat[i] << "\"\n";
		}
	}
	else if (kayttajan_valinnat == "")
	{
		ValintaBool[0] = true;
	}
	else if (kayttajan_valinnat[0] != '-' || kayttajan_valinnat[1] != 'o')
	{
		ValintaBool[1] = true;
	}
}

void Application::kysymykset()
{
	std::cout << "Give a string from which to search for: ";
	std::getline (std::cin, annettu_teksti);

	std::cout << "Give search string: ";
	std::getline(std::cin, etsittava_teksti);
}

void Application::tekstin_etsiminen_rivista(std::string teksti, std::string rivi)
{
	do
	{
		if (ValintaBool[5])
		{
			// Muuntaa kaikki kirjamet pieniksi kirjaimiksi ("i" valinta)
			std::for_each(teksti.begin(), teksti.end(), [](char& c) {
				c = ::tolower(c);
				});
			std::for_each(rivi.begin(), rivi.end(), [](char& c) {
				c = ::tolower(c);
				});
		}

		tekstin_sijainti = rivi.find(teksti, tekstin_sijainti + 1);

		if (tekstin_sijainti != -1)
		{
			_laskuri += 1;
			teksti_bool = true;
			break;
		}
	} while (tekstin_sijainti != -1);

	vastauksen_maaritys();
	teksti_bool = false;
}

void Application::vastauksen_maaritys()
{
	if (!ValintaBool[4] && teksti_bool)
	{
		if (ValintaBool[2])
			std::cout << tekstin_rivi << ":";
		if (ValintaBool[0])
			std::cout << "\"" << etsittava_teksti << "\" found in \"" << annettu_teksti << "\" in postion " << tekstin_sijainti << std::endl;
		else
			std::cout << annettu_teksti << " " << std::endl;
	}
	else if (ValintaBool[4] && !teksti_bool)
	{
		if (ValintaBool[2])
			std::cout << tekstin_rivi << ":";

		std::cout << annettu_teksti << " " << std::endl;
	}
	else if (_laskuri == 0 && ValintaBool[0])
		std::cout << "\"" << etsittava_teksti << "\" NOT found in \"" << annettu_teksti << "\"" << std::endl;
	
}

void Application::loppu_lauseen_maaritys(const std::string& teksti, const std::string& tiedoston_nimi)
{
	if (ValintaBool[3] && !ValintaBool[4])
		std::cout << "\nOccurrences of lines containing \"" << teksti << "\": " << _laskuri << std::endl;
	else if (ValintaBool[3])
		std::cout << "\nOccurrences of lines NOT containing \"" << teksti << "\": " << tekstin_rivi - _laskuri << std::endl;
	if (_laskuri == 0 && !ValintaBool[3])
		std::cout << "\"" << teksti << "\" NOT found in file \"" << tiedoston_nimi << "\"" << std::endl;
}

void Application::virheiden_etsinta(std::ifstream& tiedostoa, const std::string& nimi)
{
	try
	{
		tiedosto.open(nimi);
		if (tiedosto.fail())
		{
			throw "Logical error on i/o operation.\n";
			if (tiedosto.bad())
				throw "Read or writing error on i/o operation.";
		}
		if (!tiedosto.is_open())
			throw 1;

		tiedosto.close();
	}
	catch (const char* virhe)
	{
		std::cerr << "An exception has occured: \n" << virhe;
	}
	catch (int numero_virhe)
	{
		std::cerr << "Error number " << numero_virhe << ". Couldn't open the file \"" << nimi << "\"\n";
	}
}

void Application::TekstinEtsiminenTiedostosta(const std::string& teksti, const std::string& tiedoston_nimi)
{
	tiedosto.open(tiedoston_nimi);
	if (tiedosto.is_open())
	{
		while (std::getline(tiedosto, annettu_teksti))
		{
			tekstin_rivi += 1;
			tekstin_etsiminen_rivista(teksti, annettu_teksti);
		}
		loppu_lauseen_maaritys(teksti, tiedoston_nimi);
	}
	else
	{
		virheiden_etsinta(tiedosto, tiedoston_nimi);
	}

	tiedosto.close();
}

void Application::Inkrementti1()
{
	kysymykset();

	tekstin_etsiminen_rivista(etsittava_teksti, annettu_teksti);
}

void Application::Alku(const char* valinta[])
{	
	if (valinta[1] != NULL)
		kayttajan_valinnat = valinta[1];
		
	valintojen_maaritys();
}

Application::Application()
{

}