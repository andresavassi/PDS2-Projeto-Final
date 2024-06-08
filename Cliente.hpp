#ifndef CLIENTE_HPP
#define CLIENTE_HPP

#include "Hotel.hpp" //vetor cliente depende do hotel escolhido nesse caso
#include "Passagem.hpp" // vetor cliente depende da passagem nesse caso

/// <summary>
/// 
/// Enumeracao que organiza os codigos que definem a exibicao dos produtos
/// </summary>
enum productKind {  // definicao de produtos no "carrinho"
	FLY_TICKETS, //passagens areas
	HOTEL_ROOMS, // quarto de hotel
	BOTH // ambas opcoes supracitadas
};

/// <summary>
/// 
/// Classe que representa o cliente
/// </summary>
class Cliente {
	public: //entrada com variavel cliente publica
		Cliente(std::string name);
		void addToCart(Passagem ticket); // registrar aquisicao de passagem pelo cliente no carrinho
		void addToCart(Hotel hotel); //registrar aquisicao de quarto de hotel, 
		void dispCart(int productKind); // mostra o carrinho baseado no tipo de aquisicao feita pelo cliente acima; dispcart mostra os itens de acordo com o especificado
		void removeFromCart(); // remocao de todos os itens previamente alocados ao carrinho
		void checkOut(); // finalizacao de aquisicao de itens pelo cliente
		void clearCart(); // limpeza do carrinho de compras
		float getCartSubTotal(); // registra previamente o valor total das aquisicoes pelo cliente (somatorio)
	private: //atributo privado com intencao de armazenar os seguintes itens
		std::vector<Passagem> ticketsCart; // passagens aereas do cliente via vetor
		std::vector<Hotel> hotelRoomsCart; // quartos de hotel do cliente via vetor
		std::string name; // nome do cliente
		float cartSubtotal; // subtotal do carrinho
};

#endif // !CLIENTE_HPP
