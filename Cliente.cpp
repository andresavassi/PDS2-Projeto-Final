#include "Sistema.hpp"

Cliente::Cliente(std::string nome) {
	this->name = nome;
	this->cartSubtotal = 0.0f;
}

void Cliente::addToCart(Passagem passagem) {
	int numTickets;
	if (passagem.getId()) {
		std::cout << std::endl << "digite quantas passagens deseja reservar" << std::endl;
		Sistema::readInteger(numTickets, 1, 10);
		this->ticketsCart.push_back(passagem);
		this->cartSubtotal += numTickets * passagem.getPrice();
	}
}

void Cliente::addToCart(Hotel hotel) {
	int numDays;
	if (hotel.getId()) {
		std::cout << std::endl << "digite quantas noites deseja reservar" << std::endl;
		Sistema::readInteger(numDays, 1, 30);
		this->hotelRoomsCart.push_back(hotel);
		this->cartSubtotal += numDays * hotel.getPrice();
	}
}

void Cliente::dispCart(int productKind) {
	if (!this->ticketsCart.empty() || !this->hotelRoomsCart.empty()) {
		if (productKind == FLY_TICKETS || productKind == BOTH) {
			if (!this->ticketsCart.empty()) {
				std::cout << std::endl << "apresentando o carrinho de passagens de " << this->name << std::endl << std::endl;
				for (Passagem ticket : this->ticketsCart) {
					std::cout << "id: " << ticket.getId() << std::endl;
					std::cout << "price: $" << ticket.getPrice() << std::endl;
					std::cout << "taking off: " << ticket.getTakeOffLocation().city << std::endl;
					std::cout << "landing: " << ticket.getLandingLocation().city << std::endl << std::endl;
				}
			}
		}
		if (productKind == HOTEL_ROOMS || productKind == BOTH) {
			if (!this->hotelRoomsCart.empty()) {
				std::cout << std::endl << "apresentando o carrinho de quartos de hotel de " << this->name << std::endl << std::endl;
				for (Hotel hotelRoom : this->hotelRoomsCart) {
					std::cout << "id: " << hotelRoom.getId() << ";" << std::endl;
					std::cout << "price/day: $" << hotelRoom.getPrice() << ";" << std::endl;
					std::cout << "location: " << hotelRoom.getLocation().city << ";" << std::endl << std::endl;
				}
			}
		}
		std::cout << "subtotal da compra: " << this->cartSubtotal << std::endl << std::endl;
	}
	else {
		std::cout << std::endl << "o carrinho esta vazio" << std::endl;
	}
}

void Cliente::removeFromCart() {
	int productId;
	this->dispCart(BOTH);
	std::cout << "digite o id do produto que deseja remover" << std::endl;
	std::cout << ">> ";
	std::cin >> productId;
	for (auto it = this->ticketsCart.begin(); it != this->ticketsCart.end(); it++) {
		if (it->getId() == productId) {
			this->cartSubtotal -= it->getPrice();
			this->ticketsCart.erase(it);
			return;
		}
	}
	for (auto it = this->hotelRoomsCart.begin(); it != this->hotelRoomsCart.end(); it++) {
		if (it->getId() == productId) {
			this->cartSubtotal -= it->getPrice();
			this->hotelRoomsCart.erase(it);
			return;
		}
	}
	std::cout << "o id nao corresponde a nenhum item" << std::endl;
}

