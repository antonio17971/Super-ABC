#include "stdafx.h"
#include "Cliente.h"


Cliente::Cliente():
	id(id), productos(Pila())
{
	for (int i = 0; i < 20; i++)
	{
		this->nombre[i] = '\0';
	}
	strcpy_s(this->nombre, sizeof(this->nombre), "Sin Nombre");
}

Cliente::Cliente(char * nombre, int id):
	id(id)
{
	for (int i = 0; i < 20; i++)
	{
		this->nombre[i] = '\0';
	}
	this->setNombre(nombre);
}

Cliente::~Cliente()
{
}

void Cliente::setNombre(string nombre)
{
	for (int i = 0; i < nombre.size(); i++)
	{
		this->nombre[i] = nombre.at(i);
		if (i == 19) i += nombre.size();
	}
	for (int i = nombre.size(); i < 20; i++)
	{
		this->nombre[i] = '\0';
	}
}

void Cliente::setId(int id)
{
	this->id = id;
}

void Cliente::addProducto(Producto p)
{
	this->productos.push(p);
}

Producto Cliente::getProducto()
{
	return this->productos.top();
}

Pila Cliente::getProductos()
{
	return this->productos;
}

void Cliente::pop()
{
	this->productos.pop();
}

int Cliente::getId()
{
	return this->id;
}

char * Cliente::getNombre()
{
	return this->nombre;
}

void Cliente::toString()
{
	cout << "Nombre:\t" << this->getNombre() << endl <<
		"Id:\t" << this->getId() << endl <<
		"Carrito de compras:\n";
	this->productos.toString();
}
