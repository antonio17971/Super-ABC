#pragma once
#include "SuperMercado.h"
#include <cstdlib>
#define NOM_ARCHIVO "super.txt"
#include<fstream>
class IO_Archivo
{
public:
	IO_Archivo();
	~IO_Archivo();

	static SuperMercado read();
	static void write(SuperMercado super);

	static void writeCliente(Cliente super);
	static Cliente readCliente();
};

