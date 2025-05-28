#include<iostream>
#include<algorithm>
#include "data.h"
#include "ui.h"
void Pause()
{
	std::cout <<"(Enter pentru a continua)";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
void ClearScreen()
{
	#ifdef _WIN32
		std::system("cls");
	#else
		std::system("clear");
	#endif
}
void ShowMainMenu()
{
	ClearScreen();
	std::cout << "Salut, cu ce te pot ajuta azi?" << std::endl;
	std::cout << "1.Catalog" << std::endl;
	std::cout << "2.Clienti" << std::endl;
	std::cout << "3.Comenzi" << std::endl;
	std::cout << "0.Salveaza si iesi" << std::endl;
	std::cout << "Alege optiunea scriind in consola numarul ei" << std::endl;
}
void ShowCatalog()
{
	ClearScreen();
	std::cout << "Bine ai venit in sectiunea catalog, ce ai dori sa faci?" << std::endl;
	std::cout << "1.Gestionare Albume" << std::endl;
	std::cout << "2.Gestionare Artisti" << std::endl;
	std::cout << "3.Gestionare Genuri Muzicale" << std::endl;
	std::cout << "4.Gestionare Case De Discuri" << std::endl;
	std::cout << "0.Inapoi la meniul principal" << std::endl;
	std::cout << "Alege optiunea scriind in consola numarul ei" << std::endl;
}
void ShowAlbum()
{
	ClearScreen();
	std::cout << "1.Afiseaza toate albumele" << std::endl;
	std::cout << "2.Adauga un album nou" << std::endl;
	std::cout << "3.Sterge un album" << std::endl;
	std::cout << "0.Inapoi la catalog" << std::endl;
}
void ShowArtisti()
{
	ClearScreen();
	std::cout << "1.Afiseaza toti artistii" << std::endl;
	std::cout << "2.Adauga un artist de tip solo" << std::endl;
	std::cout << "3.Adauga un artist de tip trupa" << std::endl;
	std::cout << "4.Sterge un artist" << std::endl;
	std::cout << "0.Inapoi la catalog" << std::endl;
}
void ShowGenuriMuzicale()
{
	ClearScreen();
	std::cout << "1.Afiseaza toate genurile muzicale" << std::endl;
	std::cout << "2.Adauga un gen muzical nou" << std::endl;
	std::cout << "3.Sterge un gen muzical" << std::endl;
	std::cout << "0.Inapoi la catalog" << std::endl;
}
void ShowCaseDeDiscuri()
{
	ClearScreen();
	std::cout << "1.Afiseaza toate casele de discuri" << std::endl;
	std::cout << "2.Adauga o casa noua de discuri" << std::endl;
	std::cout << "3.Sterge o casa de discuri" << std::endl;
	std::cout << "0.Inapoi la catalog" << std::endl;
}
void ShowClienti()
{
	ClearScreen();
	std::cout << "Bine ai venit in sectiunea Clienti, ce ai dori sa faci?" << std::endl;
	std::cout << "1.Afiseaza toti clientii" << std::endl;
	std::cout << "2.Adauga un client" << std::endl;
	std::cout << "3.Sterge un client" << std::endl;
	std::cout << "4.Gestioneaza adresele unui client" << std::endl;
	std::cout << "0.Inapoi la meniul principal" << std::endl;
	std::cout << "Alege optiunea scriind in consola numarul ei" << std::endl;
}
void ShowComenzi()
{
	ClearScreen();
	std::cout << "Bine ai venit in sectiunea Comenzi, ce ai dori sa faci?" << std::endl;
	std::cout << "1.Afiseaza toate comenzile" << std::endl;
	std::cout << "2.Adauga o comanda" << std::endl;
	std::cout << "3.Sterge o comanda" << std::endl;
	std::cout << "0.Inapoi la meniul principal" << std::endl;
}
void ShowAdreseClient()
{
	ClearScreen();
	std::cout << "Bine ai venit in sectiunea Adrese Clienti, ce ai dori sa faci?" << std::endl;
	std::cout << "1.Afiseaza toate adresele clientului" << std::endl;
	std::cout << "2.Adauga o noua adresa clientului" << std::endl;
	std::cout << "3.Sterge adresa unui client" << std::endl;
	std::cout << "0.Inapoi la gestionarea clientilor" << std::endl;
}
void GestiuneCatalog(Service& service)
{
	bool back = false;
	while (!back)
	{
		ShowCatalog();
		std::cout << "Optiunea dorita: ";
		int subop;
		std::cin >> subop;
		std::cin.ignore();
		switch (subop)
		{
		case 1:
		{
			GestiuneAlbum(service);
			break;
		}
		case 2:
		{
			GestiuneArtisti(service);
			break;
		}
		case 3:
		{
			GestiuneGenuriMuzicale(service);
			break;
		}
		case 4:
		{
			GestiuneCaseDeDiscuri(service);
			break;
		}
		case 0:
		{
			back = true;
			break;
		}
		default:
		{
			std::cout << "Optiunea nu exista!" << std::endl;
			Pause();
			break;
		}
		}
	}
}
void GestiuneAlbum(Service& service)
{
	bool back = false;
	while (!back)
	{
		ShowAlbum();
		int op;
		std::cout << "Optiunea dorita: ";
		std::cin >> op;
		std::cin.ignore();
		switch (op)
		{
		case 1:
		{
			const auto& albume = service.GetAllAlbum();
			if (albume.empty())
				std::cout << "Nu avem niciun album introdus"<< std::endl;
			else
			{
				for (const auto& a : albume)
					std::cout << a << std::endl;
			}
			Pause();
			break;
		}
		case 2:
		{
			int nr_melodii, id_gen, id_casa, id_artist;
			std::string titlu;
			Data data;
			std::cout << "Titlu: "<<std::endl;
			std::getline(std::cin, titlu);
			std::cout << "Zi lansare: " << std::endl;
			std::cin >> data.zi;
			std::cin.ignore();
			std::cout << "Luna lansare: " << std::endl;
			std::cin >> data.luna;
			std::cin.ignore();
			std::cout << "An lansare: " << std::endl;
			std::cin >> data.an;
			std::cin.ignore();
			std::cout << "Numar melodii: " << std::endl;
			std::cin >> nr_melodii;
			std::cin.ignore();
			std::cout << "Id Gen: " << std::endl;
			std::cin >> id_gen;
			std::cin.ignore();
			std::cout << "Id Casa: " << std::endl;
			std::cin >> id_casa;
			std::cin.ignore();
			std::cout << "Id Artist: " << std::endl;
			std::cin >> id_artist;
			std::cin.ignore();
			if (!service.AddAlbum(titlu, data, nr_melodii, id_gen, id_casa, id_artist))
				std::cout << "Artist sau Casa de Discuri inexistent!" << std::endl;
			Pause();
			break;
		}
		case 3:
		{
			int id_album;
			std::cout <<"Id-ul albumului pe care vreti sa il stergeti:" << std::endl;
			std::cin >> id_album;
			std::cin.ignore();
			if (!service.RemoveAlbum(id_album))
				std::cout << "Album inexistent!" << std::endl;
			else
				std::cout << " Album sters cu succes!" << std::endl;
			Pause();
			break;
		}
		case 0:
		{
			back = true;
			break;
		}
		default:
		{
			std::cout << "Optiune invalida" << std::endl;
			Pause();
		}
			
		}
	}
}
void GestiuneArtisti(Service& service)
{
	bool back = false;
	while (!back)
	{
		ShowArtisti();
		int op;
		std::cout << "Optiunea dorita: ";
		std::cin >> op;
		std::cin.ignore();
		switch (op)
		{
		case 1:
		{
			const auto& artisti = service.GetAllArtist();
			if (artisti.empty())
				std::cout << "Nu avem niciun artist introdus"<<std::endl;
			else
			{
				for (const auto& p : artisti)
					std::cout << *p << std::endl;
			}
			Pause();
			break;
		}
		case 2:
		{
			std::string nume, tara, nume_real;
			std::cout << "Nume: ";
			std::getline(std::cin, nume);
			std::cout << "Tara: ";         
			std::getline(std::cin, tara);
			std::cout << "Nume real: ";     
			std::getline(std::cin, nume_real);
			service.AddSolo(nume, tara, nume_real);
			std::cout << "Artist solo adaugat!"<<std::endl;
			Pause();
			break;
		}
		case 3:
		{
			std::string nume, tara;
			int membri;
			std::cout << "Nume: ";   
			std::getline(std::cin, nume);
			std::cout << "Tara: ";        
			std::getline(std::cin, tara);
			std::cout << "Numar membri: "; 
			std::cin >> membri; 
			std::cin.ignore();
			service.AddTrupa(nume, tara, membri);
			std::cout << "Trupa adaugata!"<<std::endl;
			Pause();
			break;
		}
		case 4:
		{
			int id;
			std::cout << "Id-ul artistului pe care vreti sa il stergeti: ";
			std::cin >> id; 
			std::cin.ignore();
			if (!service.RemoveArtist(id))
				std::cout << "Artist inexistent!";
			else
				std::cout << "Artist sters cu succes!"<<std::endl;
			Pause();
			break;
		}
		case 0:
		{
			back = true;
			break;
		}
		default:
		{
			std::cout << "Optiune invalida" << std::endl;
			Pause();
		}
		}
	}
}
void GestiuneGenuriMuzicale(Service& service)
{
	bool back = false;
	while (!back)
	{
		ShowGenuriMuzicale();
		int op;
		std::cout <<" Optiunea dorita: ";
		std::cin >> op;
		std::cin.ignore();
		switch (op)
		{
		case 1:
		{
			const auto& genuri = service.GetAllGenMuzical();
			if (genuri.empty())
				std::cout << "Nu avem niciun gen muzical introdus"<<std::endl;
			else
			{
				for (const auto& g : genuri)
					std::cout << g << std::endl;
			}
			Pause();
			break;
		}
		case 2:
		{
			std::string denumire;
			std::cout << "Denumire:" << std::endl;
			std::getline(std::cin, denumire);
			try
			{
				service.AddGenMuzical(denumire);
				std::cout << "Gen muzical adaugat!" << std::endl;
			}
			catch (...)
			{
				std::cout << "Eroare!" << std::endl;
			}
			Pause();
			break;
		}
		case 3:
		{
			int id_gen_muzical;
			std::cout << "Id-ul genului muzical pe care vreti sa il stergeti:" << std::endl;
			std::cin >> id_gen_muzical;
			std::cin.ignore();
			if (!service.RemoveGenMuzical(id_gen_muzical))
				std::cout << "Gen muzical inexistent!" << std::endl;
			else
				std::cout << "Gen muzcial sters cu succes!" << std::endl;
			Pause();
			break;
		}
		case 0:
		{
			back = true;
			break;
		}
		default:
		{
			std::cout << "Optiune invalida" << std::endl;
			Pause();
		}
			
		}
	}
}
void GestiuneCaseDeDiscuri(Service& service)
{
	bool back = false;
	while (!back)
	{
		ShowCaseDeDiscuri();
		int op;
		std::cout << "Optiunea dorita: ";
		std::cin >> op;
		std::cin.ignore();
		switch (op)
		{
		case 1:
		{
			const auto& case_de_discuri = service.GetAllCasaDeDiscuri();
			if (case_de_discuri.empty())
				std::cout << "Nu avem nicio casa de discuri introdusa"<<std::endl;
			else
			{
				for(const auto & c :case_de_discuri)
					std::cout<<c<<std::endl;
			}
			Pause();
			break;
		}
		case 2:
		{
			std::string nume, tara, cod_fiscal;
			std::cout << "Nume: " << std::endl;
			std::getline(std::cin, nume);
			std::cout << "Tara: " << std::endl;
			std::getline(std::cin, tara);
			std::cout << "Cod fiscal: " << std::endl;
			std::getline(std::cin, cod_fiscal);
			try
			{
				service.AddCasaDeDiscuri(nume, tara, cod_fiscal);
				std::cout << "Casa de discuri adaugata!" << std::endl;
			}
			catch (...)
			{
				std::cout << "Eroare!" << std::endl;
			}
			Pause();
			break;
		}
		case 3:
		{
			int id_casa;
			std::cout << "Id-ul casei de discuri pe care vreti sa o stergeti:" << std::endl;
			std::cin >> id_casa;
			std::cin.ignore();
			if (!service.RemoveCasaDeDiscuri(id_casa))
				std::cout << "Casa de discuri inexistenta!" << std::endl;
			else
				std::cout << "Casa se discuri stearsa cu succes!" << std::endl;
			Pause();
			break;
		}
		case 0:
		{
			back = true;
			break;
		}
		default:
		{
			std::cout << "Optiune invalida" << std::endl;
			Pause();
		}
			
		}
	}
}
void GestiuneComenzi(Service& service)
{
	bool back = false;
	while (!back)
	{
		ShowComenzi();
		int op;
		std::cin >> op;
		std::cin.ignore();
		switch (op)
		{
		case 1:
		{
			std::vector<Comanda> comenzi = service.GetAllComanda();
			if (comenzi.empty())
				std::cout << "Nu exista comenzi inregistrate!"<<std::endl;
			else
			{
				for (const auto& c : comenzi)
				{
					std::cout << c << std::endl;
					auto detalii = service.GetDetaliiComanda(c.GetIdComanda());
					for (const auto& d : detalii)
					{
						std::cout << "Album:" << d.GetIdDetaliiComanda().id_album << " Cantitate:" << d.GetCantitate() << std::endl;
					}
				}
			}
			Pause();
			break;
		}
		case 2:
		{
			int id_client;
			std::cout << "Id client: ";
			std::cin >> id_client;
			std::cin.ignore();
			int id_comanda = service.AddComanda(id_client);
			bool more = true;
			while (more)
			{
				int id_album;
				std::cout << "Id album: ";
				std::cin >> id_album;
				std::cin.ignore();
				int cantitate;
				std::cout << "Cantitate: ";
				std::cin >> cantitate;
				std::cin.ignore();
				if (!service.AddDetaliiComanda(id_comanda, id_album, cantitate))
					std::cout << "Comanda sau album inexistent!" << std::endl;
				else
				{
					std::cout << "Album adaugat!" << std::endl;
					char caracter;
					std::cout << "Mai bagi un album? Y/N" << std::endl;
					std::cin >> caracter;
					std::cin.ignore();
					if (caracter == 'N' || caracter == 'n')
						more = false;
				}
			}
			std::cout << "Comanda creata cu succes!"<<std::endl;
			Pause();
			break;
		}
		case 3:
		{
			int id_comanda;
			std::cout << "Id comanda:";
			std::cin >> id_comanda;
			std::cin.ignore();
			if (!service.RemoveComanda(id_comanda))
				std::cout << "Comanda inexistenta!" << std::endl;
			else
				std::cout << "Comanda stearsa cu succes!" << std::endl;
			Pause();
			break;
		}
		case 0:
		{
			back = true;
			break;
		}
		default:
		{
			std::cout << "Optiune invalida!" << std::endl;
			Pause();
		}
		}
	}
}
void GestiuneAdreseClient(Service& service,int id_client)
{
	bool exista_client=std::any_of(service.GetAllClient().begin(),service.GetAllClient().end(),[id_client](const Client& c)
	{return c.GetIdClient() == id_client;});
	if (!exista_client)
	{
		std::cout << "Client inexistent!!";
		return;
	}
	bool back = false;
	while (!back)
	{
		ShowAdreseClient();
		int op;
		std::cout<< "Optiunea dorita:";
		std::cin >> op;
		std::cin.ignore();
		switch (op)
		{
		case 1:
		{
			auto adrese = service.GetAllAdresaClient(id_client);
			if (adrese.empty())
				std::cout << "Clientul nu are adrese!"<<std::endl;
			else
			{
				for (const auto& a : adrese)
				{
					std::cout << a<<std::endl;
				}

			}
			Pause();
			break;
		}
		case 2:
		{
			std::string tara, oras, judet, strada, bloc, cod_postal;
			int scara, apartament;
			std::cout << "Tara: ";          
			std::getline(std::cin, tara);
			std::cout << "Oras: ";
			std::getline(std::cin, oras);
			std::cout << "Judet: ";
			std::getline(std::cin, judet);
			std::cout << "Strada: ";
			std::getline(std::cin, strada);
			std::cout << "Bloc: ";
			std::getline(std::cin, bloc);
			std::cout << "Scara: ";
			std::cin >> scara;       
			std::cin.ignore();
			std::cout << "Apartament: ";
			std::cin >> apartament;  
			std::cin.ignore();
			std::cout << "Cod postal: ";
			std::getline(std::cin, cod_postal);
			try
			{
				service.AddAdresaClient(tara, oras, judet, strada,bloc, scara, apartament,cod_postal, id_client);
				std::cout << "Adresa adaugata!\n";
			}
			catch (...)
			{
				std::cout << "Eroare!" << std::endl;
			}
			Pause();
			break;
		}
		case 3:
		{
			int id_adresa;
			std::cout << "ID: ";
			std::cin >> id_adresa; 
			std::cin.ignore();
			if (!service.RemoveAdresaClient(id_adresa))
				std::cout << "Adresa inexistenta!"<<std::endl;
			else
				std::cout << "Adresa stearsa cu succes!"<<std::endl;
			Pause();
			break;
		}
		case 0:
		{
			back = true;
			break;
		}
		default:
		{
			std::cout << "Optiune invalida!" << std::endl;
			Pause();
		}
		}
	}
}
void GestiuneClienti(Service& service)
{
	bool back = false;
	while (!back)
	{
		ShowClienti();
		int op;
		std::cout << "Optiunea:";
		std::cin >> op;
		std::cin.ignore();
		switch (op)
		{
		case 1:
		{
			std::vector <Client> clienti = service.GetAllClient();
			if (clienti.empty())
				std::cout << "Nu avem clienti inregsitrati!" << std::endl;
			else
			{
				for (const auto& c : clienti)
				{
					std::cout << c << std::endl;

				}
			}
			Pause();
			break;
		}
		case 2:
		{
			std::string nume,prenume,email,telefon;
			std::cout << "Nume: " << std::endl;
			std::getline(std::cin, nume);
			std::cout << "Prenume: " << std::endl;
			std::getline(std::cin, prenume);
			std::cout << "Email: " << std::endl;
			std::getline(std::cin, email);
			std::cout << "Telefon: " << std::endl;
			std::getline(std::cin, telefon);
			try
			{
				service.AddClient(nume,prenume,email,telefon);
				std::cout << "Client adaugat!" << std::endl;
			}
			catch (...)
			{
				std::cout << "Eroare!" << std::endl;
			}
			Pause();
			break;
		}
		case 3:
		{
			int id_client;
			std::cout << "Id: ";
			std::cin >> id_client;
			std::cin.ignore();
			if (!service.RemoveClient(id_client))
			{
				std::cout << "Client inexistent!" << std::endl;
			}
			else
			{
				std::cout << "Client sters cu succes!" << std::endl;
			}
			Pause();
			break;
		}
		case 4:
		{
			int id_client;
			std::cout << "Id client:";
			std::cin >> id_client;
			std::cin.ignore();
			GestiuneAdreseClient(service, id_client);
			Pause();
			break;
		}
		case 0:
		{
			back = true;
			break;
		}
		default:
		{
			std::cout << "Optiune invalida" << std::endl;
			Pause();
		}
			
		}
	}
}
void RunUI(Service& service)
{
	bool exit = false;
	while (!exit)
	{
		ShowMainMenu();
		int op;
		std::cout << "Optiunea dorita: ";
		std::cin >> op;
		std::cin.ignore();
		switch (op)
		{
		case 1:
		{
			GestiuneCatalog(service);
			break;
		}
		case 2:
		{
			GestiuneClienti(service);
			break;
		}
		case 3:
		{
			GestiuneComenzi(service);
			break;
		}
		case 0:
		{
			exit = true;
			break;
		}
		default:
			std::cout << "Optiune invalida!" << std::endl;
		}
	}
}