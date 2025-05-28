#include "gen_muzical.h"
#include <string>

int GenMuzical::m_next_id_gen = 0;
GenMuzical::GenMuzical(std::string denumire): m_id_gen(++m_next_id_gen),m_denumire(denumire)
{
}
int GenMuzical::GetIdGen() const
{
	return m_id_gen;
}
std::string GenMuzical::GetDenumire() const
{
	return m_denumire;
}
void GenMuzical::SetDenumire(std::string denumire)
{
	m_denumire = denumire;
}
std::ostream& operator<<(std::ostream& os, const GenMuzical& g)
{
	return os << "Id: " << g.m_id_gen << " Denumire:" << g.m_denumire;

}