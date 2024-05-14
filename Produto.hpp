#ifndef  PRODUTO_HPP
#define PRODUTO_HPP

#include "Location.hpp"

class Produto {
	public:
		float getPrice();
		int getId();
	protected:
		float price;
		int id;
};

#endif // ! PRODUTO_HPP
