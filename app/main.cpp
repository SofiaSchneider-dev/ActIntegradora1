#include <iostream>
#include <string>
#include "../src/funciones.h"

using namespace std;

int main() {
    // Leer los archivos
    string transmission1 = leerArchivo("transmission1.txt");
    if (transmission1.empty()) {
        cerr << "Error al leer transmission1.txt" << endl;
        return 1;
    }

    string transmission2 = leerArchivo("transmission2.txt");
    if (transmission2.empty()) {
        cerr << "Error al leer transmission2.txt" << endl;
        return 1;
    }

    string mcode1 = leerArchivo("mcode1.txt");
    if (mcode1.empty()) {
        cerr << "Error al leer mcode1.txt" << endl;
        return 1;
    }

    string mcode2 = leerArchivo("mcode2.txt");
    if (mcode2.empty()) {
        cerr << "Error al leer mcode2.txt" << endl;
        return 1;
    }

    string mcode3 = leerArchivo("mcode3.txt");
    if (mcode3.empty()) {
        cerr << "Error al leer mcode3.txt" << endl;
        return 1;
    }

    // Parte 1: Verificar si transmission1 y transmission2 contienen los códigos maliciosos
    size_t pos;
    cout << "Parte 1: Verificación de códigos maliciosos:" << endl;
    cout << (KMP(transmission1, mcode1, pos) ? "true " + to_string(pos + 1) : "false") << endl;
    cout << (KMP(transmission1, mcode2, pos) ? "true " + to_string(pos + 1) : "false") << endl;
    cout << (KMP(transmission1, mcode3, pos) ? "true " + to_string(pos + 1) : "false") << endl;
    cout << (KMP(transmission2, mcode1, pos) ? "true " + to_string(pos + 1) : "false") << endl;
    cout << (KMP(transmission2, mcode2, pos) ? "true " + to_string(pos + 1) : "false") << endl;
    cout << (KMP(transmission2, mcode3, pos) ? "true " + to_string(pos + 1) : "false") << endl;

    // Parte 2: Encontrar el palíndromo más largo
    auto palindromo1 = palindromoMasLargo(transmission1);
    auto palindromo2 = palindromoMasLargo(transmission2);
    cout << "Parte 2: Palíndromo más largo:" << endl;
    cout << palindromo1.first.first + 1 << " " << palindromo1.first.second + 1 << " " << palindromo1.second << endl;
    cout << palindromo2.first.first + 1 << " " << palindromo2.first.second + 1 << " " << palindromo2.second << endl;

    // Parte 3: Encontrar el substring común más largo
    auto substringComun = substringComunMasLargo(transmission1, transmission2);
    cout << "Parte 3: Substring común más largo:" << endl;
    cout << substringComun.first.first << " " << substringComun.first.second << " " << substringComun.second << endl;

    return 0;
}
