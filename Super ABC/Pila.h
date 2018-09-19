#pragma once
#include "Producto.h"
class Pila
{
public:
	Pila();
	~Pila();

	void push(Producto p);
	void push(char *nombre, int id);
	void pop();
	Producto top();
	void toString();
	bool empty();
	stack<Producto> getProductos();

private:
	stack<Producto> productos;
};

