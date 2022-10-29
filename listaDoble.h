#pragma once
#include "nodoDual.h"
ref class listaDoble
{
	nodoDual^ cabeza;
public:
	void InsertarNuevo(String^ valor);
	void InsertarNuevoEnPocision(String^ valor, int indice);
	int Buscar(String^ valor);
	bool Eliminar(String^ valor);
	String^ EliminarEnPosicion(int i);
	int dimension();
	String^ Ver(int i);
	void reemplazar(String^ valor, int i);
};

