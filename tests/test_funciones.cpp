#include <catch2/catch_test_macros.hpp>
#include "funciones.h"
#include <fstream>

using namespace mynamespace;

// Helper function: create a test file with specific content
void create_test_file(const std::string& filename, const std::string& content) {
    std::ofstream file(filename);
    file << content;
    file.close();
}

// Test for leerArchivo
TEST_CASE("leer_archivo: Cargar archivo correctamente") {
    const std::string testFilename = "testfile.txt";
    const std::string content = "123ABCDEF";

    // Crear archivo de prueba
    create_test_file(testFilename, content);

    std::string resultado = leer_archivo(testFilename);
    REQUIRE(resultado == content);
}

TEST_CASE("leer_archivo: Archivo inexistente") {
    std::string resultado = leer_archivo("archivo_inexistente.txt");
    REQUIRE(resultado == "");
}

// Test for KMP
TEST_CASE("kmp: Encontrar patrón en texto") {
    const std::string texto = "ABCD123ABCDEF";
    const std::string patron = "123ABC";
    size_t pos;

    REQUIRE(kmp(texto, patron, pos) == true);
    REQUIRE(pos == 4);
}

TEST_CASE("kmp: No encontrar patrón") {
    const std::string texto = "ABCD123ABCDEF";
    const std::string patron = "XYZ";
    size_t pos;

    REQUIRE(kmp(texto, patron, pos) == false);
}

// Test for palindromoMasLargo
TEST_CASE("palindromo_mas_largo: Encontrar el palíndromo más largo") {
    const std::string cadena = "123454321ABC";
    auto resultado = palindromo_mas_largo(cadena);

    REQUIRE(resultado.second == "123454321");
    REQUIRE(resultado.first.first == 0);
    REQUIRE(resultado.first.second == 8);
}

TEST_CASE("palindromo_mas_largo: Sin palíndromos largos") {
    const std::string cadena = "ABCDEFG";
    auto resultado = palindromo_mas_largo(cadena);

    REQUIRE(resultado.second == "A"); // Primer carácter
    REQUIRE(resultado.first.first == 0); // Índice ajustado
    REQUIRE(resultado.first.second == 0);
}

TEST_CASE("substring_comun_mas_largo: Encontrar el substring común más largo") {
    const std::string cadena1 = "ABCDEF123456";
    const std::string cadena2 = "XYZ123456ABC";

    auto resultado = substring_comun_mas_largo(cadena1, cadena2);

    REQUIRE(resultado.second == "123456");
    REQUIRE(resultado.first.first == 7); // Índice ajustado a 1
    REQUIRE(resultado.first.second == 12);
}

TEST_CASE("substring_comun_mas_largo: Sin substring común") {
    const std::string cadena1 = "ABCDEFG";
    const std::string cadena2 = "HIJKLMN";

    auto resultado = substring_comun_mas_largo(cadena1, cadena2);

    REQUIRE(resultado.second == "");
    REQUIRE(resultado.first.first == 0);
    REQUIRE(resultado.first.second == 0);
}

