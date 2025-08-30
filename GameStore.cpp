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
