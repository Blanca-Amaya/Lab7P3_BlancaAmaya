#pragma once
#include <string>
#include <iostream>
using namespace std;


class Imagen {
protected:
    string nombre;
    int ancho;
    int altura;
    int pixeles;
public:
    Imagen(const string& nombre, int ancho, int altura);
    virtual ~Imagen();

    // Getters
    int getPixeles() const;
    string getNombre() const;

    virtual bool aplicarBrillo(int brillo) = 0; // puro virtual
    virtual void mostrarPropiedades() = 0;
    virtual void listarAtributos() const;
};

