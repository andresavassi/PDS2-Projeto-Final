#ifndef PASSAGEM_HPP
#define PASSAGEM_HPP

#include "Produto.hpp"  //passagem depende do produto escolhido pelo cliente

/// <summary>
/// 
/// Classe que representa uma passagem de aviao
/// </summary>
class Passagem : public Produto { // passagem agora sera herdada do produto
	public:
		Passagem(int id, float price, Location takeOffLocation, Location landingLocation, int qntd=1); // construtor inicializado com parametros
		Passagem(); // construtor que nao aceita argumentos
		Location getTakeOffLocation(); //retorno do local de decolagem vide passagem adquirida
		Location getLandingLocation(); //retorno do local de pouso vide passagem adquirida
		int getQntd(); // retorna o total de passagens
		void setQntd(int qntd); // define o total de passagens
	private: //atributo privado com intencao de armazenar local de pouso e decolagel e total de passagens adquiridas
		Location takeOffLocation, landingLocation;
		int qntd;
};

#endif // !PASSAGEM_HPP
