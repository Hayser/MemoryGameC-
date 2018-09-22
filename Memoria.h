/*	Nombre del archivo:				Memoria.h
*	Información de la versión:		Se creó en CodeBlocks 16.01
*	Fecha:							Domingo, 25 de septiembre de 2016.
*	Autor:					    Hayser Dávila Abarca
*/
#ifndef MEMORIA_H
#define MEMORIA_H
#include "ListaCaracter.h"
#include <cstdlib>
#include <sstream>
using namespace std;


class Memoria {
private:
	int tam;
	int cant;
	int fil;
	int col;
	char ***memoria;
	int cont;
public:

	Memoria(int, int);
	int* get(int);
	void set(int, int, char);
	~Memoria();
	bool hayEspacio(int, int);
	char retornaCaracter(int, int);
	bool pareja(int, int);
	void insertarCaracteres(char*);
	void setMemoria(int, int, char);
	bool gano();
	void cuentaPareja();
	std::string toString();
	bool esIgual(Memoria&);
	std::string ImprimeMemoriaCaracteresEncontrados(int, int, char, char);
	std::string imprimeCasilla();

};
#endif
std::ostream& operator<<(std::ostream&, Memoria*);//sobrecargas
bool operator ==(Memoria&, Memoria&);
bool operator !=(Memoria&, Memoria&);
