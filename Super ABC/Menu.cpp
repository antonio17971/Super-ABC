#include "stdafx.h"
#include "Menu.h"


Menu::Menu() :
	super(SuperMercado())
{
}


Menu::~Menu()
{
}

void Menu::main()
{
	int var;
	cout << "BIENVENIDO\n" <<
		"Este es tu supermecado " << this->super.getNombre() << "\n" <<
		"Seleccione una opccion\n" <<
		"1-Usuario frecuente \n" <<
		"2-Comprar \n" <<
		"3-Administrador\n" <<
		"4-Salir\n";
	cin >> var;
	switch (var)
	{
	case 1:
		usuarioFrecuente();
		system("pause");
		system("cls");
		main();
		break;
	case 2:
		menuCompra();
		system("pause");
		system("cls");
		main();
		break;
	case 3:
		menuAdmi();
		system("pause");
		system("cls");
		main();
		break;
	case 4:
		return;
		break;
	default:
		main();
		break;
	}
}

void Menu::usuarioFrecuente()
{
	char t;
	int cont = 0;
	int a = 0, b = 0, e = 0, d = 0;
	Cliente c;
	c = IO_Archivo::readCliente();
	c.toString();
	cout << "Desea comprar lo mostrado anterior mente\n" << "Precione la letra Y\n";
	cin >> t;
	if (t == 'y' || t == 'Y')
	{
		for (Pasillo pasi : this->super.getPasillos())
		{
			for (Estante es : pasi.getEstantes())
			{
				for (Pila pil : es.getProductos())
				{
					if (c.getProducto().getId() == pil.top().getId())
					{
						super.comprar(a, b, e);

					}
					else
					{
						if(!pil.empty())
						super.comprar(a, b, 0);
					}
					c.pop();
					e++;

				}
				e = 0;
				b++;

			}
			b = 0;
			a++;
		}

	}
	cout << "Comprado \n";
	system("pause");
	system("cls");
}

void Menu::menuCompra()
{
	char var;
	int pasillo, estante, producto;
	cout << "A continuacion se mostrara la lista de los pasillos con si ID\n";
	super.toString();
	system("pause");
	cout << "\n Ingrese el # de pasillo donde esta el producto \n";
	cin >> pasillo;
	cout << "Ingrese el # de estante en el que este el producto\n";
	cin >> estante;
	cout << "Ingrese el # de posicion del produto\n ";
	cin >> producto;
	super.comprar(pasillo, estante, producto);
	cout << "producto comprado\n";
	system("cls");
	cout << "Desea comprar otro producto\n" <<
		"Precione la letra Y para continuar comprando\n";
	cin >> var;
	Sleep(2000);
	if (var == 'y' || var == 'Y')menuCompra();
	else return;
}

void Menu::menuAdmi()
{
	int id;
	Cliente c;
	char t;
	cout << "BIENVENIDO ADMINISTRADOR\n" <<
		"Seleccione la operacion a realizar\n" <<
		"1-Ir ala caja \n" <<
		"2-Agregar \n" <<
		"3-Borrar\n" <<
		"4-Mover\n" <<
		"5-Mostrar\n" <<
		"6-salir\n";
	cin >> id;
	switch (id)
	{
	case 1:
		cout << "El usuario desea pagar\n";
		while (!this->super.getClientes().empty())
		{
			cout << "Cliente:\t" << this->super.getCliente().getNombre() << "\nPaga:\n";
			while (!this->super.colaCLIvacia())
			{

				/*cout << this->super.getCliente().getProducto().getNombre() << endl <<
					this->super.getCliente().getProducto().getId() << endl << endl;
				super.popCLiProducto();*/
				super.getCliente().toString();
				this->super.popProCli();
			Sleep(2000);
			}
			cout << endl << endl;
			cout << "Hora y dia : ";


			/*struct tm tm = *localtime(&(time_t){time(NULL) });
			printf("%s", asctime(&tm));
		#ifdef __STDC_LIB_EXT1__
			char str[26];
			asctime_s(str, sizeof str, &tm);
			printf("%s", str);
		#endif*/

		}
		system("pause");
		system("cls");
		break;

	case 2:
		this->agregar();
		break;

	case 3:
		this->borrar();
		break;

	case 4:
		this->mover();
		break;

	case 5:
		this->super.toString();
		break;

	default:
		return;
	}
	menuAdmi();
}

