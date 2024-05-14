#ifndef HOTEL_HPP
#define HOTEL_HPP

#include "Produto.hpp"

class Hotel : public Produto {
	public:
		Hotel(int id, float price, Location location);
		Location getLocation();
	private:
		Location location;
};

#endif // !HOTEL_HPP
