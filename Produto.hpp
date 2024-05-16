#ifndef  PRODUTO_HPP
#define PRODUTO_HPP

#include "Location.hpp"
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

class Produto {
	public:
		float getPrice();
		int getId();
	protected:
		float price;
		int id;
};

#endif // ! PRODUTO_HPP
