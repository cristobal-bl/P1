#include <string>

#ifndef NODO
#define NODO

class Nodo { //Clase Nodo de la lista
private:
	Nodo * nodoSiguiente;
	std::string nombreMedicamento;
	std::string fechaInicio;
	std::string fechaVencimiento;
	std::string tipo;
	std::string contenido;

public:
	Nodo * obtenerNodoSiguiente();
	void asignarNodoSiguiente(Nodo * nuevoNodo);
	void asignarDatosNodo(std::string nombre, std::string fechaI, std::string fechaV, std::string t, std::string cont);
	std::string obtenerNombreMedicamento();
	std::string obtenerFechaInicio();
	std::string obtenerFechaVencimiento();
	std::string obtenerTipo();
	std::string obtenerContenido();
};
#endif
