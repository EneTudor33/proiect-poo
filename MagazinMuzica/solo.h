#pragma once
#include<string>
#include "artist.h"
class Solo: public Artist{
private:
	std::string m_nume_real;
public:
	Solo(const std::string nume, const std::string tara, const std::string nume_real);
	std::string GetNumeReal() const;
	void SetNumeReal(std::string nume_real);
	std::ostream& print(std::ostream& os) const override;
};