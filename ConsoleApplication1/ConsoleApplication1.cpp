//#include "pch.h" //Visual Studio (Eliminar al final)
#include <iostream>
#include <stdlib.h>
#include <string>
#include "Nodo.h"
#include "Lista.h"
#include "Show.h"

using namespace std;

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

//Mostrar opciones del menu
void menu() {
	show(" ");
	for(int i = 0; i < 36; i++){
		show("_");
	}
	showl("");
	showl("|                                    |");
	showl("|              MENU:                 |");
	showl("|  1. Ingreso de datos               |");
	showl("|  2. Impresion en pantalla          |");
	showl("|  3. Almacenar en archivo           |");
	showl("|  4. Proceso o accion               |"); //Utilizar listas enlazadas. Pilas y colas, si es necesario
	showl("|  5. Impresion de ticket o boleta   |");
	showl("|  6. Salida                         |");
	show("|");
	for(int i = 0; i < 36; i++){
		show("_");
	}
	showl("|");
}

//Método Principal
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
			system("cls");
			break;
		case 2:
			listaDeDatos.imprimirEnPantalla();
			system("pause");
			system("cls");
			break;
		case 3:
			listaDeDatos.almacenarEnArchivo();
			system("pause");
			system("cls");
			break;
		case 6:
			showl("La aplicacion se cerrara");
			system("pause");
			break;
		default:
			showl("La opcion seleccionada no es valida.");
			showl("");
		}
	}
}
