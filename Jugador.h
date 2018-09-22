#ifndef JUGADOR_H
#define JUGADOR_H
#include <iostream>
#include <sstream>
#include <ctime>

class Jugador {
private:
	std::string nombre;

public:
	Jugador(std::string = "Usuario");
	void setNombre(std::string);
	std::string getNombre();
	~Jugador();
	std::string toString();
	void setClock(double);
	double getClock();
	double inicia();
	double finaliza();
	double tiempoTotal();

};
#endif
