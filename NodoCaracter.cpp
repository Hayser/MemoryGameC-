#include "NodoCaracter.h"



NodoCaracter::NodoCaracter()
{
	c = new char('\0');
	sig = NULL;
}

NodoCaracter::NodoCaracter(char *c)
{
	this->c = c;
	this->sig = NULL;
}

void NodoCaracter::setCaracter(char * c)
{
	this->c = c;
}

void NodoCaracter::setSiguiente(NodoCaracter *sig)
{
	this->sig = sig;
}

char * NodoCaracter::getCaracter()
{
	return c;
}

NodoCaracter * NodoCaracter::getSiguiente()
{
	return sig;
}


NodoCaracter::~NodoCaracter()
{
	delete c;
}
