#include <iostream>
#include "GameStore.h"
using namespace std;


void mostrarMenuPrincipal() {
    cout << "\n===== MENU PRINCIPAL =====\n";
    cout << "1. Ver catalogo de juegos\n";
    cout << "2. Agregar juego al carrito\n";
    cout << "3. Ver resumen de compra\n";
    cout << "4. Cargar compra demo\n";
    cout << "0. Salir\n";
    cout << "Seleccione una opcion: ";
}

int leerOpcionMenu() {
    int opcion;
    cin >> opcion;
    while (opcion < 0 || opcion > 4) {
        cout << "Opcion invalida. Intente de nuevo (0-4): ";
        cin.clear();
        cin.ignore(10000, '\n');
        cin >> opcion;
    }
    return opcion;
}

int main() {
    int codigosCarrito[MAX_ITEMS_CARRITO] = {0};
    int cantidadesCarrito[MAX_ITEMS_CARRITO] = {0};
    int numItems = 0;

    int opcion;
    int tipoCliente;
    double porcentajeDescuento;
    do {
        mostrarMenuPrincipal();
        opcion = leerOpcionMenu();
        switch (opcion) {
            case 1:
                mostrarCatalogoJuegos();
                break;
            case 2:
                agregarJuegoAlCarrito(codigosCarrito, cantidadesCarrito, numItems);
                break;
            case 0:
                cout << "Gracias por visitar la tienda GameStore. Nos vemos luego!\n";
                break;
        }
    } while (opcion != 0);

    return 0;
}
