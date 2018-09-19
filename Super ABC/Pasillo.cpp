#include "stdafx.h"
#include "Pasillo.h"


Pasillo::Pasillo() :
	pasillos(list<Estante>()), numero(0)
{
	for (int i = 0; i < 20; i++)
	{
		this->nombre[i] = '\0';
	}
	strcpy_s(this->nombre, sizeof(this->nombre), "Sin Nombre");
}

Pasillo::Pasillo(char * nombre, int id) :
	pasillos(list<Estante>()), numero(id)
{
	for (int i = 0; i < 20; i++)
	{
		this->nombre[i] = '\0';
	}
	this->setNombre(nombre);
}

Pasillo::Pasillo(string n, int id) :
	numero(id)
{
	for (int i = 0; i < 20; i++)
	{
		this->nombre[i] = '\0';
	}
	this->setNombre(n);
}

Pasillo::~Pasillo()
{
}

void Pasillo::addEstante(Estante e)
{
	this->pasillos.push_back(e);
}

void Pasillo::addEstante(Estante e, int p)
{
	if (this->pasillos.size() > p)
	{
		list<Estante>::iterator it = this->pasillos.begin();
		advance(it, p);
		this->pasillos.insert(it, e);
	}
	else if(this->pasillos.empty())
	{
		this->pasillos.push_back(e);
	}
}

Estante Pasillo::getEstante(int p)
{
	if (this->pasillos.size() > p)
	{
		list<Estante>::iterator it = this->pasillos.begin();
		advance(it, p);
		return it._Ptr->_Myval;
	}
	return Estante();
}

list<Estante> Pasillo::getEstantes()
{
	return this->pasillos;
}

void Pasillo::borrar(int p)
{
	if (this->pasillos.size() > p)
	{
		list<Estante>::iterator it = this->pasillos.begin();
		advance(it, p);
		this->pasillos.erase(it);
	}
}

void Pasillo::toString()
{
	cout << "\nNombre:\t" << this->getNombre() << ".\n";
	cout << "Pasillo No.\t" << this->getNumero() << ".\n\n";
	if (!this->pasillos.empty())
	{
		for (int i = 0; i < this->pasillos.size(); i++)
		{
			cout << "Estante No.\t" << i + 1 << ":\n\n";
			this->getEstante(i).toString();
		}
	}
	else
	{
		cout << "Pasillo vacio \n";
	}
	cout << "----------------------------------------\n";

}

void Pasillo::cambiarPosicion(int p1, int p2)
{
	if (p1 != p2 && p1 >= 0 && p2 >= 0 && this->pasillos.size() > p1 && this->pasillos.size() > p2)
	{
		Estante temp = this->getEstante(p1);
		list<Estante>::iterator it = this->pasillos.begin();
		list<Estante>::iterator it2 = this->pasillos.begin();
		advance(it, p1);
		advance(it2, p2);

		temp = it._Ptr->_Myval;
		it._Ptr->_Myval = it2._Ptr->_Myval;
		it2._Ptr->_Myval = temp;
	}
}

void Pasillo::setNombre(string nombre)
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

void Pasillo::setNumero(int numero)
{
	this->numero = numero;
}

int Pasillo::getNumero()
{
	return this->numero;
}

char * Pasillo::getNombre()
{
	return this->nombre;
}

void Pasillo::pop(int p1, int p2)
{
	if (this->pasillos.size() > p1)
	{
		list<Estante>::iterator it = this->pasillos.begin();
		advance(it, p1);
		it._Ptr->_Myval.pilaPop(p2);
	}
}

void Pasillo::pushProducto(int pEstante, int pProducto, Producto p)
{
	if (this->pasillos.size() > pEstante)
	{
		list<Estante>::iterator it = this->pasillos.begin();
		advance(it, pEstante);
		it._Ptr->_Myval.addProducto(p, pProducto);
	}
}

void Pasillo::borrarProducto(int pPasillo, int pEstante)
{
	if (this->pasillos.size() > pPasillo)
	{
		list<Estante>::iterator it = this->pasillos.begin();
		advance(it, pPasillo);
		it._Ptr->_Myval.borrar(pEstante);
	}
}

void Pasillo::cambiarProductos(int pPasillo, int pEstante1, int pEstante2)
{
	if (this->pasillos.size() > pPasillo)
	{
		list<Estante>::iterator it = this->pasillos.begin();
		advance(it, pPasillo);
		it._Ptr->_Myval.cambiarPosicion(pEstante1, pEstante2);
	}
}
