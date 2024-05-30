#ifndef CLIENTE_HPP
#define CLIENTE_HPP

#include "Hotel.hpp"
#include "Passagem.hpp"

/// <summary>
/// 
/// Enumeração que organiza os códigos que definem a exibição dos produtos
/// </summary>
enum productKind {
	FLY_TICKETS,
	HOTEL_ROOMS,
	BOTH
};

/// <summary>
/// 
/// Classe que representa o cliente
/// </summary>
class Cliente {
	public:
		Cliente(std::string name);
		void addToCart(Passagem ticket);
		void addToCart(Hotel hotel);
		void dispCart(int productKind);
		void removeFromCart();
		void checkOut();
		void clearCart();
		float getCartSubTotal();
	private:
		std::vector<Passagem> ticketsCart;
		std::vector<Hotel> hotelRoomsCart;
		std::string name;
		float cartSubtotal;
};

#endif // !CLIENTE_HPP
