#pragma once

#include <string>
#include <vector>

namespace mynamespace {

/**
 * @brief Lee el contenido de un archivo y lo devuelve como una cadena.
 * 
 * @param nombreArchivo Ruta del archivo a leer.
 * @return std::string Contenido del archivo.
 */
std::string leer_archivo(const std::string &nombreArchivo);

/**
 * @brief Construye el arreglo LPS (Longest Prefix Suffix) para el algoritmo KMP.
 * 
 * @param patron Patrón de texto para el cual se construirá el arreglo LPS.
 * @param lps Vector donde se almacenará el arreglo LPS.
 */
void construir_lps(const std::string &patron, std::vector<int> &lps);

/**
 * @brief Busca un patrón en un texto utilizando el algoritmo KMP.
 * 
 * @param texto Texto en el cual buscar el patrón.
 * @param patron Patrón que se busca.
 * @param pos Posición inicial del patrón encontrado (si se encuentra).
 * @return true Si el patrón se encuentra en el texto.
 * @return false Si el patrón no se encuentra en el texto.
 */
bool kmp(const std::string &texto, const std::string &patron, size_t &pos);

/**
 * @brief Encuentra el palíndromo más largo en una cadena dada.
 * 
 * @param cadena Cadena en la que se buscará el palíndromo.
 * @return std::pair<std::pair<int, int>, std::string> Información del palíndromo más largo:
 *         - Pares de índices de inicio y fin.
 *         - La cadena que corresponde al palíndromo.
 */
std::pair<std::pair<int, int>, std::string> palindromo_mas_largo(const std::string &cadena);

/**
 * @brief Encuentra la subcadena común más larga entre dos cadenas.
 * 
 * @param cadena1 Primera cadena de entrada.
 * @param cadena2 Segunda cadena de entrada.
 * @return std::pair<std::pair<int, int>, std::string> Información de la subcadena común más larga:
 *         - Pares de índices donde inicia y termina la subcadena en la primera cadena.
 *         - La subcadena más larga común.
 */
std::pair<std::pair<int, int>, std::string> substring_comun_mas_largo(
    const std::string &cadena1, const std::string &cadena2);

} // namespace mynamespace
