#pragma once
#include<iostream>
#include <cstdlib>
#include <cstdio>
#include "service.h"
void Pause();
void ClearScreen();
void ShowMainMenu();
void ShowCatalog();
void ShowAlbum();
void ShowArtisti();
void ShowGenuriMuzicale();
void ShowCaseDeDiscuri();
void ShowClienti();
void ShowComenzi();
void ShowAdreseClient();
void GestiuneCatalog(Service& service);
void GestiuneAlbum(Service& service);
void GestiuneArtisti(Service& service);
void GestiuneGenuriMuzicale(Service& service);
void GestiuneCaseDeDiscuri(Service& service);
void GestiuneComenzi(Service& service);
void GestiuneAdreseClient(Service& service, int id_client);
void GestiuneClienti(Service& service);
void RunUI(Service& service);
