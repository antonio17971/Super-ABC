#include "stdafx.h"
#include "SuperMercado.h"


SuperMercado::SuperMercado() :
	super(list<Pasillo>()), clientes(queue<Cliente>())
{
	for (int i = 0; i < 20; i++)
	{
		this->nombre[i] = '\0';
	}
	strcpy_s(this->nombre, sizeof(this->nombre), "Sin Nombre");
}

SuperMercado::SuperMercado(char * nombre) :
	super(list<Pasillo>()), clientes(queue<Cliente>())
{
	for (int i = 0; i < 20; i++)
	{
		this->nombre[i] = '\0';
	}
	this->setNombre(nombre);
}

SuperMercado::~SuperMercado()
{
}

void SuperMercado::addPasillo(Pasillo p)
{
	this->super.push_back(p);
}

void SuperMercado::addPasillo(Pasillo e, int p)
{
	if (this->super.size() > p)
	{
		list<Pasillo>::iterator it = this->super.begin();
		advance(it, p);
		this->super.insert(it, e);
	}
}

Pasillo SuperMercado::getPasillo(int p)
{
	if (this->super.size() > p)
	{
		list<Pasillo>::iterator it = this->super.begin();
		advance(it, p);
		return it._Ptr->_Myval;
	}
	return Pasillo();
}

list<Pasillo> SuperMercado::getPasillos()
{
	return this->super;
}

void SuperMercado::borrar(int p)
{
	if (this->super.size() > p)
	{
		list<Pasillo>::iterator it = this->super.begin();
		advance(it, p);
		this->super.erase(it);
	}
}

void SuperMercado::toString()
{
	if (!this->super.empty())
	{

		cout << "\t" << this->getNombre() << ".\n\n";
		for (int i = 0; i < this->super.size(); i++)
		{
			this->getPasillo(i).toString();
		}
	}
}

void SuperMercado::cambiarPosicion(int p1, int p2)
{
	if (p1 != p2 && p1 >= 0 && p2 >= 0 && this->super.size() > p1 && this->super.size() > p2)
	{
		Pasillo temp = this->getPasillo(p1);
		list<Pasillo>::iterator it = this->super.begin();
		list<Pasillo>::iterator it2 = this->super.begin();
		advance(it, p1);
		advance(it2, p2);

		temp = it._Ptr->_Myval;
		it._Ptr->_Myval = it2._Ptr->_Myval;
		it2._Ptr->_Myval = temp;
	}
}

void SuperMercado::setNombre(string nombre)
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

char * SuperMercado::getNombre()
{
	return this->nombre;
}

void SuperMercado::comprar(int pasillo, int estante, int producto)
{
	this->addProducto(this->getPasillo(pasillo).getEstante(estante).getProducto(producto).top());
	this->prodPop(pasillo, estante, producto);
}

void SuperMercado::addCliente(Cliente c)
{
	this->clientes.push(c);
}

Cliente SuperMercado::getCliente()
{
	return this->clientes.front();
}

queue<Cliente> SuperMercado::getClientes()
{
	return this->clientes;
}

void SuperMercado::prodPop(int p1, int p2, int p3)
{
	if (this->super.size() > p1)
	{
		list<Pasillo>::iterator it = this->super.begin();
		advance(it, p1);
		it._Ptr->_Myval.pop(p2, p3);
	}
}

void SuperMercado::addProducto(Producto p)
{
	this->clientes.front().addProducto(p);
}

void SuperMercado::insertarEstante(int pPasillo, int pEstante, Estante e)
{
	if (this->super.size() > pPasillo)
	{
		list<Pasillo>::iterator it = this->super.begin();
		advance(it, pPasillo);
		it._Ptr->_Myval.addEstante(e, pEstante);
	}
}

void SuperMercado::pushProducto(int pPasillo, int pEstante, int pPila, Producto p)
{
	if (this->super.size() > pPasillo)
	{
		list<Pasillo>::iterator it = this->super.begin();
		advance(it, pPasillo);
		it._Ptr->_Myval.pushProducto(pEstante, pPila, p);
	}
}

void SuperMercado::borrarEstante(int pPasillo, int pEstante)
{
	if (this->super.size() > pPasillo)
	{
		list<Pasillo>::iterator it = this->super.begin();
		advance(it, pPasillo);
		it._Ptr->_Myval.borrar(pEstante);
	}
}

void SuperMercado::borrarProducto(int pPasillo, int pEstante, int pProducto)
{
	if (this->super.size() > pPasillo)
	{
		list<Pasillo>::iterator it = this->super.begin();
		advance(it, pPasillo);
		it._Ptr->_Myval.borrarProducto(pEstante, pProducto);
	}
}

void SuperMercado::cambiarProductos(int pPasillo, int pEstante, int p1, int p2)
{
	if (this->super.size() > pPasillo)
	{
		list<Pasillo>::iterator it = this->super.begin();
		advance(it, pPasillo);
		it._Ptr->_Myval.cambiarProductos(pEstante, p1, p2);
	}
}

void SuperMercado::cambiarEstante(int pPasillo, int pEst1, int pEst2)
{
	if (this->super.size() > pPasillo)
	{
		list<Pasillo>::iterator it = this->super.begin();
		advance(it, pPasillo);
		it._Ptr->_Myval.cambiarPosicion(pEst1, pEst2);
	}
}

Estante SuperMercado::getEstante(int pEst1, int pPasillo)
{
	return getPasillo(pPasillo).getEstante(pPasillo);
}

Pila SuperMercado::getProducto(int pasillo, int estante, int pila)
{
	return getEstante(estante, pasillo).getProducto(pila);
}

void SuperMercado::popProCli()
{
	clientes.pop();
}

bool SuperMercado::colaCLIvacia()
{
	return clientes.empty();
}

void SuperMercado::popCLiProducto()
{
	clientes.front().pop();
}
