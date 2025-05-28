#pragma once
#include<string>
#include<ostream>
#include "data.h"
class Album {
private:
	static int m_next_id_album;
	int m_id_album;
	std::string m_titlu;
	Data m_data_lansare;
	int m_numar_melodii;
	int m_id_gen;
	int m_id_casa;
	int m_id_artist;
public:
	Album(std::string titlu,Data data_lansare,int numar_melodii,int id_gen,int id_casa,int id_artist);
	int GetIdAlbum() const;
	std::string GetTitlu() const;
	Data GetDataLansare() const;
	int GetNumarMelodii() const;
	int GetIdGen() const;
	int GetIdCasa() const;
	int GetIdArtist() const;
	void SetTitlu(std::string titlu);
	void SetNumarMelodii(int numar_melodii);
	friend std::ostream& operator<<(std::ostream& os, const Album& a);
};
