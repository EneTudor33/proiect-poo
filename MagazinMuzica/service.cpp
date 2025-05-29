#include "service.h"
#include<memory>
#include<string>
#include<algorithm>
#include<vector>
const std::vector<Album>& Service::GetAllAlbum() const
{
	return m_albume;
}
bool Service::AddAlbum(std::string titlu, Data data_lansare, int numar_melodii,double pret, int id_gen, int id_casa, int id_artist)
{
	bool exista_artist = std::any_of(m_artisti.begin(), m_artisti.end(),[id_artist](const std::unique_ptr<Artist>& p)
	{return p->GetIdArtist() == id_artist;});
	bool exista_casa = std::any_of(m_case_de_discuri.begin(), m_case_de_discuri.end(),[id_casa](const CasaDeDiscuri& c)
	{return c.GetIdCasa() == id_casa;});
	bool exista_gen = std::any_of(m_genuri_muzicale.begin(), m_genuri_muzicale.end(),[id_gen](const GenMuzical& g)
	{return g.GetIdGen() == id_gen;});
	if (!exista_artist || !exista_casa || !exista_gen)
		return false;
	m_albume.emplace_back(titlu, data_lansare, numar_melodii, pret, id_gen, id_casa,id_artist);
	return true;
}
bool Service::RemoveAlbum(int id)
{
	auto it = std::remove_if(m_albume.begin(), m_albume.end(),[id](const Album& a) {return a.GetIdAlbum() == id;});
		if (it == m_albume.end())
			return false;
		m_albume.erase(it, m_albume.end());
		return true;
}


const std::vector<std::unique_ptr<Artist>>& Service::GetAllArtist() const
{
	return m_artisti;
}
void Service::AddSolo(std::string nume, std::string tara, std::string nume_real)
{
	m_artisti.emplace_back(std::make_unique<Solo>(nume, tara, nume_real));
}
void Service::AddTrupa(std::string nume,std::string tara,int nr_membri)
{
	m_artisti.emplace_back(std::make_unique<Trupa>(nume, tara, nr_membri));
}
bool Service::RemoveArtist(int id)
{
	auto it = std::remove_if(m_artisti.begin(), m_artisti.end(),[id](const std::unique_ptr<Artist>& p) 
	{return p->GetIdArtist() == id;});
	if (it == m_artisti.end()) 
		return false;
	m_artisti.erase(it, m_artisti.end());
	return true;
}

const std::vector<GenMuzical>& Service::GetAllGenMuzical() const
{
	return m_genuri_muzicale;
}
void Service::AddGenMuzical(std::string denumire)
{
	m_genuri_muzicale.emplace_back(denumire);
}
bool Service::RemoveGenMuzical(int id)
{
	auto it = std::remove_if(m_genuri_muzicale.begin(), m_genuri_muzicale.end(), [id](const GenMuzical& a) {return a.GetIdGen() == id;});
	if (it == m_genuri_muzicale.end())
		return false;
	m_genuri_muzicale.erase(it, m_genuri_muzicale.end());
	return true;
}

