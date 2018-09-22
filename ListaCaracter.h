#ifndef LISTACARACTER_H
#define LISTACARACTER_H
#include "NodoCaracter.h"
class ListaCaracter {
private:
	NodoCaracter* Inicio;
public:
	ListaCaracter();
	~ListaCaracter();
	void insertarCaracteres(char);
	std::string toString();
	char* get(int);

};
#endif
