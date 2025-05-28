#include"client.h"
#include<string>
#include<iostream>
int Client::m_next_id_client = 0;
Client::Client(std::string nume, std::string prenume, std::string email, std::string telefon):
m_id_client(++m_next_id_client),m_nume(nume),m_prenume(prenume),m_email(email),m_telefon(telefon)
{
	std::cout << "Clientul nou cu id-ul "<<m_id_client<<" a fost adaugat";
}
int Client::GetIdClient() const
{
	return m_id_client;
}
std::string Client::GetNume() const
{
	return m_nume;
}
std::string Client::GetPrenume() const
{
	return m_prenume;
}
std::string Client::GetEmail() const
{
	return m_email;
}
std::string Client::GetTelefon() const
{
	return m_telefon;
}
void Client::SetNume(std::string nume)
{
	m_nume = nume;
}
void Client::SetPrenume(std::string prenume)
{
	m_prenume = prenume;
}
void Client::SetEmail(std::string email)
{
	m_email = email;
}
void Client::SetTelefon(std::string telefon)
{
	m_telefon = telefon;
}
std::ostream& operator<<(std::ostream& os, const Client& c)
{
	return os << "Id: " << c.m_email << " Nume:" << c.m_nume << " Prenume:" << c.m_prenume << " Email:" << c.m_email << " Telefon:" << c.m_telefon;
}