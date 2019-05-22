#include "Nodo.h"

Nodo * Nodo::obtenerNodoSiguiente()
{
	return nodoSiguiente;
}

void Nodo::asignarNodoSiguiente(Nodo * nuevoNodo)
{
	nodoSiguiente = nuevoNodo;
}

void Nodo::asignarDatosNodo(int codigo, std::string nombre, std::string fechaI, std::string fechaV, std::string t, std::string cont){
	codigoMedicamento = codigo;
	nombreMedicamento=nombre;
	fechaInicio=fechaI;
	fechaVencimiento = fechaV;
	tipo = t;
	contenido = cont;
}

int Nodo::obtenerCodigoMedicamento(){
	return codigoMedicamento;
}

std::string Nodo::obtenerNombreMedicamento()
{
	return nombreMedicamento;
}

std::string Nodo::obtenerFechaInicio()
{
	return fechaInicio;
}

std::string Nodo::obtenerFechaVencimiento()
{
	return fechaVencimiento;
}

std::string Nodo::obtenerTipo()
{
	return tipo;
}

std::string Nodo::obtenerContenido()
{
	return contenido;
}
