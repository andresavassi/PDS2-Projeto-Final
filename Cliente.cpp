#include "Sistema.hpp"

/// <summary>
/// 
/// Construtor padrao
/// </summary>
/// <param name="nome">: nome do cliente</param>
Cliente::Cliente(std::string nome) {
	this->name = nome;
	this->cartSubtotal = 0.0f;
}

/// <summary>
/// 
/// Adiciona uma passagem ao carrinho
/// </summary>
/// <param name="ticket">: passagem a adicionar no carrinho</param>
void Cliente::addToCart(Passagem ticket) {
	int numTickets;
	if (ticket.getId()) {
		std::cout << std::endl << "digite quantas passagens deseja reservar" << std::endl;
		Sistema::readInteger(numTickets, 1, 10);
		ticket.setQntd(numTickets);
		this->ticketsCart.push_back(ticket);
		this->cartSubtotal += ticket.getQntd() * ticket.getPrice();
	}
}

/// <summary>
/// 
/// Adiciona uma reserva de quarto de hotel ao carrinho
/// </summary>
/// <param name="hotel">: quarto de hotel cuja reserva vai ser adicionada ao carrinho</param>
void Cliente::addToCart(Hotel hotel) {
	int numDays;
	if (hotel.getId()) {
		std::cout << std::endl << "digite quantas noites deseja reservar" << std::endl;
		Sistema::readInteger(numDays, 1, 30);
		hotel.setQntd(numDays);
		this->hotelRoomsCart.push_back(hotel);
		this->cartSubtotal += hotel.getQntd() * hotel.getPrice();
	}
}

/// <summary>
/// 
/// Imprime as informacoes do carrinho
/// </summary>
/// <param name="productKind">: tipo de produto a ser impresso</param>
void Cliente::dispCart(int productKind) {
	if (!this->ticketsCart.empty() || !this->hotelRoomsCart.empty()) {
		if (productKind == FLY_TICKETS || productKind == BOTH) {
			if (!this->ticketsCart.empty()) {
				std::cout << std::endl << "apresentando o carrinho de passagens de " << this->name << std::endl << std::endl;
				for (Passagem ticket : this->ticketsCart) {
					std::cout << "id: " << ticket.getId() << ";" << std::endl;
					std::cout << "preço: $" << ticket.getPrice() << ";" << std::endl;
					std::cout << "decolando de: " << ticket.getTakeOffLocation().city << ";" << std::endl;
					std::cout << "pousando em: " << ticket.getLandingLocation().city << ";" << std::endl;
					std::cout << "quantidade: " << ticket.getQntd() << ";" << std::endl << std::endl;
				}
			}
		}
		if (productKind == HOTEL_ROOMS || productKind == BOTH) {
			if (!this->hotelRoomsCart.empty()) {
				std::cout << std::endl << "apresentando o carrinho de quartos de hotel de " << this->name << std::endl << std::endl;
				for (Hotel hotelRoom : this->hotelRoomsCart) {
					std::cout << "id: " << hotelRoom.getId() << ";" << std::endl;
					std::cout << "preço: $" << hotelRoom.getPrice() << ";" << std::endl;
					std::cout << "local: " << hotelRoom.getLocation().city << ";" << std::endl;
					std::cout << "quantidade: " << hotelRoom.getQntd() << ";" << std::endl << std::endl;
				}
			}
		}
		std::cout << "subtotal da compra: $" << this->cartSubtotal << std::endl << std::endl;
	}
	else {
		std::cout << std::endl << "o carrinho esta vazio" << std::endl;
	}
}

/// <summary>
/// 
/// Remove um produto do carrinho
/// </summary>
void Cliente::removeFromCart() {
	int productId;
	this->dispCart(BOTH);
	std::cout << "digite o id do produto que deseja remover" << std::endl;
	std::cout << ">> ";
	std::cin >> productId;
	for (auto it = this->ticketsCart.begin(); it != this->ticketsCart.end(); it++) {
		if (it->getId() == productId) {
			this->cartSubtotal -= it->getPrice() * it->getQntd();
			this->ticketsCart.erase(it);
			return;
		}
	}
	for (auto it = this->hotelRoomsCart.begin(); it != this->hotelRoomsCart.end(); it++) {
		if (it->getId() == productId) {
			this->cartSubtotal -= it->getPrice() * it->getQntd();
			this->hotelRoomsCart.erase(it);
			return;
		}
	}
	std::cout << "o id nao corresponde a nenhum item" << std::endl;
}

/// <summary>
/// 
/// Finaliza a compra e limpa o carrinho
/// </summary>
void Cliente::checkOut() {
	std::cout << std::endl << "voce escolheu fazer check-out (confirmar compra dos itens armazenados no carrinho)" << std::endl;
	this->dispCart(BOTH);
	std::cout << "total com impostos e taxas (+15%): $" << this->getCartSubTotal() * 1.15 << std::endl << std::endl;
	std::cout << "deseja confirmar a compra? [1/0 : sim/nao]" << std::endl;
	int compraConfirmada;
	Sistema::readInteger(compraConfirmada, 0, 1);
	if (!compraConfirmada)
		return;
	else
		this->clearCart();
	std::cout << std::endl << "compra finalizada. obrigado pela preferencia" << std::endl;
}

/// <summary>
/// 
/// Limpa o carrinho
/// </summary>
void Cliente::clearCart() {
	this->hotelRoomsCart.clear();
	this->ticketsCart.clear();
}

/// <summary>
/// 
/// Retorna o sub-total dos produtos guardados no carrinho
/// </summary>
/// <returns>sub-total dos produtos do carrinho</returns>
float Cliente::getCartSubTotal() {
	float subTotal = 0.0f;
	for (Hotel hotelRoom : this->hotelRoomsCart)
		subTotal += hotelRoom.getPrice() * hotelRoom.getQntd();
	for (Passagem ticket : this->ticketsCart)
		subTotal += ticket.getPrice() * ticket.getQntd();
	return subTotal;
}

