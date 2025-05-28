#pragma once
#include "data.h"
#include <string>
#include <ostream>
class Comanda {
private:
	int m_id_comanda;
	static int m_next_id_comanda;
	std::string m_status;
	int m_id_client;
	Data m_data_comanda;
public:
	Comanda(int id_client);
	Data GetDataComanda() const;
	int GetIdComanda() const;
	std::string GetStatus() const;
	int GetIdClient() const;
	void SetStatus(std::string status);
	void SetDataComanda(Data data_comanda);
	friend std::ostream& operator<<(std::ostream& os, const Comanda& c);
};