#include "Jugador.h"
using std::stringstream;



Jugador::Jugador(std::string nombre) :nombre(nombre) {}

void Jugador::setNombre(std::string nombre)
{
	this->nombre = nombre;
}

std::string Jugador::getNombre()
{
	return this->nombre;
}

Jugador::~Jugador() {}

std::string Jugador::toString()
{
	stringstream s;
	s << "Nombre del jugador " << nombre << " Tiempo:" << getClock() << std::endl;
	return s.str();
}

void Jugador::setClock(double  inicio)
{
	inicio = tiempoTotal();
}

double Jugador::getClock()
{

	return tiempoTotal();
}

double Jugador::inicia()
{
	clock_t start = clock();
	return start;
}

double Jugador::finaliza()
{
	clock_t end = clock();
	return end;
}



double Jugador::tiempoTotal()
{

	double time = finaliza() - inicia() / (double)CLOCKS_PER_SEC;
	return time;
}
