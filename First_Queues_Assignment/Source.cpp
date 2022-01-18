/**/

//HEADERS
#include <iostream>
const int TAM =  50;
const int SIZE = 50;

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

//Clase pila
template <class dataType> class Stack {
private:
	//Arreglo que se convertirá en la pila
	dataType stack[SIZE];

	//Cima o tope, indica en que posición del arrego se encuentra el último dato ingresado
	int top;

public:
	//Constructor
	Stack();

	//Retorna true si la pila está llena
	bool isFull();

	//Retorna true si la pila está vacía
	bool isEmpty();

	//Inserta un elemento en el tope de la pila
	void push(dataType key);

	//Extrae el elemento que se encuentre en el tope de la pila
	int pop();

	//Limpia toda la pila dejándola vacía
	void clean();

	//Obtiene el elemento en el tope de la pila y lo imprime sin extraerlo
	void topStack();

	//Obtiene el número de elemtos que tiene la pila
	void length();

	//Imprime toda la pila sin extraer los elementos
	void print();
};

//Constructor
template <class dataType> Stack<dataType>::Stack() {
	top = -1;

	for (int i = 0; i < SIZE; i++) {
		stack[i] = NULL;
	}
}

//Retorna true si la pila está llena
template <class dataType> bool Stack<dataType>::isFull() {
	if (top != SIZE - 1) {
		return false;
	}

	return true;
}

//Retorna true si la pila está vacía
template <class dataType> bool Stack<dataType>::isEmpty() {
	if (top != -1) {
		return false;
	}

	return true;
}

//Inserta un elemento en el tope de la pila
template <class dataType> void Stack<dataType>::push(dataType key) {
	if (this->isFull()) {
		cerr << "ERROR: Error de OVERFLOW en la pila." << endl;
		return;
	}

	top++;
	stack[top] = key;
}

//Extrae el elemento que se encuentre en el tope de la pila
template <class dataType> int Stack<dataType>::pop() {
	if (isEmpty()) {
		cerr << "Error: Error de UNDERFLOW en la pila." << endl;
		return NULL;
	}

	dataType key;

	key = stack[top];
	top--;

	return key;
}

//Limpia toda la pila dejándola vacía
template <class dataType> void Stack<dataType>::clean() {
	if (this->isEmpty()) {
		cerr << "Error: Error de UNDERFLOW en la pila." << endl;
	}

	//Pone tope en -1, de esta forma no se pueden acceder a los datos ya escritos y reescribiendo si quisieran guardar nuevos datos
	top = -1;

	cout << "La pila ha sido limpiada" << endl;
}

template <class dataType> void Stack<dataType>::topStack() {
	if (this->isEmpty()) {
		cerr << "Error: Error de UNDERFLOW en la pila." << endl;
	}

	cout << "El elemento en el tope de la pila es: " << stack[top] << endl;
}

template <class dataType> void Stack<dataType>::length() {
	if (this->isEmpty()) {
		cerr << "Error: Error la pila se encuentra vacía." << endl;
	}

	cout << "La pila tiene " << (top + 1) << " elementos." << endl;
}

//Imprime toda la pila sin extraer los elementos
template <class dataType> void Stack<dataType>::print() {
	if (isEmpty()) {
		cerr << "Error: Error de UNDERFLOW en la pila." << endl;
	}
	for (int i = top; i >= 0; i--) {
		if (stack[i] != NULL) {
			cout << "Pos: " << i << ": " << stack[i] << endl;
		}
	}
}


bool capicuo(int numero) {
	ColaCircular<int> colaCircular;
	Stack<int> pila;
	int cociente = numero;
	int resto = 0;
	while (cociente > 0) {
		resto = cociente % 10;
		cociente = cociente / 10;
		colaCircular.insertarElemento(resto);
		pila.push(resto);
	}
	while (!pila.isEmpty() && !colaCircular.colaVacia()) {
		if (pila.pop() == colaCircular.extraerElemento()) {
			continue;
		}
		else {
			return false;
		}
	}
	return true;
}


//FUNCION PRINCIPAL
int main(int args, const char* argsv[]) {

	int numero;
	cout << "Ingrese un numero: ";
	cin >> numero;
	cout << endl;

	if (capicuo(numero)) {
		cout << "capicuo" << endl;
	}
	else {
		cout << "no capicuo" << endl;
	}

	return 0;
}