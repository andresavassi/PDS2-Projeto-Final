#ifndef LOCATION_HPP
#define LOCATION_HPP

#include <iostream>

/// <summary>
/// 
/// Struct que organiza e armazena informacoes de localizacao
/// </summary>
typedef struct Location_ {
	std::string country, state, city; // armazenamento de pais, estado e cidade respectivamente
} Location;

#endif // !LOCATION_HPP
