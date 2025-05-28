#include "artist.h"
#include<string>
#include<ostream>
int Artist::m_next_id_artist = 0;
Artist::Artist(std::string nume, std::string tara_origine):
m_id_artist(++m_next_id_artist),m_nume(nume),m_tara_origine(tara_origine)
{
}
int Artist::GetIdArtist() const 
{
	return m_id_artist;
}
std::string Artist::GetNume() const
{
	return m_nume;
}
std::string Artist::GetTaraOrigine() const
{
	return m_tara_origine;
}
void Artist::SetNume(std::string nume)
{
	m_nume = nume;
}
void Artist::SetTaraOrigine(std::string tara_origine)
{
	m_tara_origine = tara_origine;
}