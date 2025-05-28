#pragma once
#include<string>
#include<ostream>
class GenMuzical {
private:
	static int m_next_id_gen;
	int m_id_gen;
	std::string m_denumire;
public:
	GenMuzical(std::string denumire);
	int GetIdGen() const;
	std::string GetDenumire() const;
	void SetDenumire(std::string denumire);
	friend std::ostream& operator<<(std::ostream& os, const GenMuzical& g);
};
