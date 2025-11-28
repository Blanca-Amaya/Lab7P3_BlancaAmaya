#pragma once
#include <vector>
#include "Imagen.h"
using namespace std;


class ImagenEscalaGrises : public Imagen {
private:
	int contraste;
	vector <int> vectorIntensidad;

public:
	// Constructor
	ImagenEscalaGrises(const string& nombre, int ancho, int altura, int contraste);
	~ImagenEscalaGrises();
	ImagenEscalaGrises(int contraste2);

	// Metodos
	void aplicarBrillo();
	void calcularPropiedades();

	// Getters y Setters
	int getContraste();
};

