#include "Sistema.hpp"

// split string based on character delimiter
// source: https://stackoverflow.com/questions/14265581/parse-split-a-string-in-c-using-string-delimiter-standard-c
std::vector<std::string> Sistema::splitString(const std::string& s, char delim) {
	std::vector<std::string> result;
	std::stringstream ss(s);
	std::string item;

	while (getline(ss, item, delim)) {
		result.push_back(item);
	}

	return result;
}

void Sistema::loadStoreFromFile(std::string filepath) {
	std::fstream filestream;
	std::vector<std::string> splittedLine, splittedTakeOffLocationString, splittedLandingLocationString, splittedLocationString;
	std::string linebuf;
	filestream.open(filepath);
	if (!filestream.is_open()) {
		std::cout << "falha ao abrir arquivo" << std::endl;
		return;
	}
	else {
		while (std::getline(filestream, linebuf)) {
			splittedLine = splitString(linebuf, '/');
			char kind = splittedLine[0][0];
			if (kind == 'T') {
				int id = std::stoi(splittedLine[1]);
				float price = std::stof(splittedLine[2]);

				splittedTakeOffLocationString = splitString(splittedLine[3], ',');
				Location takeOffLocaton;
				takeOffLocaton.city = splittedTakeOffLocationString[0];
				takeOffLocaton.state = splittedTakeOffLocationString[1];
				takeOffLocaton.country = splittedTakeOffLocationString[2];
				
				splittedLandingLocationString = splitString(splittedLine[4], ',');
				Location landingLocaton;
				landingLocaton.city = splittedLandingLocationString[0];
				landingLocaton.state = splittedLandingLocationString[1];
				landingLocaton.country = splittedLandingLocationString[2];

				Passagem passagem(id, price, takeOffLocaton, landingLocaton);
				this->flyTickets.push_back(passagem);
			}
			else if (kind == 'H') {
				int id = std::stoi(splittedLine[1]);
				float price = std::stof(splittedLine[2]);

				splittedLocationString = splitString(splittedLine[3], ',');
				Location location;
				location.city = splittedTakeOffLocationString[0];
				location.state = splittedTakeOffLocationString[1];
				location.country = splittedTakeOffLocationString[2];

				Hotel hotelRoom(id, price, location);
				this->hotelRooms.push_back(hotelRoom);
			}
		}
	}
}

void Sistema::showProductList(int productKind) {
	if (productKind == TICKETS) {
		for (Passagem ticket : this->flyTickets) {
			std::cout << "id: " << ticket.getId() << std::endl;
			std::cout << "price: $" << ticket.getPrice() << std::endl;
			std::cout << "taking off: " << ticket.getTakeOffLocation().city << std::endl;
			std::cout << "landing: " << ticket.getLandingLocation().city << std::endl << std::endl;
		}
	}
	else if (productKind == HOTEL_ROOMS) {
		for (Hotel hotelRoom : this->hotelRooms) {
			std::cout << "id: " << hotelRoom.getId() << ";" << std::endl;
			std::cout << "price/day: $" << hotelRoom.getPrice() << ";" << std::endl;
			std::cout << "location: " << hotelRoom.getLocation().city << ";" << std::endl << std::endl;
		}
	}
}

