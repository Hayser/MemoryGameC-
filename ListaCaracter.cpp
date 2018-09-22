#include "ListaCaracter.h"
using std::stringstream;
using std::endl;

ListaCaracter::ListaCaracter()
{
	Inicio = NULL;
}


ListaCaracter::~ListaCaracter()
{
	NodoCaracter*aux = Inicio;
	while (aux != NULL) {
		Inicio = Inicio->getSiguiente();
		delete aux;
		aux = Inicio;
	}
}

void ListaCaracter::insertarCaracteres(char c)
{
	NodoCaracter *aux = new NodoCaracter(new char(c));
	aux->setSiguiente(Inicio);
	Inicio = aux;
}

std::string ListaCaracter::toString()
{
	NodoCaracter*aux = Inicio;
	stringstream s;
	while (aux != NULL) {
		s << *aux->getCaracter() << endl;
		aux = aux->getSiguiente();
	}
	return s.str();
}

char * ListaCaracter::get(int idx)
{
	int i = 0;
	NodoCaracter* aux = Inicio;
	while (i++ < idx && aux)
		aux = aux->getSiguiente();
	return (aux) ? aux->getCaracter() : NULL;
}
