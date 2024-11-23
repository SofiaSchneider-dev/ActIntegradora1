#include <catch2/catch_test_macros.hpp>
#include "funciones.h"  // Asegúrate de incluir el archivo de cabecera de funciones

using namespace std;
using namespace mynamespace;  // Si usas un espacio de nombres, agrega esto

TEST_CASE("Prueba de la función leerArchivo") {
    SECTION("Archivo existente") {
        // Aquí asumes que el archivo 'transmission1.txt' existe en el directorio adecuado
        string contenido = leerArchivo("transmission1.txt");
        REQUIRE_FALSE(contenido.empty());  // Aseguramos que el archivo no está vacío
    }

    SECTION("Archivo no existente") {
        string contenido = leerArchivo("archivo_inexistente.txt");
        REQUIRE(contenido.empty());  // Aseguramos que el archivo no se pudo leer
    }
}

TEST_CASE("Prueba de la función KMP") {
    string texto = "Esto es un test";
    string patron = "test";
    size_t pos;

    SECTION("Patrón encontrado") {
        REQUIRE(KMP(texto, patron, pos) == true);
        REQUIRE(pos == 14);  // El patrón "test" empieza en la posición 14
    }

    SECTION("Patrón no encontrado") {
        string patronNoEncontrado = "noexiste";
        REQUIRE(KMP(texto, patronNoEncontrado, pos) == false);
    }
}

TEST_CASE("Prueba de palíndromo más largo") {
    string texto = "abacabadabacaba";  // Un palíndromo clásico

    SECTION("Encontrar palíndromo") {
        auto resultado = palindromoMasLargo(texto);
        REQUIRE(resultado.first.first == 0);
        REQUIRE(resultado.first.second == texto.size() - 1);  // El palíndromo cubre toda la cadena
        REQUIRE(resultado.second == "abacabadabacaba");  // La cadena misma es el palíndromo
    }
}

TEST_CASE("Prueba de substring común más largo") {
    string cadena1 = "abcdef";
    string cadena2 = "zabcf";
    auto resultado = substringComunMasLargo(cadena1, cadena2);

    SECTION("Encontrar substring común más largo") {
        REQUIRE(resultado.first.first == 2);  // La subcadena común empieza en la posición 2 de cadena1
        REQUIRE(resultado.first.second == 4);  // La subcadena común termina en la posición 4 de cadena1
        REQUIRE(resultado.second == "bc");  // El substring común más largo es "bc"
    }
}
