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
    virtual bool aplicarBrillo(int brillo) override;
    virtual void mostrarPropiedades() override;
    virtual void listarAtributos() override;

    int getContraste();
    void generarIntensidadesAleatorias();
};

