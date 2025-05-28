#pragma once
#include<string>
#include<ostream>
class Client
{
private:
	int m_id_client;
	std::string m_nume;
	std::string m_prenume;
	std::string m_email;
	std::string m_telefon;
	static int m_next_id_client;
public:
	Client(std::string nume, std::string prenume, std::string email, std::string telefon);
	int GetIdClient() const;
	std::string GetNume() const;
	std::string GetPrenume() const;
	std::string GetEmail() const;
	std::string GetTelefon() const;
	void SetNume(std::string nume);
	void SetPrenume(std::string prenume);
	void SetEmail(std::string email);
	void SetTelefon(std::string telefon);
	friend std::ostream& operator<<(std::ostream& os, const Client& c);
};