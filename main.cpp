


#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Función para leer el contenido de un archivo
string leerArchivo(const string &nombreArchivo) {
    ifstream archivo(nombreArchivo);
    if (!archivo) {
        cerr << "Error al abrir el archivo: " << nombreArchivo << endl;
        return "";
    }
    string contenido((istreambuf_iterator<char>(archivo)),
                     istreambuf_iterator<char>());
    return contenido;
}


// Función para preprocesar el patrón y construir el array LPS, El array LPS nos ayuda a saltar las comparaciones innecesarias
void construirLPS(const string &patron, vector<int> &lps) {
  int longitud = 0; // Longitud del prefijo más largo que también es sufijo
  size_t i = 1;
  lps[0] = 0; // lps[0] siempre es 0

  // Preprocesar el patrón para construir el array lps
  while (i < patron.length()) {
    if (patron[i] == patron[longitud]) {
      longitud++;
      lps[i] = longitud;
      i++;
    } else {
      if (longitud != 0) {
        longitud =
            lps[longitud -
                1]; // Retrocede para revisar la siguiente posición posible
      } else {
        lps[i] = 0;
        i++;
      }
    }
  }
}

// Algoritmo KMP para buscar el patrón en el texto
bool KMP(const string &texto, const string &patron, size_t &pos) {
  int n = texto.length();
  int m = patron.length();

  // Crear el array LPS
  vector<int> lps(m, 0);
  construirLPS(patron, lps);

  int i = 0; // Índice para texto[]
  int j = 0; // Índice para patron[]
  while (i < n) {
    if (patron[j] == texto[i]) {
      i++;
      j++;
    }

    if (j == m) {  // Se encontró una coincidencia completa
      pos = i - j; // El inicio de la coincidencia en el texto
      return true; // Patrón encontrado
    } else if (i < n && patron[j] != texto[i]) {
      // Si hay un desajuste después de j coincidencias
      if (j != 0) {
        j = lps[j - 1]; // Saltar con la ayuda de lps[]
      } else {
        i++;
      }
    }
  }
  return false; // No se encontró el patrón
}

// Función para verificar el palíndromo más largo en una cadena
pair<pair<int, int>, string> palindromoMasLargo(const string &cadena) {
  int n = cadena.size();
  pair<int, int> resultado = {0, 0};
  int maxLen = 1;
  string palindromo;

  for (int i = 0; i < n; ++i) {
    // Palíndromo impar
    int l = i, r = i;
    while (l >= 0 && r < n && cadena[l] == cadena[r]) {
      if (r - l + 1 > maxLen) {
        maxLen = r - l + 1;
        resultado = {l, r};
        palindromo = cadena.substr(l, r - l + 1);
      }
      l--;
      r++;
    }

    // Palíndromo par
    l = i, r = i + 1;
    while (l >= 0 && r < n && cadena[l] == cadena[r]) {
      if (r - l + 1 > maxLen) {
        maxLen = r - l + 1;
        resultado = {l, r};
        palindromo = cadena.substr(l, r - l + 1);
      }
      l--;
      r++;
    }
  }

  return {resultado, palindromo};
}

// Función para encontrar el substring más largo común entre dos cadenas
pair<pair<int, int>, string> substringComunMasLargo(const string &cadena1,
                                                    const string &cadena2) {
  int m = cadena1.size(), n = cadena2.size();
  vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
  int maxLen = 0, endPos1 = 0;
  string substring;

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

  return {{endPos1 - maxLen + 1, endPos1}, substring};
}

int main() {
  // Leer los archivos
  string transmission1 = leerArchivo("transmission1.txt");
  string transmission2 = leerArchivo("transmission2.txt");
  string mcode1 = leerArchivo("mcode1.txt");
  string mcode2 = leerArchivo("mcode2.txt");
  string mcode3 = leerArchivo("mcode3.txt");

  // Parte 1: Verificar si transmission1 y transmission2 contienen los códigos
  // maliciosos
  cout << "Parte 1:" << endl;
  size_t pos;

  // Usando KMP se determina si se encuentra el código malicioso en la transmisión
  cout << (KMP(transmission1, mcode1, pos) ? "true " + to_string(pos + 1)
                                           : "false")
       << endl;
  cout << (KMP(transmission1, mcode2, pos) ? "true " + to_string(pos + 1)
                                           : "false")
       << endl;
  cout << (KMP(transmission1, mcode3, pos) ? "true " + to_string(pos + 1)
                                           : "false")
       << endl;
  cout << (KMP(transmission2, mcode1, pos) ? "true " + to_string(pos + 1)
                                           : "false")
       << endl;
  cout << (KMP(transmission2, mcode2, pos) ? "true " + to_string(pos + 1)
                                           : "false")
       << endl;
  cout << (KMP(transmission2, mcode3, pos) ? "true " + to_string(pos + 1)
                                           : "false")
       << endl;
  cout << "" << endl;

  // Parte 2: Encontrar el palíndromo más largo en cada transmisión
  cout << "Parte 2:" << endl;
  auto palindromo1 = palindromoMasLargo(transmission1);
  auto palindromo2 = palindromoMasLargo(transmission2);
  cout << palindromo1.first.first + 1 << " " << palindromo1.first.second + 1
       << " " << palindromo1.second << endl;
  cout << palindromo2.first.first + 1 << " " << palindromo2.first.second + 1
       << " " << palindromo2.second << endl;

  // Parte 3: Encontrar el substring más largo común entre transmission1 y
  // transmission2
  cout << "Parte 3: " << endl;
  auto substringComun = substringComunMasLargo(transmission1, transmission2);
  cout << substringComun.first.first << " " << substringComun.first.second
       << " " << substringComun.second << endl;

  return 0;
}
