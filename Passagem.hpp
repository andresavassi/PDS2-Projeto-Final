#ifndef PASSAGEM_HPP
#define PASSAGEM_HPP

#include "Produto.hpp"

class Passagem : public Produto {
	public:
		Passagem(int id, float price, Location takeOffLocation, Location landingLocation);
		Passagem();
		Location getTakeOffLocation();
		Location getLandingLocation();
	private:
		Location takeOffLocation, landingLocation;
};

#endif // !PASSAGEM_HPP
