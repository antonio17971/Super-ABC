#include "stdafx.h"
#include "Pila.h"


Pila::Pila() :
	productos(stack<Producto>())
{
}

Pila::~Pila()
{
	while (!this->productos.empty())
	{
		this->productos.pop();
	}
}

void Pila::push(Producto p)
{
	this->productos.push(p);
}

void Pila::push(char *nombre, int id)
{
	this->productos.push(Producto(nombre, id));
}

void Pila::pop()
{
	this->productos.pop();
}

Producto Pila::top()
{
	return this->productos.top();
}

void Pila::toString()
{
	stack<Producto> aux = this->productos;
	while (!aux.empty())
	{
		aux.top().toString();
		aux.pop();
	}
}

bool Pila::empty()
{
	return this->productos.empty();
}

stack<Producto> Pila::getProductos()
{
	return this->productos;
}
