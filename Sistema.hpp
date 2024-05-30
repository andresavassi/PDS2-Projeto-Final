#ifndef SISTEMA_HPP
#define SISTEMA_HPP

#include "Cliente.hpp"

/// <summary>
/// 
/// Classe que representa o sistema de reservas
/// </summary>
class Sistema {
	public:
		void loadStoreFromFile(std::string filepath);
		void showProductList(int productKind);
		Passagem pickFlyTicket();
		Hotel pickHotelRoom();
		std::vector<std::string> splitString(const std::string& s, char delim);
		static void readInteger(int& n, int min, int max);
		static void printSectionDelimiter();
	private:
		std::vector<Passagem> flyTickets;
		std::vector<Hotel> hotelRooms;
};

#endif // !SISTEMA_HPP
