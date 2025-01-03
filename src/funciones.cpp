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

#include "funciones.h"
#include <fstream>
#include <iostream>

namespace mynamespace {

std::string leer_archivo(const std::string &nombreArchivo) {
    std::ifstream archivo(nombreArchivo);
    if (!archivo) {
        std::cerr << "Error al abrir el archivo: " << nombreArchivo << std::endl;
        return "";
    }
    return std::string((std::istreambuf_iterator<char>(archivo)),
                       std::istreambuf_iterator<char>());
}

void construir_lps(const std::string &patron, std::vector<int> &lps) {
    int longitud = 0;
    size_t i = 1;
    lps[0] = 0;

    while (i < patron.length()) {
        if (patron[i] == patron[longitud]) {
            longitud++;
            lps[i] = longitud;
            i++;
        } else {
            if (longitud != 0) {
                longitud = lps[longitud - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

bool kmp(const std::string &texto, const std::string &patron, size_t &pos) {
    int n = texto.length();
    int m = patron.length();
    std::vector<int> lps(m, 0);
    construir_lps(patron, lps);

    int i = 0, j = 0;
    while (i < n) {
        if (patron[j] == texto[i]) {
            i++;
            j++;
        }
        if (j == m) {
            pos = i - j;
            return true;
        } else if (i < n && patron[j] != texto[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
    return false;
}
std::pair<int, std::string> encontrar_palindromo(const std::string &cadena, int l, int r) {
    int maxLen = 0;
    std::string palindromo;

    while (l >= 0 && r < cadena.size() && cadena[l] == cadena[r]) {
        int len = r - l + 1;
        if (len > maxLen) {
            maxLen = len;
            palindromo = cadena.substr(l, len);
        }
        l--;
        r++;
    }

    return {maxLen, palindromo};
}

std::pair<std::pair<int, int>, std::string> palindromo_mas_largo(const std::string &cadena) {
    int n = cadena.size();
    if (n == 0) {
        return {{0, 0}, ""};
    }

    int maxLen = 1;
    std::string palindromo = cadena.substr(0, 1);
    std::pair<int, int> resultado = {0, 0};

    for (int i = 0; i < n; ++i) {
        // Palíndromo con centro único
        auto [len1, pal1] = encontrar_palindromo(cadena, i, i);
        if (len1 > maxLen) {
            maxLen = len1;
            palindromo = pal1;
            resultado = {i - len1 / 2, i + len1 / 2};
        }

        // Palíndromo con centro doble
        auto [len2, pal2] = encontrar_palindromo(cadena, i, i + 1);
        if (len2 > maxLen) {
            maxLen = len2;
            palindromo = pal2;
            resultado = {i - len2 / 2 + 1, i + len2 / 2};
        }
    }

    return {resultado, palindromo};
}

std::pair<std::pair<int, int>, std::string> substring_comun_mas_largo(const std::string &cadena1, const std::string &cadena2) {
    int m = cadena1.size(), n = cadena2.size();
    if (m == 0 || n == 0) {
        return {{0, 0}, ""};
    }

    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
    int maxLen = 0, endPos1 = 0;
    std::string substring;

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (cadena1[i - 1] == cadena2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if (dp[i][j] > maxLen) {
                    maxLen = dp[i][j];
                    endPos1 = i;
                    substring = cadena1.substr(i - maxLen, maxLen);
                }
            }
        }
    }

    if (maxLen == 0) {
        return {{0, 0}, ""};
    }

    return {{endPos1 - maxLen + 1, endPos1}, substring};
}

} // namespace mynamespace
