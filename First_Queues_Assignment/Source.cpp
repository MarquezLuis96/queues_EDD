/**/

//HEADERS
#include <iostream>
const int TAM = 50;

//DECLARACI[ON DE NOMBRES DE ESPACIO
using namespace std;

template <class dataType>
class Cola {
	private:
		int primero;
		int ultimo;
		dataType arregloCola[TAM];

	public:
		Cola() {
			primero = 0;
			ultimo = -1;
		}

		bool colaLlena() {
			if (ultimo == TAM - 1) {
				return true;
			}
			return false;
		}

		bool colaVacia() {
			if (primero > ultimo) {
				return true;
			}
			return false;
		}

		void insertarElemento(dataType elemento) {
			if (colaLlena()) {
				cerr << "Error: La cola se encuentra llena" << endl;
			}
			else {
				arregloCola[++ultimo] = elemento;
			}
		}

		dataType extraerElemento() {
			if (colaVacia()) {
				cerr << "Error: La cola se encuentra vacia" << endl;
				return NULL;
			}
			else {
				return arregloCola[primero++];
			}
		}

		void borrarCola() {
			primero = 0;
			ultimo = -1;
		}

		dataType verPrimero() {
			if (colaVacia()) {
				cerr << "Error: La cola se encuentra vacia" << endl;
				return NULL;
			}
			else {
				return arregloCola[primero];
			}
		}
};

//FUNCION PRINCIPAL
int main(int args, const char* argsv[]) {
	Cola <int> colita;

	colita.insertarElemento(10);
	colita.insertarElemento(20);
	colita.insertarElemento(30);
	cout << "El primer elemento es: " << colita.verPrimero() << endl;
	colita.extraerElemento();
	cout << "El primer elemento es: " << colita.verPrimero() << endl;

	return 0;
}