#include "comanda.h"
#include <ctime>
int Comanda::m_next_id_comanda = 0;
Comanda::Comanda(int id_client) : 
m_id_comanda(++m_next_id_comanda),m_status("In curs de procesare"),m_id_client(id_client)
{
    std::time_t t = std::time(nullptr);
    std::tm bt{};
    #if defined(_WIN32) || defined(_WIN64)
        localtime_s(&bt, &t);
    #else
        localtime_r(&t, &bt);
    #endif
    m_data_comanda.zi = bt.tm_mday;
    m_data_comanda.luna = bt.tm_mon + 1;
    m_data_comanda.an = bt.tm_year + 1900;
}
int Comanda::GetIdComanda() const
{
	return m_id_comanda;
}
std::string Comanda::GetStatus() const
{
	return m_status;
}
int Comanda::GetIdClient() const
{
	return m_id_client;
}
Data Comanda::GetDataComanda() const
{
	return m_data_comanda;
}
void Comanda::SetStatus(std::string status)
{
	m_status = status;
}
void Comanda::SetDataComanda(Data data_comanda)
{
	m_data_comanda = data_comanda;
}
std::ostream& operator<<(std::ostream& os, const Comanda& c)
{
    return os << "Id:" << c.m_id_comanda << " Data: " << c.m_data_comanda.zi << "/" << c.m_data_comanda.luna << "/" << c.m_data_comanda.an << " Status: "
        <<c.m_status << " " << "Id client:" << c.m_id_client;

}