#define CATCH_CONFIG_MAIN  // Necesario para que Catch2 genere la función main()
#include <catch2/catch.hpp>
#include "../src/funciones.h"  // Asegúrate de que el path sea correcto

using namespace std;  // Agregado para evitar el uso repetido de std::

TEST_CASE("Test de la función KMP", "[KMP]") {
    string texto = "abcdef";
    string patron = "cd";
    size_t pos;

    // Comprobamos si KMP encuentra el patrón y devuelve la posición correcta
    REQUIRE(KMP(texto, patron, pos));  // El patrón debe ser encontrado
    REQUIRE(pos == 2);  // La posición de inicio del patrón es 2 (empezando desde 0)
}

TEST_CASE("Test de palíndromo más largo", "[palindromoMasLargo]") {
    string texto = "abccba";
    auto resultado = palindromoMasLargo(texto);

    // Comprobamos que el palíndromo más largo es "abccba"
    REQUIRE(resultado.second == "abccba");
    REQUIRE(resultado.first.first == 0);  // La posición inicial del palíndromo
    REQUIRE(resultado.first.second == 5);  // La posición final del palíndromo
}
