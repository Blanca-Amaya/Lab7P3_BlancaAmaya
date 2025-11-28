#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "RGB.h"
#include "Imagen.h"
using namespace std;

class ImagenColor : public Imagen {
private: 
	int profundidadColor;
	vector <RGB*> vectorRGB;
public:
	// Constructor
	ImagenColor(string nombre_, int ancho_, int altura_, int profundidad_);
	~ImagenColor();
	void aplicarBrillo(); 
	void calcularPropiedad();
	bool aplicarBrillo(int brillo) override;
	void mostrarPropiedades() override;
	void listarAtributos() override;

	// Getters
	int getProfundidadColor();

	// Setters
};

