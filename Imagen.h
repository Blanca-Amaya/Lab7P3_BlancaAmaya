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
        if (datos.empty()) return 0.0;
        double suma = 0.0;
        for (const auto& dato : datos) suma += static_cast<double>(dato);  // ? range-based for
        return suma / static_cast<double>(datos.size());  // ? static_cast
    }

    virtual bool aplicarBrillo(int brillo) = 0;
    virtual void mostrarPropiedades() = 0;
    virtual void listarAtributos();
};

