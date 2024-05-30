#include "Passagem.hpp"

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

Passagem::Passagem(int id, float price, Location takeOffLocation, Location landingLocation, int qntd) {
	this->id = id;
	this->price = price;
	this->takeOffLocation = takeOffLocation;
	this->landingLocation = landingLocation;
	this->qntd = qntd;
}

Location Passagem::getTakeOffLocation() {
	return this->takeOffLocation;
}

Location Passagem::getLandingLocation() {
	return this->landingLocation;
}

int Passagem::getQntd()
{
	return this->qntd;
}

void Passagem::setQntd(int qntd) {
	this->qntd = qntd;
}
