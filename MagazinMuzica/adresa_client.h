#pragma once
#include<string>
class AdresaClient {
public:
	AdresaClient(std::string tara, std::string oras, std::string judet, std::string strada,
		std::string bloc, int scara, int apartament, std::string cod_postal,int id_client);
	int GetIdAdresa() const;
	std::string GetTara() const;
	std::string GetOras() const;
	std::string GetJudet() const;
	std::string GetStrada() const;
	std::string GetBloc() const;
	int GetScara() const;
	int GetApartament() const;
	std::string GetCodPostal() const;
	int GetIdClient() const;
	void SetTara(std::string tara);
	void SetOras(std::string oras);
	void SetJudet(std::string judet);
	void SetStrada(std::string strada);
	void SetBloc(std::string bloc);
	void SetScara(int scara);
	void SetApartament(int apartament);
	void SetCodPostal(std::string cod_postal);
	friend std::ostream& operator<<(std::ostream& os, const AdresaClient& a);
private:
	int static m_next_id_adresa;
	int m_id_adresa;
	std::string m_tara;
	std::string m_oras;
	std::string m_judet;
	std::string m_strada;
	std::string m_bloc;
	int m_scara;
	int m_apartament;
	std::string m_cod_postal;
	int m_id_client;
};