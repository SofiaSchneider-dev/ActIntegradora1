#include <catch2/catch_test_macros.hpp>
#include "funciones.h"
#include <fstream>

using namespace mynamespace;

// Helper function: create a test file with specific content
void createTestFile(const std::string& filename, const std::string& content) {
    std::ofstream file(filename);
    file << content;
    file.close();
}

// Test for leerArchivo
TEST_CASE("leerArchivo: Cargar archivo correctamente") {
    const std::string testFilename = "testfile.txt";
    const std::string content = "123ABCDEF";

    // Crear archivo de prueba
    createTestFile(testFilename, content);

    std::string resultado = leerArchivo(testFilename);
    REQUIRE(resultado == content);
}

TEST_CASE("leerArchivo: Archivo inexistente") {
    std::string resultado = leerArchivo("archivo_inexistente.txt");
    REQUIRE(resultado == "");
}

// Test for KMP
TEST_CASE("KMP: Encontrar patrón en texto") {
    const std::string texto = "ABCD123ABCDEF";
    const std::string patron = "123ABC";
    size_t pos;

    REQUIRE(KMP(texto, patron, pos) == true);
    REQUIRE(pos == 4);
}

TEST_CASE("KMP: No encontrar patrón") {
    const std::string texto = "ABCD123ABCDEF";
    const std::string patron = "XYZ";
    size_t pos;

    REQUIRE(KMP(texto, patron, pos) == false);
}

// Test for palindromoMasLargo
TEST_CASE("palindromoMasLargo: Encontrar el palíndromo más largo") {
    const std::string cadena = "123454321ABC";
    auto resultado = palindromoMasLargo(cadena);

    REQUIRE(resultado.second == "123454321");
    REQUIRE(resultado.first.first == 0);
    REQUIRE(resultado.first.second == 8);
}

TEST_CASE("palindromoMasLargo: Sin palíndromos largos") {
    const std::string cadena = "ABCDEFG";
    auto resultado = palindromoMasLargo(cadena);

    REQUIRE(resultado.second == "A"); // Primer carácter
    REQUIRE(resultado.first.first == 0); // Índice ajustado
    REQUIRE(resultado.first.second == 0);
}

TEST_CASE("substringComunMasLargo: Encontrar el substring común más largo") {
    const std::string cadena1 = "ABCDEF123456";
    const std::string cadena2 = "XYZ123456ABC";

    auto resultado = substringComunMasLargo(cadena1, cadena2);

    REQUIRE(resultado.second == "123456");
    REQUIRE(resultado.first.first == 7); // Índice ajustado a 1
    REQUIRE(resultado.first.second == 12);
}

TEST_CASE("substringComunMasLargo: Sin substring común") {
    const std::string cadena1 = "ABCDEFG";
    const std::string cadena2 = "HIJKLMN";

    auto resultado = substringComunMasLargo(cadena1, cadena2);

    REQUIRE(resultado.second == "");
    REQUIRE(resultado.first.first == 0);
    REQUIRE(resultado.first.second == 0);
}

