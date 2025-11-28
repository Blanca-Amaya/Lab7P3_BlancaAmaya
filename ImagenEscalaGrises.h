#pragma once
#include <vector>
#include "Imagen.h"
using namespace std;


class ImagenEscalaGrises : public Imagen {
private:
	int contraste;
	vector <int> vectorIntensidad;

public:
    // Contructor
    ImagenEscalaGrises(const string& nombre, int ancho, int altura, int contraste);
    ~ImagenEscalaGrises();

    // Metodos
    bool aplicarBrillo(int brillo) override;
    void mostrarPropiedades() override;
    void listarAtributos() override;

    int getContraste();
    void generarIntensidadesAleatorias();
};

