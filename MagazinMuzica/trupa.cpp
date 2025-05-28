#include "trupa.h"

Trupa::Trupa(const std::string& nume, const std::string& tara, int  membrii) : Artist(nume, tara), m_numar_membrii(membrii)
{

}
int Trupa::GetNumarMembrii() const
{
	return m_numar_membrii;
}
void Trupa::SetNumarMembrii(int numar_membrii)
{
	m_numar_membrii = numar_membrii;
}
std::ostream& Trupa::print(std::ostream& os) const
{
	return os << "Id:" << m_id_artist <<" Nume:" << m_nume << " Tara origine:" << m_tara_origine << "(Trupa,Numar membrii:" << m_numar_membrii << ")";
}
