#include "Imagen.h"
#include <iostream>

Imagen::Imagen(const std::string& nombre, int ancho, int altura) : nombre(nombre), ancho(ancho), altura(altura) { 
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
	cout << "Nombre: " << nombre << endl;
	cout << "Ancho: " << ancho << endl;
	cout << "Altura: " << altura << endl;
	cout << "Pixeles: " << pixeles << endl;
}
