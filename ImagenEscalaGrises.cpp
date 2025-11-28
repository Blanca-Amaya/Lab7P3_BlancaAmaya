#include "ImagenEscalaGrises.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

ImagenEscalaGrises::ImagenEscalaGrises(const string& nombre, int ancho, int altura, int contraste): Imagen(nombre, ancho, altura), contraste(0) {
    if (contraste < 0) {
        this->contraste = 0;
    }
    else if (contraste > 100) {
        this->contraste = 100;
    }
    else {
        this->contraste = contraste;
    }
    generarIntensidadesAleatorias();
}

ImagenEscalaGrises::~ImagenEscalaGrises() {
    vectorIntensidad.clear();
}

int ImagenEscalaGrises::getContraste() {
    return 0;
}

void ImagenEscalaGrises::generarIntensidadesAleatorias() {
    srand(time(0));
    int totalPixeles = getPixeles();
    // valor de intensidad aleatorio para cada pixel
    for (int i = 0; i < totalPixeles; i++) {
        int intensidad = rand() % 256; // -- num entre 0-255
        vectorIntensidad.push_back(intensidad);
    }
}

bool ImagenEscalaGrises::aplicarBrillo(int brillo) {
    if (brillo < 10 || brillo > 40) {
        cout << "Brillo debe estar entre 10-40" <<  endl;
        return false;
    }

    if (vectorIntensidad.empty()) {
        cout << "No hay intensidades para aplicar brillo" << endl;
        return false;
    }

    for (int i = 0; i < vectorIntensidad.size(); i++) {
        double factorContraste = 1.0 + (contraste / 100.0);
        double nuevovalor = vectorIntensidad[i] + (brillo * factorContraste);
        // que este en rango 0-255
        if (nuevovalor < 0) {
            vectorIntensidad[i] = 0;
        }
        else if (nuevovalor > 255) {
            vectorIntensidad[i] = 255;
        }
        else {
            vectorIntensidad[i] = (int)nuevovalor;
        }
    }

    cout << "Brillo aplicado correctamente a la imagen escala de grises" << endl;
    return true;
}

void ImagenEscalaGrises::mostrarPropiedades() {

}

void ImagenEscalaGrises::listarAtributos() {

}
