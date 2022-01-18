/**/

//HEADERS
#include <iostream>
const int TAM = 50;

//DECLARACI[ON DE NOMBRES DE ESPACIO
using namespace std;

template <class dataType>
class Cola {
	protected:
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

		void limpiarCola() {
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

template <class dataType>
class ColaCircular : public Cola <int> {
	protected:
		int siguiente(int x) {
			return (x + 1) % TAM;
		}

	public:
		ColaCircular() {
			primero = 0;
			ultimo = TAM - 1;
		}

		bool colaLlena() {
			if (primero == siguiente(siguiente(ultimo))) {
				return true;
			}
			else {
				return false;
			}
		}

		bool colaVacia() {
			if (primero == siguiente(ultimo)) {
				return true;
			}
			else {
				return false;
			}
		}

		void insertarElemento(dataType elemento) {
			if (colaLlena()) {
				cerr << "Error> La cola se encuentra llena." << endl;
			}
			ultimo = siguiente(ultimo);
			arregloCola[ultimo] = elemento;
		}

		dataType extraerElemento() {
			if (colaVacia()) {
				cerr << "Error: La cola se encuentra vacia." << endl;
				return NULL;
			}
			dataType retorno = arregloCola[primero];
			primero = siguiente(primero);
			return retorno;
		}

		void limpiarCola() {
			primero = 0;
			ultimo = TAM - 1;
		}

		dataType verPrimero() {
			if (colaVacia()) {
				cerr << "Error: La cola se encuentra vacia." << endl;
				return NULL;
			}
			return arregloCola[primero];
		}
};

//FUNCION PRINCIPAL
int main(int args, const char* argsv[]) {
	Cola <int> colita;

	/*colita.insertarElemento(10);
	colita.insertarElemento(20);
	colita.insertarElemento(30);
	cout << "El primer elemento es: " << colita.verPrimero() << endl;
	colita.extraerElemento();
	cout << "El primer elemento es: " << colita.verPrimero() << endl;*/

	ColaCircular <int> colitaCircular;
	/*colitaCircular.insertarElemento(10);
	colitaCircular.insertarElemento(20);
	colitaCircular.insertarElemento(30);
	cout << "El primer elemento es: " << colitaCircular.verPrimero() << endl;
	colitaCircular.extraerElemento();
	cout << "El primer elemento es: " << colitaCircular.verPrimero() << endl;
	colitaCircular.insertarElemento(40);
	cout << "El primer elemento es: " << colitaCircular.verPrimero() << endl;
	colitaCircular.extraerElemento();
	cout << "El primer elemento es: " << colitaCircular.verPrimero() << endl;
	colitaCircular.extraerElemento();
	cout << "El primer elemento es: " << colitaCircular.verPrimero() << endl;*/

	return 0;
}