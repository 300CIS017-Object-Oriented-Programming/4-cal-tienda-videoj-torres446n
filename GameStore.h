#ifndef GAMESTORE_H
#define GAMESTORE_H

#include <string>
using namespace std;

// -----------Constantes del sistema-----------
/**
 * @brief Total de juegos disponibles en la tienda.
 */
const int TOTAL_JUEGOS = 12;

/**
 * @brief Máximo número de ítems que se pueden guardar en el carrito.
 */
const int MAX_ITEMS_CARRITO = 10;

// -----------Datos de los juegos-----------
/**
 * @brief Códigos de cada juego
 */
const int codigosJuegos[TOTAL_JUEGOS] = {101,102,103,201,202,203,301,302,303,401,402,403};

/**
 * @brief Nombres de cada juego
 */
const string nombresJuegos[TOTAL_JUEGOS] = {
        "Call of Duty: Warzone", "Red Dead Redemption 2", "God of War",          // Acción
        "Zelda BOTW", "Hollow Knight", "Celeste",      // Aventura
        "FC 25", "NBA 2K25", "Gran Turismo",        // Deportes
        "Civilization VI", "Age of Empires IV", "Starcraft II" // Estrategia
};

/**
 * @brief Precio de cada juego en pesos colombianos
 */
const double preciosJuegos[TOTAL_JUEGOS]= {
        250000, 200000, 180000,
        270000, 90000, 80000,
        280000, 250000, 150000,
        200000, 220000, 170000
};

/**
 * @brief Plataforma de cada juego
 */
const string plataformasJuegos[TOTAL_JUEGOS] = {
        "PC","PS5","PS5",
        "Switch","PC","PC",
        "PS5","Xbox","PC",
        "PC","PC","PC"
};

/**
 * @brief Categoria de cada juego
 */
const string categoriasJuegos[TOTAL_JUEGOS] = {
        "Accion","Accion","Accion",
        "Aventura","Aventura","Aventura",
        "Deportes","Deportes","Deportes",
        "Estrategia","Estrategia","Estrategia"
};

/**


int stockJuego[TOTAL_JUEGOS] = {
        50,50,50,
        50,50,50,
        50,50,50,
        50,50,50
};
*/
// --- Declaraciones de funciones ---
/**
 * @brief Muestra el catálogo de juegos en la tienda
 */
void mostrarCatalogoJuegos();

/**
 * @brief Solicita al usuario un código de juego válido
 * @return Código de juego ingresado
 */
int leerCodigoJuego();

/**
 * @brief Solicita al usuario la cantidad de juegos
 * @return Cantidad ingresada
 */
int leerCantidadJuegos();

/**
 * @brief Retorna el nombre de un juego dado su código
 * @param codigoJuego Código del juego
 * @return Nombre del juego
 */
string obtenerNombreJuego(int codigoJuego);

/**
 * @brief Retorna el precio de un juego dado su código
 * @param codigoJuego Código del juego
 * @return Precio del juego
 */
double obtenerPrecioJuego(int codigoJuego);

/**
 * @brief Retorna la plataforma de un juego dado su código
 * @param codigoJuego Código del juego
 * @return Plataforma del juego
 */
string obtenerPlataforma(int codigoJuego);

/**
 * @brief Retorna la categoría de un juego dado su código.
 * @param codigoJuego Código del juego.
 * @return Categoría del juego.
 */
string obtenerCategoria(int codigoJuego);

/**
 * @brief Agrega un juego al carrito de compras.
 * @param codigos Arreglo de códigos de juegos en el carrito.
 * @param cantidades Arreglo de cantidades correspondientes a cada juego en el carrito.
 * @param cantidadJuegosRegistrados Referencia al número actual de juegos en el carrito.
 */
void agregarJuegoAlCarrito(int codigos[], int cantidades[], int& cantidadJuegosRegistrados);

/**
 * @brief Calcula el subtotal de todos los juegos en el carrito.
 * @param codigos Arreglo de códigos de juegos en el carrito.
 * @param cantidades Arreglo de cantidades correspondientes a cada juego.
 * @param cantidadJuegosRegistrados Número de juegos actualmente en el carrito.
 * @return Subtotal acumulado (no incluye descuentos).
 */
double calcularSubtotalCarrito(const int codigos[], const int cantidades[], int cantidadJuegosRegistrados);

/**
 * @brief Lee el tipo de cliente.
 * @return Tipo de cliente (1 = Regular, 2 = Premium, 3 = VIP).
 */
int leerTipoCliente();

/**
 * @brief Obtiene el porcentaje de descuento según el tipo de cliente.
 * @param tipoCliente Tipo de cliente (1 = Regular, 2 = Premium, 3 = VIP).
 * @return Porcentaje de descuento en decimal.
 */
double obtenerPorcentajeDescuento(int tipoCliente);


/**
 * @brief Calcula descuentos adicionales según las cantidades compradas.
 * @param codigos Arreglo de códigos de juegos en el carrito.
 * @param cantidades Arreglo de cantidades correspondientes a cada juego.
 * @param cantidadJuegosRegistrados Número de juegos actualmente en el carrito.
 * @return Valor total de descuentos adicionales aplicables.
 */
double calcularDescuentosAdicionales(const int codigos[], const int cantidades[], int cantidadJuegosRegistrados);

/**
 * @brief Calcula el total final después de aplicar descuentos.
 * Descuentos:
 * - Si el cliente compra más de 1 juego de categoría "Acción", se aplica un 10% de descuento
 *   sobre el subtotal de esos juegos.
 * - Si el cliente compra más de 3 juegos de plataforma "PS5", se aplica un 15% de descuento
 *   sobre el subtotal de esos juegos.
 * @param subtotal Subtotal de la compra (sin descuentos).
 * @param porcentajeDescuento Descuento por tipo de cliente (ej: 0.1 = 10%).
 * @param descuentosAdicionales Valor total de descuentos adicionales.
 * @return double Total a pagar después de aplicar todos los descuentos.
 */
double calcularTotalFinal(double subtotal, double porcentajeDescuento, double descuentosAdicionales);

/**
 * @brief Muestra un resumen detallado de la compra.
 * @param codigos Arreglo de códigos de juegos en el carrito.
 * @param cantidades Arreglo de cantidades correspondientes a cada juego.
 * @param cantidadJuegosRegistrados Número de juegos actualmente en el carrito.
 * @param porcentajeDescuento Descuento aplicado según el tipo de cliente.
 */
void mostrarResumenCompra(const int codigos[], const int cantidades[], int cantidadJuegosRegistrados, double porcentajeDescuento);

/**
 * @brief Carga un carrito de compras de demostración.
 * @param codigos Arreglo de códigos de juegos en el carrito.
 * @param cantidades Arreglo de cantidades correspondientes a cada juego.
 * @param cantidadJuegosRegistrados Referencia al número de juegos en el carrito.
 */
void cargarCompraDemo(int codigos[], int cantidades[], int& cantidadJuegosRegistrados);

/**
 * @brief Funcion auxiliar para verificar si el codigo es valido.
 * @param codigo Codigo a ingresarr.
 * @return booleano que indica si existe o no.
 */
bool existeCodigoJuego(int codigo);

#endif // GAMESTORE_H
