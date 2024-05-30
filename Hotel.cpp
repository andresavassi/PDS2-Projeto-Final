#include "Hotel.hpp"


/// <summary>
/// 
/// Construtor padrao da classe Hotel
/// 
/// </summary>
Hotel::Hotel() { 
	this->id = 0;
	this->price = 0.f;
	Location nowhere;
	nowhere.city = " ";
	nowhere.state = " ";
	nowhere.country = " ";
	this->location = nowhere;
	this->qntd = 1;
}

/// <summary>
/// 
/// Construtor completo
/// 
/// </summary>
/// <param name="id">: código de identificação</param>
/// <param name="price">: preço por noite</param>
/// <param name="location">: localização</param>
/// <param name="qntd">: número de noites reservadas (default: 1)</param>
Hotel::Hotel(int id, float price, Location location, int qntd) {
	this->id = id;
	this->price = price;
	this->location = location;
	this->qntd = qntd;
}

/// <summary>
/// 
/// Retorna a localizacao
/// </summary>
/// <returns>Hotel::location</returns>
Location Hotel::getLocation() {
	return this->location;
}

/// <summary>
/// 
/// Retorna o numero de noites reservadas
/// </summary>
/// <returns>Hotel::qntd</returns>
int Hotel::getQntd() {
	return this->qntd;
}

/// <summary>
/// 
/// Altera o numero de noites reservadas
/// </summary>
/// <param name="qntd">: numero de noites reservadas</param>
void Hotel::setQntd(int qntd) {
	this->qntd = qntd;
}

