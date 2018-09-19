#pragma once
class Producto
{
public:
	Producto();
	Producto(char *nombre, int id);
	Producto(string nombre, int id);
	~Producto();

	char *getNombre();
	int getId();

	void setNombre(string nombre);
	void setId(int id);


	void toString();

private:
	int id;
	char nombre[20];
};

