#include "Interfaz.h"
#include <Windows.h>
using std::cout;
using std::cin;
using std::endl;



Interfaz::Interfaz() {}

Interfaz::~Interfaz() {}


void Interfaz::menu()
{
	std::string titulo = " BIENVENIDO AL JUEGO DE MEMORIA:";
	cout << "\n\n\n\t\t\t";
	for (size_t i = 0; i < titulo.length(); i++) {
		cout << titulo[i];
		Sleep(40);
	}
	cout << "\n\t\t\t***************************************";
	cout << "\n\t\t\t*         MENU PRINCIPAL              *";
	cout << "\n\t\t\t*                                     *";
	cout << "\n\t\t\t*         Opcion 1:JUGAR              *";
	cout << "\n\t\t\t*                                     *";
	cout << "\n\t\t\t*         Opcion 2:VER PUNTAJES       *";
	cout << "\n\t\t\t*                                     *";
	cout << "\n\t\t\t*         Opcion 3:SALIR              *";
	cout << "\n\t\t\t***************************************";
	cout << "\n";
	cout << "\n\t\t\t\t Digite un Opcion:" << endl;
	cout << "\n\t\t\t\t\t";
}

std::string Interfaz::solicitaNombre()
{
	system("cls");
	std::string nom;
	cout << "Ingrese su nombre Por favor:" << endl;
	cin >> nom;
	cin.clear();
	return nom;
}