void Menu::agregar()
{
	int opcion;
	int posicion;
	int estante;
	int num;
	string nombre;
	cout << "Que desea agregar?\n" <<
		"1- Pasillo.\n" <<
		"2- Estante.\n" <<
		"3- Producto.\n";
	cin >> opcion;
	switch (opcion)
	{
	case 1:
		this->super.toString();
		cout << "Ingrese el nombre del pasillo:\t";
		cin.ignore();
		getline(cin, nombre);
		cout << "Ingrese el numero del pasillo:\t";
		cin >> opcion;
		cout << "Ingrese la posicion del passillo:\t";
		cin >> posicion;
		this->super.addPasillo(Pasillo(nombre, opcion), posicion);
		cout << "Pasillo agregado.\n";
		break;

	case 2:
		this->super.toString();
		cout << "Ingrese numero del pasillo para insertar estante:\n";
		cin >> opcion;
		cout << "Ingrese la posicion:\t";
		cin >> posicion;
		this->super.insertarEstante(opcion, posicion, Estante());
		cout << "Estante insertado";
		break;

	case 3:
		this->super.toString();
		cout << "Ingrese el numero de pasillo para insertar producto:\n";
		cin >> opcion;
		cout << "Ingrese el numero del estante:\t";
		cin >> estante;
		cout << "Ingrese la posicion del producto:\t";
		cin >> num;
		cout << "Ingrese el ID del producto:\t";
		cin >> posicion;
		cout << "Ingrese el nombre del Producto:\t";
		cin.ignore();
		getline(cin, nombre);
		this->super.pushProducto(opcion, estante, num, Producto(nombre, posicion));
		cout << "Producto insertado\n";
		break;

	default:
		break;
	}
	cout << endl;
	system("pause");
	system("cls");
}

void Menu::borrar()
{
	int opcion;
	int posicion;
	int estante;
	int num;
	string nombre;
	cout << "Que desea borrar?\n" <<
		"1- Pasillo.\n" <<
		"2- Estante.\n" <<
		"3- Producto.\n";
	cin >> opcion;
	switch (opcion)
	{
	case 1:
		this->super.toString();
		cout << "Ingrese la posicion del passillo:\t";
		cin >> posicion;
		this->super.borrar(posicion);
		cout << "Pasillo borrado.\n";
		break;

	case 2:
		this->super.toString();
		cout << "Ingrese numero del pasillo para borrar estante:\n";
		cin >> opcion;
		cout << "Ingrese la posicion del estante:\t";
		cin >> posicion;
		this->super.borrarEstante(opcion, posicion);
		cout << "Estante insertado";
		break;

	case 3:
		this->super.toString();
		cout << "Ingrese el numero de pasillo para eliminar producto:\n";
		cin >> opcion;
		cout << "Ingrese el numero del estante:\t";
		cin >> estante;
		cout << "Ingrese la posicion del producto:\t";
		cin >> num;
		this->super.borrarProducto(opcion, estante, num);
		cout << "Producto insertado\n";
		break;

	default:
		break;
	}
	cout << endl;
	system("pause");
	system("cls");
}

void Menu::mover()
{
	int opcion;
	int posicion;
	int estante;
	int num;
	string nombre;
	cout << "Que desea mover?\n" <<
		"1- Pasillo.\n" <<
		"2- Estante.\n" <<
		"3- Producto.\n";
	cin >> opcion;
	switch (opcion)
	{
	case 1:
		this->super.toString();
		cout << "Ingrese el numero del primer pasillo:\t";
		cin >> opcion;
		cout << "Ingrese la posicion del segundo passillo:\t";
		cin >> posicion;
		this->super.cambiarPosicion(opcion, posicion);
		cout << "Pasillos movido.\n";
		break;

	case 2:
		this->super.toString();
		cout << "Ingrese la posicion del pasillo:\t";
		cin >> num;
		cout << "Ingrese la posicion 1:\n";
		cin >> opcion;
		cout << "Ingrese la posicion 2:\t";
		cin >> posicion;
		this->super.cambiarEstante(num, opcion, posicion);
		cout << "Estantes movido";
		break;

	case 3:
		this->super.toString();
		cout << "Ingrese el numero de pasillo:\n";
		cin >> opcion;
		cout << "Ingrese el numero del estante:\t";
		cin >> estante;
		cout << "Ingrese la posicion del producto 1:\t";
		cin >> num;
		cout << "Ingrese la posicion del producto 2:\t";
		cin >> posicion;
		this->super.cambiarProductos(opcion, estante, num, posicion);
		cout << "Productos movido\n";
		break;

	default:
		break;
	}
	cout << endl;
	system("pause");
	system("cls");
}

void Menu::setSuper(SuperMercado s)
{
	this->super = s;
}

SuperMercado Menu::getSuper()
{
	return this->super;
}
