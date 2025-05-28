#include "solo.h"
#include<string>

Solo::Solo(const std::string nume,const std::string tara,const std::string nume_real): Artist(nume, tara),m_nume_real(nume_real) 
{

}
std::string Solo::GetNumeReal() const
{
	return m_nume_real;
}
void Solo::SetNumeReal(std::string nume_real)
{
	m_nume_real = nume_real;
}
std::ostream& Solo::print(std::ostream& os) const
{
	return os<<"Id:"<<m_id_artist<<" Nume:"<<m_nume<< " Tara origine:" << m_tara_origine << 
	" (Solo, Nume real: " << m_nume_real<<")";
}
