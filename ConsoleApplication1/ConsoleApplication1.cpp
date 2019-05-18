// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//INVESTIGAR PILAS Y COLAS EN C++

#include "pch.h"
#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>

using namespace std;

/*
	METODOS GENERALES
*/

void showl(string s) { //Metodos para imprimir en consola
	cout << s << endl;
}

void show(string s) {
	cout << s;
}

/*
	CLASES A UTILIZAR Y SUS METODOS
*/

class Nodo { //Clase Nodo de la lista
private:
	Nodo * nodoSiguiente;
	string nombreMedicamento;
	string fechaInicio;
	string fechaVencimiento;
	string tipo;
	string contenido;

public:
	Nodo * obtenerNodoSiguiente();
	void asignarNodoSiguiente(Nodo * nuevoNodo);
	void asignarDatosNodo(string nombre, string fechaI, string fechaV, string t, string cont);
	string obtenerNombreMedicamento();
	string obtenerFechaInicio();
	string obtenerFechaVencimiento();
	string obtenerTipo();
	string obtenerContenido();
};

Nodo * Nodo::obtenerNodoSiguiente()
{
	return nodoSiguiente;
}

void Nodo::asignarNodoSiguiente(Nodo * nuevoNodo)
{
	nodoSiguiente = nuevoNodo;
}

void Nodo::asignarDatosNodo(string nombre, string fechaI, string fechaV, string t, string cont){
	nombreMedicamento=nombre;
	fechaInicio=fechaI;
	fechaVencimiento = fechaV;
	tipo = t;
	contenido = cont;
}

string Nodo::obtenerNombreMedicamento()
{
	return nombreMedicamento;
}

string Nodo::obtenerFechaInicio()
{
	return fechaInicio;
}

string Nodo::obtenerFechaVencimiento()
{
	return fechaVencimiento;
}

string Nodo::obtenerTipo()
{
	return tipo;
}

string Nodo::obtenerContenido()
{
	return contenido;
}

//Clase Lista de nodos
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
};

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

/*
	METODOS DE FUNCIONALIDADES DEL MENU
*/

Nodo * ingresarDatos() {
	Nodo * nuevoNodo = new Nodo;
	string nombre;
	string fechaI;
	string fechaV;
	string t;
	string cont;
	string auxiliar;
	showl("___________________________________");
	showl("        [Ingreso de Datos]");
	showl("Ingrese el nombre del medicamento: ");
	getline(std::cin, auxiliar);
	getline(std::cin, nombre);
	showl("Ingrese la fecha inicial: ");
	getline(cin, fechaI);
	showl("Ingrese la fecha de vencimiento: ");
	getline(cin, fechaV);
	showl("Ingrese el tipo: ");
	getline(cin, t);
	showl("Ingrese el contenido: ");
	getline(cin, cont);
	nuevoNodo->asignarDatosNodo(nombre, fechaI, fechaV, t, cont);
	return nuevoNodo;
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
				cout << "[Medicamento " << (i+1) << "]" << endl;
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

void Lista::almacenarEnArchivo() {//TODO, Utilizar punteros
	ofstream archivo;
	
	Nodo * nodoAuxiliar = nodoInicial;
	archivo.open("Prueba.txt");
	for (int i = 0; i < cantidad; i++)
	{
		archivo << "Medicamento " << i;
		
		archivo << "Nombre: " << nodoAuxiliar->obtenerNombreMedicamento() << endl;
		archivo << "Fecha de inicio: " << nodoAuxiliar->obtenerFechaInicio() << endl;
		archivo << "Fecha de vencimiento: " << nodoAuxiliar->obtenerFechaVencimiento() << endl;
		archivo << "Tipo:" << nodoAuxiliar->obtenerTipo() << endl;
		archivo << "Contenido: " << nodoAuxiliar->obtenerContenido() << endl;
		nodoAuxiliar = nodoAuxiliar->obtenerNodoSiguiente();
	}

    archivo << "ingreso mi primer texto" << endl;
    archivo << "segundo texto" << endl;
    archivo << "final del texto" << endl;

    archivo.close();
}

void menu() { //Mostrar opciones del menu
	show(" ");
	for(int i = 0; i < 37; i++){
		show("_");
	}
	showl("");
	showl("|                                     |");
	showl("|              MENU:                  |");
	showl("|  1. Ingreso de datos                |");
	showl("|  2. Impresion en pantalla           |");
	showl("|  3. Almacenar en archivo            |");
	showl("|  4. Ordenar informacion             |"); //Utilizar listas enlazadas. Pilas y colas, si es necesario
	showl("|  5. Impresion de datos fisicamente  |");
	showl("|  6. Salida                          |");
	show("|");
	for(int i = 0; i < 37; i++){
		show("_");
	}
	showl("|");
}

int main() {
	int opcion = 20;
	Lista listaDeDatos;
	listaDeDatos.iniciarCantidad();
	while (opcion != 6) {
		menu();
		show("Seleccione una opcion: ");
		cin >> opcion;
		switch (opcion)
		{
		case 1:
			{
				Nodo * nuevoNodo = ingresarDatos();
				listaDeDatos.agregarNodo(nuevoNodo);
				showl("");
			}
			system("pause");
			break;
		case 2:
			listaDeDatos.imprimirEnPantalla();
			system("pause");
			break;
		case 3:
			listaDeDatos.almacenarEnArchivo();
		case 6:
			break;
		default:
			showl("La opcion seleccionada no es valida.");
			showl("");
		}
	}
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
