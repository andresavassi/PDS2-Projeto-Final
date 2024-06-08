#ifndef HOTEL_HPP
#define HOTEL_HPP

#include "Produto.hpp"


/// <summary>
/// 
/// Classe que representa um quarto de hotel
/// </summary>
class Hotel : public Produto { //hotel agora sera herdado do produto
	public:
		Hotel(int id, float price, Location location, int qntd=1); // construtor inicializado com parametros
		Hotel(); // construtor qual nao aceita argumentos
		Location getLocation(); // retorno do quarto de hotel escolhido
		int getQntd(); // retorna a qtdade de quartos de hotel escolhidos
		void setQntd(int qntd); // definicao da qtade de quartos de hotel
	private:
		Location location; // aramezena a localizacao do quarto de hotel
		int qntd; // armazena a qtdade de quartos de hotel escolhidos
};

#endif // !HOTEL_HPP
