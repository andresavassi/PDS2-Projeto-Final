#ifndef  PRODUTO_HPP
#define PRODUTO_HPP

#include "Location.hpp"
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
		float getPrice();
		int getId();
	protected:
		float price;
		int id;
};

#endif // ! PRODUTO_HPP