const std::vector<Comanda>& Service::GetAllComanda() const
{
	return m_comenzi;
}
int Service::AddComanda(int id_client)
{
	bool exista = std::any_of(m_clienti.begin(), m_clienti.end(),[id_client](const Client& c) 
	{return c.GetIdClient() == id_client;});
	if (!exista)
		return -1;
	m_comenzi.emplace_back(id_client);
	return m_comenzi.back().GetIdComanda();
}
bool Service::RemoveComanda(int id_comanda)
{
	auto itDet = std::remove_if(m_detalii_comenzi.begin(), m_detalii_comenzi.end(),[id_comanda](const DetaliiComanda& d)
	{return d.GetIdComanda() == id_comanda;});
	if(itDet != m_detalii_comenzi.end())
		m_detalii_comenzi.erase(itDet, m_detalii_comenzi.end());
	auto itCmd = std::remove_if(m_comenzi.begin(), m_comenzi.end(),[id_comanda](const Comanda& c)
		{return c.GetIdComanda() == id_comanda;});
	if (itCmd == m_comenzi.end())
		return false;
	m_comenzi.erase(itCmd, m_comenzi.end());
	return true;
}
const std::vector<DetaliiComanda> Service::GetDetaliiComanda(int id_comanda) const
{
	std::vector<DetaliiComanda> rezultat;
	for (const auto& d:m_detalii_comenzi)
		if (d.GetIdDetaliiComanda().id_comanda == id_comanda)
			rezultat.push_back(d);
	return rezultat;
}
bool Service::RemoveDetaliiComanda(int id_comanda, int id_album)
{
	auto it = std::remove_if(m_detalii_comenzi.begin(), m_detalii_comenzi.end(),
		[id_comanda,id_album](const DetaliiComanda& d)
		{return d.GetIdComanda() == id_comanda && d.GetIdAlbum() == id_album;});
	if (it == m_detalii_comenzi.end())
		return false;
	m_detalii_comenzi.erase(it, m_detalii_comenzi.end());
	return true;
}
bool Service::AddDetaliiComanda(int id_comanda, int id_album, int cantitate)
{
	bool exista_cmd = std::any_of(m_comenzi.begin(), m_comenzi.end(),[id_comanda](const Comanda& c)
	{return c.GetIdComanda() == id_comanda;});
	bool exista_alb = std::any_of(m_albume.begin(), m_albume.end(),[id_album](const Album& a) 
	{return a.GetIdAlbum() == id_album;});
	if (!exista_cmd || !exista_alb)
		return false;
	m_detalii_comenzi.emplace_back(id_comanda, id_album, cantitate);
	return true;
}
double Service::GetTotalPretComanda(int id_comanda) const
{
	double total = 0.0;
	for (const auto& d : m_detalii_comenzi)
		if (d.GetIdComanda() == id_comanda)
		{
			auto itAlb = std::find_if(m_albume.begin(), m_albume.end(),[&](const Album& a) 
				{return a.GetIdAlbum() == d.GetIdAlbum();});
			if (itAlb != m_albume.end())
				total += itAlb->GetPret() * d.GetCantitate();
		}
	return total;
}

const std::vector<Client>& Service::GetAllClient() const
{
	return m_clienti;
}
void Service::AddClient(std::string nume, std::string prenume, std::string email, std::string telefon)
{
	m_clienti.emplace_back(nume, prenume, email, telefon);
}
bool Service::RemoveClient(int id)
{
	auto it = std::remove_if(m_clienti.begin(), m_clienti.end(), [id](const Client& a) {return a.GetIdClient() == id;});
	if (it == m_clienti.end())
		return false;
	m_clienti.erase(it, m_clienti.end());
	auto itAdr = std::remove_if(m_adrese_clienti.begin(), m_adrese_clienti.end(),[id](const AdresaClient& a) 
	{return a.GetIdClient() == id;});
	m_adrese_clienti.erase(itAdr, m_adrese_clienti.end());
	return true;
}

const std::vector<AdresaClient> Service::GetAllAdresaClient(int id_client) const
{
	std::vector<AdresaClient> rezultat;
	for (const auto& a : m_adrese_clienti)
	{
		if (a.GetIdClient() == id_client)
			rezultat.push_back(a);
	}
	return rezultat;
}
void Service::AddAdresaClient(std::string tara, std::string oras, std::string judet, std::string strada,
	std::string bloc, int scara, int apartament, std::string cod_postal, int id_client)
{
	m_adrese_clienti.emplace_back(tara, oras, judet, strada, bloc, scara, apartament, cod_postal, id_client);
}
bool Service::RemoveAdresaClient(int id)
{
	auto it = std::remove_if(m_adrese_clienti.begin(), m_adrese_clienti.end(), [id](const AdresaClient& a) {return a.GetIdAdresa() == id;});
	if (it == m_adrese_clienti.end())
		return false;
	m_adrese_clienti.erase(it, m_adrese_clienti.end());
	return true;
}

const std::vector<CasaDeDiscuri>& Service::GetAllCasaDeDiscuri() const
{
	return m_case_de_discuri;
}
void Service::AddCasaDeDiscuri(std::string nume, std::string tara, std::string cod_fiscal)
{
	m_case_de_discuri.emplace_back(nume, tara, cod_fiscal);
}
bool Service::RemoveCasaDeDiscuri(int id)
{
	auto it = std::remove_if(m_case_de_discuri.begin(), m_case_de_discuri.end(), [id](const CasaDeDiscuri& a) {return a.GetIdCasa() == id;});
	if (it == m_case_de_discuri.end())
		return false;
	m_case_de_discuri.erase(it, m_case_de_discuri.end());
	return true;
}