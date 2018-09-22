#ifndef NODOJUGADOR_H
#define NODOJUGADOR_H
#include "Jugador.h"
class NodoJugador {
private:
	Jugador *j1;
	NodoJugador *sig;
public:
	NodoJugador();
	NodoJugador(Jugador*);
	void setJugador(Jugador*);
	void setSiguiente(NodoJugador*);
	Jugador*getJugador();
	NodoJugador*getSiguiente();
	~NodoJugador();
};
#endif
