#pragma once
#include "tuplu_id.h"
class DetaliiComanda {
private:
	TupluComandaAlbum m_id_detalii_comanda;
	int m_cantitate;
public:
	DetaliiComanda(int id_comanda, int id_album, int cantitate);
	TupluComandaAlbum GetIdDetaliiComanda() const;
	int GetIdComanda() const;
	int GetIdAlbum() const;
	int GetCantitate() const;
	void SetCantitate(int cantitate);

};