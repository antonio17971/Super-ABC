#pragma once
#include "SuperMercado.h"
#define __STDC_WANT_LIB_EXT1__ 1


#include"IO_Archivo.h"
class Menu
{
public:
	Menu();
	~Menu();
	void main();
	void usuarioFrecuente();
	void menuCompra();
	void menuAdmi();
	void agregar();
	void borrar();
	void mover();
	void setSuper(SuperMercado s);
	SuperMercado getSuper();

private:
	SuperMercado super;
};

