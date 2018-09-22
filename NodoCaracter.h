#ifndef NODOCARACTER_H
#define NODOCARACTER_H
#include <iostream>
#include <sstream>
class NodoCaracter {
private:
	char *c;
	NodoCaracter *sig;
public:
	NodoCaracter();
	NodoCaracter(char*);
	void setCaracter(char*);
	void setSiguiente(NodoCaracter*);
	char* getCaracter();
	NodoCaracter* getSiguiente();
	~NodoCaracter();

};
#endif


