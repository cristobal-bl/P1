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

Nodo * ingresarDatos(int codigo) {
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
	show("El codigo del medicamento es: ");
	cout << codigo;
	nuevoNodo->asignarDatosNodo(codigo, nombre, fechaI, fechaV, t, cont);
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
	showl("|  4. Despachar medicamentos         |");
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
	Lista listaDespacho;
	listaDespacho.iniciarCantidad();
	while (opcion != 6) {
		menu();
		show("Seleccione una opcion: ");
		try
		{
		    cin >> opcion;
		}
		catch(string e)
		{
		    system("pause");
		}
		switch (opcion)
		{
		case 1:
			{
				Nodo * nuevoNodo = ingresarDatos(listaDeDatos.obtenerCantidad() + 1);
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
		case 4:
			{
				showl("___________________________________");
				showl("   [Crear una lista de despacho]   ");
				if(listaDeDatos.obtenerCantidad()==0){
					showl("   No hay informacion almacenada");
					showl("");
				}else if(listaDeDatos.obtenerCantidad() > 0){
					int opcion2 = 1;
					while (opcion2 !=2){
						show("Ingrese el codigo del medicamento que desea agregar: ");
						int codigo;
						cin >> codigo;
						if(codigo>listaDeDatos.obtenerCantidad()){
							showl("El codigo ingresado no coincide con ningun medicamento");
							showl("");
						}else if(codigo <= listaDeDatos.obtenerCantidad()){
							Nodo * nuevoNodo = listaDeDatos.buscarMedicamento(codigo);
							listaDespacho.agregarNodo(nuevoNodo);
							show("Nombre del medicamento: ");
							showl(nuevoNodo->obtenerNombreMedicamento());
							showl("El medicamento se agrego a la lista de despacho");
							showl("");
						}
						showl("Desea agregar otro medicamento a la lista? (1. Si, 2. No): ");
						cin >> opcion2;
					}
				}
			}
			system("pause");
			system("cls");
			break;
		case 5:
			listaDespacho.imprimirEnPantalla();
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
			system("pause");
			system("cls");
			break;
		}
	}
}
