#include "album.h"
#include<string>

int Album::m_next_id_album = 0;
Album::Album(std::string titlu,Data data_lansare,int numar_melodii,double pret,int id_gen,int id_casa,int id_artist) : 
m_id_album(++m_next_id_album),m_titlu(titlu),m_data_lansare(data_lansare),m_numar_melodii(numar_melodii),m_pret(pret),
m_id_gen(id_gen),m_id_casa(id_casa),m_id_artist(id_artist)
{
}
int Album::GetIdAlbum() const 
{
	return m_id_album;
}
std::string Album::GetTitlu() const
{
	return m_titlu;
}
Data Album::GetDataLansare() const
{
	return m_data_lansare;
}
int Album::GetNumarMelodii() const
{
	return m_numar_melodii;
}
double Album::GetPret() const
{
	return m_pret;
}
void Album::SetTitlu(std::string titlu)
{
	m_titlu = titlu;
}
void Album::SetNumarMelodii(int numar_melodii)
{
	m_numar_melodii = numar_melodii;
}
int Album::GetIdGen() const
{
	return m_id_gen;
}
int Album::GetIdCasa() const
{
	return m_id_casa;
}
int Album::GetIdArtist() const
{
	return m_id_artist;
}
std::ostream& operator<<(std::ostream& os, const Album& a)
{
	return os << "Id:"<<a.m_id_album << " Titlu:" << a.m_titlu << " Data lansare:"
		<< a.m_data_lansare.zi << "/" << a.m_data_lansare.luna << "/" << a.m_data_lansare.an<<" Numar melodii:"<<a.m_numar_melodii
		<<" Pret: "<<a.m_pret<<" Id casa: "<<a.m_id_casa<<" Id artist: "<<a.m_id_artist<<" Id gen: "<<a.m_id_gen;

}
double operator+(const Album& album1, const Album& album2)
{
	return album1.m_pret + album2.m_pret;
}