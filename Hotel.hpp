#ifndef HOTEL_HPP
#define HOTEL_HPP

#include "Produto.hpp"


/// <summary>
/// 
/// Classe que representa um quarto de hotel
/// </summary>
class Hotel : public Produto {
	public:
		Hotel(int id, float price, Location location, int qntd=1);
		Hotel();
		Location getLocation();
		int getQntd();
		void setQntd(int qntd);
	private:
		Location location;
		int qntd;
};

#endif // !HOTEL_HPP
