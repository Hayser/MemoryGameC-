/*	Nombre del archivo:				main.cpp
*	Informaci�n de la versi�n:		Se cre� en CodeBlocks 16.01
*	Fecha:							Domingo, 25 de septiembre de 2016.
*	Autores:					    Hayser D�vila Abarca, Boris Mendez Acu�a
*/
#include "Control.h"



int main()
{
    Control *c = new Control();
	c->MenuPrincipal();
	delete c;
}
