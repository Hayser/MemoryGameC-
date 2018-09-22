/*	Nombre del archivo:				main.cpp
*	Información de la versión:		Se creó en CodeBlocks 16.01
*	Fecha:							Domingo, 25 de septiembre de 2016.
*	Autores:					    Hayser Dávila Abarca, Boris Mendez Acuña
*/
#include "Control.h"



int main()
{
    Control *c = new Control();
	c->MenuPrincipal();
	delete c;
}
