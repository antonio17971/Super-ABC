#pragma once
#include "Pasillo.h"
#include "Cliente.h"
class SuperMercado
{
public:
	SuperMercado();

	SuperMercado(char *nombre);

	~SuperMercado();

	void addPasillo(Pasillo p);
	void addPasillo(Pasillo e, int p);
	Pasillo getPasillo(int p);
	list<Pasillo> getPasillos();
	void borrar(int p);
	void toString();
	void cambiarPosicion(int p1, int p2);
	void setNombre(string nombre);
	char *getNombre();
	void comprar(int pasillo, int estante, int producto);
	void addCliente(Cliente c);
	Cliente getCliente();
	queue<Cliente> getClientes();
	void prodPop(int p1, int p2, int p3);
	void addProducto(Producto p);
	void insertarEstante(int pPasillo, int pEstante, Estante e);
	void pushProducto(int pPasillo, int pEstante, int pPila, Producto p);
	void borrarEstante(int pPasillo, int pEstante);
	void borrarProducto(int pPasillo, int pEstante, int pProducto);
	void cambiarProductos(int pPasillo, int pEstante, int p1, int p2);
	void cambiarEstante(int pPasillo, int pEst1, int pEst2);

	//gets
	Estante getEstante(int ,int);
	Pila getProducto(int, int, int);


	//clientes cola
	void popProCli();
	bool colaCLIvacia();
	void popCLiProducto();



private:
	char nombre[20];
	list<Pasillo> super;
	queue<Cliente> clientes;
};