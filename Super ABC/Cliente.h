#pragma once
#include "Pila.h"
class Cliente
{
public:
	Cliente();

	Cliente(char *nombre, int id);

	~Cliente();

	void setNombre(string nombre);
	
	void setId(int id);

	void addProducto(Producto p);

	Producto getProducto();

	Pila getProductos();

	void pop();

	int getId();

	char *getNombre();

	void toString();

private:
	Pila productos;
	char nombre[20];
	int id;
};

