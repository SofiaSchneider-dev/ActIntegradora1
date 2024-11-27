#pragma once

#include <string>
#include <vector>

namespace mynamespace {

std::string leer_archivo(const std::string &nombreArchivo);
void construir_lps(const std::string &patron, std::vector<int> &lps);
bool kmp(const std::string &texto, const std::string &patron, size_t &pos);
std::pair<std::pair<int, int>, std::string> palindromo_mas_largo(const std::string &cadena);
std::pair<std::pair<int, int>, std::string> substring_comun_mas_largo(const std::string &cadena1, const std::string &cadena2);

} // namespace mynamespace
