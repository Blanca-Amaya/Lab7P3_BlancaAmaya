#include <iostream>
using namespace std;

// Liberar Memoria
void liberarMemoria() {

}

// 1. Crear Imagen
void crearImagen() {

}

// 2. Listar Imagenes
void listarImagenes() {

}

// 3. Aplicar Brillo
void aplicarBrillo() {

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