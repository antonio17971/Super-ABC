#include "stdafx.h"
#include "Estante.h"


Estante::Estante() :
	estantes(list<Pila>())
{
}

Estante::~Estante()
{
}

void Estante::addProducto(Pila p)
{
	this->estantes.push_back(p);
}

void Estante::addProducto(Pila p, int pos)
{
	if (this->estantes.size() > pos)
	{
		list<Pila>::iterator it = this->estantes.begin();
		advance(it, pos);
		this->estantes.insert(it, p);
	}
	else if (estantes.empty())
	{
		addProducto(p);
	}
}

void Estante::addProducto(Producto p, int pos)
{
	if (this->estantes.size() > pos)
	{
		list<Pila>::iterator it = this->estantes.begin();
		advance(it, pos);
	 it._Ptr->_Myval.push(p);
	}
	else
	{
		this->producto(p);
	}
}

void Estante::producto(Producto p)
{
	Pila aux;
	aux.push(p);
	this->estantes.push_back(aux);
}

Pila Estante::getProducto(int p)
{
	if (this->estantes.size() > p)
	{
		list<Pila>::iterator it = this->estantes.begin();
		advance(it, p);
		return it._Ptr->_Myval;
	}
	return Pila();
}

void Estante::borrar(int p)
{
	if (this->estantes.size() > p)
	{
		list<Pila>::iterator it = this->estantes.begin();
		advance(it, p);
		this->estantes.erase(it);
	}
}

void Estante::toString()
{
	if (!this->estantes.empty())
	{
		for (int i = 0; i < this->estantes.size(); i++)
		{
			cout << "\tProducto No.\t" << i + 1 << ":\n\n";
			this->getProducto(i).toString();
			cout << "----------------------------------------\n\n";
		}
	}
}

void Estante::cambiarPosicion(int p1, int p2)
{
	if (p1 != p2 && p1 >= 0 && p2 >= 0 && this->estantes.size() > p1 && this->estantes.size() > p2)
	{
		Pila temp = this->getProducto(p1);
		list<Pila>::iterator it = this->estantes.begin();
		list<Pila>::iterator it2 = this->estantes.begin();
		advance(it, p1);
		advance(it2, p2);

		temp = it._Ptr->_Myval;
		it._Ptr->_Myval = it2._Ptr->_Myval;
		it2._Ptr->_Myval = temp;
	}
}

void Estante::pilaPop(int p)
{
	if (this->estantes.size() > p)
	{
		list<Pila>::iterator it = this->estantes.begin();
		advance(it, p);
		it._Ptr->_Myval.pop();
	}
}

list<Pila> Estante::getProductos()
{
	return this->estantes;
}
