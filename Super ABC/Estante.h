#pragma once
#include "Pila.h"
class Estante
{
public:
	Estante();
	~Estante();

	void addProducto(Pila p);
	void addProducto(Pila p, int pos);
	void addProducto(Producto p, int pos);
	void producto(Producto p);
	Pila getProducto(int p);
	void borrar(int p);
	void toString();
	void cambiarPosicion(int p1, int p2);
	void pilaPop(int p);
	list<Pila> getProductos();

private:
	list<Pila>estantes;
};

