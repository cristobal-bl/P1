#include <iostream>
#include <fstream>
#include <unistd.h>

#include "Lista.h"
#include "Show.h"

void Lista::agregarNodo(Nodo * nuevoNodo) {
	if (cantidad == 0)
	{
		nodoInicial = nuevoNodo;
		nodoFinal = nuevoNodo;
		cantidad++;
	}
	else if (cantidad > 0)
	{
		nodoFinal->asignarNodoSiguiente(nuevoNodo);
		nodoFinal = nuevoNodo;
		cantidad++;
	}
}


Nodo * Lista::obtenerNodoInicial()
{
	return nodoInicial;
}

Nodo * Lista::obtenerNodoFinal()
{
	return nodoFinal;
}

void Lista::iniciarCantidad(){
	cantidad = 0;
}


void Lista::imprimirEnPantalla() {
	showl("___________________________________");
	showl("       [Mostrar Informacion]");
	if (cantidad == 0) {
		showl("   No hay informacion almacenada");
		showl("");
	}
	else if (cantidad > 0) {
		{
			Nodo * nodoAuxiliar = nodoInicial;
			for (int i = 0; i < cantidad; i++)
			{
				std::cout << "[Medicamento " << nodoAuxiliar->obtenerCodigoMedicamento() << "]" << std::endl;
				show("Nombre: ");
				showl(nodoAuxiliar->obtenerNombreMedicamento());
				show("Fecha de inicio: ");
				showl(nodoAuxiliar->obtenerFechaInicio());
				show("Fecha de vencimiento: ");
				showl(nodoAuxiliar->obtenerFechaVencimiento());
				show("Tipo: ");
				showl(nodoAuxiliar->obtenerTipo());
				show("Contenido: ");
				showl(nodoAuxiliar->obtenerContenido());
				showl("");
				nodoAuxiliar = nodoAuxiliar->obtenerNodoSiguiente();
			}
			showl("");
		}
	}
}

void Lista::almacenarEnArchivo() {
	if(cantidad == 0){
		showl("_______________________________________");
		showl("  [Almacenar informacion en archivo]");
		showl("No hay informacion para almacenar");
	}else{
		showl("__________________________________________");
		showl("[Almacenando en archivo, por favor espere]");
		std::ofstream archivo;
		
		Nodo * nodoAuxiliar = nodoInicial;
		archivo.open("Prueba.txt");
		for (int i = 0; i < cantidad; i++)
		{
			archivo << "[Medicamento " << (i+1) << "]" << std::endl;
			
			archivo << "Nombre: " << nodoAuxiliar->obtenerNombreMedicamento() << std::endl;
			archivo << "Fecha de inicio: " << nodoAuxiliar->obtenerFechaInicio() << std::endl;
			archivo << "Fecha de vencimiento: " << nodoAuxiliar->obtenerFechaVencimiento() << std::endl;
			archivo << "Tipo:" << nodoAuxiliar->obtenerTipo() << std::endl;
			archivo << "Contenido: " << nodoAuxiliar->obtenerContenido() << std::endl << std::endl;
			nodoAuxiliar = nodoAuxiliar->obtenerNodoSiguiente();
		}
	
	    archivo.close();
	
	    float progreso = 0.0;
		while (progreso <= 1.0) {
	    	int anchoBarra = 35;
	
	    	std::cout << "[";
	    	int pos = anchoBarra * progreso;
		    for (int i = 0; i < anchoBarra; ++i) {
		        if (i < pos) show("=");
		        else if (i == pos) show(">");
		        else show(" ");
		    }
		    std::cout << "] " << int(progreso * 100.0) << " %\r";
		    std::cout.flush();
		
		    progreso += 0.20; // for demonstration only
		    sleep(1);
		}
		showl("");
		showl("La informacion se guardo con exito");
	}
}

int Lista::obtenerCantidad(){
	return cantidad;
}
