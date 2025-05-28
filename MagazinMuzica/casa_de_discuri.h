#pragma once
#include<string>
#include<ostream>
class CasaDeDiscuri {
private:
	static int m_next_id_casa;
	int m_id_casa;
	std::string m_nume;
	std::string m_tara;
	std::string m_cod_fiscal;
public:
	CasaDeDiscuri(std::string nume,std::string tara,std::string cod_fiscal);
	int GetIdCasa() const;
	std::string GetNume() const;
	std::string GetTara () const;
	std::string GetCodFiscal() const;
	void SetNume(std::string nume);
	void SetTara(std::string tara);
	void SetCodFiscal(std::string cod_fiscal);
	friend std::ostream& operator<<(std::ostream& os, const CasaDeDiscuri& c);
};
