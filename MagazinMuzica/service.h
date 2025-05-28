#pragma once
#include "album.h"
#include "artist.h"
#include "solo.h"
#include "trupa.h"
#include "gen_muzical.h"
#include "casa_de_discuri.h"
#include "adresa_client.h"
#include "client.h"
#include "comanda.h"
#include "detalii_comanda.h"
#include <vector>
#include<memory>
class Service {
private:
	std::vector <Album> m_albume;
	std::vector<std::unique_ptr<Artist>> m_artisti;
	std::vector <GenMuzical> m_genuri_muzicale;
	std::vector <Comanda> m_comenzi;
	std::vector<DetaliiComanda> m_detalii_comenzi;
	std::vector <Client> m_clienti;
	std::vector <AdresaClient> m_adrese_clienti;
	std::vector <CasaDeDiscuri> m_case_de_discuri;
public:
	const std::vector<Album>& GetAllAlbum() const;
	bool AddAlbum(std::string titlu, Data data_lansare, int numar_melodii, int id_gen, int id_casa, int id_artist);
	bool RemoveAlbum(int id);

	const std::vector<std::unique_ptr<Artist>>& GetAllArtist() const;
	void AddSolo(std::string nume, std::string tara, std::string nume_real);
	void AddTrupa(std::string nume, std::string tara, int nr_membri);
	bool RemoveArtist(int id);

	const std::vector<GenMuzical>& GetAllGenMuzical() const;
	void AddGenMuzical(std::string denumire);
	bool RemoveGenMuzical(int id);

	const std::vector<Comanda>& GetAllComanda() const;
	int AddComanda(int id_client);
	bool RemoveComanda(int id_comanda);

	const std::vector<DetaliiComanda> GetDetaliiComanda(int id_comanda) const;
	bool AddDetaliiComanda(int id_comanda, int id_album, int cantitate);
	bool RemoveDetaliiComanda(int id_comanda, int id_album);

	const std::vector<Client>& GetAllClient() const;
	void AddClient(std::string nume, std::string prenume, std::string email, std::string telefon);
	bool RemoveClient(int id);

	const std::vector<AdresaClient> GetAllAdresaClient(int id_client) const;
	void AddAdresaClient(std::string tara, std::string oras, std::string judet, std::string strada,
		std::string bloc, int scara, int apartament, std::string cod_postal, int id_client);
	bool RemoveAdresaClient(int id);

	const std::vector<CasaDeDiscuri>& GetAllCasaDeDiscuri() const;
	void AddCasaDeDiscuri(std::string nume, std::string tara, std::string cod_fiscal);
	bool RemoveCasaDeDiscuri(int id);
};
