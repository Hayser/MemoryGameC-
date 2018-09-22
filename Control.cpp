#include <Windows.h>
#include <sstream>
#include <iomanip>
#include "Control.h"
#include <time.h>
#include <ctime>
using std::cout;
using std::endl;
using std::cin;




Control::Control() {}

Control::~Control() {}

void Control::MenuPrincipal()
{
	srand(time(NULL));
	ListaCaracter *l1 = new ListaCaracter();//lista para Matriz de 4X4
	l1->insertarCaracteres('@');
	l1->insertarCaracteres('%');
	l1->insertarCaracteres('$');
	l1->insertarCaracteres('#');
	l1->insertarCaracteres('&');
	l1->insertarCaracteres('!');
	l1->insertarCaracteres('?');
	l1->insertarCaracteres('{');

	ListaCaracter *l2 = new ListaCaracter();//lista para Matriz de 4X5
	l2->insertarCaracteres('@');
	l2->insertarCaracteres('%');
	l2->insertarCaracteres('$');
	l2->insertarCaracteres('#');
	l2->insertarCaracteres('&');
	l2->insertarCaracteres('!');
	l2->insertarCaracteres('?');
	l2->insertarCaracteres('{');
	l2->insertarCaracteres('"');
	l2->insertarCaracteres('-');

	ListaCaracter *l3 = new ListaCaracter();//lista para Matriz de 4X6
	l3->insertarCaracteres('@');
	l3->insertarCaracteres('%');
	l3->insertarCaracteres('$');
	l3->insertarCaracteres('#');
	l3->insertarCaracteres('&');
	l3->insertarCaracteres('!');
	l3->insertarCaracteres('?');
	l3->insertarCaracteres('{');
	l3->insertarCaracteres('"');
	l3->insertarCaracteres('-');
	l3->insertarCaracteres('~');
	l3->insertarCaracteres('/');

	ListaJugador *j2 = new ListaJugador();//lista de Jugadores.

	double finaliza = 0;



	bool bandera = true;//variable que finaliza el Juego.

	int x = 0;
	int y = 0;
	char simbolo;
	int* aux;
	double final = 0;



	do {
		Memoria *m1 = new Memoria(4, 4);//creamos la Matriz y ingresamos la lista.
		for (int i = 0; i < 8; i++) {
			m1->insertarCaracteres(l1->get(i));
		}
		Memoria *m2 = new Memoria(4, 5);
		for (int i = 0; i < 10; i++) {
			m2->insertarCaracteres(l2->get(i));
		}
		Memoria *m3 = new Memoria(4, 6);

		for (int i = 0; i < 12; i++) {
			m3->insertarCaracteres(l3->get(i));
		}
		char opcion = 0;
		Jugador *j = new Jugador();//se crea un nuevo jugador;
		system("cls");
		Interfaz::menu();
		cin >> opcion;
		j->finaliza();
		j->inicia();//se inicia a contar el tiempo para el usuario
		switch (opcion)
		{
		case '1':
			j->setNombre(Interfaz::solicitaNombre());
			j2->insertar(j);

			while (!m1->gano()) {
				system("cls");
				//cout << m1->toString();
				cout << m1->imprimeCasilla();
				cout << "Ingrese Una Posicion Por favor" << endl;
				cin >> x;
				system("cls");
				//cout << m1->toString();
				cout << m1->imprimeCasilla();
				cout << "Ingrese otra Posicion Por favor" << endl;
				cin >> y;
				system("cls");
				aux = m1->get(x);
				if (aux != NULL)
					simbolo = (char)aux[2];
				else
					simbolo = '\0';
				if (m1->pareja(x, y)) {
					if (simbolo == 'X') {
						cout << "Esta pareja ya fue encontrada" << endl;
					}
					else {
						cout << "<------------------------------------------------------------->" << endl;
						cout << "Pareja encontrada: " << simbolo << "-" << simbolo << endl;
						cout << "<------------------------------------------------------------->" << endl;
						cout << endl << endl;
						system("pause");
					}

				}

				else {
					cout << "Vuelva a intentarlo" << endl;
					cout << endl;
					system("pause");
				}
			}
			final = j->tiempoTotal();
			j->getClock();
			system("cls");
			cout << endl;
			cout << "Felidades " << j->getNombre() << " has Ganado" << " Tiempo Total:" << final << endl;
			system("pause");
			system("cls");

			delete m1;
			if (j->getClock() < 120000 && j->getClock() < 240000) {
				cout << endl;
				cout << "Felicidades has pasado al Nivel Medio:" << endl;
				cout << "Pero seras capas de llegar al nivel Dificil" << endl;
				cout << endl << endl;
				system("pause");
				while (!m2->gano()) {
					system("cls");
					//cout << m2->toString();
					cout << m2->imprimeCasilla();
					cout << "Ingrese Una Posicion Por favor" << endl;
					cin >> x;
					system("cls");
					//cout << m2->toString();
					cout << m2->imprimeCasilla();
					cout << "Ingrese Una Posicion Por favor" << endl;
					cin >> y;
					system("cls");
					aux = m2->get(x);
					if (aux != NULL)
						simbolo = (char)aux[2];
					else
						simbolo = '\0';
					if (m2->pareja(x, y)) {
						if (simbolo == 'X') {
							cout << "Esta pareja ya fue encontrada" << endl;
						}
						else {
							cout << "<------------------------------------------------------------->" << endl;
							cout << "Pareja encontrada: " << simbolo << "-" << simbolo << endl;
							cout << "<------------------------------------------------------------->" << endl;
							cout << endl << endl;
							system("pause");
						}

					}

					else {
						cout << "Vuelva a intentarlo" << endl;
						cout << endl;
						system("pause");
					}
				}
				j->tiempoTotal();
				j->getClock();
				system("cls");
				final = j->tiempoTotal();
				cout << endl;
				cout << "Felicidades " << j->getNombre() << " has Ganado, Tiempo Total:" << j->finaliza() << endl;
				system("pause");
				//}
				delete m2;
				system("cls");
				//if (j->getClock() > 240000) {
					cout << "Felicidades has llegado al ultimo nivel" << endl;
					cout << "Seras capas de terminarlo" << endl;
					system("pause");
					while (!m3->gano()) {
						cout << "Felicidades has pasado al Nivel Dificil:" << endl;
						system("cls");
						//cout << m3->toString();
						cout << m3->imprimeCasilla();
						cout << "Ingrese Una Posicion Por favor" << endl;
						cin >> x;
						system("cls");
						//cout << m3->toString();
						cout << m3->imprimeCasilla();
						cout << "Ingrese Una Posicion Por favor" << endl;
						cin >> y;
						system("cls");
						aux = m3->get(x);
						if (aux != NULL)
							simbolo = (char)aux[2];
						else
							simbolo = '\0';
						if (m3->pareja(x, y)) {
							if (simbolo == 'X') {
								cout << "Esta pareja ya fue encontrada" << endl;
							}
							else {
								cout << "<------------------------------------------------------------->" << endl;
								cout << "Pareja encontrada: " << simbolo << "-" << simbolo << endl;
								cout << "<------------------------------------------------------------->" << endl;
								cout << endl << endl;
								system("pause");
							}

						}

						else {
							cout << "Vuelva a intentarlo" << endl;
							cout << endl;
							system("pause");
						}
					}
					j->tiempoTotal();
					system("cls");
					final = j->tiempoTotal();
					cout << endl;
					cout << "Felidades " << j->getNombre() << " Eres muy bueno en este juego, has terminado el nivel mas dificil, Tiempo Total:" << j->finaliza() << endl;
					system("pause");
				//}
				delete m3;
				j->finaliza();
			}
			break;
		case '2':
			system("cls");
			cout << "Lista de los Mejores Tiempos" << endl;
			cout << j2->toString() << endl;
			system("pause");
			break;
		case '3':
			system("cls");
			bandera = false;
			break;
		default:
			cout << "\n\t\t\tIngrese una opcion valida por favor:" << endl;
			Sleep(1500);
			break;
		}

	} while (bandera);
	delete l1;
	delete l2;
	delete l3;
	delete j2;
}
