#ifndef INTERFAZ_H
#define INTERFAZ_H
#include <iostream>
#include <string>

class Interfaz {
public:
	Interfaz();
	~Interfaz();
	static void menu();
	static std::string solicitaNombre();
};
#endif
