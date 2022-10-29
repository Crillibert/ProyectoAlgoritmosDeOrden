#include "listaDoble.h"
void listaDoble::InsertarNuevo(String^ valor)
{
	//agregar un dato a la lista y mover referencias de anterior y siguiente
	nodoDual^ nuevo = gcnew nodoDual();
	nuevo->Valor = valor;
	if (cabeza == nullptr)
	{
		cabeza = nuevo;
		cabeza->Anterior = nuevo;
	}
	else
	{
		nodoDual^ NodoActual = cabeza;
		while (NodoActual->Siguiente != nullptr)
		{
			NodoActual = NodoActual->Siguiente;
		}
		NodoActual->Siguiente = nuevo;
		nuevo->Anterior = NodoActual;
	}
}
void listaDoble::InsertarNuevoEnPocision(String^ valor, int indice)
{
	//lo mismo que antes, añade un dato a la lista en el lugar indicado y revisa en que posicion se esta introduciendo
	if (indice == 0)
	{
		InsertarNuevo(valor);
	}
	else
	{
		nodoDual^ nuevo = gcnew nodoDual();
		nuevo->Valor = valor;
		int LugarActual = 0;
		nodoDual^ nodoActual = cabeza;
		while (LugarActual < indice)
		{
			nodoActual = nodoActual->Siguiente;
			LugarActual++;
		}
		nuevo->Siguiente = nodoActual;
		nodoActual->Anterior->Siguiente = nuevo;
		nuevo->Anterior = nodoActual->Anterior;
		if (nuevo->Siguiente != nullptr)
		{
			nuevo->Siguiente->Anterior = nuevo;
		}
	}
}
int listaDoble::Buscar(String^ valor)
{
	//buscar un dato basado en su indice
	int counter = 0;
	for (nodoDual^ indice = cabeza; indice != nullptr; indice = indice->Siguiente)
	{
		if (indice->Valor == valor)
		{
			return counter;
		}
		counter++;
	}
	return -1;
}
bool listaDoble::Eliminar(String^ valor)
{
	//quita el valor indicato basado en su nombre
	nodoDual^ Actual = cabeza;
	int indice = Buscar(valor);
	if (indice == -1)
	{
		return false;
	}
	else if (indice == 0)
	{
		Actual = cabeza;
		cabeza->Siguiente->Anterior = nullptr;
		cabeza = cabeza->Siguiente;
	}
	else
	{
		for (int i = 0; i < indice; i++)
		{
			Actual = Actual->Siguiente;
		}
		Actual->Anterior->Siguiente = Actual->Siguiente;
		Actual->Siguiente->Anterior = Actual->Anterior;
	}
	delete(Actual);
	return true;
}
String^ listaDoble::EliminarEnPosicion(int i)
{
	//nodoDual^ indice = cabeza; indice != nullptr; indice = indice->Siguiente
	String^ resultado = "";
	nodoDual^ indice = cabeza;
	int cantidad = listaDoble::dimension();
	for (int j =0; j<cantidad;j++)
	{
		if (j == i)
		{
			resultado = indice->Valor;
			if (j == 0)
			{
				indice = cabeza;
				if (cabeza->Siguiente != nullptr)
				{
					cabeza->Siguiente->Anterior = nullptr;
					cabeza = cabeza->Siguiente;
				}
				else
				{
					cabeza = nullptr;
				}
			}
			else
			{
				if (indice->Anterior != nullptr)
				{
					indice->Anterior->Siguiente = indice->Siguiente;
				}
				if (indice->Siguiente != nullptr)
				{
					indice->Siguiente->Anterior = indice->Anterior;
				}
			}
			return resultado;
		}
		else
		{
			indice = indice->Siguiente;
		}
	}
	return resultado;
}
int listaDoble::dimension()
{
	int Cantidad = 0;
	for (nodoDual^ i = cabeza; i != nullptr; i = i->Siguiente)
	{
		Cantidad++;
	}
	return Cantidad;
}
String^ listaDoble::Ver(int j)
{
	int Cantidad = 0;
	String^ resultado = "";
	for (nodoDual^ i = cabeza; i != nullptr; i = i->Siguiente)
	{
		if (Cantidad == j)
		{
			resultado = i->Valor;
		}
		Cantidad++;
	}
	return resultado;
}
void listaDoble::reemplazar(String^ valor, int j)
{
	int Cantidad = 0;
	for (nodoDual^ i = cabeza; i != nullptr; i = i->Siguiente)
	{
		if (Cantidad == j)
		{
			i->Valor = valor;
		}
		Cantidad++;
	}
}