#include "casa_de_discuri.h"
#include<string>
int CasaDeDiscuri::m_next_id_casa = 0;
CasaDeDiscuri::CasaDeDiscuri(std::string nume, std::string tara, std::string cod_fiscal):
m_id_casa(++m_next_id_casa),m_nume(nume),m_tara(tara),m_cod_fiscal(cod_fiscal)
{
}
int CasaDeDiscuri::GetIdCasa() const
{
	return m_id_casa;
}
std::string CasaDeDiscuri::GetNume() const
{
	return m_nume;
}
std::string CasaDeDiscuri::GetTara() const
{
	return m_tara;
}
std::string CasaDeDiscuri::GetCodFiscal() const
{
	return m_cod_fiscal;
}
void CasaDeDiscuri::SetNume(std::string nume)
{
	m_nume = nume;
}
void CasaDeDiscuri::SetTara(std::string tara)
{
	m_tara = tara;
}
void CasaDeDiscuri::SetCodFiscal(std::string cod_fiscal)
{
	m_cod_fiscal = cod_fiscal;
}
std::ostream& operator<<(std::ostream& os, const CasaDeDiscuri& c)
{
	return os << "Id:" << c.m_id_casa << " Nume:" << c.m_nume << " Tara:" << c.m_tara<<" Cod fiscal:"<<c.m_cod_fiscal;
}