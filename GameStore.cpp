#include <iostream>
#include "GameStore.h"
using namespace std;

// ------------Implementación de funciones------------
void mostrarCatalogoJuegos() {
    cout << "======= CATALOGO DE JUEGOS =======\n";
    for (int i = 0; i < TOTAL_JUEGOS; i++) {
        cout << "Codigo: " << codigosJuegos[i] << "\n";
        cout << " | Nombre: " << nombresJuegos[i] << "\n";
        cout << " | Categoria: " << categoriasJuegos[i] << "\n";
        cout << " | Plataforma: " << plataformasJuegos[i] << "\n";
        cout << " | Precio: $" << preciosJuegos[i] << "\n";
    }
    cout << "==================================\n";
}


int leerCodigoJuego() {
    int codigo;
    bool valido = false;
    while (!valido) {
        cout << "Ingrese el codigo del juego:  ";
        cin >> codigo;
        for (int i = 0; i < TOTAL_JUEGOS; i++) {
            if (codigosJuegos[i] == codigo) {
                valido = true;
                break;
            }
        }
        if (!valido) {
            cout << "Codigo invalido. Intente de nuevo.\n";
        }
    }
    return codigo;
}

int leerCantidadJuegos() {
    int cantidad;
    cout << "Ingrese la cantidad de unidades que desea comprar: ";
    cin >> cantidad;

    // Validación básica
    if (cantidad <= 0) {
        cout << "Cantidad inválida, se asignará 1 por defecto." << endl;
        cantidad = 1;
    }
    return cantidad;
}

string obtenerNombreJuego(int codigoJuego) {
    for (int i = 0; i < TOTAL_JUEGOS; i++) {
        if (codigosJuegos[i] == codigoJuego) {
            return nombresJuegos[i];
        }
    }
    return "Juego no encontrado";
}

double obtenerPrecioJuego(int codigoJuego) {
    for (int i = 0; i < TOTAL_JUEGOS; i++) {
        if (codigosJuegos[i] == codigoJuego) {
            return preciosJuegos[i];
        }
    }
    return -1;
}

string obtenerPlataforma(int codigoJuego) {
    for (int i = 0; i < TOTAL_JUEGOS; i++) {
        if (codigosJuegos[i] == codigoJuego) {
            return plataformasJuegos[i];
        }
    }
    return "Plataforma no encontrada";
}

string obtenerCategoria(int codigoJuego) {
    for (int i = 0; i < TOTAL_JUEGOS; i++) {
        if (codigosJuegos[i] == codigoJuego) {
            return categoriasJuegos[i];
        }
    }
    return "Categoria no encontrada";
}
