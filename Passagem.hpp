#ifndef PASSAGEM_HPP
#define PASSAGEM_HPP

#include "Produto.hpp"

/// <summary>
/// 
/// Classe que representa uma passagem de aviao
/// </summary>
class Passagem : public Produto {
	public:
		Passagem(int id, float price, Location takeOffLocation, Location landingLocation, int qntd=1);
		Passagem();
		Location getTakeOffLocation();
		Location getLandingLocation();
		int getQntd();
		void setQntd(int qntd);
	private:
		Location takeOffLocation, landingLocation;
		int qntd;
};

#endif // !PASSAGEM_HPP
