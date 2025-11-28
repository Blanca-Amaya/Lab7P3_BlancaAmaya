#include "Imagen.h"
#include <iostream>

Imagen::Imagen(const std::string& nombre, int ancho, int altura) : nombre(nombre), ancho(ancho), altura(altura) { 
	pixeles = ancho * altura;
}

Imagen::~Imagen() {}

int Imagen::getPixeles() const { 
	return pixeles; 
}


string Imagen::getNombre() const {
	return nombre;
}

void Imagen::listarAtributos() const {
	cout << "Nombre: " << nombre << endl;
	cout << "Ancho: " << ancho << endl;
	cout << "Altura: " << altura << endl;
	cout << "Pixeles: " << pixeles << endl;
}
