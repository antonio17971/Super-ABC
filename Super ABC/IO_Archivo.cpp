#include "stdafx.h"
#include "IO_Archivo.h"


IO_Archivo::IO_Archivo()
{
}

IO_Archivo::~IO_Archivo()
{
}
//
//SuperMercado IO_Archivo::read()
//{
//	int con=0;
//	string line = "";
//	SuperMercado super;
//	Pasillo pasillo;
//	Estante estante;
//	Pila pila;
//	Producto producto;
//	int pos1 = 0, pos2 = 0;
//	ifstream archivo(NOM_ARCHIVO);
//	if (archivo.is_open() && archivo)
//	{
//		while (!archivo.eof() || line != "</SuperMerdaco>")
//		{
//			getline(archivo, line);
//			pos1 = archivo.tellg();
//			if (line == "<nombre>")
//			{
//
//			}
//		}
//	}
//	else
//	{
//		cout << "Archivo dañado.\n";
//	}
//
//	return SuperMercado();
//}
//
//void IO_Archivo::write(SuperMercado super)
//{
//	ofstream archivo(NOM_ARCHIVO);
//	if (archivo.is_open() && archivo.good())
//	{
//		archivo << "<SuperMercado>\n";
//
//		archivo << "<nombre>\n";
//		archivo << super.getNombre() << endl;
//		archivo << "</nombre>\n";
//
//		for (Pasillo pasillo : super.getPasillos())
//		{
//			archivo << "<pasillo>\n";
//
//			archivo << "<nombre>\n";
//			archivo << pasillo.getNombre() << endl;
//			archivo << "</nombre>\n";
//
//			archivo << "<numero>\n";
//			archivo << pasillo.getNumero() << endl;
//			archivo << "</numero>\n";
//
//			for (Estante estante : pasillo.getEstantes())
//			{
//				archivo << "<estante>\n";
//
//				for (Pila pila : estante.getProductos())
//				{
//					archivo << "<pila>\n";
//
//					while (!pila.getProductos().empty())
//					{
//						archivo << "<producto>\n";
//
//						archivo << "<nombre>\n";
//						archivo << pila.top().getNombre() << endl;
//						archivo << "</nombre>\n";
//
//						archivo << "<id>\n";
//						archivo << pila.top().getId() << endl;
//						archivo << "</id>\n";
//
//						pila.pop();
//
//						archivo << "</producto>\n";
//					}
//
//					archivo << "</pila>\n";
//				}
//
//				archivo << "</estante>\n";
//			}
//
//			archivo << "</pasillo>\n";
//		}
//
//		archivo << "</SuperMercado>";
//		archivo.close();
//	}
//	else
//	{
//		cout << "No se pudo cargar el archivo.\n";
//	}
//}

void IO_Archivo::writeCliente(Cliente super)
{
	ofstream cl("Cliente.txt");
	cl << super.getNombre() << endl;
	cl << super.getId() << endl;

	while (!super.getProductos().empty())
	{
		cl << super.getProducto().getNombre() << endl;
		cl << super.getProducto().getId() << endl;
		super.pop();

	}
	cl.close();
}

Cliente IO_Archivo::readCliente()
{
	int cont = 0;
	string linea;
	Cliente c;
	Pila  p;
	Producto pro;
	ifstream cl("Cliente.txt");

	if (cl.is_open() && cl.good())
	{
		while (!cl.eof())
		{
			if(cont<2){
			if (c.getNombre() !=nullptr&&cont!=1)
			{
				getline(cl, linea);
				c.setNombre(linea);
			}
			else {
				getline(cl, linea);
				c.setId(atoi(linea.c_str()));
			}
			cont++;
			}
			else 
			{
				if (pro.getNombre() !=nullptr&&cont!=3)
				{
					getline(cl, linea);
					pro.setNombre(linea);
				}
				else {
					getline(cl, linea);
					pro.setId(atoi(linea.c_str()));
					 }
				cont++;
				if (cont == 4)
				{
					c.addProducto(pro);
					pro.setNombre("Sin Nombre") ;
					cont = 2;
				}
			}
			

		}
	}

	return c;
}
