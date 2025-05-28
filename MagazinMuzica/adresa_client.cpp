#include "adresa_client.h"
#include<ostream>
int AdresaClient::m_next_id_adresa = 0;
AdresaClient::AdresaClient(std::string tara, std::string oras, std::string judet, std::string strada,
	std::string bloc, int scara, int apartament, std::string cod_postal,int id_client) :
	m_id_adresa(++m_next_id_adresa),m_tara(tara),m_oras(oras),m_judet(judet),m_strada(strada),m_bloc(bloc),
	m_scara(scara),m_apartament(apartament),m_cod_postal(cod_postal),m_id_client(id_client)
	{
	}
int AdresaClient::GetIdAdresa() const
{
	return m_id_adresa;
}
std::string AdresaClient::GetTara() const
{
	return m_tara;
}
std::string AdresaClient::GetOras() const
{
	return m_oras;
}
std::string AdresaClient::GetJudet() const
{
	return m_judet;
}
std::string AdresaClient::GetStrada() const
{
	return m_strada;
}
std::string AdresaClient::GetBloc() const
{
	return m_bloc;
}
int AdresaClient::GetScara() const
{
	return m_scara;
}
int AdresaClient::GetApartament() const
{
	return m_apartament;
}
std::string AdresaClient::GetCodPostal() const
{
	return m_cod_postal;
}
int AdresaClient::GetIdClient() const
{
	return m_id_client;
}
void AdresaClient::SetTara(std::string tara)
{
	m_tara = tara;
}
void AdresaClient::SetOras(std::string oras)
{
	m_oras = oras;
}
void AdresaClient::SetJudet(std::string judet)
{
	m_judet = judet;
}
void AdresaClient::SetStrada(std::string strada)
{
	m_strada = strada;
}
void AdresaClient::SetBloc(std::string bloc)
{
	m_bloc = bloc;
}
void AdresaClient::SetScara(int scara)
{
	m_scara = scara;
}
void AdresaClient::SetApartament(int apartament)
{
	m_apartament = apartament;
}
void AdresaClient::SetCodPostal(std::string cod_postal)
{
	m_cod_postal = cod_postal;
}
std::ostream& operator<<(std::ostream& os, const AdresaClient& a)
{
	return os << "Id: " << a.m_id_adresa << " Tara: " << a.m_tara << " Oras: " << a.m_oras << " Tara: " << a.m_tara
		<< " Judet: " << a.m_judet << " Strada:" << a.m_strada << " Bloc: " << a.m_bloc << " Scara: " << a.m_scara << " Apartament: " << a.m_apartament
		<< " Cod Postal: " << a.m_cod_postal;
}