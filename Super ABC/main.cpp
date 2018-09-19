// SuperABC.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include "Menu.h"
#include"IO_Archivo.h"
int main()
{
	Menu menu;
	SuperMercado super("Romelio");
	Producto p1("Arroz", 11), p2("Frijoles", 12), p3("Papa", 21), p4("Yuca", 22), p5("Galletas", 31), p6("Biscocho", 32);
	Pila pila1, pila2, pila3, pila4;
	Estante e1, e2, e3;
	Pasillo pasillo1("Granos", 1), pasillo2("Verduras", 2), pasillo3("Snacks", 3);

	pila1.push(p1);
	pila1.push(p2);
	pila2.push(p3);
	pila2.push(p4);
	pila3.push(p5);
	pila4.push(p6);

	e1.addProducto(pila1);
	e1.addProducto(pila2);
	e2.addProducto(pila3);
	e3.addProducto(pila4);

	pasillo1.addEstante(e1);
	pasillo2.addEstante(e2);
	pasillo3.addEstante(e3);

	super.addPasillo(pasillo1);
	super.addPasillo(pasillo2);
	super.addPasillo(pasillo3);
	super.addCliente(Cliente("Adrian", 12345));
	//IO_Archivo::binaryWrtite(super);
	
	Cliente cm;
	cm.addProducto(p1);
	cm = IO_Archivo::readCliente();
	//cm.toString();
	super.addCliente(cm);// se agrega ala cila para tener una opccion mas en la cola 
	menu.setSuper(super);
	menu.main();
	

	return 0;
}

