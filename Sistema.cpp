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

void Sistema::readInteger(int& n, int min, int max) {
	int ans = min - 1;
	while (true) {
		std::cout << ">> ";
		if (std::cin >> ans) {
			if (ans < min || ans > max) {
				std::cout << "valor fora da faixa esperada" << std::endl;
			}
			else {
				n = ans;
				break;
			}
		}
		else {
			std::cout << "input ruim - tipo invalido" << std::endl;
			std::cin.clear();
			std::cin.ignore(512, '\n');
		}
	}
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
	if (productKind == FLY_TICKETS) {
		for (Passagem ticket : this->flyTickets) {
			std::cout << "id: " << ticket.getId() << std::endl;
			std::cout << "preco: $" << ticket.getPrice() << std::endl;
			std::cout << "decolando de: " << ticket.getTakeOffLocation().city << std::endl;
			std::cout << "pousando em: " << ticket.getLandingLocation().city << std::endl << std::endl;
		}
	}
	else if (productKind == HOTEL_ROOMS) {
		for (Hotel hotelRoom : this->hotelRooms) {
			std::cout << "id: " << hotelRoom.getId() << ";" << std::endl;
			std::cout << "preco/dia: $" << hotelRoom.getPrice() << ";" << std::endl;
			std::cout << "local: " << hotelRoom.getLocation().city << ";" << std::endl << std::endl;
		}
	}
}

Passagem Sistema::pickFlyTicket() {
	int ticketId;
	std::cout << std::endl << "apresentando lista de passagens aereas disponiveis" << std::endl << std::endl;
	this->showProductList(FLY_TICKETS);
	std::cout << "digite o id da passagem desejada para seleciona-la" << std::endl;
	std::cout << ">> ";
	std::cin >> ticketId;
	for (auto passagem : this->flyTickets)
		if (passagem.getId() == ticketId)
			return passagem;
	std::cout << "o id nao corresponde a nenhum item" << std::endl;
	Passagem blankFlyTicket;
	return blankFlyTicket;
}

Hotel Sistema::pickHotelRoom() {
	int hotelRoomId;
	std::cout << std::endl << "apresentando lista de quartos de hotel disponiveis" << std::endl << std::endl;
	this->showProductList(HOTEL_ROOMS);
	std::cout << "digite o id do quarto de hotel desejado para seleciona-lo" << std::endl;
	std::cout << ">> ";
	std::cin >> hotelRoomId;
	for (auto hotelRoom : this->hotelRooms)
		if (hotelRoom.getId() == hotelRoomId)
			return hotelRoom;
	std::cout << "o id nao corresponde a nenhum item" << std::endl;
	Hotel emptyHotelRoom;
	return emptyHotelRoom;
}

void Sistema::printSectionDelimiter() {
	std::cout << std::endl << "-----------------------------------------------------------------------" << std::endl;
}
