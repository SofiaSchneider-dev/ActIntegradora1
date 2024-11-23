#pragma once

#include <string>
#include <vector>

namespace mynamespace {

std::string leerArchivo(const std::string &nombreArchivo);
void construirLPS(const std::string &patron, std::vector<int> &lps);
bool KMP(const std::string &texto, const std::string &patron, size_t &pos);
std::pair<std::pair<int, int>, std::string> palindromoMasLargo(const std::string &cadena);
std::pair<std::pair<int, int>, std::string> substringComunMasLargo(const std::string &cadena1, const std::string &cadena2);

} // namespace mynamespace
