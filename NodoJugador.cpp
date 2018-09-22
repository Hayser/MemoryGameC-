#include "NodoJugador.h"



NodoJugador::NodoJugador()
{
	j1 = new Jugador(*j1);
	sig = NULL;

}

NodoJugador::NodoJugador(Jugador *j1)
{
	this->j1 = j1;
	sig = NULL;

}

void NodoJugador::setJugador(Jugador *j1)
{
	this->j1 = j1;
}

void NodoJugador::setSiguiente(NodoJugador *sig)
{
	this->sig = sig;
}

Jugador * NodoJugador::getJugador()
{
	return j1;
}

NodoJugador * NodoJugador::getSiguiente()
{
	return sig;
}


NodoJugador::~NodoJugador()
{
	delete j1;
	delete sig;

}
