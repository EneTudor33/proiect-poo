#pragma once
#include<string>
#include<ostream>
class Artist {
protected:
	static int m_next_id_artist;
	int m_id_artist;
	std::string m_nume;
	std::string m_tara_origine;
public:
	Artist(std::string nume,std::string tara_origine);
	virtual ~Artist() = default;
	int GetIdArtist() const;
	std::string GetNume() const;
	std::string GetTaraOrigine() const;
	void SetNume(std::string nume);
	void SetTaraOrigine(std::string tara_origine);
	virtual std::ostream& print(std::ostream& os) const = 0;
	friend std::ostream& operator<<(std::ostream& os, const Artist& a);
};
inline std::ostream& operator<<(std::ostream& os, const Artist& a)
{
	return a.print(os);
}
