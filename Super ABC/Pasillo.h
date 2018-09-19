#pragma once
#include "Estante.h"
class Pasillo
{
public:
	Pasillo();

	Pasillo(char *nombre, int id);

	Pasillo(string n, int id);

	~Pasillo();

	void addEstante(Estante e);
	void addEstante(Estante e, int p);
	Estante getEstante(int p);
	list<Estante> getEstantes();
	void borrar(int p);
	void toString();
	void cambiarPosicion(int p1, int p2);
	void setNombre(string nombre);
	void setNumero(int numero);
	int getNumero();
	char *getNombre();
	void pop(int p1, int p2);
	void pushProducto(int pEstante, int pPdorcuto, Producto p);
	void borrarProducto(int pPasillo, int pEstante);
	void cambiarProductos(int pPasillo, int pEstante1, int pEstante2);

private:
	list<Estante> pasillos;
	char nombre[20];
	int numero;
};

