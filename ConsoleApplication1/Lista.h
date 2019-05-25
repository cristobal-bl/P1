#include <string>
#include "Nodo.h"

#ifndef LISTA
#define LISTA

class Lista { 
private:
	Nodo * nodoInicial;
	Nodo * nodoFinal;
	int cantidad;

public:
	void agregarNodo(Nodo * nuevoNodo);
	Nodo * obtenerNodoInicial();
	Nodo * obtenerNodoFinal();
	void imprimirEnPantalla();
	void iniciarCantidad();
	void almacenarEnArchivo();
	int obtenerCantidad();
	Nodo * buscarMedicamento(int codigo);
};

#endif
