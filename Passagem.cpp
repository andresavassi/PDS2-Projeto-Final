#include "Passagem.hpp"

/// <summary>
/// 
/// Construtor padrao
/// </summary>
Passagem::Passagem() { 
	this->id = 0;
	this->price = 0.f;
	Location nowhere;
	nowhere.city = " ";
	nowhere.state = " ";
	nowhere.country = " ";
	this->landingLocation = nowhere;
	this->takeOffLocation = nowhere;
	this->qntd = 1;
}

/// <summary>
/// 
/// Construtor completo
/// </summary>
/// <param name="id">: codigo de identificacao</param>
/// <param name="price">: preco por assento</param>
/// <param name="takeOffLocation">: local de decolagem</param>
/// <param name="landingLocation">: local de aterrissagem</param>
/// <param name="qntd">: numero de assentos reservados (default: 1)</param>
Passagem::Passagem(int id, float price, Location takeOffLocation, Location landingLocation, int qntd) {
	this->id = id;
	this->price = price;
	this->takeOffLocation = takeOffLocation;
	this->landingLocation = landingLocation;
	this->qntd = qntd;
}

/// <summary>
/// 
/// Retorna o local de decolagem
/// </summary>
/// <returns>Passagem::takeOffLocation</returns>
Location Passagem::getTakeOffLocation() {
	return this->takeOffLocation;
}

/// <summary>
/// 
/// Retorna o local de destino
/// </summary>
/// <returns>Passagem::landingLocation</returns>
Location Passagem::getLandingLocation() {
	return this->landingLocation;
}

/// <summary>
/// 
/// Retorna o numero de assentos reservados
/// </summary>
/// <returns>Passagem::qntd</returns>
int Passagem::getQntd()
{
	return this->qntd;
}

/// <summary>
/// 
/// Altera o numero de assentos reservados
/// </summary>
/// <param name="qntd">: numero de assentos reservados</param>
void Passagem::setQntd(int qntd) {
	this->qntd = qntd;
}
