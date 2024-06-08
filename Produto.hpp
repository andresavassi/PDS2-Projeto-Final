#ifndef  PRODUTO_HPP
#define PRODUTO_HPP

#include "Location.hpp" //produto depende de location
#include <vector>
#include <fstream>
#include <string>  
#include <sstream>

/// <summary>
/// 
/// Classe que implementa os atributos basicos comuns a todo produto
/// e os metodos para acessa-los
/// </summary>
class Produto {
	public:
		float getPrice(); // obtencao e retonro do valor do produto
		int getId(); // obtencao e retorno do id do produto
	protected: // acessiveis por produto e tambem por classes derivadas
		float price; // preco do produto
		int id; // id do produto
};

#endif // ! PRODUTO_HPP
