#include "ListaJugador.h"
using std::stringstream;



ListaJugador::ListaJugador()
{
	inicio = NULL;
}


ListaJugador::~ListaJugador() {}

void ListaJugador::insertar(Jugador *j)
{
	NodoJugador *aux = new NodoJugador(j);
	if (inicio == NULL)
		inicio = aux;
	else {
		aux->setSiguiente(inicio);
		inicio = aux;
	}

}


std::string ListaJugador::toString() {
	NodoJugador*aux = inicio;
	stringstream s;
	if (aux == NULL) {
		s << "No hay Jugadores Registrados:" << std::endl;
	}
	else {
		while (aux != NULL) {
			s << aux->getJugador()->toString() << std::endl;
			s << std::endl;
			aux = aux->getSiguiente();
		}
	}
	return s.str();
}
