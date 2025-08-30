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
        cout << "==================================\n";
    }

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

void agregarJuegoAlCarrito(int codigos[], int cantidades[], int& cantidadJuegosRegistrados) {
    int codigo, cantidad;
    int espacioActualDelCarrito = contarCopiasEnCarrito(cantidades, cantidadJuegosRegistrados);
    if (espacioActualDelCarrito >= MAX_ITEMS_CARRITO) {
        cout << "El carrito ya esta lleno\n";
        return;
    }
    codigo = leerCodigoJuego();

    string nombreJuego = obtenerNombreJuego(codigo);

    cout << "El codigo " << codigo  << " pertenece al juego: " << nombreJuego << "\n";
    cantidad = leerCantidadJuegos();

    if (espacioActualDelCarrito + cantidad > MAX_ITEMS_CARRITO) {
        cout << "Se excedio la cantidad de items del carrito\n";
        cout << "Espacio actual del carrito: " << espacioActualDelCarrito << "\n";
        return;
    }

    // Verificar si el código ya está en el carrito
    for (int i = 0; i < cantidadJuegosRegistrados; i++) {
        if (codigos[i] == codigo) {
            cantidades[i] += cantidad;
            cout << "Cantidad actualizada en el carrito.\n";
            return;
        }
    }

    // Si no estaba, se agrega al final
    codigos[cantidadJuegosRegistrados] = codigo;
    cantidades[cantidadJuegosRegistrados] = cantidad;
    cantidadJuegosRegistrados++;
    cout << "Se ha agregado correctamente la cantidad de " << cantidad << " copias del juego " << nombreJuego << " en el carrito!\n";
}

double calcularSubtotalCarrito(const int codigos[], const int cantidades[], int cantidadJuegosRegistrados) {
    double subtotal = 0;
    for (int i = 0; i < cantidadJuegosRegistrados; i++) {
        subtotal += obtenerPrecioJuego(codigos[i]) * cantidades[i];
    }
    return subtotal;
}

int leerTipoCliente() {
    int tipo;
    cout << "Ingrese el tipo de cliente (1 = Regular, 2 = Premium, 3 = VIP): ";
    cin >> tipo;
    return tipo;
}

double obtenerPorcentajeDescuento(int tipoCliente) {
    switch (tipoCliente) {
        case 1:
            return 0.0;   // regular
        case 2:
            return 0.10;  // premium (10%)
        case 3:
            return 0.20;  // VIP (20%)
        default:
            return 0.0;
    }
}

double calcularDescuentosAdicionales(const int codigos[], const int cantidades[], int cantidadJuegosRegistrados) {
    double descuentoTotal = 0.0;
    int totalAccion = 0;
    double subtotalAccion = 0.0;
    int totalPS5 = 0;
    double subtotalPS5 = 0.0;

    for (int i = 0; i < cantidadJuegosRegistrados; i++) {
        int codigo = codigos[i];
        int cantidad = cantidades[i];

        string categoria = obtenerCategoria(codigo);
        string plataforma = obtenerPlataforma(codigo);
        double precio = obtenerPrecioJuego(codigo);

        if (categoria == "Accion") {
            totalAccion += cantidad;
            subtotalAccion += precio * cantidad;
        }

        if (plataforma == "PS5") {
            totalPS5 += cantidad;
            subtotalPS5 += precio * cantidad;
        }
    }

    if (totalAccion > 1) {
        descuentoTotal += subtotalAccion * 0.10; // 10%
    }

    if (totalPS5 > 3) {
        descuentoTotal += subtotalPS5 * 0.15; // 15%
    }

    return descuentoTotal;
}

double calcularTotalFinal(double subtotal, double porcentajeDescuento, double descuentosAdicionales) {
    double descuentoCliente = subtotal * porcentajeDescuento;
    return subtotal - descuentoCliente - descuentosAdicionales;
}

void mostrarResumenCompra(const int codigos[], const int cantidades[], int cantidadJuegosRegistrados, double porcentajeDescuento) {
    cout << "\n\n======= RESUMEN DE COMPRA =======\n";
    double subtotal = calcularSubtotalCarrito(codigos, cantidades, cantidadJuegosRegistrados);
    double descuentoCliente = subtotal * porcentajeDescuento;
    double descuentoExtra = calcularDescuentosAdicionales(codigos, cantidades, cantidadJuegosRegistrados);
    double totalFinal = calcularTotalFinal(subtotal, porcentajeDescuento, descuentoExtra);

    for (int i = 0; i < cantidadJuegosRegistrados; i++) {
        cout << cantidades[i] << "x " << obtenerNombreJuego(codigos[i])
             << " (" << obtenerPlataforma(codigos[i]) << ", " << obtenerCategoria(codigos[i]) << ")"
             << " - $" << obtenerPrecioJuego(codigos[i]) << " c/u\n";
    }

    cout << "---------------------------------\n";
    cout << "Subtotal: $" << subtotal << "\n";
    cout << "Descuento cliente: -$" << descuentoCliente << "\n";
    cout << "Descuentos adicionales: -$" << descuentoExtra << "\n";
    cout << "TOTAL A PAGAR: $" << totalFinal << "\n";
    cout << "=================================\n\n";
}

void cargarCompraDemo(int codigos[], int cantidades[], int& cantidadJuegosRegistrados) {
    codigos[0] = 101;
    cantidades[0] = 2;
    codigos[1] = 103;
    cantidades[1] = 4;
    codigos[2] = 203;
    cantidades[2] = 1;
    codigos[3] = 201;
    cantidades[3] = 1;
    codigos[4] = 301;
    cantidades[4] = 2;
    cantidadJuegosRegistrados = 5;
}

int contarCopiasEnCarrito(const int cantidades[], int cantidadJuegosRegistrados) {
    int totalCopias = 0;
    for (int i = 0; i < cantidadJuegosRegistrados; i++) {
        totalCopias += cantidades[i];
    }
    return totalCopias;
}

void limpiarCarrito(int codigos[], int cantidades[], int& cantidadJuegosRegistrados) {
    for (int i = 0; i < cantidadJuegosRegistrados; i++) {
        codigos[i] = 0;
        cantidades[i] = 0;
    }
    cantidadJuegosRegistrados = 0;
    cout << "El carrito ha sido vaciado correctamente.\n";
}