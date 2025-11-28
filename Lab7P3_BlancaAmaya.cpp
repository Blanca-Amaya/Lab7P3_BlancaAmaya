#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <ctime>
#include "Imagen.h"
#include "ImagenColor.h"
#include "ImagenEscalaGrises.h"
using namespace std;

vector <Imagen*> imagenes;

// Liberar Memoria
void liberarMemoria() {
    for (int i = 0; i < imagenes.size(); i++) {
        delete imagenes[i];
    }
    imagenes.clear();
}


// 1. Crear Imagen a Color
void crearImagenColor() {
    string nombre;
    int ancho, altura, profundidad, cantidad;
    cout << "Nombre: ";
    cin >> nombre;
    cout << "Ancho (1-10): ";
    cin >> ancho;
    cout << "Altura (1-10): ";
    cin >> altura;
    cout << "Profundidad (1-24): ";
    cin >> profundidad;
    cout << "Cantidad de Colores a Agregar: ";
    cin >> cantidad;
    if (cantidad <= 0) {
        cout << "Error: La cantidad de colores debe ser mayor a 0" << endl;
        return;
    }
    ImagenColor* nuevaImagen = new ImagenColor(nombre, ancho, altura, profundidad);
    for (int i = 0; i < cantidad; i++) {
        int R, G, B;
        cout << "Color " << (i + 1) << " - R: ";
        cin >> R;
        cout << "Color " << (i + 1) << " - G: ";
        cin >> G;
        cout << "Color " << (i + 1) << " - B: ";
        cin >> B;
        RGB* nuevoRGB = new RGB(R, G, B);
        nuevaImagen->agregarRGB(nuevoRGB);
    }
    imagenes.push_back(nuevaImagen);
    cout << "Imagen a Color agregada correctamente" << endl;
}


// 1. Crear Imagen Escala de Grises
void crearImagenGrises() {
    string nombre;
    int ancho, altura, contraste;
    cout << "Nombre: ";
    cin >> nombre;
    cout << "Ancho (1-10): ";
    cin >> ancho;
    cout << "Altura (1-10): ";
    cin >> altura;
    cout << "Contraste (0-100): ";
    cin >> contraste;
    ImagenEscalaGrises* nuevaImagen = new ImagenEscalaGrises(nombre, ancho, altura, contraste);
    imagenes.push_back(nuevaImagen);
    cout << "Imagen a Escala de Grises agregada correctamente" << endl;
}


// 1. Crear Imagen
void crearImagen() {
    int opcion;
    bool resp = true;
    while (resp) {
        cout << "------ Crear Imagenes ------" << endl;
        cout << "1. Crear Imagen a Color" << endl;
        cout << "2. Crear Imagen a Escala de Grises" << endl;
        cout << "3. Salir. " << endl;
        cin >> opcion;

        switch (opcion) {
        case 1:
            crearImagenColor();
            break;
        case 2:
            crearImagenGrises();
            break;
        case 3:
            cout << "Saliendo..." << endl;
            resp = false;
            break;
        default:
            cout << "Opcion invalida" << endl;
            break;
        }
    }
}

// 2. Listar Imagenes
void ListarImagenes() {
    if (imagenes.empty()) {
        cout << "No hay imagenes guardadas";
        return;
    }

    cout << "Imagenes Guardadas ---"; cout << endl;
    for (int i = 0; i < imagenes.size(); i++) {
        cout << "-> Posicion " << i << " ---\n";
        imagenes[i]->listarAtributos();
    }
    cout << endl;
}

// 3. Aplicar Brillo
void AplicarBrillo() {
    if (imagenes.empty()) {
        cout << "No hay imagenes para aplicar brillo"; cout << endl;
        return;
    }
    ListarImagenes();
    int posicion, brillo;
    cout << "Ingrese la posicion de la imagen a la que desea aplicar brillo: ";
    cin >> posicion;

    if (posicion < 0 || posicion >= imagenes.size()) {
        cout << "Posicion invalida";
        return;
    }
    cout << "Ingrese el valor de brillo a aplicar (10-40): ";
    cin >> brillo;

    bool exito = imagenes[posicion]->aplicarBrillo(brillo);
    if (!exito) {
        cout << "Hubo un error al aplicar el brillo" << endl;
    }
}

// 4. Mostrar Propiedades 
void mostrarPropiedades() {

}

void menu() {
    int opcion;
    bool resp = true;
    while (resp) {
        cout << "------ Menu ------" << endl;
        cout << "1. Crear Imagen" << endl;
        cout << "2. Listar Imagenes" << endl;
        cout << "3. Aplicar Brillo" << endl;
        cout << "4. Mostrar Propiedades" << endl;
        cout << "5. Salir." << endl;
        cout << "Ingrese la opcion que desea realizar: ";
        cin >> opcion;
        switch (opcion) {
        case 1:
            crearImagen();
            break;
        case 2:
            ListarImagenes();
            break;
        case 3:
            AplicarBrillo();
            break;
        case 4:
            mostrarPropiedades();
            break;
        case 5:
            cout << "Saliendo..." << endl;
            resp = false;
            liberarMemoria();
            break;
        default:
            cout << "Opcion invalida" << endl;
            break;
        }
    }
    liberarMemoria();
}

int main() {
    menu();
}