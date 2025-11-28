#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;


class Imagen {
protected:
    string nombre;
    int ancho;
    int altura;
    int pixeles;

public:
    Imagen(string nombre, int ancho, int altura);
    virtual ~Imagen();

    // Getters
    string getNombre();
    int getAncho();
    int getAltura();
    int getPixeles();

    template<typename T>
    double promedio(vector<T>& datos) {
        if (datos.size() == 0) return 0.0;
        double suma = 0.0;
        for (int i = 0; i < datos.size(); ++i) suma += (double)datos[i];
        return suma / (double)datos.size();
    }

    virtual bool aplicarBrillo(int brillo) = 0;
    virtual void mostrarPropiedades() = 0;
    virtual void listarAtributos();
};

