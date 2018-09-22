#ifndef LISTAJUGADOR_H
#define LISTAJUGADOR_H
#include "NodoJugador.h"
#include <sstream>
class ListaJugador {
private:
	NodoJugador *inicio;
public:
	ListaJugador();
	~ListaJugador();
	void insertar(Jugador*);
	std::string toString();

};
#endif;
