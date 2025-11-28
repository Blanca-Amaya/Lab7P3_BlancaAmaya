#include "ImagenColor.h"

ImagenColor::ImagenColor(string nombre_, int ancho_, int altura_, int profundidad_) : Imagen(nombre_, ancho_, altura_), profundidadColor(1) {
    if (profundidad_ < 1) profundidadColor = 1;
    else if (profundidad_ > 24) profundidadColor = 24;
    else profundidadColor = profundidad_;
}


ImagenColor::~ImagenColor() {
    for (auto* rgb : vectorRGB) {
        delete rgb;
    }
    vectorRGB.clear();
}

void ImagenColor::calcularPropiedad() {
    mostrarPropiedades();
}

void ImagenColor::agregarRGB(RGB* rgb) {
    vectorRGB.push_back(rgb);
}

bool ImagenColor::aplicarBrillo(int brillo) {
    if (brillo < 10 || brillo > 40) {
        cout << "Brillo debe estar entre 10-40\n";
        return false;
    }

    if (vectorRGB.empty()) {
        cout << "No hay colores RGB para aplicar brillo\n";
        return false;
    }

    for (int i = 0; i < vectorRGB.size(); i++) {
        vectorRGB[i]->ajustar(brillo);
    }

    cout << "Brillo aplicado correctamente a la imagen color!\n";
    return true;
}

void ImagenColor::mostrarPropiedades() {
    if (vectorRGB.empty()) {
        cout << "No hay colores RGB para calcular propiedades\n";
        return;
    }
    vector<int> valoresR, valoresG, valoresB;

    for (int i = 0; i < vectorRGB.size(); i++) {
        valoresR.push_back(vectorRGB[i]->getR());
        valoresG.push_back(vectorRGB[i]->getG());
        valoresB.push_back(vectorRGB[i]->getB());
    }
    double promedioR = promedio(valoresR);
    double promedioG = promedio(valoresG);
    double promedioB = promedio(valoresB);
    cout << "Promedio de R: " << promedioR << "\n";
    cout << "Promedio de G: " << promedioG << "\n";
    cout << "Promedio de B: " << promedioB << "\n";
    string colorMasFrecuente = "";
    int maxFrecuencia = 0;
    for (int i = 0; i < vectorRGB.size(); i++) {
        int frecuenciaActual = 1;
        string colorActual = to_string(vectorRGB[i]->getR()) + "," +
            to_string(vectorRGB[i]->getG()) + "," +
            to_string(vectorRGB[i]->getB());
        // -- comparar con los otros colores
        for (int j = i + 1; j < vectorRGB.size(); j++) {
            string colorComparar = to_string(vectorRGB[j]->getR()) + "," + to_string(vectorRGB[j]->getG()) + "," + to_string(vectorRGB[j]->getB());
            if (colorActual == colorComparar) {
                frecuenciaActual++;
            }
        }
        if (frecuenciaActual > maxFrecuencia) {
            maxFrecuencia = frecuenciaActual;
            colorMasFrecuente = colorActual;
        }
    }
    cout << "El color RGB que más se repite es: (" << colorMasFrecuente << ")";
    cout << " - aparece " << maxFrecuencia << " veces" << endl;
    int coloresUnicos = 0;
    vector<string> coloresVistos;

    for (int i = 0; i < vectorRGB.size(); i++) {
        string colorActual = to_string(vectorRGB[i]->getR()) + "," + to_string(vectorRGB[i]->getG()) + "," + to_string(vectorRGB[i]->getB());

        bool visto = false;
        for (int j = 0; j < coloresVistos.size(); j++) {
            if (coloresVistos[j] == colorActual) {
                visto = true;
                break;
            }
        }

        if (!visto) {
            coloresVistos.push_back(colorActual);
            coloresUnicos++;
        }
    }

    cout << "Total de colores únicos: " << coloresUnicos << "\n";
    cout << "Profundidad de color: " << profundidadColor << " bits\n";
}

void ImagenColor::listarAtributos() {
    cout << "Nombre: " << getNombre() << "\n";
    cout << "Ancho: " << getAncho() << "\n";
    cout << "Altura: " << getAltura() << "\n";
    cout << "Pixeles: " << getPixeles() << "\n";
    cout << "Profundidad: " << profundidadColor << "\n";
    if (vectorRGB.empty()) {
        cout << "Colores: No hay colores agregados\n";
    }
    else {
        cout << "Colores (" << vectorRGB.size() << "):\n";
        for (int i = 0; i < vectorRGB.size(); i++) {
            cout << "  RGB " << i << ": (" << vectorRGB[i]->getR() << ", " << vectorRGB[i]->getG() << ", " << vectorRGB[i]->getB() << ")\n";
        }
    }
    cout << endl;
}

int ImagenColor::getProfundidadColor() {
    return profundidadColor;
}