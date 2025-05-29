#pragma once
#include<string>
#include<ostream>
#include "data.h"
class Album {
public:
	Album(std::string titlu,Data data_lansare,int numar_melodii,double pret,int id_gen,int id_casa,int id_artist);
	int GetIdAlbum() const;
	std::string GetTitlu() const;
	Data GetDataLansare() const;
	int GetNumarMelodii() const;
	int GetIdGen() const;
	int GetIdCasa() const;
	int GetIdArtist() const;
	double GetPret() const;
	void SetTitlu(std::string titlu);
	void SetNumarMelodii(int numar_melodii);
	friend std::ostream& operator<<(std::ostream& os, const Album& a);
	friend double operator+(const Album& album1, const Album& album2);
private:
	static int m_next_id_album;
	int m_id_album;
	std::string m_titlu;
	Data m_data_lansare;
	int m_numar_melodii;
	int m_id_gen;
	int m_id_casa;
	int m_id_artist;
	double m_pret;
};
