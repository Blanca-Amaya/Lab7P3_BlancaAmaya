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
    
}

// 1. Crear Imagen a Color
void crearImagenColor() {
    string nombre;
    cout << "Nombre: ";
    cin >> nombre;
    int ancho, altura, profundidad, cantidad;
    int R, G, B;
    cout << "Ancho: ";
    cin >> ancho;
    cout << "Altura: ";
    cin >> altura;
    cout << "Profundidad (1-24): ";
    cin >> profundidad;
    cout << "Cantidad de Colores a Agregar: ";
    cin >> cantidad;
    for (int i = 0; i < cantidad; i++) {
        cout << "R: ";cin >> R;
        cout << "G: "; cin >> G;
        cout << "B: "; cin >> B;
        cout << endl;
    }
}


// 1. Crear Imagen Escala de Grises
void crearImagenGrises() {
    string nombre;
    cout << "Nombre: ";
    cin >> nombre;
    int ancho, altura, pixeles;
    cout << "Ancho (1-10): ";
    cin >> ancho;
    cout << "Altura (1-10): ";
    cin >> altura;
    cout << "Pixeles: ";
    cin >> pixeles;
    cout << "Contraste: ";
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

        case 2:
           
        default:
            break;
        }
    }
}

// 2. Listar Imagenes
void ListarImagenes() {

}

// 3. Aplicar Brillo
void AplicarBrillo() {

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

            break;
        case 2:

            break;
        case 3:

            break;
        case 4:

            break;
        case 5:
            cout << "Saliendo..." << endl;
            resp = false;
            break;
        default:
            cout << "Opcion invalida" << endl;
            break;
        }
    }
}

int main() {
    menu();
}