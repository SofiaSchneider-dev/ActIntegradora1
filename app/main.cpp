/*
 * SonarQube, open source software quality management tool.
 * Copyright (C) 2008-2013 SonarSource
 * http://github.com/SonarOpenCommunity/sonar-cxx
 *
 * SonarQube is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 3 of the License, or (at your option) any later version.
 *
 * SonarQube is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */
#include <iostream>
#include <string>
#include <vector>
#include "funciones.h"

using namespace std;
using namespace mynamespace;

void verificar_archivos(const vector<string>& archivos, vector<string>& contenidos) {
    for (const string& archivo : archivos) {
        string contenido = leer_archivo(archivo);
        if (contenido.empty()) {
            cerr << "Error al leer " << archivo << endl;
            exit(1);  // Salir del programa si hay un error
        }
        contenidos.push_back(contenido);
    }
}

void verificar_codigos(const string& transmission, const vector<string>& mcodes) {
    size_t pos;
    for (const string& mcode : mcodes) {
        cout << (kmp(transmission, mcode, pos) ? "true " + to_string(pos + 1) : "false") << endl;
    }
}

void procesar_transmisiones(const string& transmission1, const string& transmission2) {
    auto palindromo1 = palindromo_mas_largo(transmission1);
    auto palindromo2 = palindromo_mas_largo(transmission2);
    cout << "Palíndromo más largo:" << endl;
    cout << palindromo1.first.first + 1 << " " << palindromo1.first.second + 1 << " " << palindromo1.second << endl;
    cout << palindromo2.first.first + 1 << " " << palindromo2.first.second + 1 << " " << palindromo2.second << endl;

    auto substring_comun = substring_comun_mas_largo(transmission1, transmission2);
    cout << "Substring común más largo:" << endl;
    cout << substring_comun.first.first << " " << substring_comun.first.second << " " << substring_comun.second << endl;
}

int main() {
    vector<string> archivos = {"transmission1.txt", "transmission2.txt", "mcode1.txt", "mcode2.txt", "mcode3.txt"};
    vector<string> contenidos;

    verificar_archivos(archivos, contenidos);

    cout << "Parte 1: Verificación de códigos maliciosos:" << endl;
    verificar_codigos(contenidos[0], {contenidos[2], contenidos[3], contenidos[4]});
    verificar_codigos(contenidos[1], {contenidos[2], contenidos[3], contenidos[4]});

    cout << "Parte 2 y 3: Procesamiento de transmisiones:" << endl;
    procesar_transmisiones(contenidos[0], contenidos[1]);

    return 0;
}
