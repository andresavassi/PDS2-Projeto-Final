#ifndef SISTEMA_HPP
#define SISTEMA_HPP

#include "Passagem.hpp"
#include "Hotel.hpp"
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

enum {
	TICKETS,
	HOTEL_ROOMS
};

class Sistema {
	public:
		void loadStoreFromFile(std::string filepath);
		void showProductList(int productKind);
		std::vector<std::string> splitString(const std::string& s, char delim);
	private:
		std::vector<Passagem> flyTickets;
		std::vector<Hotel> hotelRooms;
};

#endif // !SISTEMA_HPP
