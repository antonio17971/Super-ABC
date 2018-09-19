#include "stdafx.h"
#include "Producto.h"


Producto::Producto()
{
	this->setId(0);
	for (int i = 0; i < 20; i++)
	{
		this->nombre[i] = '\0';
	}
	strcpy_s(this->nombre, sizeof(this->nombre), "Sin Nombre");
}

Producto::Producto(char *nombre, int id)
{
	for (int i = 0; i < 20; i++)
	{
		this->nombre[i] = '\0';
	}
	this->setNombre(nombre);
	this->setId(id);
}

Producto::Producto(string nombre, int id):
	id(id)
{
	for (int i = 0; i < 20; i++)
	{
		this->nombre[i] = '\0';
	}
	this->setNombre(nombre);
}

Producto::~Producto()
{
}

char * Producto::getNombre()
{
	return this->nombre;
}

int Producto::getId()
{
	return this->id;
}

void Producto::setNombre(string nombre)
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

void Producto::setId(int id)
{
	this->id = id;
}

void Producto::toString()
{
	cout << "Nombre del producto:\t" << this->getNombre() << endl <<
		"Id del producto:\t" << this->getId() << endl;
}
