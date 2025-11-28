#include "Imagen.h"
#include <iostream>

Imagen::Imagen(string nombre_, int ancho_, int altura_) {
	pixeles = ancho * altura;
	if (ancho_ < 1) {
		ancho = 1;
	}
	else if (ancho_ > 10) {
		ancho = 10;
	}
	else {
		ancho = ancho_;
	}
	if (altura_ < 1) {
		altura = 1;
	}
	else if (altura_ > 10) {
		altura = 10;
	}
	else {
		altura = altura_;
	}
	pixeles = ancho * altura;
}

Imagen::~Imagen() {}

string Imagen::getNombre() {
	return nombre;
}

int Imagen::getAncho() {
	return ancho;
}

int Imagen::getAltura() {
	return altura;
}

int Imagen::getPixeles() {
	return pixeles;
}



void Imagen::listarAtributos() {
	cout << "Nombre: " << nombre << "\n";
	cout << "Ancho: " << ancho << "\n";
	cout << "Altura: " << altura << "\n";
	cout << "Pixeles: " << pixeles << "\n";
}
