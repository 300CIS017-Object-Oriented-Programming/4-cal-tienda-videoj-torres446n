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

// ---------------------------------------------------
// Prototipos de funciones
// ---------------------------------------------------

/**
 * @brief Muestra el catálogo de juegos en la tienda
 */
void mostrarCatalogoJuegos();

#endif // GAMESTORE_H
