#include "detalii_comanda.h"
#include "tuplu_id.h"

DetaliiComanda::DetaliiComanda(int id_comanda, int id_album, int cantitate) :
	m_id_detalii_comanda{id_comanda,id_album}, m_cantitate(cantitate)
{

}
TupluComandaAlbum DetaliiComanda::GetIdDetaliiComanda() const
{
	return m_id_detalii_comanda;
}
int DetaliiComanda::GetIdComanda() const
{
	return m_id_detalii_comanda.id_comanda;
}
int DetaliiComanda::GetIdAlbum() const
{
	return m_id_detalii_comanda.id_album;
}
int DetaliiComanda::GetCantitate() const
{
	return m_cantitate;
}
void DetaliiComanda::SetCantitate(int cantitate)
{
	m_cantitate = cantitate;
}