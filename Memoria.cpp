#include "Memoria.h"


Memoria::Memoria(int f = 4, int c = 4)
{
	cant = 0;
	fil = f;
	col = c;
	tam = f * c;
	cont = 0;
	memoria = new char**[fil];
	for (int i = 0; i<fil; i++) {
		memoria[i] = new char*[col];
		for (int j = 0; j<col; j++)
			memoria[i][j] = NULL;
	}
}

Memoria::~Memoria()
{
	for (int i = 0; i<fil; i++) {
		for (int j = 0; j<col; j++)
			delete memoria[i][j];
		delete[] memoria[i];
	}
	delete[] memoria;
}

bool Memoria::hayEspacio(int i, int j)
{

	return memoria[i][j] == NULL;
}


char Memoria::retornaCaracter(int i, int j)
{
	return *memoria[i][j];
}

int* Memoria::get(int pos)//metodo para ingresar una posicion ejemplo 1,15,24.
{
	if (pos > 0 && pos <= tam) {
		for (int i = 1; i <= this->fil; i++) {
			int ultimo = (i * this->col);
			if (pos < ultimo) {
				int actual = ultimo - (this->col);
				for (int j = 1; j <= this->col; j++) {
					if (pos == actual + j)
						return new int[3]{ i - 1, j - 1,*this->memoria[i - 1][j - 1] };
				}
			}

			if (pos == ultimo)
				return new int[3]{ i - 1, this->col - 1,*this->memoria[i - 1][this->col - 1] };
		}
	}
	return NULL;
}

void Memoria::set(int i, int j, char v)
{
	delete this->memoria[i][j];
	this->memoria[i][j] = new char(v);
}

bool Memoria::pareja(int w, int p) {//busca la parejas.
	int* a = get(w);
	int* b = get(p);
	if (a != NULL && b != NULL && a[2] == b[2]) {
		this->set(a[0], a[1], 'X');
		this->set(b[0], b[1], 'X');
		this->cuentaPareja();
		return true;
	}
	return false;
}


void Memoria::insertarCaracteres(char *l1)
{
	if (cant < tam) {
		for (int i = 0; i < 2; i++) {
			int f = { rand() % fil };
			int c = { rand() % col };
			if (memoria[f][c] == NULL) {
				memoria[f][c] = new char(*l1);
				cant++;
			}
			else {
				i--;
				continue;
			}
		}
	}
}

void Memoria::setMemoria(int x, int y, char c)
{
	*memoria[x][y] = c;
}

bool Memoria::gano()//Este metodo nos indica si fueron encontradas todas las parejas.
{
	return cont >= tam / 2;
}

void Memoria::cuentaPareja()
{
	this->cont++;
}

std::string Memoria::toString()//Imprime los Caracteres dentro de la matriz.
{
	std::stringstream s;
	for (int i = 0; i< fil; i++) {
		for (int j = 0; j< col; j++)
			s << "|" << *memoria[i][j] << "|" << " ";
		s << std::endl;
	}
	s << std::endl;
	return s.str();
}

bool Memoria::esIgual(Memoria &m2)
{
	for (int i = 0; i < fil; i++) {
		for (int j = 0; j < col; j++)

			return (Memoria::pareja(i, j) == m2.pareja(i, j));
	}
}


std::string Memoria::ImprimeMemoriaCaracteresEncontrados(int x, int y, char c, char h)
{

	std::stringstream s;
	if (pareja(c, h)) {
		*memoria[x][y] = c;
		*memoria[x][y] = h;
		s << imprimeCasilla();
	}
	else {
		s << imprimeCasilla();
	}
	return s.str();
}



std::string Memoria::imprimeCasilla() {
	std::stringstream s;
	s << "Posiciones del juego Memoria" << std::endl;
	for (int i = 0; i < this->fil; i++) {
		for (int j = 1; j <= this->col; j++) {
			int pos = (i * this->col) + j;
			s << "| ";
			if (*this->memoria[i][j - 1] != 'X') {
				if (pos < 10)
					s << " " << pos;
				else
					s << pos;
			}
			else {
				s << " X";
			}

			s << " | ";
		}
		s << std::endl;
	}
	s << std::endl;
	return s.str();

}

////////////*SOBRECARGA DE OPERADORES*///////////////////


std::ostream & operator<<(std::ostream &salida, Memoria *n)
{
	salida << n->toString();
	return salida;
}

bool operator==(Memoria &m1, Memoria &m2)
{
	Memoria m3(m1);
	return m3.esIgual(m2);
}

bool operator!=(Memoria &m1, Memoria &m2)
{
	return !(m1 == m2);
}
