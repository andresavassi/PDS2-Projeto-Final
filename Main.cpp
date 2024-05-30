#include "Sistema.hpp"

int main() {
	Sistema sistema;
	int mainMenuOpt;
	bool leave = false;
	std::string name;
	std::cout << "digite seu nome para realizar o cadastro" << std::endl;
	std::cout << ">> ";
	std::cin >> name;
	std::cout << std::endl;
	Cliente cliente(name);
	sistema.loadStoreFromFile("ProductList.txt");
	while (!leave) {
		Sistema::printSectionDelimiter();
		std::cout << std::endl << "menu principal" << std::endl << std::endl;
		std::cout << "(0) sair" << std::endl;
		std::cout << "(1) reservar passagem de aviao" << std::endl;
		std::cout << "(2) reservar quarto de hotel" << std::endl;
		std::cout << "(3) remover item do carrinho" << std::endl;
		std::cout << "(4) ver carrinho" << std::endl;
		std::cout << "(5) fazer check-out" << std::endl << std::endl;
		std::cout << "digite o numero correspondente a acao desejada" << std::endl;
		mainMenuOpt = -1;
		Sistema::readInteger(mainMenuOpt, 0, 5);
		switch (mainMenuOpt) {
			case 0:
				std::cout << std::endl << "voce saiu do programa" << std::endl;
				leave = true;
				break;
			case 1:
				Sistema::printSectionDelimiter();
				cliente.addToCart(sistema.pickFlyTicket());
				break;
			case 2:
				Sistema::printSectionDelimiter();
				cliente.addToCart(sistema.pickHotelRoom());
				break;
			case 3:
				Sistema::printSectionDelimiter();
				cliente.removeFromCart();
				break;
			case 4:
				Sistema::printSectionDelimiter();
				cliente.dispCart(BOTH);
				break;
			case 5:
				Sistema::printSectionDelimiter();
				cliente.checkOut();
				break;
			default:
				std::cout << "o numero digitado nao corresponde a nenhuma acao" << std::endl;
		}
	}
	return 0;
}
