#ifndef CLIENTE_HPP
#define CLIENTE_HPP

#include "Hotel.hpp"
#include "Passagem.hpp"

enum productKind {
	FLY_TICKETS,
	HOTEL_ROOMS,
	BOTH
};

class Cliente {
	public:
		Cliente(std::string name);
		void addToCart(Passagem passagem);
		void addToCart(Hotel hotel);
		void dispCart(int productKind);
		void removeFromCart();
	private:
		std::vector<Passagem> ticketsCart;
		std::vector<Hotel> hotelRoomsCart;
		std::string name;
		float cartSubtotal;
};

#endif // !CLIENTE_HPP
