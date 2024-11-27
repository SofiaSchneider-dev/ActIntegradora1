#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>
#include "funciones.h"
#include <fstream>
#include <cstdio> 

using namespace mynamespace;

// Helper function: create a test file with specific content
void create_test_file(const std::string& filename, const std::string& content) {
    std::ofstream file(filename);
    if (file) {
        file << content;
        file.close();
    }
}

// Test for leer_archivo
TEST_CASE("leer_archivo: Cargar archivo correctamente", "[leer_archivo]") {
    const std::string testFilename = "testfile.txt";
    const std::string content = "123ABCDEF";

    create_test_file(testFilename, content);

    std::string resultado = leer_archivo(testFilename);
    REQUIRE(resultado == content);

    // Cleanup test file
    std::remove(testFilename.c_str());
}

TEST_CASE("leer_archivo: Archivo inexistente", "[leer_archivo]") {
    std::string resultado = leer_archivo("archivo_inexistente.txt");
    REQUIRE(resultado.empty());
}

// Test for KMP
TEST_CASE("kmp: Encontrar patrón en texto", "[kmp]") {
    const std::string texto = "ABCD123ABCDEF";
    const std::string patron = "123ABC";
    size_t pos;

    REQUIRE(kmp(texto, patron, pos));
    REQUIRE(pos == 4);
}

TEST_CASE("kmp: No encontrar patrón", "[kmp]") {
    const std::string texto = "ABCD123ABCDEF";
    const std::string patron = "XYZ";
    size_t pos;

    REQUIRE_FALSE(kmp(texto, patron, pos));
}

// Test for palindromo_mas_largo
TEST_CASE("palindromo_mas_largo: Encontrar el palíndromo más largo", "[palindromo_mas_largo]") {
    const std::string cadena = "123454321ABC";
    auto resultado = palindromo_mas_largo(cadena);

    REQUIRE(resultado.second == "123454321");
    REQUIRE(resultado.first.first == 0);
    REQUIRE(resultado.first.second == 8);
}

TEST_CASE("palindromo_mas_largo: Sin palíndromos largos", "[palindromo_mas_largo]") {
    const std::string cadena = "ABCDEFG";
    auto resultado = palindromo_mas_largo(cadena);

    REQUIRE(resultado.second == "A");
    REQUIRE(resultado.first.first == 0);
    REQUIRE(resultado.first.second == 0);
}

// Test for substring_comun_mas_largo
TEST_CASE("substring_comun_mas_largo: Encontrar el substring común más largo", "[substring_comun_mas_largo]") {
    const std::string cadena1 = "ABCDEF123456";
    const std::string cadena2 = "XYZ123456ABC";

    auto resultado = substring_comun_mas_largo(cadena1, cadena2);

    REQUIRE(resultado.second == "123456");
    REQUIRE(resultado.first.first == 7);
    REQUIRE(resultado.first.second == 12);
}

TEST_CASE("substring_comun_mas_largo: Sin substring común", "[substring_comun_mas_largo]") {
    const std::string cadena1 = "ABCDEFG";
    const std::string cadena2 = "HIJKLMN";

    auto resultado = substring_comun_mas_largo(cadena1, cadena2);

    REQUIRE(resultado.second.empty());
    REQUIRE(resultado.first.first == 0);
    REQUIRE(resultado.first.second == 0);
}
